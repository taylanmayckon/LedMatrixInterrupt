#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "hardware/timer.h"
#include "libs/led_matrix/led_matrix.h"

// Definição dos pinos do Led RGB
#define RGB_RED 13
#define RGB_GREEN 11
#define RGB_BLUE 12
#define BUTTON_A 5
#define BUTTON_B 6
#define IS_RGBW false
#define LED_MATRIX_PIN 7

// Definindo a máscara para GPIOs do Led RGB (11, 12 e 13)
#define OUTPUT_MASK ((1 << RGB_RED) | (1 << RGB_GREEN) | (1 << RGB_BLUE))
// Máscara para GPIO dos botões
#define INPUT_MASK ((1 << BUTTON_A) | (1 << BUTTON_B))

// Variável que verifica e atualiza o estado do LED VERMELHO
bool led_on = false;
// Variável de contador para a interrupção
uint16_t contador = 6;
// Variável que armazena o tempo do último evento, em microssegundos (para implementar o debounce)
static volatile uint32_t last_time = 0;

// Variáveis da PIO declaradas no escopo global
PIO pio;
uint sm;

// Função de interrupção
void gpio_irq_handler(uint gpio, uint32_t events){
    // Obtendo o tempo atual (em microssegundos)
    uint32_t current_time = to_us_since_boot(get_absolute_time());

    // Verificando se passou tempo suficiente desde o último evento (para implementar o debounce)
    if(current_time - last_time > 200000){
        // Atualizando o last_time para a próxima verificação de debounce
        last_time = current_time;

        // Imprime o número na matriz com base no botão pressionado
        if(gpio == BUTTON_A){ // Incrementa o número exibido
            atualiza_numero(contador);
        }
        if(gpio == BUTTON_B){ // Decrementa o número exibido
            atualiza_numero(contador);
        }
    }
}

int main(){
    stdio_init_all();

    // Inicializando todos os pinos da máscara de OUTPUT
    gpio_init_mask(OUTPUT_MASK);
    // Definindo como saída
    gpio_set_dir_out_masked(OUTPUT_MASK);

    // Inicializando todos os pinos da máscara de INPUT
    gpio_init_mask(INPUT_MASK);
    // Definindo os botões como pull up
    gpio_pull_up(BUTTON_A);
    gpio_pull_up(BUTTON_B);

    // Inicializando a PIO
    pio = pio0;
    sm = 0;

    uint offset = pio_add_program(pio, &ws2812_program);
    ws2812_program_init(pio, sm, offset, LED_MATRIX_PIN, 800000, IS_RGBW);

    // Configuração das interrupções
    gpio_set_irq_enabled_with_callback(BUTTON_A, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
    gpio_set_irq_enabled_with_callback(BUTTON_B, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);

    while (true) {
        // Alternando o estado do led a cada 100ms (gera um período de 200ms = 5 piscadas por segundo)
        led_on = !led_on;
        gpio_put(RGB_RED, led_on);
        sleep_ms(100);
    }
}

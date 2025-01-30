#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "pio_matrix.pio.h"

// Definição dos pinos do Led RGB
#define RGB_RED 13
#define RGB_GREEN 11
#define RGB_BLUE 12
#define LED_MATRIX_PIN 7

// Definindo a máscara para GPIOs do Led RGB (11, 12 e 13)
#define GPIO_MASK ((1 << RGB_RED) | (1 << RGB_GREEN) | (1 << RGB_BLUE))

// Variável que vai servir pra alternar o estado do LED
bool led_on = false;

// Função de configuração do PIO
uint pio_config(PIO pio){
    bool ok;

    // Colocando a frequência de clock para 128 MHz, facilitando a divisão de clock
    ok = set_sys_clock_khz(128000, false);

    printf("iniciando a transmissão PIO");
    if (ok) printf("clock set to %ld\n", clock_get_hz(clk_sys));

    // Configurações da PIO
    uint offset = pio_add_program(pio, &pio_matrix_program);
    uint sm = pio_claim_unused_sm(pio, true);
    pio_matrix_program_init(pio, sm, offset, LED_MATRIX_PIN);

    return sm;
}

int main(){
    stdio_init_all();

    // Inicializando todos os pinos da máscara
    gpio_init_mask(GPIO_MASK);
    // Definindo como saída
    gpio_set_dir_out_masked(GPIO_MASK);

    // Inicializando a PIO
    PIO pio = pio0;
    uint sm = pio_config(pio);

    while (true) {
        // Alternando o estado do led a cada 100ms (gera um período de 200ms = 5 piscadas por segundo)
        led_on = !led_on;
        gpio_put(RGB_RED, led_on);
        sleep_ms(100);
    }
}

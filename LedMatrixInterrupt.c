#include <stdio.h>
#include "pico/stdlib.h"

// Definição dos pinos do Led RGB
#define RGB_RED 13
#define RGB_GREEN 11
#define RGB_BLUE 12

// Definindo a máscara para GPIOs do Led RGB (11, 12 e 13)
#define GPIO_MASK ((1 << RGB_RED) | (1 << RGB_GREEN) | (1 << RGB_BLUE))

// Variável que vai servir pra alternar o estado do LED
bool led_on = false;

int main(){
    stdio_init_all();

    // Inicializando todos os pinos da máscara
    gpio_init_mask(GPIO_MASK);
    // Definindo como saída
    gpio_set_dir_out_masked(GPIO_MASK);

    while (true) {
        // Alternando o estado do led a cada 100ms (gera um período de 200ms = 5 piscadas por segundo)
        led_on = !led_on;
        gpio_put(RGB_RED, led_on);
        sleep_ms(100);
    }
}

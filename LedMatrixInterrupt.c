#include <stdio.h>
#include "pico/stdlib.h"

// Definição dos pinos do Led RGB
#define RGB_RED 13
#define RGB_GREEN 11
#define RGB_BLUE 12

// Definindo a máscara para GPIOs do Led RGB (11, 12 e 13)
#define GPIO_MASK ((1 << RGB_RED) | (1 << RGB_GREEN) | (1 << RGB_BLUE))


int main(){
    stdio_init_all();

    // Inicializando todos os pinos da máscara
    gpio_init_mask(GPIO_MASK);
    // Definindo como saída
    gpio_set_dir_out_masked(GPIO_MASK);

    while (true) {
        gpio_put(RGB_RED, 1);
        sleep_ms(100);

        gpio_put(RGB_RED, 0);
        sleep_ms(100);
    }
}

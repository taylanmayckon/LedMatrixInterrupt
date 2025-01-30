#include "led_matrix.h"

#define MATRIX_PIN 7

// Declaração das cores dos frames que serão usados na matriz de leds
uint8_t led_r = 200;
uint8_t led_g = 0;
uint8_t led_b = 0;

// Quantidade de pixels
#define NUM_PIXELS 25

////////////////////////////////////// FRAMES UTILIZADOS //////////////////////////////////////
// Declaração dos frames que serão exibidos na matriz de leds
bool frame_0[NUM_PIXELS] = {
    1, 1, 1, 1, 1, // Linha 0
    1, 0, 0, 0, 1, // Linha 1
    1, 0, 0, 0, 1, // Linha 3
    1, 0, 0, 0, 1, // Linha 4
    1, 1, 1, 1, 1, // Linha 5
};

bool frame_1[NUM_PIXELS] = {
    0, 0, 0, 0, 1, // Linha 0
    0, 0, 0, 0, 1, // Linha 1
    0, 0, 0, 0, 1, // Linha 3
    0, 0, 0, 0, 1, // Linha 4
    0, 0, 0, 0, 1, // Linha 5
};

bool frame_2[NUM_PIXELS] = {
    1, 1, 1, 1, 1, // Linha 0
    0, 0, 0, 0, 1, // Linha 1
    1, 1, 1, 1, 1, // Linha 3
    1, 0, 0, 0, 0, // Linha 4
    1, 1, 1, 1, 1, // Linha 5
};

bool frame_3[NUM_PIXELS] = {
    1, 1, 1, 1, 1, // Linha 0
    0, 0, 0, 0, 1, // Linha 1
    1, 1, 1, 1, 1, // Linha 3
    0, 0, 0, 0, 1, // Linha 4
    1, 1, 1, 1, 1, // Linha 5
};

bool frame_4[NUM_PIXELS] = {
    1, 0, 0, 0, 1, // Linha 0
    1, 0, 0, 0, 1, // Linha 1
    1, 1, 1, 1, 1, // Linha 3
    0, 0, 0, 0, 1, // Linha 4
    0, 0, 0, 0, 1, // Linha 5
};

bool frame_5[NUM_PIXELS] = {
    1, 1, 1, 1, 1, // Linha 0
    1, 0, 0, 0, 0, // Linha 1
    1, 1, 1, 1, 1, // Linha 3
    0, 0, 0, 0, 1, // Linha 4
    1, 1, 1, 1, 1, // Linha 5
};

bool frame_6[NUM_PIXELS] = {
    1, 1, 1, 1, 1, // Linha 0
    1, 0, 0, 0, 0, // Linha 1
    1, 1, 1, 1, 1, // Linha 3
    1, 0, 0, 0, 1, // Linha 4
    1, 1, 1, 1, 1, // Linha 5
};

bool frame_7[NUM_PIXELS] = {
    1, 1, 1, 1, 1, // Linha 0
    0, 0, 0, 0, 1, // Linha 1
    0, 0, 0, 0, 1, // Linha 3
    0, 0, 0, 0, 1, // Linha 4
    0, 0, 0, 0, 1, // Linha 5
};

bool frame_8[NUM_PIXELS] = {
    1, 1, 1, 1, 1, // Linha 0
    1, 0, 0, 0, 1, // Linha 1
    1, 1, 1, 1, 1, // Linha 3
    1, 0, 0, 0, 1, // Linha 4
    1, 1, 1, 1, 1, // Linha 5
};

bool frame_9[NUM_PIXELS] = {
    1, 1, 1, 1, 1, // Linha 0
    1, 0, 0, 0, 1, // Linha 1
    1, 1, 1, 1, 1, // Linha 3
    0, 0, 0, 0, 1, // Linha 4
    0, 0, 0, 0, 1, // Linha 5
};
////////////////////////////////////// FRAMES UTILIZADOS //////////////////////////////////////

// Buffer que armazena o frame atual
bool led_buffer[NUM_PIXELS] = {
    1, 1, 1, 1, 1, // Linha 0
    1, 0, 0, 0, 1, // Linha 1
    1, 0, 0, 0, 1, // Linha 3
    1, 0, 0, 0, 1, // Linha 4
    1, 1, 1, 1, 1, // Linha 5
};

static inline void put_pixel(uint32_t pixel_grb){
    pio_sm_put_blocking(pio0, 0, pixel_grb << 8u);
}

// Função que vai transformar valores correspondentes ao padrão RGB em dados binários
uint32_t urgb_u32(double r, double g, double b){
    return ((uint32_t)(r) << 8) | ((uint32_t)(g) << 16) | (uint32_t)(b);
}

// Função que vai imprimir cada pixel na matriz
void set_one_led(uint8_t r, uint8_t g, uint8_t b){
    // Define a cor com base nos parâmetros fornecidos
    uint32_t color = urgb_u32(r, g, b);

    // Define todos os LEDs com a cor especificada
    for (int i = 0; i < NUM_PIXELS; i++){
        if (led_buffer[i]){
            put_pixel(color); // Liga o LED com um no buffer
        }
        else{
            put_pixel(0);  // Desliga os LEDs com zero no buffer
        }
    }
}

// Função que faz as operações necessárias para atualizar o display
void atualiza_numero(uint16_t numero){
    // Pegando o ponteiro para o frame selecionado
    //bool* ponteiro_selecionado = all_frames[numero];
    // Criando a variável para armazenar os valores do frame selecionado
    //bool frame_selecionado;

    // Extraindo cada elemento para a variável criada
    //for (int i = 0; i < 5; i++){
    //    for (int j = 0; j < 5; j++){
    //        frame_selecionado[i][j] = (*ponteiro_selecionado)[i][j];
    //    }
    //}

    // Chamando a função que vai imprimir o número
    set_one_led(led_r, led_g, led_b);
}
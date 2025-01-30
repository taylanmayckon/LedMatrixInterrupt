#include "led_matrix.h"

#define MATRIX_PIN 7

// Declaração das cores dos frames que serão usados na matriz de leds
static const RGB_cod cor_0 = {0.0, 0.0, 0.0};
static const RGB_cod cor_1 = {0.0, 255.0/255.0, 0.0};

////////////////////////////////////// FRAMES UTILIZADOS //////////////////////////////////////
// Declaração dos frames que serão exibidos na matriz de leds
Matrix_frames frame_0 = {
//Cols 0      1      3      4      5
    {cor_1, cor_1, cor_1, cor_1, cor_1}, // Linha 0
    {cor_1, cor_0, cor_0, cor_0, cor_1}, // Linha 1
    {cor_1, cor_0, cor_0, cor_0, cor_1}, // Linha 3
    {cor_1, cor_0, cor_0, cor_0, cor_1}, // Linha 4
    {cor_1, cor_1, cor_1, cor_1, cor_1}, // Linha 5
};

Matrix_frames frame_1 = {
//Cols 0      1      3      4      5
    {cor_0, cor_0, cor_0, cor_0, cor_1}, // Linha 0
    {cor_0, cor_0, cor_0, cor_0, cor_1}, // Linha 1
    {cor_0, cor_0, cor_0, cor_0, cor_1}, // Linha 3
    {cor_0, cor_0, cor_0, cor_0, cor_1}, // Linha 4
    {cor_0, cor_0, cor_0, cor_0, cor_1}, // Linha 5
};

Matrix_frames frame_2 = {
//Cols 0      1      3      4      5
    {cor_1, cor_1, cor_1, cor_1, cor_1}, // Linha 0
    {cor_0, cor_0, cor_0, cor_0, cor_1}, // Linha 1
    {cor_1, cor_1, cor_1, cor_1, cor_1}, // Linha 3
    {cor_1, cor_0, cor_0, cor_0, cor_0}, // Linha 4
    {cor_1, cor_1, cor_1, cor_1, cor_1}, // Linha 5
};

Matrix_frames frame_3 = {
//Cols 0      1      3      4      5
    {cor_1, cor_1, cor_1, cor_1, cor_1}, // Linha 0
    {cor_0, cor_0, cor_0, cor_0, cor_1}, // Linha 1
    {cor_1, cor_1, cor_1, cor_1, cor_1}, // Linha 3
    {cor_0, cor_0, cor_0, cor_0, cor_1}, // Linha 4
    {cor_1, cor_1, cor_1, cor_1, cor_1}, // Linha 5
};

Matrix_frames frame_4 = {
//Cols 0      1      3      4      5
    {cor_1, cor_0, cor_0, cor_0, cor_1}, // Linha 0
    {cor_1, cor_0, cor_0, cor_0, cor_1}, // Linha 1
    {cor_1, cor_1, cor_1, cor_1, cor_1}, // Linha 3
    {cor_0, cor_0, cor_0, cor_0, cor_1}, // Linha 4
    {cor_0, cor_0, cor_0, cor_0, cor_1}, // Linha 5
};

Matrix_frames frame_5 = {
//Cols 0      1      3      4      5
    {cor_1, cor_1, cor_1, cor_1, cor_1}, // Linha 0
    {cor_1, cor_0, cor_0, cor_0, cor_0}, // Linha 1
    {cor_1, cor_1, cor_1, cor_1, cor_1}, // Linha 3
    {cor_0, cor_0, cor_0, cor_0, cor_1}, // Linha 4
    {cor_1, cor_1, cor_1, cor_1, cor_1}, // Linha 5
};

Matrix_frames frame_6 = {
//Cols 0      1      3      4      5
    {cor_1, cor_1, cor_1, cor_1, cor_1}, // Linha 0
    {cor_1, cor_0, cor_0, cor_0, cor_0}, // Linha 1
    {cor_1, cor_1, cor_1, cor_1, cor_1}, // Linha 3
    {cor_1, cor_0, cor_0, cor_0, cor_1}, // Linha 4
    {cor_1, cor_1, cor_1, cor_1, cor_1}, // Linha 5
};

Matrix_frames frame_7 = {
//Cols 0      1      3      4      5
    {cor_1, cor_1, cor_1, cor_1, cor_1}, // Linha 0
    {cor_0, cor_0, cor_0, cor_0, cor_1}, // Linha 1
    {cor_0, cor_0, cor_0, cor_0, cor_1}, // Linha 3
    {cor_0, cor_0, cor_0, cor_0, cor_1}, // Linha 4
    {cor_0, cor_0, cor_0, cor_0, cor_1}, // Linha 5
};

Matrix_frames frame_8 = {
//Cols 0      1      3      4      5
    {cor_1, cor_1, cor_1, cor_1, cor_1}, // Linha 0
    {cor_1, cor_0, cor_0, cor_0, cor_1}, // Linha 1
    {cor_1, cor_1, cor_1, cor_1, cor_1}, // Linha 3
    {cor_1, cor_0, cor_0, cor_0, cor_1}, // Linha 4
    {cor_1, cor_1, cor_1, cor_1, cor_1}, // Linha 5
};

Matrix_frames frame_9 = {
//Cols 0      1      3      4      5
    {cor_1, cor_1, cor_1, cor_1, cor_1}, // Linha 0
    {cor_1, cor_0, cor_0, cor_0, cor_1}, // Linha 1
    {cor_1, cor_1, cor_1, cor_1, cor_1}, // Linha 3
    {cor_0, cor_0, cor_0, cor_0, cor_1}, // Linha 4
    {cor_0, cor_0, cor_0, cor_0, cor_1}, // Linha 5
};
////////////////////////////////////// FRAMES UTILIZADOS //////////////////////////////////////

// Vetor de ponteiros para os frames utilizados (no caso armazena os endereços dos frames declarados anteriormente)
Frames_compiled all_frames = {
    &frame_0,
    &frame_1,
    &frame_2,
    &frame_3,
    &frame_4,
    &frame_5,
    &frame_6,
    &frame_7,
    &frame_8,
    &frame_9,
};


// Função que vai transformar valores normalizados (0-1) em binários correspondentes ao padrão RGB
uint32_t gera_binario_rgb(double red, double green, double blue){
    unsigned char RED, GREEN, BLUE;
    RED = red * 255.0;
    GREEN = green * 255.0;
    BLUE = blue * 255.0;
    return (GREEN << 24) | (RED << 16) | (BLUE << 8);
}

// Função que vai imprimir o desenho do frame em questão
void imprime_numero(Matrix_frames frame, PIO pio, uint sm){
    for(int contador_linha = 4; contador_linha >= 0; contador_linha--){
        if(contador_linha % 2){
            for(int contador_coluna; contador_coluna < 5; contador_coluna ++){
                uint32_t valor_cor_binario = gera_binario_rgb(
                    frame[contador_linha][contador_coluna].red,
                    frame[contador_linha][contador_coluna].green,
                    frame[contador_linha][contador_coluna].blue
                );

                pio_sm_put_blocking(pio, sm, valor_cor_binario);
            }
        }
        else {
            for(int contador_coluna = 4; contador_coluna >= 0; contador_coluna --){
                uint32_t valor_cor_binario = gera_binario_rgb(
                    frame[contador_linha][contador_coluna].red,
                    frame[contador_linha][contador_coluna].green,
                    frame[contador_linha][contador_coluna].blue
                );

                pio_sm_put_blocking(pio, sm, valor_cor_binario);
            }
        }
    }
}

// Função que faz as operações necessárias para atualizar o display
void atualiza_numero(uint16_t numero, PIO pio, uint sm){
    // Pegando o ponteiro para o frame selecionado
    Matrix_frames* ponteiro_selecionado = all_frames[numero];
    // Criando a variável para armazenar os valores do frame selecionado
    Matrix_frames frame_selecionado;

    // Extraindo cada elemento para a variável criada
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            frame_selecionado[i][j] = (*ponteiro_selecionado)[i][j];
        }
    }

    // Chamando a função que vai imprimir o número
    imprime_numero(frame_selecionado, pio, sm);
}
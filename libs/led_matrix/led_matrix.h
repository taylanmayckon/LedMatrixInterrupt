#ifndef LED_MATRIX_H
#define LED_MATRIX_H

// Criando estrutura struct para controlar a cor dos LEDS
typedef struct {
    double red;
    double green;
    double blue;
}RGB_defs;

// Variável que vai armazenar cores individualmente
typedef RGB_defs RGB_cod;

// Vetor que vai armazenar as cores num formato 5x5 (para facilitar a interpretação da matriz de leds)
typedef RGB_defs Matrix_frames[5][5];

// Vetor de ponteiros que armazena 10 ponteiros para o tipo Matrix_frames
typedef Matrix_frames* Frames_compiled[10];

#endif
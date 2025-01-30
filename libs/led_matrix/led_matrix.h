#ifndef LED_MATRIX_H
#define LED_MATRIX_H

// Criando estrutura struct para controlar a cor dos LEDS
typedef struct {
    double red;
    double green;
    double blue;
}RGB_defs;

typedef RGB_defs RGB_cod;
typedef RGB_defs Matrix_frames[5][5];
typedef Matrix_frames* Frames_compiled[10];

#endif
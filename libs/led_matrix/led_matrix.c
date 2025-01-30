#include "led_matrix.h"

#define MATRIX_PIN 7

// Declaração das cores dos frames que serão usados na matriz de leds
static const RGB_cod cor_0 = {0.0, 0.0, 0.0};
static const RGB_cod cor_1 = {0.0, 100.0/255.0, 0.0};

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
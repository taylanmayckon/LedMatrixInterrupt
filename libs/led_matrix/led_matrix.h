#ifndef LED_MATRIX_H
#define LED_MATRIX_H

#include "hardware/clocks.h"
#include "hardware/timer.h"
#include "ws2812.pio.h"

// Declaração das funções utilizadas na lib led_matrix
static inline void put_pixel(uint32_t pixel_grb);

uint32_t urgb_u32(double r, double g, double b);

void set_one_led(uint8_t r, uint8_t g, uint8_t b);

void atualiza_numero(uint16_t numero);

#endif
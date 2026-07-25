#ifndef SENSOR_MATH_H
#define SENSOR_MATH_H

#include <stdint.h>

uint16_t clamp_u16(uint16_t value,
                   uint16_t low,
                   uint16_t high);

uint16_t average_samples(uint16_t values[],
                         int count);

int count_above(uint16_t values[],
                int count,
                uint16_t threshold);

#endif

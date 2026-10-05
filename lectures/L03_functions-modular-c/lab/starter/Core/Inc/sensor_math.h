/* sensor_math.h - functions for the sensor values */

#include <stdint.h>

/* Returns low if value is below low, high if value is above high,
   and value itself otherwise. */
uint16_t clamp_u16(uint16_t value, uint16_t low, uint16_t high);

/* TODO (Checkpoint B): declare average_samples here. */

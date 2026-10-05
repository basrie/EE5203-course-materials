#include "sensor_math.h"

uint16_t clamp_u16(uint16_t value,
                   uint16_t low,
                   uint16_t high)
{
    /* TODO (Checkpoint B): return low if value < low,
       high if value > high, otherwise value. */
    (void)low;
    (void)high;
    return value;
}

/* TODO (Checkpoint B): define average_samples here.
   Return 0U when count is 0. Otherwise add every value into a
   uint32_t sum and divide once at the end. Every loop uses i < count. */

#include "sensor_math.h"

uint16_t clamp_u16(uint16_t value,
                   uint16_t low,
                   uint16_t high)
{
    /* TODO: return low, high, or the original value. */
    (void)low;
    (void)high;
    return value;
}

uint16_t average_samples(uint16_t values[],
                         int count)
{
    /* TODO: handle count == 0, accumulate safely, and return the average. */
    (void)values;
    (void)count;
    return 0U;
}

int count_above(uint16_t values[],
                int count,
                uint16_t threshold)
{
    /* TODO: count elements strictly greater than threshold. */
    (void)values;
    (void)count;
    (void)threshold;
    return 0;
}

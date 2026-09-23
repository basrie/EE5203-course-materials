#include "status_text.h"

bool make_status(char destination[],
                 int capacity,
                 uint16_t average)
{
    /* TODO: write "LOW", "OK", or "HIGH", then '\0'. Check capacity first. */
    (void)average;

    if (capacity > 0) {
        destination[0] = '\0';
    }

    return false;
}

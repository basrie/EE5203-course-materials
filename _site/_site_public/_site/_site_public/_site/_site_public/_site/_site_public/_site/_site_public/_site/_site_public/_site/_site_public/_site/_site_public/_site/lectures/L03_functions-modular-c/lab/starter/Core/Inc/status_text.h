#ifndef STATUS_TEXT_H
#define STATUS_TEXT_H

#include <stdbool.h>
#include <stdint.h>

bool make_status(char destination[],
                 int capacity,
                 uint16_t average);

#endif

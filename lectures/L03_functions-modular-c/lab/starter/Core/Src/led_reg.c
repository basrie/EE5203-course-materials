#include "led_reg.h"
#include "main.h"   /* gives RCC and GPIOA */

/* TODO (Checkpoint C): define led_init.
   1. Set bit 0 of RCC->AHB1ENR (GPIOA clock).
   2. Clear bits 11:10 of GPIOA->MODER.
   3. Write the pattern 01 into bits 11:10 (PA5 = output). */

/* TODO (Checkpoint D): define led_on and led_off with GPIOA->BSRR.
   Bit 5 sets PA5. Bit 21 resets PA5. */

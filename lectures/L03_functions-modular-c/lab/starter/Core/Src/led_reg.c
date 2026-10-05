#include "led_reg.h"
#include "main.h"   /* gives RCC, GPIOA and the register names (CMSIS) */

/* TODO (Checkpoint C): define led_init.
     1. Set bit 0 of RCC->AHB1ENR (GPIOA clock). Do not change other bits.
     2. Clear bits 11:10 of GPIOA->MODER, then write the pattern 01
        (PA5 = general-purpose output).

   TODO (Checkpoint D): define led_on and led_off with GPIOA->BSRR.
     Bit 5 sets PA5. Bit 21 (5 + 16) resets PA5.
     Do not use HAL_GPIO_WritePin or HAL_GPIO_TogglePin.              */

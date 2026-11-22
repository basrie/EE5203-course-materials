/* lcd_i2c.h - 16x2 character LCD (HD44780) with a PCF8574 I2C backpack.
 * EE5203 Lab 9 starter file. Uses hi2c1 (I2C1 on PB8 = SCL, PB9 = SDA, 100 kHz).
 */
#ifndef LCD_I2C_H
#define LCD_I2C_H

#include "stm32f4xx_hal.h"

/* The 7-bit address from the bus scan, shifted left by one for HAL.
 * Most backpacks answer at 0x27. If your scan prints found 0x3F, change 0x27 to 0x3F. */
#define LCD_ADDR  (0x27 << 1)

HAL_StatusTypeDef lcd_init(void);               /* once, after MX_I2C1_Init(); takes about 60 ms.
                                                   HAL_ERROR: no ACK, check address and wires */
void lcd_clear(void);                           /* clear the screen; takes about 2.5 ms */
void lcd_set_cursor(uint8_t row, uint8_t col);  /* row 0 or 1, col 0 to 15 */
void lcd_print(const char *text);               /* write text from the cursor on */

#endif /* LCD_I2C_H */

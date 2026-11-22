/* lcd_i2c.c - 16x2 character LCD (HD44780) with a PCF8574 I2C backpack.
 * EE5203 Lab 9 starter file. You do not need to change this file.
 *
 * PCF8574 pin -> LCD pin (the usual backpack wiring):
 *   P0 = RS (0: command, 1: character)   P1 = RW (always 0: write)
 *   P2 = EN (the LCD reads D4-D7 when EN falls)   P3 = backlight (1: on)
 *   P4-P7 = D4-D7 (the LCD runs in 4-bit mode)
 * One byte for the LCD = two halves (high half first), each sent twice:
 * once with EN = 1, once with EN = 0. So 4 bytes on the bus, in one
 * HAL_I2C_Master_Transmit(): address + 4 bytes = 45 clocks = 450 us at 100 kHz.
 */
#include "lcd_i2c.h"

extern I2C_HandleTypeDef hi2c1;          /* made by CubeMX in main.c */

#define LCD_RS  0x01u                    /* P0 */
#define LCD_EN  0x04u                    /* P2 (P1 = RW stays 0) */
#define LCD_BL  0x08u                    /* P3 */

/* Send one half (in bits 7:4) with an EN pulse. Used only in lcd_init(). */
static HAL_StatusTypeDef lcd_half(uint8_t half)
{
    uint8_t b[2];
    b[0] = (uint8_t)((half & 0xF0u) | LCD_BL | LCD_EN);
    b[1] = (uint8_t)((half & 0xF0u) | LCD_BL);
    return HAL_I2C_Master_Transmit(&hi2c1, LCD_ADDR, b, 2, 10);
}

/* Send one full byte: a command (rs = 0) or a character (rs = LCD_RS). */
static void lcd_byte(uint8_t value, uint8_t rs)
{
    uint8_t high = (uint8_t)(value & 0xF0u);
    uint8_t low  = (uint8_t)((value << 4) & 0xF0u);
    uint8_t b[4];
    b[0] = (uint8_t)(high | LCD_BL | rs | LCD_EN);
    b[1] = (uint8_t)(high | LCD_BL | rs);           /* EN falls: LCD reads D7-D4 */
    b[2] = (uint8_t)(low  | LCD_BL | rs | LCD_EN);
    b[3] = (uint8_t)(low  | LCD_BL | rs);           /* EN falls: LCD reads D3-D0 */
    HAL_I2C_Master_Transmit(&hi2c1, LCD_ADDR, b, 4, 10);
    /* Each command except clear needs 37 us; the next transfer comes 450 us later. */
}

/* HD44780 datasheet, Figure 24: initializing by instruction, 4-bit interface. */
HAL_StatusTypeDef lcd_init(void)
{
    HAL_Delay(50);                       /* more than 40 ms after power-on */
    if (lcd_half(0x30) != HAL_OK)        /* function set (8-bit), 1st time */
        return HAL_ERROR;                /* nobody answered at LCD_ADDR */
    HAL_Delay(5);                        /* more than 4.1 ms */
    lcd_half(0x30);                      /* 2nd time */
    HAL_Delay(1);                        /* more than 100 us */
    lcd_half(0x30);                      /* 3rd time */
    HAL_Delay(1);
    lcd_half(0x20);                      /* function set: 4-bit interface from now on */
    HAL_Delay(1);
    lcd_byte(0x28, 0);                   /* function set: 4-bit, 2 lines, 5x8 dots */
    lcd_byte(0x08, 0);                   /* display off */
    lcd_clear();                         /* clear, cursor to row 0, col 0 */
    lcd_byte(0x06, 0);                   /* entry mode: cursor moves right, no shift */
    lcd_byte(0x0C, 0);                   /* display on, cursor off, blink off */
    return HAL_OK;
}

void lcd_clear(void)
{
    lcd_byte(0x01, 0);
    HAL_Delay(2);                        /* clear needs 1.52 ms */
}

void lcd_set_cursor(uint8_t row, uint8_t col)
{
    uint8_t addr = (uint8_t)((row ? 0x40u : 0x00u) + (col & 0x0Fu));   /* row 1 starts at 0x40 */
    lcd_byte((uint8_t)(0x80u | addr), 0);                               /* set DDRAM address */
}

void lcd_print(const char *text)
{
    while (*text != '\0') {
        lcd_byte((uint8_t)*text, LCD_RS);
        text++;
    }
}

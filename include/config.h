#ifndef CONFIG_H
#define CONFIG_H

#define LCD_ROWS 2
#define LCD_COLS 16

#define BAUDRATE 115200 

enum LCD_PINS
{
    LCD_D7 = 3u,
    LCD_D6,
    LCD_D5,
    LCD_D4,
    LCD_D3,
    LCD_D2,
    LCD_D1,
    LCD_D0,
    LCD_EN,
    LCD_RW,
    LCD_RS,
};


#define KEYPAD_ROWS 4
#define KEYPAD_COLS 4

enum KEYPAD_PINS
{
    KEYPAD_ROW_0 = 14u,
    KEYPAD_ROW_1,
    KEYPAD_ROW_2,
    KEYPAD_ROW_3,
    KEYPAD_COL_0,
    KEYPAD_COL_1,
    KEYPAD_COL_2,
    KEYPAD_COL_3,
};

#define LED_RED 23
#define LED_GREEN 22
#define ACCESS_CODE "1234"
#define RESET_TIME 3000
#define CODE_LENGTH 4
#define RESET_KEY '*'
#endif // CONFIG_H

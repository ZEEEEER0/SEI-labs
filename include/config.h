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

#define DebounceTIME 200

#define BUTTON_LED_TASK_OFFSET 0
#define BUTTON_LEDD_TASK_RECURRENCE 50

#define BLINK_LED_TASK_OFFSET 3
#define BLINK_LED_TASK_RECURRENCE 1

#define SET_BLINK_FREQUENCY_TASK_OFFSET 5
#define SET_BLINK_FREQUENCY_TASK_RECURRENCE 100

#define DEFAULT_BLINK_FREQUENCY 1
#define MINIMUM_BLINK_FREQUENCY 1
#define MAXIMUM_BLINK_FREQUENCY 10
#define BUTTON_UP_PIN 3 // Define the pin number for BUTTON_UP_PIN
#define BUTTON_DOWN_PIN 4 // Define the pin number for BUTTON_DOWN_PIN
#define BUTTON_PIN 5 // Define the pin number for BUTTON_PIN
#define LED_GREEN_PIN 7 // Define the pin number for LED_GREEN_PIN
#define LED_BLUE_PIN 6 // Define the pin number for LED_BLUE_PIN
#define MY_TIMER_DEFAULT 1
#define DATA_REFRESH 1

#define LED_RED 23

#define ACCESS_CODE "1234"
#define RESET_TIME 3000
#define CODE_LENGTH 4
#define RESET_KEY '*'
#endif // CONFIG_H

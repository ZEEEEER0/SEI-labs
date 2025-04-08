#ifndef CONFIG_H
#define CONFIG_H

#define BAUD_RATE 115200 

#define RESET_KEY '*'
#define LCD_ROWS 2
#define LCD_COLS 16

#define KEYPAD_ROWS 4
#define KEYPAD_COLS 4

#define LED_RED_PIN 23
#define LED_GREEN_PIN 25

#define ACCESS_CODE "656584"
#define CODE_LENGTH strlen(ACCESS_CODE)
#define RESET_TIME 3000

enum LCD_PINS
{
    LCD_RS = 12u,
    LCD_RW = 11u,
    LCD_EN = 10u,
    LCD_D0 = 9u,
    LCD_D1 = 8u,
    LCD_D2 = 7u,
    LCD_D3 = 6u,
    LCD_D4 = 5u,
    LCD_D5 = 4u,
    LCD_D6 = 3u,
    LCD_D7 = 2u
};

enum KEYPAD_PINS
{
    KEYPAD_ROW_0 = 14u,
    KEYPAD_ROW_1,
    KEYPAD_ROW_2,
    KEYPAD_ROW_3,
    KEYPAD_COL_0,
    KEYPAD_COL_1,
    KEYPAD_COL_2,
    KEYPAD_COL_3
};





#define RESISTOR_TASK_PRIORITY 1
#define PRINT_TASK_PRIORITY 2
#define PLOTTER_TASK_PRIORITY 1
#define RESISTOR_TASK_REC   20 // Intervalul de timp pentru Task 1 (100 ms)
#define PRINT_TASK_REC      500 // Intervalul de timp pentru Task 2 (100 ms)
#define PLOTTER_TASK_REC    25 // Intervalul de timp pentru Task 3 (100 ms)

#define SENSOR_PIN A0
#define SENSOR_NAME (char*) "Resistor"
#define SENSOR_MAX_VALUE 10000
#define SENSOR_RESISTANCE_ID 0

#define ADC_RESOLUTION 10
#define ADC_MAX_VALUE ((1<<ADC_RESOLUTION)-1)
#define ADC_REF_VOLTAGE 5.0
#define ADC_VOLTAGE_STEP   (ADC_REF_VOLTAGE / ADC_RESOLUTION)

#define WINDOW_SIZE    7

#define PLOTTER_TASK_ACTIVE 1
#define PRINT_TASK_ACTIVE 0


#endif // CONFIG_H
#ifndef CONFIG_H
#define CONFIG_H

#define BAUD_RATE 115200 

// Lightbulb settings
#define LIGHTBULB_TASK_STACK_SIZE 256
#define LIGHTBULB_TASK_PRIORITY 1
#define LIGHTBULB_TASK_RECURRENCE 100
#define LIGHTBULB_TASK_NAME "LightbulbTask"
#define LIGHTBULB_PIN 3
#define LIGHTBULB_ID 0u
#define LIGHTBULB_NAME "Lightbulb"

// Relay settings
#define RELAY_PIN 2
#define RELAY_ID 0u
#define RELAY_NAME "Relay"
#define RELAY_TASK_STACK_SIZE 256
#define RELAY_TASK_PRIORITY 1

// Potentiometer settings
#define POT_PIN A0

// Hysteresis settings
#define HYSTERESIS_VALUE 50

// LCD settings
#define LCD_I2C_ADDRESS 0x27
#define LCD_COLUMNS 16
#define LCD_ROWS 2

// Motor control (L298N) settings
#define MOTOR_EN_PIN 9
#define MOTOR_IN1_PIN 7
#define MOTOR_IN2_PIN 8

// Button settings
#define BUTTON_INC_PIN 30  // Pin pentru butonul de incrementare
#define BUTTON_DEC_PIN 31  // Pin pentru butonul de decrementare
#define BUTTON_RESET_PIN 32 // Pin pentru butonul de resetare

// Set point adjustment limits
#define SET_POINT_MIN 0
#define SET_POINT_MAX 1023

// Additional pins (if needed for other peripherals)
#define BUZZER_PIN 4
#define LED_PIN 13

#endif // CONFIG_H
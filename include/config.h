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

// Potentiometer settings
#define POT_PIN A0

// LCD settings
#define LCD_I2C_ADDRESS 0x27
#define LCD_COLUMNS 16
#define LCD_ROWS 2

// Motor control (L298N) settings
#define MOTOR_EN_PIN 9
#define MOTOR_IN1_PIN 7
#define MOTOR_IN2_PIN 8

// Set point adjustment limits
#define SET_POINT_MIN 0
#define SET_POINT_MAX 1023

// Additional pins
#define BUZZER_PIN 4
#define LED_PIN 13

// PID tuning parameters
#define PID_KP 10.0
#define PID_KI 0.5
#define PID_KD 0.1

// Humidity control settings
#define HUMIDITY_SETPOINT_DEFAULT 50.0 // Default humidity set point (%)
#define DHTPIN 2 // Pinul conectat la DHT
#define DHTTYPE DHT11 // Tipul senzorului DHT

// Serial Plotter settings
#define SERIAL_PLOTTER_BAUD_RATE 115200

// Conectare pini Arduino Mega2560

// DHT22 (umiditate/temperatură)
// VCC  -> 5V
// GND  -> GND
// DATA -> Pin 2 (DHTPIN)

// Potențiometru (pentru setpoint PID)
// VCC  -> 5V
// GND  -> GND
// SIG  -> A0 (POT_PIN)

// L298N (control motor DC)
// ENA  -> Pin 9 (MOTOR_EN_PIN)  [PWM]
// IN1  -> Pin 7 (MOTOR_IN1_PIN)
// IN2  -> Pin 8 (MOTOR_IN2_PIN)
// GND  -> GND
// VCC  -> 5V sau sursă externă pentru motor



#endif // CONFIG_H
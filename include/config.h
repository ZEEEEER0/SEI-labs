#ifndef CONFIG_H
#define CONFIG_H

#define BAUD_RATE 115200 

// Potentiometer settings
#define POT_PIN A0

// OLED settings
#define OLED_WIDTH 128
#define OLED_HEIGHT 32

// Motor control (L298N) settings
#define MOTOR_EN_PIN 9
#define MOTOR_IN1_PIN 7
#define MOTOR_IN2_PIN 8

// Set point adjustment limits
#define SET_POINT_MIN 0
#define SET_POINT_MAX 1023

// Additional pins
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

// Define OLED display width and height if not defined in config.h
#define OLED_WIDTH 128
#define OLED_HEIGHT 64

#endif // CONFIG_H
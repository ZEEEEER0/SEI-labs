#include <Arduino.h>
#include <L298N.h>
#include <config.h>

// Motor pins
const uint8_t IN1 = MOTOR_IN1_PIN;
const uint8_t IN2 = MOTOR_IN2_PIN;
const uint8_t EN = MOTOR_EN_PIN;

// Motor instance
L298N motor(EN, IN1, IN2);

void motor_init(void) {
    pinMode(MOTOR_IN1_PIN, OUTPUT);
    pinMode(MOTOR_IN2_PIN, OUTPUT);
    pinMode(MOTOR_EN_PIN, OUTPUT);
    analogWrite(MOTOR_EN_PIN, 0); // Motor oprit la start
}

#include <Arduino.h>
#include <L298N.h>
#include <config.h>

// Motor pins
const uint8_t IN1 = 7;
const uint8_t IN2 = 8;
const uint8_t EN = 9;

// Motor instance
L298N motor(EN, IN1, IN2);

void motor_init(void) {
    motor.setSpeed(128); // 50% power
}

void motor_control_callback(uint8_t state) {
    if (state == 1) {
        motor.forward();
    } else {
        motor.backward();
    }
}

#ifndef CONFIG_H
#define CONFIG_H

#define BAUD_RATE      115200

#define LED_PIN        13
#define BUTTON_PIN     2

#define DEBOUNCE_DELAY 50      // ms

#define TIMEOUT_OFF    0       // ms
#define TIMEOUT_ON     5000    // ms
#define TIMEOUT_HALF   5000    // ms
#define TIMEOUT_BLINK  0       // ms

#define BLINK_INTERVAL 500     // ms
#define HALF_PWM       128     // 50% duty cycle for analogWrite
#define HALF_TOGGLE    10      // ms for software 50% if no PWM

#endif // CONFIG_H
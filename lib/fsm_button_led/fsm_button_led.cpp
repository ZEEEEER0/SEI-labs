#include <Arduino.h>
#include "fsm_button_led.h"
#include <lcd_display.h>
#include <config.h>

// FSM state
fsm_led_state_t current_state = FSM_LED_OFF;
static uint8_t btn_pin = 0;
static uint8_t led_pin = 0;

// Debounce
static uint8_t last_btn_state = HIGH;
static uint8_t stable_btn_state = HIGH;
static unsigned long last_debounce_time = 0;

// BLINK
static unsigned long last_blink_time = 0;
static bool blink_led_on = false;

// HALF (PWM)
static bool led_pwm_supported = false;

// Timeout
static const unsigned long state_timeouts[] = {
    TIMEOUT_OFF, TIMEOUT_ON, TIMEOUT_HALF, TIMEOUT_BLINK
};
static unsigned long state_entry_time = 0;

static bool is_pwm_pin(uint8_t pin) {
    // Mega2560: 2-13, 44-46 are PWM
    return (pin >= 2 && pin <= 13) || (pin >= 44 && pin <= 46);
}

static void enter_state(fsm_led_state_t new_state) {
    current_state = new_state;
    state_entry_time = millis();
    if (current_state == FSM_LED_BLINK) {
        last_blink_time = millis();
        blink_led_on = false;
    }
}

void fsm_init(uint8_t button_pin, uint8_t led_pin_) {
    btn_pin = button_pin;
    led_pin = led_pin_;
    pinMode(btn_pin, INPUT_PULLUP);
    pinMode(led_pin, OUTPUT);
    digitalWrite(led_pin, LOW);
    led_pwm_supported = is_pwm_pin(led_pin);
    last_btn_state = digitalRead(btn_pin);
    stable_btn_state = last_btn_state;
    last_debounce_time = millis();
    last_blink_time = millis();
    blink_led_on = false;
    enter_state(FSM_LED_OFF);
}

void fsm_update(void) {
    // Debounce button
    uint8_t reading = digitalRead(btn_pin);
    if (reading != last_btn_state) {
        last_debounce_time = millis();
    }
    bool button_pressed = false;
    if ((millis() - last_debounce_time) > DEBOUNCE_DELAY) {
        if (reading != stable_btn_state) {
            stable_btn_state = reading;
            if (stable_btn_state == LOW) { // Button pressed
                button_pressed = true;
            }
        }
    }
    last_btn_state = reading;

    // Timeout logic
    unsigned long timeout = state_timeouts[current_state];
    bool timeout_expired = (timeout > 0) && (millis() - state_entry_time >= timeout);

    // Tranziție la următoarea stare dacă timeout sau buton
    if (button_pressed || timeout_expired) {
        fsm_led_state_t next_state = (fsm_led_state_t)((current_state + 1) % 4);
        enter_state(next_state);
    }

    // Output logic
    switch (current_state) {
        case FSM_LED_OFF:
            digitalWrite(led_pin, LOW);
            break;
        case FSM_LED_ON:
            digitalWrite(led_pin, HIGH);
            break;
        case FSM_LED_HALF:
            if (led_pwm_supported) {
                analogWrite(led_pin, HALF_PWM); // 50% duty cycle
            } else {
                static unsigned long last_toggle = 0;
                static bool half_on = false;
                if (millis() - last_toggle > HALF_TOGGLE) {
                    half_on = !half_on;
                    digitalWrite(led_pin, half_on ? HIGH : LOW);
                    last_toggle = millis();
                }
            }
            break;
        case FSM_LED_BLINK:
            if (millis() - last_blink_time > BLINK_INTERVAL) {
                blink_led_on = !blink_led_on;
                digitalWrite(led_pin, blink_led_on ? HIGH : LOW);
                last_blink_time = millis();
            }
            break;
    }
}

void fsm_report(void) {
    switch (current_state) {
        case FSM_LED_OFF:
            lcd_show_state("LED: OFF");
            break;
        case FSM_LED_ON:
            lcd_show_state("LED: ON");
            break;
        case FSM_LED_HALF:
            lcd_show_state("LED: HALF");
            break;
        case FSM_LED_BLINK:
            lcd_show_state("LED: BLINK");
            break;
    }
}

fsm_led_state_t fsm_get_state(void) {
    return current_state;
}



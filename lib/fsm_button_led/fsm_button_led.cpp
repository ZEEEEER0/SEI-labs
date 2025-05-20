#include <Arduino.h>
#include "fsm_button_led.h"

static uint8_t btn_pin;
static uint8_t led_pin;
static fsm_led_state_t state = FSM_LED_OFF;

void fsm_init(uint8_t button_pin, uint8_t led_pin_) {
    btn_pin = button_pin;
    led_pin = led_pin_;
    pinMode(btn_pin, INPUT_PULLUP);
    pinMode(led_pin, OUTPUT);
    digitalWrite(led_pin, LOW);
    state = FSM_LED_OFF;
}

void fsm_update(void) {
    static uint8_t lastStableBtn = HIGH;
    static uint8_t lastReadBtn = HIGH;
    static unsigned long lastDebounceTime = 0;
    const unsigned long debounceDelay = 50;

    uint8_t reading = digitalRead(btn_pin);

    if (reading != lastReadBtn) {
        lastDebounceTime = millis();
    }
    lastReadBtn = reading;

    if ((millis() - lastDebounceTime) > debounceDelay) {
        if (reading != lastStableBtn) {
            lastStableBtn = reading;
            if (lastStableBtn == LOW) {
                // Button pressed (falling edge)
                state = (state == FSM_LED_OFF) ? FSM_LED_ON : FSM_LED_OFF;
                digitalWrite(led_pin, (state == FSM_LED_ON) ? HIGH : LOW);
            }
        }
    }
}

fsm_led_state_t fsm_get_state(void) {
    return state;
}

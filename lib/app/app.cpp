#include <Arduino.h>
#include <config.h>
#include <motor_control.h>
#include <hysteresis.h>
#include <lcd_display.h>
#include <sensor.h>

// Variabile globale
static uint16_t setPoint = 512; // Valoarea implicită
static uint16_t currentPosition = 0;
static hysteresis_t hysteresis; // Instanță de hysteresis

void buttons_init() {
    pinMode(BUTTON_INC_PIN, INPUT_PULLUP);
    pinMode(BUTTON_DEC_PIN, INPUT_PULLUP);
    pinMode(BUTTON_RESET_PIN, INPUT_PULLUP);
}

void buttons_process_input(uint16_t *setPoint, uint16_t min, uint16_t max) {
    if (digitalRead(BUTTON_INC_PIN) == LOW) {
        *setPoint = (*setPoint < max) ? (*setPoint + 1) : max;
        delay(200); // Debounce delay
    }
    if (digitalRead(BUTTON_DEC_PIN) == LOW) {
        *setPoint = (*setPoint > min) ? (*setPoint - 1) : min;
        delay(200); // Debounce delay
    }
    if (digitalRead(BUTTON_RESET_PIN) == LOW) {
        *setPoint = min; // Reset la valoarea minimă
        delay(200); // Debounce delay
    }
}

void app_setup() {
    Serial.begin(BAUD_RATE);
    motor_init();
    lcd_init();
    hysteresis_init(&hysteresis, currentPosition, setPoint, HYSTERESIS_VALUE, motor_control_callback);
    buttons_init(); // Inițializează butoanele
}

void app_loop() {
    currentPosition = sensor_read_position();
    hysteresis_update(&hysteresis, currentPosition);
    lcd_update_display(setPoint, currentPosition);
    buttons_process_input(&setPoint, SET_POINT_MIN, SET_POINT_MAX); // Procesează intrările de la butoane
    delay(100);
}

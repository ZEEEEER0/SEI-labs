#include "fsm_semafor.h"
#include <Arduino.h>
#include <config.h>

const fsm_state_t fsm_table[8] = {
    // e_red, e_yellow, e_green, n_red, n_yellow, n_green, timeout, lcd, serial
    {0, 0, 1, 1, 0, 0, 10000,  "E:VERDE N:ROSU",  "S1: E:VERDE N:ROSU"},
    {0, 0, 1, 1, 0, 0, 3000,  "E:VERDE N:ROSU",  "S2: E:VERDE N:ROSU"},
    {0, 1, 0, 1, 0, 0, 2000,  "E:GALBEN N:ROSU", "S3: E:GALBEN N:ROSU"},
    {1, 0, 0, 1, 0, 0, 1000,  "E:ROSU N:ROSU",   "S4: E:ROSU N:ROSU"},
    {1, 0, 0, 0, 0, 1, 30000, "E:ROSU N:VERDE",  "S5: E:ROSU N:VERDE"},
    {1, 0, 0, 0, 0, 1, 3000,  "E:ROSU N:VERDE",  "S6: E:ROSU N:VERDE"},
    {1, 0, 0, 0, 1, 0, 2000,  "E:ROSU N:GALBEN", "S7: E:ROSU N:GALBEN"},
    {1, 1, 0, 1, 0, 0, 1000,  "E:GALBEN N:ROSU", "S8: E:GALBEN N:ROSU"}
};

static uint8_t current_state = 0;
unsigned long next_change_time = 0; // elimină static pentru a fi vizibil extern

static void set_leds(const fsm_state_t* s) {
    digitalWrite(LED_E_RED,    s->e_red    ? HIGH : LOW);
    digitalWrite(LED_E_YELLOW, s->e_yellow ? HIGH : LOW);
    digitalWrite(LED_E_GREEN,  s->e_green  ? HIGH : LOW);
    digitalWrite(LED_N_RED,    s->n_red    ? HIGH : LOW);
    digitalWrite(LED_N_YELLOW, s->n_yellow ? HIGH : LOW);
    digitalWrite(LED_N_GREEN,  s->n_green  ? HIGH : LOW);
}

void fsm_semafor_init(uint8_t /*button_pin*/) {
    pinMode(LED_E_RED, OUTPUT);
    pinMode(LED_E_YELLOW, OUTPUT);
    pinMode(LED_E_GREEN, OUTPUT);
    pinMode(LED_N_RED, OUTPUT);
    pinMode(LED_N_YELLOW, OUTPUT);
    pinMode(LED_N_GREEN, OUTPUT);
    current_state = 0;
    set_leds(&fsm_table[current_state]);
    next_change_time = millis() + fsm_table[current_state].timeout_ms;
}

void fsm_semafor_update(void) {
    set_leds(&fsm_table[current_state]);
    // DEBUG: vezi timpul curent și timpul de schimbare
    Serial.print("millis: "); Serial.print(millis());
    Serial.print(" next_change_time: "); Serial.print(next_change_time);
    Serial.print(" current_state: "); Serial.println(current_state);

    if ((long)(millis() - next_change_time) >= 0) {
        Serial.println("Trec la urmatoarea stare!");
        current_state = (current_state + 1) % 8;
        set_leds(&fsm_table[current_state]);
        next_change_time = millis() + fsm_table[current_state].timeout_ms;
        Serial.print("Nou next_change_time: "); Serial.println(next_change_time);
    }
}

semafor_state_t fsm_semafor_get_state(void) {
    return (semafor_state_t)current_state;
}

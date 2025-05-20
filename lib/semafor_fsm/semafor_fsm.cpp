#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <semphr.h>
#include <config.h>
#include <lcd_display.h>
#include "semafor_fsm.h"

// Timpi semafor (milisecunde)
#define GREEN_TIME   5000
#define YELLOW_TIME  2000
#define RED_TIME     5000

static SemaphoreHandle_t xButtonSemaphore;
static volatile bool cerere_nord = false;

void set_semafor_E(uint8_t r, uint8_t y, uint8_t g) {
    digitalWrite(LED_E_RED, r);
    digitalWrite(LED_E_YELLOW, y);
    digitalWrite(LED_E_GREEN, g);
}
void set_semafor_N(uint8_t r, uint8_t y, uint8_t g) {
    digitalWrite(LED_N_RED, r);
    digitalWrite(LED_N_YELLOW, y);
    digitalWrite(LED_N_GREEN, g);
}

// Debounce software pentru ISR
void button_isr() {
    static unsigned long last_interrupt_time = 0;
    unsigned long interrupt_time = millis();
    if (interrupt_time - last_interrupt_time > 200) { // 200ms debounce
        cerere_nord = true;
        BaseType_t xHigherPriorityTaskWoken = pdFALSE;
        xSemaphoreGiveFromISR(xButtonSemaphore, &xHigherPriorityTaskWoken);
        last_interrupt_time = interrupt_time;
    }
}

void semafor_fsm_init(void) {
    pinMode(LED_E_RED, OUTPUT);
    pinMode(LED_E_YELLOW, OUTPUT);
    pinMode(LED_E_GREEN, OUTPUT);
    pinMode(LED_N_RED, OUTPUT);
    pinMode(LED_N_YELLOW, OUTPUT);
    pinMode(LED_N_GREEN, OUTPUT);
    pinMode(BUTTON_NORTH, INPUT_PULLUP);

    xButtonSemaphore = xSemaphoreCreateBinary();
    attachInterrupt(digitalPinToInterrupt(BUTTON_NORTH), button_isr, FALLING);
}

void semafor_fsm_task(void *pvParameters) {
    semafor_state_t state = SEMAFOR_E_GREEN;

    set_semafor_E(LOW, LOW, HIGH); // Est verde
    set_semafor_N(HIGH, LOW, LOW); // Nord roșu

    vTaskDelay(100 / portTICK_PERIOD_MS);

    for (;;) {
        const char* lcd_state = "";
        switch (state) {
            case SEMAFOR_E_GREEN:
                set_semafor_E(LOW, LOW, HIGH);
                set_semafor_N(HIGH, LOW, LOW);
                lcd_state = "E:VERDE N:ROSU";
                if (xSemaphoreTake(xButtonSemaphore, GREEN_TIME / portTICK_PERIOD_MS) == pdTRUE) {
                    // cerere_nord deja setat în ISR
                }
                if (cerere_nord) state = SEMAFOR_E_YELLOW;
                break;
            case SEMAFOR_E_YELLOW:
                set_semafor_E(LOW, HIGH, LOW);
                set_semafor_N(HIGH, LOW, LOW);
                lcd_state = "E:GALBEN N:ROSU";
                vTaskDelay(YELLOW_TIME / portTICK_PERIOD_MS);
                state = SEMAFOR_E_RED;
                break;
            case SEMAFOR_E_RED:
                set_semafor_E(HIGH, LOW, LOW);
                set_semafor_N(LOW, LOW, HIGH);
                lcd_state = "E:ROSU N:VERDE";
                vTaskDelay(RED_TIME / portTICK_PERIOD_MS);
                cerere_nord = false;
                state = SEMAFOR_E_GREEN;
                break;
        }
        // Afișare stare pe serial și LCD
        Serial.println(lcd_state);
        lcd_show_state(lcd_state);
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}

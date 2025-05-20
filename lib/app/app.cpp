#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <config.h>
#include <fsm_button_led.h>
#include <lcd_display.h>


void app_setup() {
    Serial.begin(BAUD_RATE);
    lcd_init();
    fsm_init(BUTTON_PIN, LED_PIN);
}

void app_loop() {
    fsm_update();
    static fsm_led_state_t last_state = FSM_LED_OFF;
    fsm_led_state_t state = fsm_get_state();
    if (state != last_state) {
        last_state = state;
        switch (state) {
            case FSM_LED_OFF:
                Serial.println("LED OFF");
                lcd_show_state("LED: OFF");
                break;
            case FSM_LED_ON:
                Serial.println("LED ON");
                lcd_show_state("LED: ON");
                break;
            case FSM_LED_HALF:
                Serial.println("LED HALF");
                lcd_show_state("LED: HALF");
                break;
            case FSM_LED_BLINK:
                Serial.println("LED BLINK");
                lcd_show_state("LED: BLINK");
                break;
        }
    }
    delay(10);
}

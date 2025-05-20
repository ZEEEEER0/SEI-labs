#include <Arduino.h>
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
    fsm_led_state_t state = fsm_get_state();

    // Serial reporting
    if (state == FSM_LED_ON) {
        Serial.println("LED ON");
        lcd_show_state("ON");
    } else {
        Serial.println("LED OFF");
        lcd_show_state("OFF");
    }
    delay(100);
}

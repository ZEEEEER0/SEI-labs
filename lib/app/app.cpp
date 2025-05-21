#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <config.h>
#include <fsm_semafor.h>
#include <lcd_display.h>

void semafor_task(void *pvParameters) {
    (void)pvParameters;
    for (;;) {
        fsm_semafor_update();
        vTaskDelay(1 / portTICK_PERIOD_MS); // era 50, acum 1 ms pentru test
    }
}

void report_task(void *pvParameters) {
    (void)pvParameters;
    for (;;) {
        uint8_t state = (uint8_t)fsm_semafor_get_state();
        Serial.println(fsm_table[state].serial_text);

        // Calculează timpul rămas până la următoarea stare
        extern unsigned long next_change_time; // declară extern dacă nu e deja public
        unsigned long now = millis();
        unsigned long ms_left = (next_change_time > now) ? (next_change_time - now) : 0;

        // Construiește text cu LED-urile aprinse
        const fsm_state_t* s = &fsm_table[state];
        char e_led[2], n_led[2];
        if (s->e_green)   strcpy(e_led, "V"); // Verde
        else if (s->e_yellow) strcpy(e_led, "G"); // Galben
        else if (s->e_red)    strcpy(e_led, "R"); // Rosu
        else strcpy(e_led, "-");

        if (s->n_green)   strcpy(n_led, "V");
        else if (s->n_yellow) strcpy(n_led, "G");
        else if (s->n_red)    strcpy(n_led, "R");
        else strcpy(n_led, "-");

        char lcd_buf[32];
        snprintf(lcd_buf, sizeof(lcd_buf), "E:%s N:%s\nTimp: %lus", e_led, n_led, ms_left / 1000);

        lcd_show_state(lcd_buf);

        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}

void app_setup() {
    Serial.begin(BAUD_RATE);
    lcd_init();
    fsm_semafor_init(BUTTON_PIN);
    xTaskCreate(semafor_task, "Semafor", 256, NULL, 2, NULL);
    xTaskCreate(report_task, "Report", 256, NULL, 1, NULL);
}

void app_loop() {
    vTaskDelay(portMAX_DELAY);
}

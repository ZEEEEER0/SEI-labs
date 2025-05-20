#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <semphr.h>
#include <task.h>
#include <config.h>
#include <lcd_display.h>
#include <semafor_fsm.h>

void app_setup() {
    Serial.begin(BAUD_RATE);
    lcd_init();
    semafor_fsm_init();
    xTaskCreate(semafor_fsm_task, "SemaforFSM", 256, NULL, 1, NULL);
    vTaskStartScheduler();
}

void app_loop() {
    // Nu folosi loop, FreeRTOS rulează task-urile
    vTaskDelay(portMAX_DELAY);
}

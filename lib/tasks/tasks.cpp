#include "tasks.h"

SemaphoreHandle_t xButtonSemaphore = NULL;
QueueHandle_t xQueue = NULL;

void systemSetup(void)
{
    if (xButtonSemaphore == NULL)
    {
        xButtonSemaphore = xSemaphoreCreateBinary();
    }

    if (xQueue == NULL)
    {
        xQueue = xQueueCreate(10, sizeof(uint32_t));
    }

    xTaskCreate(buttonLedTask, "ButtonLedTask", STACK_SIZE, NULL, 1, NULL);
    xTaskCreate(sincronTask, "SincronTask", STACK_SIZE, NULL, 1, NULL); // Adăugarea celui de-al doilea task
}

void buttonLedTaskSetup(void)
{
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(LED_GREEN_PIN, OUTPUT);
}

void buttonLedTask(void *arg)
{
    static uint8_t needInit = true;
    static TickType_t buttonDebounceTime = 0;
    static TickType_t taskRecurence = BLINK_LED_TASK_RECURRENCE;

    if (needInit)
    {
        buttonLedTaskSetup();
        taskRecurence = xTaskGetTickCount();
        needInit = false;
    }
    while (true)
    {
        if (digitalRead(BUTTON_PIN) == LOW)
        {
            if (millis() >= buttonDebounceTime)
            {
                xSemaphoreGive(xButtonSemaphore);
                digitalWrite(LED_GREEN_PIN, !digitalRead(LED_GREEN_PIN));
                buttonDebounceTime = xTaskGetTickCount() + pdMS_TO_TICKS(DebounceTIME);
            }
            xTaskDelayUntil(&taskRecurence, pdMS_TO_TICKS(BLINK_LED_TASK_RECURRENCE));
        }
    }
}

void sincronTaskSetup(void)
{
    pinMode(LED_RED_PIN, OUTPUT);
}

void sincronTask(void *pvParameters)
{
    static uint8_t needInit = true;
    static uint8_t N = 1; // Start with 1 blink
    static uint8_t count = 0;
    static TickType_t ledChangeStateTime = 0;
    static TickType_t ledCount = 0;

    if (needInit)
    {
        sincronTaskSetup();
        needInit = false;
    }

    while (true)
    {
        if (ledCount)
        {
            digitalWrite(LED_RED_PIN, !digitalRead(LED_RED_PIN));
            ledCount--;
            vTaskDelay(pdMS_TO_TICKS(SECOND_LED_STATE_CHANGE)); // Delay between blinks
        }

        if (xSemaphoreTake(xButtonSemaphore, pdMS_TO_TICKS(SINCRON_TASK_RECURRENCE)) == pdTRUE)
        {
            N++; // Increment the number of blinks
            ledCount = N * 2; // Each blink consists of two state changes (on and off)
        }
    }
}

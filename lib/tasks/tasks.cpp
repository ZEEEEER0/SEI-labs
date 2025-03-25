#include "tasks.h"

SemaphoreHandle_t xButtonSemaphore;
QueueSetHandle_t xIncrement;
QueueHandle_t xBufferQueue = NULL;  // Coada pentru comunicarea între Task 2 și Task 3
void freeRTOSInit(void)
{
    xTaskCreate(buttonLedTask, "Button Led", STACK_SIZE, NULL, PRIORITY, NULL);
    xTaskCreate(sincronizedTask, "N increment", STACK_SIZE, NULL, PRIORITY, NULL);
    xTaskCreate(asyncTask, "Async Task", STACK_SIZE, NULL, PRIORITY, NULL);  // Adaugă Task 3
}

void buttonLedTaskSetup(void)
{
    if (xButtonSemaphore == NULL)
    {
        xButtonSemaphore = xSemaphoreCreateBinary();
        if (xButtonSemaphore != NULL)
        {
            // xSemaphoreGive(xButtonSemaphore);
        }
    }

    pinMode(ON_OFF_BUTTON, INPUT_PULLUP);
    pinMode(GREEN_LED, OUTPUT);
}

void buttonLedTask(void *pvParameters)
{
    uint8_t needInit = true;
    uint8_t ledState = LOW;
    TickType_t ledOnStateTime = 0;

    TickType_t relativeTime = 0;

    if (needInit)
    {
        buttonLedTaskSetup();
        needInit = false;
    }
	
	while (true)
	{
		if (!digitalRead(ON_OFF_BUTTON))
		{
			if (relativeTime < xTaskGetTickCount())
			{
                ledState = HIGH;
                xSemaphoreGive(xButtonSemaphore);
			}
		  relativeTime = xTaskGetTickCount() + pdMS_TO_TICKS(BUTTON_REFRESH_TIME);
		}

        if (ledState == HIGH)
        {
            ledState = LOW;
            digitalWrite(GREEN_LED, HIGH);
            ledOnStateTime = xTaskGetTickCount() + pdMS_TO_TICKS(GREEN_LED_ON_TIME);
        }

        if (ledOnStateTime < xTaskGetTickCount())
        {
            digitalWrite(GREEN_LED, LOW);
        }

		vTaskDelay(pdMS_TO_TICKS(FIRST_TASK_REC));
	}
}

void sincronizedTaskSetup(void)
{
    pinMode(BLUE_LED, OUTPUT);
    if (xIncrement == NULL)
    {
        xIncrement = xQueueCreate(1, sizeof(uint32_t));
    }
    if (xBufferQueue == NULL)
    {
        xBufferQueue = xQueueCreate(BUFFER_SIZE, sizeof(uint8_t));  // Creează coada
    }
}

void sincronizedTask(void *pvParameters)
{
    uint32_t toggleCount = 0;
    uint8_t needInit = true;
    uint32_t N = 0;
    uint8_t bufferData;  // Variabilă pentru a stoca datele trimise în coadă

    TickType_t ledStateTime = 0;

    if (needInit)
    {
        sincronizedTaskSetup();
        needInit = false;
    }

    while (true)
    {
        if (toggleCount && (ledStateTime < xTaskGetTickCount()))
        {
            if (toggleCount % 2)
            {
                digitalWrite(BLUE_LED, HIGH);
                ledStateTime = xTaskGetTickCount() + pdMS_TO_TICKS(BLUE_LED_ON_TIME);
            }
            else
            {
                digitalWrite(BLUE_LED, LOW);
                ledStateTime = xTaskGetTickCount() + pdMS_TO_TICKS(BLUE_LED_OFF_TIME);
            }
            toggleCount--;
        }

        if (xSemaphoreTake(xButtonSemaphore, pdMS_TO_TICKS(SECOND_TASK_REC)) == pdTRUE)
        {
            digitalWrite(BLUE_LED, !digitalRead(BLUE_LED));
            N++;  // Incrementează variabila N
            toggleCount = N;

            // Trimite datele în coadă (1, 2, 3, ..., N)
            for (uint8_t i = 1; i <= N; i++)
            {
                bufferData = i;
                xQueueSend(xBufferQueue, &bufferData, 0);  // Trimite fiecare byte în coadă
            }
            bufferData = 0;  // Trimite 0 pentru a indica sfârșitul mesajului
            xQueueSend(xBufferQueue, &bufferData, 0);
        }

        // Asigură-te că LED-ul este stins după ce timpul de aprindere a expirat
        if (ledStateTime < xTaskGetTickCount() && digitalRead(BLUE_LED) == HIGH)
        {
            digitalWrite(BLUE_LED, LOW);
        }

        vTaskDelay(pdMS_TO_TICKS(SECOND_TASK_REC));
    }
}

void asyncTask(void *pvParameters)
{
    uint8_t bufferData;  // Variabilă pentru a stoca datele citite din coadă
    uint8_t needInit = true;

    if (needInit)
    {
        Serial.begin(BAUD_RATE);  // Inițializează comunicarea serială
        needInit = false;
    }

    while (true)
    {
        // Citește datele din coadă
        if (xQueueReceive(xBufferQueue, &bufferData, pdMS_TO_TICKS(THIRD_TASK_REC)) == pdTRUE)
        {
            if (bufferData == 0)
            {
                Serial.println();  // Trece pe un rând nou la detectarea unui 0
            }
            else
            {
                Serial.print(bufferData);  // Afișează datele în terminal
                Serial.print(" ");
            }
        }

        vTaskDelay(pdMS_TO_TICKS(THIRD_TASK_REC));  // Așteaptă 200 ms
    }
}

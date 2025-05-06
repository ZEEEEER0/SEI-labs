#include "my_tasks.h"
static lightbulb_t lightbulb; // Global lightbulb object
static relay_t relay; // Global relay object


void systemSetup(void)
    {
        xTaskCreate(
            lightbulbTask,
            "Lightbulb Task",
            LIGHTBULB_TASK_STACK_SIZE,
            NULL,
            LIGHTBULB_TASK_PRIORITY,
            NULL
        );
    }
void system_task(void *pvParameters)
    {
        // Initialize the system
        Serial.begin(BAUD_RATE);
        Serial.println("System initialized");
        // Create the lightbulb task
        systemSetup();
        // Start the FreeRTOS scheduler
        vTaskStartScheduler();
    }
void lightbulbTaskSetup(void *pvParameters)
{

        // Initialize the lightbulb
        lightbulb_init(&lightbulb, LIGHTBULB_ID, LIGHTBULB_NAME, 100, 1, NULL);

        // Create the relay task
        xTaskCreate(
            relayTask,
            "Relay Task",
            RELAY_TASK_STACK_SIZE,
            NULL,
            RELAY_TASK_PRIORITY,
            NULL
        );
        // Start the FreeRTOS scheduler
        vTaskStartScheduler();
}

void lightbulbTask(void *pvParameters)
{
        static uint8_t needInit = true;
        TickType_t lastWakeTime = xTaskGetTickCount();

        if(needInit)
        {
            lightbulbTaskSetup(pvParameters);
            needInit = false;
        }
}

void relayTaskSetup(void *pvParameters)
{
        // Initialize the relay
        relay_init(&relay, RELAY_ID, RELAY_NAME, RELAY_PIN, NULL);
        // Start the FreeRTOS scheduler
        vTaskStartScheduler();
}

inline void functieCapusa(uint8_t state)
{
        if (state == LIGHTBULB_ON)
            {
                relay_on(&relay);
                return;
            }
        if (state == LIGHTBULB_OFF)
            {
                relay_off(&relay);
                return;
            }
}

void interpreterTaskSetup(void)
{
        own_stdio_setup();
        interpreter_init();
}

void vApplicationIdleHook(void)
{
        static uint8_t needInit = true;

        if (needInit)
            {
                interpreterTaskSetup();
                needInit = false;
            }
        interpreter_loop();
    }
#include "my_tasks.h"

// Global objects
static lightbulb_t lightbulb;
static relay_t relay;



// System setup function
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

// System task
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

// Lightbulb task setup
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
}

// Lightbulb task
void lightbulbTask(void *pvParameters)
{
    static uint8_t needInit = true;
    TickType_t lastWakeTime = xTaskGetTickCount();

    if (needInit)
    {
        lightbulbTaskSetup(NULL);
        needInit = false;
    }

    // Task loop (if needed)
    while (1)
    {
        // Perform lightbulb-related operations
        vTaskDelayUntil(&lastWakeTime, pdMS_TO_TICKS(1000)); // Example delay
    }
}

// Relay task setup
void relayTaskSetup(void *pvParameters)
{
    // Initialize the relay
    relay_init(&relay, RELAY_ID, RELAY_NAME, RELAY_PIN, NULL);
}

// Relay task (if needed)
void relayTask(void *pvParameters)
{
    // Task loop (if needed)
    while (1)
    {
        // Perform relay-related operations
        vTaskDelay(pdMS_TO_TICKS(1000)); // Example delay
    }
}

// Inline function for controlling the relay
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

// Interpreter task setup
void interpreterTaskSetup(void)
{
    own_stdio_setup();
    interpreter_init(&lightbulb);
}

// Idle hook function
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
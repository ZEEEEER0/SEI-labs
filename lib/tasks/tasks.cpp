#include "tasks.h"

void systemSetup()
{
    xTaskCreate(resistorTask, "resistorTask", 128, NULL, RESISTOR_TASK_PRIORITY, NULL);
    xTaskCreate(printTask, "printTask", 128, NULL, PRINT_TASK_PRIORITY, NULL);
    xTaskCreate(plotterTask, "plotterTask", 128, NULL, PLOTTER_TASK_PRIORITY, NULL);
    vTaskStartScheduler();
}

void resistorTaskSetup(void)
{
    analogSensorsSetup();
}

void resistorTask(void *pvParameters)
{
    uint8_t needInit = true;
    TickType_t taskRecurence = 0;

    if (needInit)
    {
        resistorTaskSetup();
        taskRecurence = xTaskGetTickCount();
        needInit = false;
    }

    while (true)
    {
        analogSensorsRead();
        xTaskDelayUntil(&taskRecurence, pdMS_TO_TICKS(RESISTOR_TASK_RECURENCE));
    }
}
void printTaskSetup(void)
{
}
void printTask(void *pvParameters)
{
    uint8_t needInit = true;
    TickType_t taskRecurence = 0;

    if (needInit)
    {
        printTaskSetup();
        taskRecurence = xTaskGetTickCount();
        needInit = false;
    }

    while (true)
    {
        xTaskDelayUntil(&taskRecurence, pdMS_TO_TICKS(PRINT_TASK_RECURENCE));
    }
}

void plotterTask(void *pvParameters)
{
    uint8_t needInit = true;
    TickType_t taskRecurence = 0;

    if (needInit)
    {
        plotterTaskSetup();
        taskRecurence = xTaskGetTickCount();
        needInit = false;
    }

    while (true)
    {
        xTaskDelayUntil(&taskRecurence, pdMS_TO_TICKS(PLOTTER_TASK_RECURENCE));
    }
}

void plotterTaskSetup(void)
{
    analogSensorsSetup();
}
#include "my_tasks.h"


void systemSetup(void)
{
    xTaskCreate(resistorTAsk, "resistorTask", 128, NULL, RESISTOR_TASK_PRIORITY, NULL);

#ifdef PRINT_TASK_ACTIVE
    xTaskCreate(printTask, "printTask", 128, NULL, PRINT_TASK_PRIORITY, NULL);
#endif

#ifdef PLOTTER_TASK_ACTIVE
    xTaskCreate(plotterTask, "plotterTask", 128, NULL, PLOTTER_TASK_PRIORITY, NULL);
#endif

    vTaskStartScheduler();
}

void resistorTaskSetup(void)
{
    analogSensorsSetup();
}

void resistorTAsk(void *pvParameters)
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
        xTaskDelayUntil(&taskRecurence, pdMS_TO_TICKS(RESISTOR_TASK_REC));
    }
}

void printTaskSetup(void)
{
    own_stdio_setup();
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
        analogSensorsPrint();
        xTaskDelayUntil(&taskRecurence, pdMS_TO_TICKS(PRINT_TASK_REC));
    }
}

void plotterTaskSetup(void)
{
    own_stdio_setup();
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
        analogSensorsPlot();
        xTaskDelayUntil(&taskRecurence, pdMS_TO_TICKS(PLOTTER_TASK_REC));
    }
}




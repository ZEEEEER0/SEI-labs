#ifndef MY_TASKS_H
#define MY_TASKS_H

#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include "config.h"
#include "my_tasks.h"
#include "own_stdio.h"
#include "analog_sensors.h"


void systemSetup(void);
void resistorTAsk(void *pvParameters);
void resistorTaskSetup(void);

void printTaskSetup(void);
void printTask(void *pvParameters);
void plotterTaskSetup(void);
void plotterTask(void *pvParameters);

#endif // MY_TASKS_H
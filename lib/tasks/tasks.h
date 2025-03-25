#ifndef TASKS_H
#define TASKS_H

#include <Arduino.h>
#include "config.h"
#include "own_stdio.h"
#include "Arduino_FreeRTOS.h"
#include "tasks.h"
#include "resistor.h"
#include "analog_sensors.h"

void systemSetup(void);
void resistorTaskSetup(void);
void resistorTask(void *pvParameters);
void printTaskSetup(void);
void printTask(void *pvParameters);
void plotterTaskSetup(void);
void plotterTask(void *pvParameters);


#endif // TASK_H
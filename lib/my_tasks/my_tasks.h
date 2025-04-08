#ifndef MY_TASKS_H
#define MY_TASKS_H

#include <Arduino.h>
#include <config.h>
#include <own_stdio.h>
#include <Arduino_FreeRTOS.h>
#include <task.h>
#include <interpreter.h>
#include <lightbulb.h>

// Function prototypes
void systemSetup(void);
void lightbulbTaskSetup(void *pvParameters);
void relayTaskSetup(void *pvParameters);
void interpreterTaskSetup(void);
void lightbulbTask(void *pvParameters);
void relayTask(void *pvParameters);


#endif // MY_TASKS_H
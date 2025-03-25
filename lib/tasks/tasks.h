#ifndef TASKS_H
#define TASKS_H

#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <semphr.h>
#include <queue.h>

#include "config.h"

void freeRTOSInit(void);
void buttonLedTaskSetup(void);
void buttonLedTask(void *pvParameters);
void sincronizedTaskSetup(void);
void sincronizedTask(void *pvParameters);
void asyncTask(void *pvParameters);
extern QueueHandle_t xBufferQueue;  // Coada pentru comunicarea între Task 2 și Task 3
void asyncTask(void *pvParameters); // Declarația pentru Task 3
#endif // MY_TASKS_H

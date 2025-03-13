#ifndef TASKS_H
#define TASKS_H

#include <Arduino.h>
#include <config.h>
#include <stdio.h>
#include"Arduino_FreeRTOS.h"
#include"semphr.h"
#include "queue.h"


void buttonLedTaskSetup(void);
void buttonLedTask(void *);
void sincronTaskSetup(void);
void sincronTask(void *pvParameters);
void asincronTaskSetup(void);
void asincronTask(void *pvParameters);
void systemSetup(void);
void systemLoop(void);


#endif // TASK_H
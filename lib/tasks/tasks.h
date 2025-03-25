#ifndef TASKS_H
#define TASKS_H

#include <Arduino.h>
#include <config.h>
#include <stdio.h>
#include <main.h>
#include "own_stdio.h"
#include "timer-api.h"


void buttonLedTaskSetup(void);
void setBlinkFrequencyTaskSetup(void);
void idleTaskSetup(void);

void buttonLedTask(void);
void setBlinkFrequency(void);
void idleTask(void);

#endif // TASK_H
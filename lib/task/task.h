#ifndef TASK_H
#define TASK_H

#include <Arduino.h>
#include <config.h>
#include <stdio.h>
#include <main.h>
#include "own_stdio.h"
#include "timer-api.h"


void buttonLedTaskSetup(void);
void buttonLedTask(void);
void blinkLedTaskSetup(void);
void blinkLedTask(void);
void setBlinkFrequency(void);
void idleTaskSetup(void);
void idleTask(void);

#endif // TASK_H
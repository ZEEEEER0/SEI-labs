#ifndef TASK_H
#define TASK_H

#include <Arduino.h>
#include "config.h"

void buttonLedTaskSetup(void);
void ledIntermittentTaskSetup(void);
void buttonVariableTaskSetup(void);
void buttonLedTask(void);
void ledIntermittentTask(void);
void buttonVariableTask(void);

#endif 
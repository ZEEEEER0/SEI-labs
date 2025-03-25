#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <Arduino.h>
#include "timer-api.h"

void scheduler_setup(void);
void scheduler_idle_task(void);

void led_task(void);
void button_task(void);

#endif // SCHEDULER_H



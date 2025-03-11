#ifndef schedule_h
#define schedule_h

#include <Arduino.h>
#include <config.h>
#include <stdio.h>
#include "task.h"
#include "timer-api.h"


void scheduleSetup(void);
void scheduleLoop(void);

#endif // schedule_h
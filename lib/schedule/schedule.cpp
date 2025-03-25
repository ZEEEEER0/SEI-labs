#ifndef SCHEDULE_H
#define SCHEDULE_H

// Add your includes here
#include "tasks.h"

void scheduleSetup();
void scheduleLoop();
void timer_handler_interrupt(int timer);

#endif // SCHEDULE_H

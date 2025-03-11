#include "schedule.h"

void scheduleSetup(void)
{
    timer_init_ISR_1KHz(TIMER_DEFAULT);
}

void scheduleLoop(void)
{
    static uint32_t buttonLedTaskCounter = BUTTON_LED_TASK_OFFSET;

    if (--buttonLedTaskCounter == 0)
    {
        buttonLedTask();
        buttonLedTaskCounter = BUTTON_LEDD_TASK_RECURRENCE;
    }   
}

void timer_handler_interrupt(int timer)
{
    if (timer == TIMER_DEFAULT)
    {
        scheduleLoop();
    }
}

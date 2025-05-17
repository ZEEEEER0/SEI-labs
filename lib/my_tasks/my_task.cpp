#include "my_task.h"

void buttonLedTaskSetup(void)
{
    pinMode(ON_OFF_BUTTON, INPUT_PULLUP);
    pinMode(GREEN_LED, OUTPUT);
}

void ledIntermittentTaskSetup(void)
{
    pinMode(BLUE_LED, OUTPUT);
}

void buttonVariableTaskSetup(void)
{
    pinMode(UP_BUTTON, INPUT_PULLUP);
    pinMode(DOWN_BUTTON, INPUT_PULLUP);
}

void buttonLedTask(void)
{
    static uint32_t nextTimeTask1 = 0;
    static bool ledLastState = false;

    if(millis() >= nextTimeTask1) 
    {
        if(!digitalRead(ON_OFF_BUTTON) & !ledLastState & ((millis() - nextTimeTask1 ) >= BUTTON_REFRESH_TIME))
        {
            ledLastState = true;
            nextTimeTask1 = millis() + BUTTON_REFRESH_TIME;
        }
        else if(digitalRead(ON_OFF_BUTTON) & ledLastState & ((millis() - nextTimeTask1 ) >= BUTTON_REFRESH_TIME))
        {
            ledLastState = false;
            digitalWrite(GREEN_LED, !digitalRead(GREEN_LED));
            printf("\nGreenLed State: %d\n", digitalRead(GREEN_LED));
            if(digitalRead(GREEN_LED))
            {
                printf("BlueInterminetOff\n");
            }
            else
            {
                printf("BlueInterminetOn\n");
                printf("CurentGlobal counter val: %d\n", globalCounter );
            }
            nextTimeTask1 = millis() + BUTTON_REFRESH_TIME;
        }
    }
}

void ledIntermittentTask(void)
{
    if (digitalRead(GREEN_LED)) 
    {
        bufferCounter = RESET;
        return;
    }

    static uint32_t nextTimeTask2 = RESET;

    if(millis() >= nextTimeTask2)
    {
      if (bufferCounter != globalCounter)
      {
        if (!digitalRead(BLUE_LED))
        {
          digitalWrite(BLUE_LED, !digitalRead(BLUE_LED));
          nextTimeTask2 = millis() + BLUE_LED_ON_TIME;
        }
        else if (digitalRead(BLUE_LED))
        {
          digitalWrite(BLUE_LED, !digitalRead(BLUE_LED));
          nextTimeTask2 = millis() + BLUE_LED_OFF_TIME;
          ++bufferCounter;
        }
      }
      else
      {
        nextTimeTask2 = millis() + BLUE_LED_PAUSE_TIME;
        bufferCounter = RESET;
      }
    }
}

void buttonVariableTask(void)
{
    static uint32_t nextTimeTask3 = 0;
    static bool lastStateUP = false;
    static bool lastStateDOWN = false;

    if(millis() >= nextTimeTask3)
    {
        //plus handler
        if (!digitalRead(UP_BUTTON) & !lastStateUP & ((millis() - nextTimeTask3) > BUTTON_REFRESH_TIME))
        {
            lastStateUP = true;
            nextTimeTask3 = millis() + BUTTON_REFRESH_TIME;
        }
        else if (digitalRead(UP_BUTTON) & lastStateUP & ((millis() - nextTimeTask3) > BUTTON_REFRESH_TIME))
        {
            lastStateUP = false;
            ++globalCounter;
            if (globalCounter > MAX_COUNTER)
            {
                globalCounter = MIN_COUNTER;
            }
            printf("NewGlobal counter val: %d\n", globalCounter );
            nextTimeTask3 = millis() + BUTTON_REFRESH_TIME;
        }
        //minus handler
        if (!digitalRead(DOWN_BUTTON) & !lastStateDOWN & ((millis() - nextTimeTask3) > BUTTON_REFRESH_TIME))
        {
            lastStateDOWN = true;
            nextTimeTask3 = millis() + BUTTON_REFRESH_TIME;
        }
        else if (digitalRead(DOWN_BUTTON) & lastStateDOWN & ((millis() - nextTimeTask3) > BUTTON_REFRESH_TIME))
        {
            lastStateDOWN = false;
            --globalCounter;
            if (globalCounter < MIN_COUNTER)
            {
                globalCounter = MAX_COUNTER;
            }
            printf("NewGlobal counter val: %d\n", globalCounter );
            nextTimeTask3 = millis() + BUTTON_REFRESH_TIME;
        }
    }
}
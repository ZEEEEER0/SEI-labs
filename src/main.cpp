#include "main.h"

void setup(void) 
{
  buttonLedTaskSetup();
  ledIntermittentTaskSetup();
  buttonVariableTaskSetup();

  own_stdio_setup();

  printf("\nSitem Started\n");
  printf("Current Global counter val: %d\n", globalCounter );
  printf("GreenLed State: %d\n", digitalRead(GREEN_LED));
  if(digitalRead(GREEN_LED))
  {
    printf("BlueInterminetOff\n");
  }
  else
  {
    printf("BlueInterminetOn\n");
  }
}

void loop(void) 
{
  buttonLedTask();
  ledIntermittentTask();
  buttonVariableTask();
}
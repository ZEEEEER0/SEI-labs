#include "main.h"

#define BUTTON_PIN 2
#define DEBOUCE_DELAY 150 // ms
void setup() 
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() 
{
  static uint32_t nextCheckTime = 0;
  
  if (digitalRead(BUTTON_PIN) == LOW)
  {
    if (millis() >= nextCheckTime)
    {
      digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    }
    nextCheckTime = millis() + DEBOUCE_DELAY;
    
  }
}

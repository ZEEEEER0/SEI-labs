#include "main.h"

void setup(void)
{
  own_stdio_setup();
  Serial.println("System started\n\r");
  pinMode(LED_BUILTIN, OUTPUT);
}  

void LedControl(const char *cmd)
{
  if (strcmp(cmd, "on") == 0)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("LED is on\n\r");
  }
  else if (strcmp(cmd, "off") == 0)
  {
    digitalWrite(LED_BUILTIN, LOW);
    Serial.println("LED is off\n\r");
  }
}

void loop(void)
{
  // Your code here
}

void serialEvent(void)
{
  char cmd[10];
  printf("Enter command: ");
  scanf("%10s", cmd);

  printf("%s:\n", cmd);
  LedControl(cmd);
}

#include "main.h"

void setup()
{
    buttonLedTaskSetup();
    setBlinkFrequencyTaskSetup();
    idleTaskSetup();

    // Alte inițializări necesare
    Serial.begin(BAUDRATE);
    printf("Setup completed\n");
}

void loop()
{

}
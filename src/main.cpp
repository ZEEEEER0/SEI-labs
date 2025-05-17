#include "main.h"


void setup()
{
    systemSetup();
}

void loop()
{

}

void serialEvent(void)
{
    static char command[32];
    static uint8_t idx = 0;
    while (Serial.available()) {
        char c = Serial.read();
        if (c == '\r' || c == '\n') {
            if (idx > 0) {
                command[idx] = '\0';
                printf("%s\r\n", command);
                parsing(command);
                idx = 0;
            }
        } else if (idx < sizeof(command) - 1) {
            command[idx++] = c;
        }
    }
}
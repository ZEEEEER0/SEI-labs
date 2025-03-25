#include "resistor.h"

void resistorSetup(resistor_t *resistor, uint8_t id, char *name, uint8_t pin, uint16_t max_value)
{
    resistor->id = id;
    resistor->name = name;
    resistor->pin = pin;
    resistor->max_value = max_value;
}

void resistorRead(resistor_t *resistor, uint16_t (*analogRead)(uint8_t))
{
    resistor->value = analogRead(resistor->pin);
}

double getResistance(resistor_t *resistor)
{
    return 0.0;
}

uint16_t getResistanceRaw(resistor_t *resistor)
{
    return resistor->value;
}


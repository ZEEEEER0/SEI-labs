#include "resistor.h"


void resistorSetup(resistor_t *resistor,
    uint8_t id,
    char *name,
    uint16_t pin,
    uint16_t max_value)
{
    resistor->id = id;
    resistor->name = name;
    resistor->pin = pin;
    resistor->value = 0;
    resistor->max_value = max_value;
}

double resistorConvertToResistance(resistor_t *resistor,const double voltage, const double adc_reference_voltage)
{
    return (resistor->max_value * voltage) / adc_reference_voltage;
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

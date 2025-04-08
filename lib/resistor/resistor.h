#ifndef RESISTOR_H
#define RESISTOR_H
#include <stdint.h>


typedef struct 
{
    uint8_t id;
    char *name;
    uint8_t pin;
    uint16_t value;
    uint16_t max_value;
} resistor_t;

 

void resistorSetup(resistor_t *resistor,
                     uint8_t id,
                     char *name,
                     uint16_t pin,
                     uint16_t max_value);

 void resistorRead(resistor_t *resistor, uint16_t (*analogRead)(uint8_t));
 double getResistance(resistor_t *resistor);
 uint16_t getResistanceRaw(resistor_t *resistor);
 double resistorConvertToResistance(resistor_t *resistor,const double voltage, const double adc_reference_voltage);
#endif // RESISTOR_H
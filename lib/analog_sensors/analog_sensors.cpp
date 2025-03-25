#include "analog_sensors.h"

static resistor_t resistor;

void analogSensorsSetup(void)
{
    resistorSetup(&resistor, RESISTANCE_SENSOR_ID, RESISTANCE_SENSOR_NAME, SENSOR_PIN, RESISTANCE_MAX_VALUE);
}

void analogSensorsRead(void)
{
    resistorRead(&resistor, (uint16_t (*)(uint8_t))analogRead);

}

void analogSensorsPrint(void)
{

}

void analogSensorsPlot(void)
{
    printf("Resistance: %s\n", getResistance(&resistor));
}
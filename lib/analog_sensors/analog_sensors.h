#ifndef ANALOG_SENSORS_H
#define ANALOG_SENSORS_H

#include <Arduino.h>
#include "resistor.h"
#include "config.h"

void analogSensorsSetup(void);
void analogSensorsRead(void);
void analogSensorsPrint(void);
void analogSensorsPlot(void);
double analogSensorConvert(void);

#endif // ANALOG_SENSORS_H
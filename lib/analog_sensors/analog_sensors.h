#ifndef ANALOG_SENSORS_H
#define ANALOG_SENSORS_H

#include "resistor.h"
#include "config.h"
#include <Arduino.h>
#include <MedianFilter.h>
#include <meanFilter.h>

void analogSensorsSetup(void);
void analogSensorsRead(void);
void analogSensorsPrint(void);
void analogSensorsPlot(void);
double analogSensorsConvertToVoltage(uint16_t);



#endif // ANALOG_SENSORS_H
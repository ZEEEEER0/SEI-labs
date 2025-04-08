#include "analog_sensors.h"
#include "resistor.h"

static resistor_t resistor;
static volatile uint16_t resistanceValueFiltered;
static volatile uint16_t resistanceValueFinal = 0;

static MeanFilter_t meanFilter;
static uint16_t meanBuffer[WINDOW_SIZE];


static sMedianFilter_t medianFilter;
static sMedianNode_t medianBuffer[WINDOW_SIZE];


void analogSensorsSetup(void)
{
    resistorSetup(&resistor, SENSOR_RESISTANCE_ID, SENSOR_NAME, SENSOR_PIN, SENSOR_MAX_VALUE);
    medianFilter.numNodes = WINDOW_SIZE;
    medianFilter.medianBuffer = medianBuffer;   
    MEDIANFILTER_Init(&medianFilter);

    MeanFilterInit(&meanFilter, meanBuffer, WINDOW_SIZE);
}

void analogSensorsRead(void)
{
    resistorRead(&resistor, (uint16_t (*)(uint8_t))analogRead);
    resistanceValueFiltered = MEDIANFILTER_Insert(&medianFilter, getResistanceRaw(&resistor));
    MeanFilterAddValue(&meanFilter, resistanceValueFiltered);
}

void analogSensorsPrint(void)
{
    double voltage = analogSensorsConvertToVoltage(resistanceValueFinal);
    double resistance = resistorConvertToResistance(&resistor, voltage, ADC_REF_VOLTAGE);

    char buffer[10];
    dtostrf(resistance, 5, 2, buffer);
    printf("resistence: %s ogmh\n", buffer);
}

void analogSensorsPlot(void)
{
    resistanceValueFiltered = MeanFilterGetMean(&meanFilter);

    printf("resistance:%d,", getResistanceRaw(&resistor));
    printf("resistancefiltered:%d,", resistanceValueFiltered);
    printf("resistancefinal:%d\n", resistanceValueFiltered);
}

double analogSensorsConvertToVoltage(uint16_t value)
{
    return value * ADC_VOLTAGE_STEP;
}
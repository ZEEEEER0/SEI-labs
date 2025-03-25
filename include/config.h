#ifndef CONFIG_H
#define CONFIG_H



#define RESISTOR_TASK_PRIORITY                  1
#define RESISTOR_TASK_RECURENCE                 20

#define PRINT_TASK_PRIORITY                     2   
#define PRINT_TASK_RECURENCE                    500

#define PLOTTER_TASK_PRIORITY                   1
#define PLOTTER_TASK_RECURENCE                  25

//Analog sensor
#define SENSOR_PIN A0
#define RESISTANCE_MAX_VALUE                    10000
#define RESISTANCE_SENSOR_ID                    0
#define RESISTANCE_SENSOR_NAME                  "Resistor"

//ADC Settings
#define ADC_RESOLUTION                          10
#define ADC_MAX_VALUE                           (1 << ADC_RESOLUTION) - 1
#define ADC_REFERENCE_VOLTAGE                   5.0
#define ADC_VOLTAGE_STEP                       ADC_REFERENCE_VOLTAGE / ADC_MAX_VALUE

#endif // CONFIG_H

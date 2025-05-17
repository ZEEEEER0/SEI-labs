#ifndef CONFIG_H
#define CONFIG_H

#define BAUD_RATE 115200 

#define RESISTOR_TASK_PRIORITY 10
#define PRINT_TASK_PRIORITY 1
#define PLOTTER_TASK_PRIORITY 1
#define RESISTOR_TASK_REC   20  // Intervalul de timp pentru Task 1 (20 ms)
#define PRINT_TASK_REC      510 // Intervalul de timp pentru Task 2 (500 ms)
#define PLOTTER_TASK_REC    25  // Intervalul de timp pentru Task 3 (25 ms)

#define SENSOR_PIN A0
#define SENSOR_NAME (char*) "Resistor"
#define SENSOR_MAX_VALUE 10000
#define SENSOR_RESISTANCE_ID 0

#define ADC_RESOLUTION 1023
#define ADC_MAX_VALUE ((1<<ADC_RESOLUTION)-1)
#define ADC_REF_VOLTAGE 5.0
#define ADC_VOLTAGE_STEP   (ADC_REF_VOLTAGE / ADC_RESOLUTION)

#define WINDOW_SIZE    7

#define PLOTTER_TASK_ACTIVE 1
#define PRINT_TASK_ACTIVE 0


#endif // CONFIG_H
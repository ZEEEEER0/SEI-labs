#ifndef CONFIG_H
#define CONFIG_H

#define GREEN_LED 7
#define BLUE_LED 6

#define ON_OFF_BUTTON 5
#define UP_BUTTON 4
#define DOWN_BUTTON 3

// Define the baud rate for the serial communication
#define BAUDRATE 115200

#define BUTTON_REFRESH_TIME 100

#define BLUE_LED_PAUSE_TIME 1000
#define BLUE_LED_ON_TIME 300
#define BLUE_LED_OFF_TIME 500
#define RESET 0

#define MAX_COUNTER 10
#define MIN_COUNTER 2

extern uint8_t globalCounter;
extern uint8_t bufferCounter;

#endif
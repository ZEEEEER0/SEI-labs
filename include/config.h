#ifndef CONFIG_H
#define CONFIG_H

#define BAUD_RATE 115200 

//Relay settings
#define RELAY_ID_RED 1
#define RELAY_ID_GREEN 2
#define RELAY_ID_BLUE 3

#define RELAY_NAME_RED "Red light control"
#define RELAY_NAME_GREEN "Green light control"
#define RELAY_NAME_BLUE "Blue light control"

#define RELAY_PIN_RED 13
#define RELAY_PIN_GREEN 12
#define RELAY_PIN_BLUE 11


#define RELAY_TASK_STACK_SIZE 256
#define RELAY_TASK_PRIORITY 1

#endif // CONFIG_H
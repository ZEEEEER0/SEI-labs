#ifndef CONFIG_H
#define CONFIG_H

#define BAUD_RATE 115200 

#define LIGHTBULB_TASK_STACK_SIZE 256
#define LIGHTBULB_TASK_PRIORITY 1
#define LIGHTBULB_TASK_RECURENCE 100
#define LIGHTBULB_TASK_NAME "LightbulbTask"

//Relay settings
#define RELAY_PIN 2
#define RELAY_ID 0u
#define RELAY_NAME "Relay"
#define RELAY_TASK_STACK_SIZE 256
#define RELAY_TASK_PRIORITY 1

//lightbulb settings
#define LIGHTBULB_ID 0u
#define LIGHTBULB_NAME "Lightbulb"
#define LIGHTBULB_PIN 3

#endif // CONFIG_H
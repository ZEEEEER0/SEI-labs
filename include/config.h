#ifndef CONFIG_H
#define CONFIG_H

// semaphore
#define GREEN_LED           7
#define BLUE_LED            6

#define ON_OFF_BUTTON       5
#define UP_BUTTON           4
#define DOWN_BUTTON         3

#define STACK_SIZE		   128
#define PRIORITY			      2

#define BAUD_RATE           9600

#define BUTTON_REFRESH_TIME	100

#define GREEN_LED_ON_TIME   1000
#define BLUE_LED_ON_TIME    300
#define BLUE_LED_OFF_TIME   500

#define FIRST_TASK_REC      10
#define SECOND_TASK_REC     20
#define THIRD_TASK_REC      200
#define IDLE_HOOK_REC       500

#define BUFFER_SIZE         10  // Dimensiunea buffer-ului (cozii)
#define THIRD_TASK_REC      200 // Intervalul de timp pentru Task 3 (200 ms)

#endif // CONFIG_H
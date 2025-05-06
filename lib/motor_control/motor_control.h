#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include <stdint.h>

void motor_init(void);
void motor_control_callback(uint8_t state);

#endif // MOTOR_CONTROL_H

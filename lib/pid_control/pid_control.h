#ifndef PID_CONTROL_H
#define PID_CONTROL_H

#include <stdint.h>
#include <PID_v1.h>

// PID control structure
typedef struct {
    double SetPoint;
    double Input;
    double Output;
    PID *pid;
} pid_control_t;

// Functions for PID control
void pid_control_init(pid_control_t *pid_control, double kp, double ki, double kd);
void pid_control_set_setpoint(pid_control_t *pid_control, double setpoint);
void pid_control_compute(pid_control_t *pid_control);
double pid_control_get_output(pid_control_t *pid_control);

#endif // PID_CONTROL_H

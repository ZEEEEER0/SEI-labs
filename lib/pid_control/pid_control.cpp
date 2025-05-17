#include "pid_control.h"
#include <PID_v1.h>
#include <stdlib.h>

void pid_control_init(pid_control_t *pid_control, double kp, double ki, double kd) {
    pid_control->SetPoint = 0.0;
    pid_control->Input = 0.0;
    pid_control->Output = 0.0;
    pid_control->pid = new PID(&pid_control->Input, &pid_control->Output, &pid_control->SetPoint, kp, ki, kd, DIRECT);
    pid_control->pid->SetMode(AUTOMATIC);
    pid_control->pid->SetOutputLimits(0, 255); // Default PWM range
}

void pid_control_set_setpoint(pid_control_t *pid_control, double setpoint) {
    pid_control->SetPoint = setpoint;
}

void pid_control_compute(pid_control_t *pid_control) {
    pid_control->pid->Compute();
}

double pid_control_get_output(pid_control_t *pid_control) {
    return pid_control->Output;
}

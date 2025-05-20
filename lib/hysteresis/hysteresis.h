#ifndef HYSTERESIS_H
#define HYSTERESIS_H

#include <stdint.h>

typedef struct {
    int16_t state; // 1 = ON, 0 = OFF
    int16_t setpoint;
    int16_t hysteresis;
} hysteresis_t;

void hysteresis_init(hysteresis_t *h, int16_t setpoint, int16_t hysteresis);
void hysteresis_update(hysteresis_t *h, int16_t value);

#endif // HYSTERESIS_H

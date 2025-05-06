#ifndef HYSTERESIS_H
#define HYSTERESIS_H

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    uint8_t state; // Current state (0 or 1)
    uint16_t actual_value; // Current value
    uint16_t set_point; // The setpoint value for the hysteresis
    uint16_t hysteresis; // The hysteresis value
    void (*callback)(uint8_t); // Callback function to be called when the state changes
} hysteresis_t;

void hysteresis_init(hysteresis_t *hysteresis, 
                    uint16_t actual_value,
                    uint16_t set_point, 
                    uint16_t hysteresis_value, 
                    void (*callback)(uint8_t));

void hysteresis_update(hysteresis_t *hysteresis, uint16_t value);
void hysteresis_set_point(hysteresis_t *hysteresis, uint16_t set_point);
void hysteresis_set_actual_value(hysteresis_t *hysteresis, uint16_t actual_value);
void hysteresis_set_hysteresis(hysteresis_t *hysteresis, uint16_t hysteresis_value);

#endif // HYSTERESIS_H
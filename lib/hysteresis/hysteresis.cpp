#include "hysteresis.h"

void hysteresis_init(hysteresis_t *hysteresis, 
                     uint16_t actual_value,
                     uint16_t set_point, 
                     uint16_t hysteresis_value, 
                     void (*callback)(uint8_t))
{
    hysteresis->state = 0; // Initialize state to 0
    hysteresis->actual_value = actual_value; // Set the actual value
    hysteresis->set_point = set_point; // Set the setpoint value
    hysteresis->hysteresis = hysteresis_value; // Set the hysteresis value
    hysteresis->callback = callback; // Set the callback function
}

void hysteresis_update(hysteresis_t *hysteresis, uint16_t value)
{
    hysteresis->actual_value = value; // Update the actual value

    // Check if the state needs to be changed
    if (hysteresis->state == 0 && hysteresis->actual_value >= hysteresis->set_point + hysteresis->hysteresis) {
        hysteresis->state = 1; // Change state to 1
        hysteresis->callback(hysteresis->state); // Call the callback function
    } else if (hysteresis->state == 1 && hysteresis->actual_value <= hysteresis->set_point - hysteresis->hysteresis) {
        hysteresis->state = 0; // Change state to 0
        hysteresis->callback(hysteresis->state); // Call the callback function
    }
}

void hysteresis_set_point(hysteresis_t *hysteresis, uint16_t set_point)
{
    hysteresis->set_point = set_point; // Set the new setpoint value
}

void hysteresis_set_actual_value(hysteresis_t *hysteresis, uint16_t actual_value)
{
    hysteresis->actual_value = actual_value; // Set the new actual value
}

void hysteresis_set_hysteresis(hysteresis_t *hysteresis, uint16_t hysteresis_value)
{
    hysteresis->hysteresis = hysteresis_value; // Set the new hysteresis value
}
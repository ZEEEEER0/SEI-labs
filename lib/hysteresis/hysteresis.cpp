#include "hysteresis.h"

void hysteresis_init(hysteresis_t *h, int16_t setpoint, int16_t hysteresis) {
    h->setpoint = setpoint;
    h->hysteresis = hysteresis;
    h->state = 0;
}

void hysteresis_update(hysteresis_t *h, int16_t value) {
    int16_t lower = h->setpoint - h->hysteresis;
    int16_t upper = h->setpoint + h->hysteresis;
    if (h->state == 0 && value < lower) {
        h->state = 1; // ON
    } else if (h->state == 1 && value > upper) {
        h->state = 0; // OFF
    }
}

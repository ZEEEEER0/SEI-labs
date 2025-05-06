#include <Arduino.h>
#include <config.h>

uint16_t sensor_read_position(void) {
    return analogRead(POT_PIN);
}

#ifndef LIGHTBULB_H
#define LIGHTBULB_H

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#define LIGHTBULB_MAX_LUMINOSITY 100
#define LIGHTBULB_MIN_LUMINOSITY 0
#define LIGHTBULB_MAX_DIMMABLE 1
#define LIGHTBULB_MIN_DIMMABLE 0
#define LIGHTBULB_MAX_NAME_LENGTH 20

typedef enum {
    LIGHTBULB_OFF = 0u,
    LIGHTBULB_ON
} lightbulb_state_t;

typedef struct {
    uint8_t id;
    char *name;
    uint8_t luminosity; // 0-100%
    uint8_t dimmable; // 0 or 1
    lightbulb_state_t state; 
    uint8_t was_changed; // 0 or 1, used to check if the lightbulb was changed
    void (*set_light)(uint8_t state); // function pointer to set pin state

} lightbulb_t;

void lightbulb_on(lightbulb_t *lightbulb);
void lightbulb_off(lightbulb_t *lightbulb);
void lightbulb_toggle(lightbulb_t *lightbulb);
void lightbulb_set_state(lightbulb_t *lightbulb, lightbulb_state_t state);
lightbulb_state_t lightbulb_get_state(lightbulb_t *lightbulb);
void lightbulb_set_name(lightbulb_t *lightbulb, char *name);
void lightbulb_set_luminosity(lightbulb_t *lightbulb, uint8_t luminosity);
uint8_t lightbulb_get_luminosity(lightbulb_t *lightbulb);
void lightbulb_set_dimmable(lightbulb_t *lightbulb, uint8_t dimmable);
uint8_t lightbulb_get_dimmable(lightbulb_t *lightbulb);
void lightbulb_set_light(lightbulb_t *lightbulb, uint8_t state);
const char *lightbulb_get_name(lightbulb_t *lightbulb);
uint8_t lightbulb_get_id(lightbulb_t *lightbulb);
int8_t lightbulb_init(lightbulb_t *lightbulb, uint8_t id, char *name, uint8_t luminosity, uint8_t dimmable, void (*set_light)(int8_t state));
void lightbulb_set_pin(lightbulb_t *lightbulb, uint8_t pin);
uint8_t lightbulb_get_pin(lightbulb_t *lightbulb);
void lightbulb_loop(lightbulb_t *lightbulb, uint8_t state);

#endif // LIGHTBULB_H
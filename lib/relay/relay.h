#ifndef RELAY_H
#define RELAY_H

#include <stdint.h>
#include <stdlib.h>

typedef enum{
    RELAY_OFF = 0u,
    RELAY_ON_COMMAND 
}relay_state_t;

typedef struct {
    uint8_t id;
    char *name;

    uint8_t pin; 
    relay_state_t state; 
    void (*set_pin)(uint8_t pin, uint8_t state); // function pointer to set pin state

}relay_t;

void relay_on                           (relay_t *relay);
void relay_off                          (relay_t *relay);
void relay_toggle                       (relay_t *relay);
void relay_set_state                    (relay_t *relay, relay_state_t state);
relay_state_t relay_get_state           (relay_t *relay);
void relay_set_name                     (relay_t *relay, char *name);
void relay_set_pin                      (relay_t *relay, uint8_t pin);
const char *relay_get_name              (relay_t *relay);
uint8_t relay_get_pin                   (relay_t *relay);
int8_t relay_init                       (relay_t *relay, uint8_t id, char *name, uint8_t pin, void (*set_pin)(uint8_t pin, uint8_t state));



#endif // RELAY_H
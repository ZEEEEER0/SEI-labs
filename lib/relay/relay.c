#include "relay.h"

#define LOW 0
#define HIGH 1

int8_t relay_init(relay_t *relay, uint8_t id, char *name, uint8_t pin, void (*set_pin)(uint8_t pin, uint8_t state)) {
    relay->id = id;
    relay->name = name;
    relay->pin = pin;
    relay->state = RELAY_OFF;
    relay->set_pin = set_pin;
    if (relay == NULL || relay->set_pin == NULL) {
        return -1; // Error: relay is NU
}
    relay ->id = id;
    relay ->name = name;
    relay ->pin = pin;
    relay ->state = RELAY_OFF;
    relay ->set_pin = set_pin;
    relay->set_pin(relay->pin, LOW); // Initialize the relay to OFF state
    return 0; // Success
    }

void relay_on(relay_t *relay) {
    if (relay->set_pin == NULL){
        return; 
    }
    relay->state = RELAY_ON_COMMAND;
    relay->set_pin(relay->pin, HIGH);
}

void relay_off(relay_t *relay) {
    relay->state = RELAY_OFF;
    relay->set_pin(relay->pin, LOW);
}

void relay_toggle(relay_t *relay) {
    if (relay->state == RELAY_OFF) {
        relay_on(relay);
    } else {
        relay_off(relay);
    }
}

void relay_set_state(relay_t *relay, relay_state_t state) {
    if (state == RELAY_ON_COMMAND) {
        relay_on(relay);
    } else {
        relay_off(relay);
    }
}

relay_state_t relay_get_state(relay_t *relay) {
    return relay->state;
}

void relay_set_name(relay_t *relay, char *name) {
    relay->name = name;
}

void relay_set_pin(relay_t *relay, uint8_t pin) {
    relay->pin = pin;
}

const char *relay_get_name(relay_t *relay) {
    return relay->name;
}

uint8_t relay_get_pin(relay_t *relay) {
    return relay->pin;
}

void relay_set_pin_state(relay_t *relay, uint8_t state) {
    relay->set_pin(relay->pin, state);
}


#include "lightbulb.h"

int8_t lightbulb_init(lightbulb_t *lightbulb, uint8_t id, char *name, uint8_t luminosity, uint8_t dimmable, void (*set_light)(uint8_t state)) {
    if (lightbulb == NULL || set_light == NULL) {
        return -1; // Error: lightbulb is NULL or set_light function is NULL
    }
    lightbulb->id = id;
    lightbulb->name = name;
    lightbulb->luminosity = luminosity;
    lightbulb->dimmable = dimmable;
    lightbulb->state = LIGHTBULB_OFF;
    lightbulb->set_light = set_light;
    lightbulb->was_changed = false; 
    lightbulb->set_light(LIGHTBULB_OFF); 
    return 0; // Success
}

void lightbulb_on(lightbulb_t *lightbulb) {
    lightbulb->set_light(LIGHTBULB_ON);
    lightbulb->was_changed = true; // Set was_changed to true when the state changes
}

void lightbulb_off(lightbulb_t *lightbulb) {
    lightbulb->set_light(LIGHTBULB_OFF);
    lightbulb->was_changed = true; // Set was_changed to true when the state changes
}

void lightbulb_toggle(lightbulb_t *lightbulb) {
    if (lightbulb->state == LIGHTBULB_OFF) {
        lightbulb_on(lightbulb);
    } else {
        lightbulb_off(lightbulb);
    }
}

void lightbulb_set_state(lightbulb_t *lightbulb, lightbulb_state_t state) {
    if (state == LIGHTBULB_ON) {
        lightbulb_on(lightbulb);
    } else {
        lightbulb_off(lightbulb);
    }
}

lightbulb_state_t lightbulb_fetch_state(lightbulb_t *lightbulb) {
    return lightbulb->state;
}


lightbulb_state_t lightbulb_get_state(lightbulb_t *lightbulb) {
    return lightbulb->state;
}

void lightbulb_set_id(lightbulb_t *lightbulb, uint8_t id) {
    lightbulb->id = id;
}

void lightbulb_set_name(lightbulb_t *lightbulb, char *name) {
    lightbulb->name = name;
}
const char *lightbulb_get_name(lightbulb_t *lightbulb) {
    return lightbulb->name;
}

uint8_t lightbulb_luminosity_constraint(uint8_t luminosity) {
    if (luminosity > LIGHTBULB_MAX_LUMINOSITY) {
        return LIGHTBULB_MAX_LUMINOSITY;
    } else if (luminosity < LIGHTBULB_MIN_LUMINOSITY) {
        return LIGHTBULB_MIN_LUMINOSITY;
    } else {
        return luminosity;
    }
}

void lightbulb_set_luminosity(lightbulb_t *lightbulb, int8_t luminosity) {
    if (lightbulb->dimmable == true){
        return;
    }

    luminosity = lightbulb_luminosity_constraint(luminosity);
    lightbulb->luminosity = luminosity;
    lightbulb->was_changed = true; // Set was_changed to true when the luminosity changes
    if (lightbulb->state == LIGHTBULB_ON) {
        lightbulb->set_light(luminosity);
    }
}
    

void lightbulb_set_dimmable(lightbulb_t *lightbulb, uint8_t dimmable) {
    if (dimmable > LIGHTBULB_MAX_DIMMABLE) {
        lightbulb->dimmable = LIGHTBULB_MAX_DIMMABLE;
    } else if (dimmable < LIGHTBULB_MIN_DIMMABLE) {
        lightbulb->dimmable = LIGHTBULB_MIN_DIMMABLE;
    } else {
        lightbulb->dimmable = dimmable;
    }
}

void lightbulb_loop(lightbulb_t *lightbulb, uint8_t state) {
    if (lightbulb->was_changed == true) {
        if (lightbulb->set_light == NULL) {
            return; // Error: set_light function is NULL
        }

        lightbulb->state = static_cast<lightbulb_state_t>(state);
        if (state == LIGHTBULB_ON && lightbulb->dimmable == 1) {
            lightbulb->set_light(lightbulb->luminosity);
        } else {
            lightbulb->set_light(LIGHTBULB_OFF);
        }

        lightbulb->was_changed = false; // Reset the was_changed flag
    }
}








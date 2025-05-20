#ifndef FSM_BUTTON_LED_H
#define FSM_BUTTON_LED_H

#include <stdint.h>

typedef enum {
    FSM_LED_OFF = 0,
    FSM_LED_ON
} fsm_led_state_t;

void fsm_init(uint8_t button_pin, uint8_t led_pin);
void fsm_update(void);
fsm_led_state_t fsm_get_state(void);

#endif // FSM_BUTTON_LED_H

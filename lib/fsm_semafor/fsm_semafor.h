#ifndef FSM_SEMAFOR_H
#define FSM_SEMAFOR_H

#include <stdint.h>

typedef struct {
    uint8_t e_red, e_yellow, e_green;
    uint8_t n_red, n_yellow, n_green;
    unsigned long timeout_ms;
    const char* lcd_text;
    const char* serial_text;
} fsm_state_t;

typedef enum {
    S1 = 0,
    S2,
    S3,
    S4,
    S5,
    S6,
    S7,
    S8
} semafor_state_t;

extern const fsm_state_t fsm_table[8];
extern unsigned long next_change_time;

void fsm_semafor_init(uint8_t button_pin);
void fsm_semafor_update(void);
semafor_state_t fsm_semafor_get_state(void);

#endif // FSM_SEMAFOR_H

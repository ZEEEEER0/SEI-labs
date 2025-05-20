#ifndef SEMAFOR_FSM_H
#define SEMAFOR_FSM_H

typedef enum {
    SEMAFOR_E_GREEN,
    SEMAFOR_E_YELLOW,
    SEMAFOR_E_RED
} semafor_state_t;

void semafor_fsm_init(void);
void semafor_fsm_task(void *pvParameters);

#endif // SEMAFOR_FSM_H

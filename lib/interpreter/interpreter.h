#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "lightbulb.h"
#include "relay.h"

typedef enum {
    RELAY_ON_COMMAND = 0u,
    RELAY_OFF_COMMAND,
    RELAY_TOGGLE_COMMAND,
    RELAY_SET_COMMAND,
    RELAY_GET_COMMAND,
    RELAY_STATUS_COMMAND,
    HELP_COMMAND,
    INVALID_COMMAND
} command_t;


void interpreter_init(void);
void interpreter_loop(void);


#endif // INTERPRETER_H
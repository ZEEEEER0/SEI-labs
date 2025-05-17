#ifndef MY_TASKS_H
#define MY_TASKS_H

#include <Arduino.h>
#include <config.h>
#include <own_stdio.h>
#include "relay.h"
#include "l298.h"

static Relay red = Relay(RELAY_ID_RED, RELAY_NAME_RED, RELAY_PIN_RED);
static Relay green = Relay(RELAY_ID_GREEN, RELAY_NAME_GREEN, RELAY_PIN_GREEN);
static Relay blue = Relay(RELAY_ID_BLUE, RELAY_NAME_BLUE, RELAY_PIN_BLUE);

// Instanță globală pentru motorul DC (pinii pot fi schimbați după nevoie)
static L298 motor(7, 6, 5);

void systemSetup(void);
void parsing(const char *command);

// Adăugare prototipuri pentru motor DC (L298)
void motorSetup(void);
void motorParseCommand(const char *command);
void motorReport(void);

#endif // MY_TASKS
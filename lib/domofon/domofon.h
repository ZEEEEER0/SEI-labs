#ifndef DOMOFON_H
#define DOMOFON_H

#include <Arduino.h>
#include "config.h"
#include "own_stdio.h"

void domofon_setup(void);
void domofon_loop(void);
void check_code(char *code);
void getCode(char ch);


#endif // DOMOFON_H
#ifndef OWN_STDIO_H
#define OWN_STDIO_H

#include <Arduino.h>
#include <stdio.h>
#include <config.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#include <Keypad.h>

void own_stdio_setup();
int own_putchar(char ch, FILE *stream);
int own_getchar(FILE *stream);

int own_lcd_putchar(char ch, FILE *stream);
int onw_lcd_getchar(FILE *stream);

uint8_t keypadGetState (void);

#endif // OWN_STDIO_H
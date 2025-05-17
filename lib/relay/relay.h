#ifndef RELAY_H
#define RELAY_H

#include <Arduino.h>
#include <stdint.h>
#include <stdlib.h>

#define NOTSET 0
#define SET 1

enum RelayControl
{
    ENABLE,
    DISABLE,
    TOGGLE,
};

enum RelayState
{
    ENABLED = HIGH,
    DISABLED = LOW,
};

class Relay
{
public:
    Relay(uint8_t id, const char* name, uint8_t pin, RelayState state = DISABLED);

    RelayState getState();                  //done
    const char *getName();                  //done
    uint8_t getPin();                       //done

    void control(RelayControl command);     //done


private:

    void set(RelayState state);             //done

    uint8_t __id;
    uint8_t __pin;
    const char *__name;
    RelayState __state;
};

#endif // RELAY_H
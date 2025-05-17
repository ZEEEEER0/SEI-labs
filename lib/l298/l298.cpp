#include "l298.h"

L298::L298(uint8_t in1, uint8_t in2, uint8_t en)
    : _in1(in1), _in2(in2), _en(en), _power(0)
{
    pinMode(_in1, OUTPUT);
    pinMode(_in2, OUTPUT);
    pinMode(_en, OUTPUT);
    stop();
}

void L298::setPower(int8_t power)
{
    power = constrain(power, -100, 100);
    _power = power;
    if (power == 0) {
        digitalWrite(_in1, LOW);
        digitalWrite(_in2, LOW);
        analogWrite(_en, 0);
    } else if (power > 0) {
        digitalWrite(_in1, HIGH);
        digitalWrite(_in2, LOW);
        analogWrite(_en, map(power, 0, 100, 0, 255));
    } else {
        digitalWrite(_in1, LOW);
        digitalWrite(_in2, HIGH);
        analogWrite(_en, map(-power, 0, 100, 0, 255));
    }
}

void L298::stop()
{
    _power = 0;
    digitalWrite(_in1, LOW);
    digitalWrite(_in2, LOW);
    analogWrite(_en, 0);
}

int8_t L298::getPower() const
{
    return _power;
}

const char* L298::getDirection() const
{
    if (_power > 0) return "forward";
    if (_power < 0) return "backward";
    return "stopped";
}

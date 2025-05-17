#ifndef L298_H
#define L298_H

#include <Arduino.h>

class L298 {
public:
    L298(uint8_t in1, uint8_t in2, uint8_t en);

    void setPower(int8_t power); // [-100, 100]
    void stop();
    int8_t getPower() const;
    const char* getDirection() const;

private:
    uint8_t _in1, _in2, _en;
    int8_t _power;
};

#endif // L298_H

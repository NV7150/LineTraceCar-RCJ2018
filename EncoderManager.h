//
// Created by 後藤大介 on 2018/08/01.
//

#ifndef LINETRACECAR_ENCODERMANAGER_H
#define LINETRACECAR_ENCODERMANAGER_H

#include "RotaryEncoder.h"
#include "Wheel.h"
#include <Arduino.h>

class EncoderManager{
    private:
    RotaryEncoder encoder;

    public:
    void update();
    bool turnRightTillCarAngle(int);
    bool turnLeftTillCarAngle(int);
    void goForwardTillProDis(int);
    float getRightProDis();
    float getRightAngle();
    float getLeftAngle();
    float getLeftProDis();
    float getProDis();
    void reset();
};

#endif //LINETRACECAR_ENCODERMANAGER_H

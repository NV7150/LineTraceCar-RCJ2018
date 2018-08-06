//
// Created by 後藤大介 on 2018/08/01.
//

#ifndef LINETRACECAR_ROTARYENCODER_H
#define LINETRACECAR_ROTARYENCODER_H

#include "Color.h"
#include <Arduino.h>
#include "Pins.h"

const int LAP_MAX = 16;

class RotaryEncoder {
    private:
    bool wasRightWhite = false;
    bool wasLeftWhite = false;

    int rightLaps = 0;
    int leftLaps = 0;

    int rightCounts = 0;
    int leftCounts = 0;

    bool progressLaps(int);

    bool progressCounts(Color,Color);


    public:

    void encodeUpdate();

    int getLeftLaps();

    int getRightLaps();

    int getLeftCounts();

    int getRightCounts();

    int getRightCountsSubLaps();

    int getLeftCountsSubLaps();

    void reset();

    int getMaxLap();
};

#endif //LINETRACECAR_ROTARYENCODER_H

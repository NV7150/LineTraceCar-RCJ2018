//
// Created by 後藤大介 on 2018/08/01.
//

#include "RotaryEncoder.h"
#include "Sensor.h"

//1週に白がいくつあるか


void RotaryEncoder::encodeUpdate() {
    Color right = judgeColor(analogRead(RE_RIGHT_PIN));
    Color left = judgeColor(analogRead(RE_LEFT_PIN));

    if(right == WHITE){
        if(!wasRightWhite) {
            rightCounts++;
            wasRightWhite = true;

            if ((rightCounts % LAP_MAX) == 0) {
                rightLaps++;
                rightCounts = 0;
            }
        }
    }else if(right == BLACK){
        wasRightWhite = false;
    }


    if(left == WHITE){
        if(!wasLeftWhite) {
            leftCounts++;
            wasLeftWhite = true;

            if ((leftCounts % LAP_MAX) == 0) {
                leftLaps++;
                leftCounts = 0;
            }
        }
    }else if(left == BLACK){
        wasLeftWhite = false;
    }
}

int RotaryEncoder::getLeftLaps(){
    return leftLaps;
}

int RotaryEncoder::getRightLaps(){
    return rightLaps;
}

int RotaryEncoder::getLeftCounts(){
    int lapBonus = leftLaps * LAP_MAX;
    int counts = leftCounts;
    return counts + lapBonus;
}

int RotaryEncoder::getRightCounts(){
    int lapBonus = rightLaps * LAP_MAX;
    int counts = rightCounts;
    return counts + lapBonus;
}

int RotaryEncoder::getRightCountsSubLaps(){
    return rightCounts;
}

int RotaryEncoder::getLeftCountsSubLaps(){
    return leftCounts;
}

void RotaryEncoder::reset(){
    rightCounts = 0;
    leftCounts = 0;
    rightLaps = 0;
    leftLaps = 0;
}

int RotaryEncoder::getMaxLap() {
    return LAP_MAX;
}

//
// Created by 後藤大介 on 2018/08/01.
//

#include "EncoderManager.h"

const float CAR_WIDE = 18;
const float WHEEL_RAD = 2.75;
const float CIR = WHEEL_RAD * 2 * PI;
const float CIR_WIDE = CAR_WIDE * 2 * PI;

float EncoderManager::getRightProDis() {
    return encoder.getRightCounts() * (CIR / encoder.getMaxLap());
}

float EncoderManager::getRightAngle() {
    int leftDis = getLeftProDis();
    leftDis *= (getLeftSpeed() > 0) ? 1 : -1;
    int rightDis = getRightProDis();
    rightDis *= (getRightSpeed() > 0) ? 1 : -1;

    int dif = leftDis - rightDis;
    if(dif == 0)
        return 0;
    return (dif / CIR_WIDE) * 360;
}

float EncoderManager::getLeftProDis() {
    return encoder.getLeftCounts() * (CIR / encoder.getMaxLap());
}

float EncoderManager::getLeftAngle() {
    int leftDis = getLeftProDis();
    leftDis *= (getLeftSpeed() > 0) ? 1 : -1;
    int rightDis = getRightProDis();
    rightDis *= (getRightSpeed() > 0) ? 1 : -1;

    int dif = rightDis - leftDis;
    if(dif == 0)
        return 0;
    return dif / CIR_WIDE * 360;
}

bool EncoderManager::turnRightTillCarAngle(int angle) {
    turnRight();
    encoder.encodeUpdate();
    return angle <= getRightAngle();
}

bool EncoderManager::turnLeftTillCarAngle(int angle) {
    turnLeft();
    encoder.encodeUpdate();
    return angle <= getLeftAngle();
}

void EncoderManager::update() {
    encoder.encodeUpdate();
}

float EncoderManager::getProDis() {

}

void EncoderManager::goForwardTillProDis(int distance) {

}
void EncoderManager::reset() {
    encoder.reset();
}
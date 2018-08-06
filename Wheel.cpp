//
// Created by 後藤大介 on 2018/06/06.
//

#include "Wheel.h"
#include "Pins.h"
#include <Arduino.h>

/*
 * 右前進：6ピン
 * 右後退：7ピン
 * 左前進：5ピン
 * 左後退：4ピン
 */


//速さ
const int SPEED = 100;

int currentRightSpeed = 0;
int currentLeftSpeed = 0;

//前進
void moveForward(){
    analogWrite(MOTOR_RIGHT_F,SPEED);
    analogWrite(MOTOR_RIGHT_B,0);
    analogWrite(MOTOR_LEFT_F,SPEED);
    analogWrite(MOTOR_LEFT_B,0);

    currentRightSpeed = SPEED;
    currentLeftSpeed = SPEED;
}

//右旋回
void turnRight(){
    analogWrite(MOTOR_RIGHT_F,0);
    analogWrite(MOTOR_RIGHT_B,0);
    analogWrite(MOTOR_LEFT_F,SPEED);
    analogWrite(MOTOR_LEFT_B,0);

    currentRightSpeed = 0;
    currentLeftSpeed = SPEED;
}

//右回転
void spinRight(){
    analogWrite(MOTOR_RIGHT_F,0);
    analogWrite(MOTOR_RIGHT_B,SPEED);
    analogWrite(MOTOR_LEFT_F,SPEED);
    analogWrite(MOTOR_LEFT_B,0);

    currentRightSpeed = -SPEED;
    currentLeftSpeed = SPEED;
}

//左旋回
void turnLeft(){
    analogWrite(MOTOR_RIGHT_F,SPEED);
    analogWrite(MOTOR_RIGHT_B,0);
    analogWrite(MOTOR_LEFT_F,0);
    analogWrite(MOTOR_LEFT_B,0);

    currentRightSpeed = SPEED;
    currentLeftSpeed = 0;
}

void spinLeft(){
    analogWrite(MOTOR_RIGHT_F,SPEED);
    analogWrite(MOTOR_RIGHT_B,0);
    analogWrite(MOTOR_LEFT_F,0);
    analogWrite(MOTOR_LEFT_B,SPEED);

    currentRightSpeed = SPEED;
    currentLeftSpeed = -SPEED;
}

int getRightSpeed(){
    return currentRightSpeed;
}

int getLeftSpeed(){
    return currentLeftSpeed;
}

void stop(){
    analogWrite(MOTOR_RIGHT_F,0);
    analogWrite(MOTOR_RIGHT_B,0);
    analogWrite(MOTOR_LEFT_F,0);
    analogWrite(MOTOR_LEFT_B,0);

}
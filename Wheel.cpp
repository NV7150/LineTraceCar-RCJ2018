//
// Created by 後藤大介 on 2018/06/06.
//

#include "Wheel.h"
#include <Arduino.h>

/*
 * 右前進：6ピン
 * 右後退：7ピン
 * 左前進：5ピン
 * 左後退：4ピン
 */
const int RIGHT_F = 7;
const int RIGHT_B = 6;
const int LEFT_F = 4;
const int LEFT_B = 5;

//速さ
const int SPEED = 100;

int currentRightSpeed = 0;
int currentLeftSpeed = 0;

//前進
void moveForward(){
    analogWrite(RIGHT_F,SPEED);
    analogWrite(RIGHT_B,0);
    analogWrite(LEFT_F,SPEED);
    analogWrite(LEFT_B,0);

    currentRightSpeed = SPEED;
    currentLeftSpeed = SPEED;
}

//右旋回
void turnRight(){
    analogWrite(RIGHT_F,0);
    analogWrite(RIGHT_B,0);
    analogWrite(LEFT_F,SPEED);
    analogWrite(LEFT_B,0);

    currentRightSpeed = 0;
    currentLeftSpeed = SPEED;
}

//右回転
void spinRight(){
    analogWrite(RIGHT_F,0);
    analogWrite(RIGHT_B,SPEED);
    analogWrite(LEFT_F,SPEED);
    analogWrite(LEFT_B,0);

    currentRightSpeed = -SPEED;
    currentLeftSpeed = SPEED;
}

//左旋回
void turnLeft(){
    analogWrite(RIGHT_F,SPEED);
    analogWrite(RIGHT_B,0);
    analogWrite(LEFT_F,0);
    analogWrite(LEFT_B,0);

    currentRightSpeed = SPEED;
    currentLeftSpeed = 0;
}

void spinLeft(){
    analogWrite(RIGHT_F,SPEED);
    analogWrite(RIGHT_B,0);
    analogWrite(LEFT_F,0);
    analogWrite(LEFT_B,SPEED);

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
    analogWrite(RIGHT_F,0);
    analogWrite(RIGHT_B,0);
    analogWrite(LEFT_F,0);
    analogWrite(LEFT_B,0);

}
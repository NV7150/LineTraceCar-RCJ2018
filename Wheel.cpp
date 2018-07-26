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
const int SPEED = 255;

const int STOP_LIMIT = 100000;

int stopCount = 0;

//前進
void moveForward(){
    analogWrite(RIGHT_F,SPEED);
    analogWrite(RIGHT_B,0);
    analogWrite(LEFT_F,SPEED);
    analogWrite(LEFT_B,0);
    stopCount = 0;
}

//右旋回
void turnRight(){
    analogWrite(RIGHT_F,0);
    analogWrite(RIGHT_B,0);
    analogWrite(LEFT_F,SPEED);
    analogWrite(LEFT_B,0);
    stopCount = 0;
    stopCount = 0;
}
//左旋回
void turnLeft(){
    analogWrite(RIGHT_F,SPEED);
    analogWrite(RIGHT_B,0);
    analogWrite(LEFT_F,0);
    analogWrite(LEFT_B,0);
    stopCount = 0;
}

//停止
void stop(){
    stopCount++;
//    if(stopCount >= STOP_LIMIT) {
//        analogWrite(RIGHT_F, 0);
//        analogWrite(RIGHT_B, 0);
//        analogWrite(LEFT_F, 0);
//        analogWrite(LEFT_B, 0);
//    }
}
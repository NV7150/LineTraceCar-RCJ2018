//
// Created by 後藤大介 on 2018/07/25.
//

#include "Sensor.h"
#include <Arduino.h>

Color preRight;
Color preLeft;
Color preCenter;
Color preMostRight;
Color preMostLeft;

Color right;
Color left;
Color center;
Color mostRight;
Color mostLeft;

bool isRGreen;
bool isLGreen;

//ピン定義
const int M_RIGHT = A0;
const int RIGHT = A1;
const int CENTER = A2;
const int LEFT = A3;
const int M_LEFT = A4;

//しきい値
const int BORDER_LINE_WHITE = 400;

//デバッグ
void printDebug(int,int,int,int,int);

void preProcessUpdate(){
    sensorUpdate();
    rightLeftGreenUpdate();
}

void aftProcessUpdate(){
    preColUpdate();
}

//赤外線センサの値を更新
void sensorUpdate() {
    //値読み取り
    int rightVal = analogRead(RIGHT);
    int leftVal = analogRead(LEFT);
    int centerVal = analogRead(CENTER);
    int mRVal = analogRead(M_RIGHT);
    int mLVal = analogRead(M_LEFT);

    printDebug(rightVal,leftVal,centerVal,mRVal,mLVal);

    right = judgeColor(rightVal);
    left = judgeColor(leftVal);
    center = judgeColor(centerVal);
    mostRight = judgeColor(mRVal);
    mostLeft = judgeColor(mLVal);
}

//緑判断の更新
void rightLeftGreenUpdate(){
    //まだカラセン届いてない
    isLGreen = false;
    isRGreen = false;
}

//過去記録の更新
void preColUpdate(){
    preLeft = left;
    preRight = right;
    preCenter = center;
    preMostRight = mostRight;
    preMostLeft = mostLeft;
}

//色判断
Color judgeColor(int val){
    if(val <= BORDER_LINE_WHITE){
        return BLACK;
    }else if(BORDER_LINE_WHITE < val){
        return WHITE;
    }
}

//各値のgetter//

Color getPreRight(){
    return preRight;
}

Color getPreMostRight(){
    return preMostRight;
}

Color getPreLeft(){
    return preLeft;
}

Color getPreMostLeft(){
    return preMostLeft;
}

Color getPreCenter(){
    return preCenter;
}

Color getRight(){
    return right;
}

Color getLeft(){
    return left;
}

Color getCenter(){
    return center;
}

Color getMostRight(){
    return mostRight;
}

Color getMostLeft(){
    return mostLeft;
}

bool isRightGreen(){
    return isRGreen;
}

bool isLeftGreen(){
    return isLGreen;
}
//ここまで//

void printDebug(int right,int left,int center,int mostRight,int mostLeft){
    Serial.print("most right : ");
    Serial.print(mostRight);
    Serial.print(" right:");
    Serial.print(right);
    Serial.print(" center : ");
    Serial.print(center);
    Serial.print(" left:");
    Serial.print(left);
    Serial.print(" most left : ");
    Serial.print(mostLeft);
    Serial.print("\n");
}
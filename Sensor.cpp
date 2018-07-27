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

int integration = 50;

//ピン定義
const int M_RIGHT = A0;
const int RIGHT = A1;
const int CENTER = A2;
const int LEFT = A3;
const int M_LEFT = A4;

const int COLOR_R_DOUT;
const int COLOR_R_RANGE;
const int COLOR_R_CK;
const int COLOR_R_GATE;

const int COLOR_L_DOUT;
const int COLOR_L_RANGE;
const int COLOR_L_CK;
const int COLOR_L_GATE;

//しきい値
const int BORDER_LINE_WHITE = 400;

const int BORDER_LINE_GREEN = 3000;

//デバッグ
void printDebug(int,int,int,int,int);

void colorSetUp(){
    pinMode(COLOR_R_DOUT,INPUT);
    pinMode(COLOR_R_RANGE,OUTPUT);
    pinMode(COLOR_R_CK,OUTPUT);
    pinMode(COLOR_R_GATE,OUTPUT);

    pinMode(COLOR_L_DOUT,INPUT);
    pinMode(COLOR_L_RANGE,OUTPUT);
    pinMode(COLOR_L_CK,OUTPUT);
    pinMode(COLOR_L_GATE,OUTPUT);
}


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
    isRGreen = isGreen(COLOR_R_DOUT,COLOR_R_GATE,COLOR_R_CK,COLOR_R_RANGE);
    isLGreen = isGreen(COLOR_L_DOUT,COLOR_L_GATE,COLOR_L_CK,COLOR_L_RANGE);
}

//緑かどうか
bool isGreen(int doutPin,int gatePin,int ckPin,int rangePin){
    int red, green, blue;  // 測定した値を格納するための変

    digitalWrite(gatePin, LOW);        // GateとCKをLOWにする。
    digitalWrite(ckPin, LOW);
    digitalWrite(rangePin, HIGH);      // RangeをHIGHにする。

    digitalWrite(gatePin, HIGH);       // GateをHIGHにして測定開始。
    delay(integration);                // 測定時間だけ待つ。
    digitalWrite(gatePin, LOW);        // GateをLOWにして測定終了。
    delayMicroseconds(4);              // 4ミリ秒待つ。
    red = shiftIn12(doutPin, ckPin);   // 赤色の値を読む。
    delayMicroseconds(3);              // 3ミリ秒待つ。
    green = shiftIn12(doutPin, ckPin); // 緑色の値を読む。
    delayMicroseconds(3);              // 3ミリ秒待つ。
    blue = shiftIn12(doutPin, ckPin);  // 青色の値を読む。

    return green >= BORDER_LINE_GREEN;
}

//12ビットの値を読み込む関数(LSBから送信されるデータを想定)
int shiftIn12(int dataPin, int clockPin) {
    int value = 0;

    for (int i = 0; i < 12; i++) {
        digitalWrite(clockPin, HIGH);           // クロックをHIGHにする
        value |= digitalRead(dataPin) << i;     // データピンの値を読み取り、所定のビットを設定する。
        digitalWrite(clockPin, LOW);            // クロックピンをLOWにする。
    }

    return value;
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
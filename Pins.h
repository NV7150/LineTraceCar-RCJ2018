//
// Created by 後藤大介 on 2018/08/06.
//

#ifndef LINETRACECAR_PINS_H
#define LINETRACECAR_PINS_H

#include <Arduino.h>
/*
 * ピン
 *
 * 赤外線センサ：一番右から中央までA0~A2、それ以降はA13、A14
 * カラーセンサ：まだきめてない
 *
 * モータ
 * 右　前進：7　後退：6
 * 左　前進：4　後退：5
 *
 * ロリンコ
 * 右：A5　左：A6
 *
 * LED
 * まだきめてない（要素１つ以上ないとコンパイルエラー吐くので対策に25を入れてる）
 */

//センサ関係
const int SENSOR_M_RIGHT = A0;
const int SENSOR_RIGHT = A1;
const int SENSOR_CENTER = A2;
const int SENSOR_LEFT = A13;
const int SENSOR_M_LEFT = A14;

const int COLOR_R_DOUT;
const int COLOR_R_RANGE;
const int COLOR_R_CK;
const int COLOR_R_GATE;

const int COLOR_L_DOUT;
const int COLOR_L_RANGE;
const int COLOR_L_CK;
const int COLOR_L_GATE;

//モータ関係
const int MOTOR_RIGHT_F = 7;
const int MOTOR_RIGHT_B = 6;
const int MOTOR_LEFT_F = 4;
const int MOTOR_LEFT_B = 5;

//ロリコン関係
const int RE_RIGHT_PIN = A5;
const int RE_LEFT_PIN = A6;

//LED関係(配列)
const int PIN_LEDS[] = {25};

#endif //LINETRACECAR_PINS_H

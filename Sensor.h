//
// Created by 後藤大介 on 2018/07/25.
//

#ifndef LINETRACECAR_SENCER_H
#define LINETRACECAR_SENCER_H

#include "Color.h"

void preProcessUpdate();
void aftProcessUpdate();

void sensorUpdate();
void rightLeftGreenUpdate();
void preColUpdate();

bool isGreen(int,int,int,int);
int shiftIn12(int dataPin, int clockPin);

Color judgeColor(int);

Color getPreRight();
Color getPreLeft();
Color getPreCenter();
Color getPreMostRight();
Color getPreMostLeft();

Color getRight();
Color getLeft();
Color getCenter();
Color getMostRight();
Color getMostLeft();

bool isRightGreen();
bool isLeftGreen();

#endif //LINETRACECAR_SENCER_H

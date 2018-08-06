#include <Arduino.h>
#include "Wheel.h"
#include "Processor.h"
#include "LED.h"
#include "EncoderManager.h"

void linetrace();
void spin90();
void spinback90();

void printCommand(int);

bool a;
bool b;

bool reseted = false;
EncoderManager encoMan;

void setup() {
    Serial.begin(9600);
//    setupLED();
//    flashLED();
}

void loop() {
//    if(!a){
//        spin90();
//    }else{
//        if(!reseted){
//            encoMan.reset();
//            reseted = true;
//        }
//        if(!b) {
//            spinback90();
//        }else {
//            stop();
//        }
//    }
//    moveForward();
    linetrace();
    //動かない場合はディレイを消す
//    delay(50);
//    stop();
}

void spin90(){
    if(encoMan.turnLeftTillCarAngle(180))
         a = true;
}

void spinback90(){
    if(encoMan.turnRightTillCarAngle(180))
        b = true;
}

void linetrace(){
    Command command = updateCommand();
//    printCommand(command);
    switch (command){
        case MOVE_FORWARD :
            moveForward();
            break;

        case TURN_RIGHT :
            spinRight();
            break;

        case TURN_LEFT :
            spinLeft();
            break;

        case NONE :
            break;
    }

}

void printCommand(int val){
    Serial.print("command : ");
    switch (val){
        case MOVE_FORWARD:
            Serial.print("前進");
            break;
        case TURN_RIGHT:
            Serial.print("右");
            break;
        case TURN_LEFT :
            Serial.print("左");
            break;
        default:
            Serial.print("前の動作を反復");
    }
    Serial.print("\n");

}

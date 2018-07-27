#include <Arduino.h>
#include "Wheel.h"
#include "Processor.h"
#include "LED.h"

void linetrace();

void printCommand(int);

void setup() {
    Serial.begin(9600);
    setupLED();
    flashLED();
}

void loop() {
//    moveForward();
    linetrace();
    //動かない場合はディレイを消す
//    delay(50);
}

void linetrace(){
    Command command = updateCommand();
    printCommand(command);
    switch (command){
        case MOVE_FORWARD :
            moveForward();
            break;

        case TURN_RIGHT :
            turnRight();
            break;

        case TURN_LEFT :
            turnLeft();
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

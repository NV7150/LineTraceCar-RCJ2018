//
// Created by 後藤大介 on 2018/07/27.
//

#include "LED.h"
#include <Arduino.h>
#include "Pins.h"

void setupLED(){
    for(int i = 0;i < (sizeof(PIN_LEDS) / sizeof(PIN_LEDS[0]));i++){
        pinMode(PIN_LEDS[i],OUTPUT);
    }
}

void flashLED(){
    for(int i = 0;i < (sizeof(PIN_LEDS) / sizeof(PIN_LEDS[0]));i++){
        digitalWrite(PIN_LEDS[i],HIGH);
    }
}

void darkLED(){
    for(int i = 0;i < (sizeof(PIN_LEDS) / sizeof(PIN_LEDS[0]));i++){
        digitalWrite(PIN_LEDS[i],LOW);
    }
}
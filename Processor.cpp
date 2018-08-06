//
// Created by 後藤大介 on 2018/07/25.
//

#include "Processor.h"
#include "Sensor.h"
#include "Pins.h"
#include <Arduino.h>

bool isKeeping = false;
bool isKeepingGreen = false;
Command keepingCom;

bool goRightGreen = false;
bool goLeftGreen = false;

bool isForwardLocked = false;

Command updateCommand(){
    //プロセス前のアップデート
    preProcessUpdate();

    updateGreenFlag();

    Command com;
    if(isKeeping){
        com = branchKeep();
    }else{
        com = branchLR();
    }

    //プロセス後のアップデート
    aftProcessUpdate();
    return com;
}

void updateGreenFlag(){
    //右が緑ならフラグを立てる
    if(isRightGreen()){
        goRightGreen = true;
    }
    //左が緑ならフラグを立てる
    if(isLeftGreen()){
        goLeftGreen = true;
    }
    //右が白ならフラグをなくす
    if(getRight() == WHITE){
        goRightGreen = false;
    }
    //左が白ならフラグをなくす
    if(getLeft() == WHITE){
        goLeftGreen = false;
    }
}

Command branchKeep(){
    //ロックを確認
    if(!isForwardLocked) {
        bool isEndKeeping = false;
        if(isKeepingGreen){
            //緑フラグが立っていたら中央のみに絞る
            isEndKeeping = (getCenter() == BLACK && getLeft() == WHITE && getRight() == WHITE);
        }else/* if(keepingCom == MOVE_FORWARD)*/{
            //前進ならどこでもおk
            isEndKeeping = (getCenter() == BLACK || getLeft() == BLACK || getRight() == BLACK);
        }/* else {
            //それ以外は中央が黒ならば
            isEndKeeping = (getCenter() == BLACK);
        }*/

        if (isEndKeeping) {
            //前進できる状態に復帰
            isKeeping = false;

            //通常ループへ
            return branchLR();
        }

        if(keepingCom == TURN_LEFT && !isKeepingGreen){
            if(getMostRight() == BLACK){
                return TURN_RIGHT;
            }
        }

        if(keepingCom == TURN_RIGHT && !isKeepingGreen){
            if(getMostLeft() == BLACK){
                return TURN_LEFT;
            }
        }

    }else{
        //一度白になったらロックを解除
        isForwardLocked = (getCenter() == WHITE);
    }
    //前動作を継続
    return NONE;
}


Command  branchLR(){
    if(getRight() == BLACK && getLeft() == WHITE){
        isKeeping = true;
        return TURN_RIGHT;
    }else if(getLeft() == BLACK && getRight() == WHITE){
        isKeeping = true;
        return TURN_LEFT;
    }
    return branchAllWhite();
}


//中央が黒かつ前進でない場合の分岐
Command branchCBLR(){
    if(getCenter() == BLACK){
        if(getRight() == BLACK || getLeft() == BLACK){
            if(goRightGreen){
                //進行フラグ：緑をもとにしたものなので緑進行フラグをつける
                isKeeping = true;
                isKeepingGreen = true;

                //ト型の場合、中央がすでに黒になっている可能性
                isForwardLocked = true;
                return TURN_RIGHT;
            }else if(goLeftGreen){
                //進行フラグ：緑をもとにしたものなので緑進行フラグをつける
                isKeeping = true;
                isKeepingGreen = true;

                //ト型の場合、中央がすでに黒になっている可能性
                isForwardLocked = true;

                return TURN_LEFT;
            }
        }
    }
    return branchAllWhite();
}

//全部白の分岐
Command branchAllWhite(){
    //全部白ならば
    if(getCenter() == WHITE && getRight() == WHITE && getLeft() == WHITE){
        // １ループ前の色を参照して進行フラグを確認
       if(getPreMostRight() == BLACK || getMostRight() == BLACK){
           //進行フラグを立てる
           isKeeping = true;
            return TURN_RIGHT;
        }else if(getPreMostLeft() == BLACK || getMostLeft() == BLACK){
           //進行フラグを立てる
           isKeeping = true;
            return TURN_LEFT;
        }else if(getPreCenter() == BLACK){
           //進行フラグを立てる
           isKeeping = true;
            return MOVE_FORWARD;
        }else{
           return exception("allWhite");
       }
    }
    return branchForward();
}

//前進の分岐
Command branchForward(){
    //中心が黒なら進む
    if(getCenter() == BLACK){
        return MOVE_FORWARD;
    }
    return exception("branchForward");
}

//例外処理
Command exception(char message[]){
    Serial.print("Exception!");

    Serial.print(" message : ");
    Serial.print(message);
    Serial.print("\n");
    return NONE;
}
//
// Created by 後藤大介 on 2018/07/25.
//

#ifndef LINETRACECAR_PROCESSOR_H
#define LINETRACECAR_PROCESSOR_H
enum Command{
    MOVE_FORWARD,
    TURN_RIGHT,
    TURN_LEFT,
    NONE
};

Command updateCommand();
Command branchKeep();
Command branchLR();
Command branchCBLR();
Command branchAllWhite();
Command branchForward();
Command exception(char[]);

void updateGreenFlag();

#endif //LINETRACECAR_PROCESSOR_H

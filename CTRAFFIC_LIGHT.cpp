#include"CTRAFFIC_LIGHT.h"
#include"Console.h"
#include<iostream>
#include<stdio.h>
using namespace std;

CTRAFFIC_LIGHT::CTRAFFIC_LIGHT(){
    mWidth = 1;
    mHeight = 2;
    state = COLOR::green;
    coutingTime = 0;
    timeInterval = 15;
    mX = X_START + 1; // estimated
    mY = 2;
}

CTRAFFIC_LIGHT::CTRAFFIC_LIGHT(int x , int y, int timeInterval){
    mWidth = 1;
    mHeight = 2;
    state = COLOR::green;
    mX = X_START + 1; // estimated
    coutingTime = 0;


    this->timeInterval = timeInterval;
    mY = y;
    mX = x;
}

void CTRAFFIC_LIGHT::draw(char ch){ // ch = 254
    TextColor(GRAY);

    GotoXY(mX, mY);   // draw light above
    printf("%c",ch);

    GotoXY(mX, mY - 1); // draw light below
    printf("%c",ch);

    if(state == COLOR::red){
        TextColor(RED);
        GotoXY(mX, mY - 1); // paint red 
        printf("%c",ch);
    }
    else {
        TextColor(GREEN);
        GotoXY(mX, mY);   //  paint green
        printf("%c",ch);
    }
}

void CTRAFFIC_LIGHT::updateState(char ch){
    if(state == COLOR::green){
        state = COLOR::red;
    }
    else {
        state = COLOR::green;
    }
    this->draw(ch);

    TextColor(15); // set text back to white
}

void CTRAFFIC_LIGHT::increaseTime(){
    coutingTime++;

    if(coutingTime > timeInterval){
        updateState(254);
        coutingTime = 0;
    }
}

bool CTRAFFIC_LIGHT::isRed(){
    return this->state == COLOR::red;
}

int CTRAFFIC_LIGHT::getcountingTime() {
    return coutingTime;
}
int CTRAFFIC_LIGHT::getstate() {
    return state;
}
int CTRAFFIC_LIGHT::gettimeInterval() {
    return timeInterval;
}
void CTRAFFIC_LIGHT::updateLoadTraffic(int state,int countingTime,int timeInterval) {
    this->state = state;
    this->coutingTime = countingTime;
    this->timeInterval = timeInterval;
}
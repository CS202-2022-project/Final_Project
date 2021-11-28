#include"CTRAFFIC_LIGHT.h"
#include"Console.h"
#include<iostream>
#include<stdio.h>
using namespace std;

CTRAFFIC_LIGHT::CTRAFFIC_LIGHT(){
    m_width = 1;
    m_height = 2;
    state = COLOR::green;
    coutingTime = 0;
    timeInterval = 15;
    m_x = BOARD_X_START + 1; // estimated
    m_y = 2;
}

CTRAFFIC_LIGHT::CTRAFFIC_LIGHT(int x , int y, int timeInterval){
    m_width = 1;
    m_height = 2;
    state = COLOR::green;
    m_x = BOARD_X_START + 1; // estimated
    coutingTime = 0;


    this->timeInterval = timeInterval;
    m_y = y;
    m_x = x;
}

void CTRAFFIC_LIGHT::draw(char ch){ // ch = 254
    TextColor(GRAY);

    GotoXY(m_x, m_y);   // draw light above
    printf("%c",ch);

    GotoXY(m_x, m_y - 1); // draw light below
    printf("%c",ch);

    if(state == COLOR::red){
        TextColor(RED);
        GotoXY(m_x, m_y - 1); // paint red 
        printf("%c",ch);
    }
    else {
        TextColor(GREEN);
        GotoXY(m_x, m_y);   //  paint green
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

void CTRAFFIC_LIGHT::run(){
    coutingTime++;

    if(coutingTime > timeInterval){
        updateState(254);
        coutingTime = 0;
    }
}

bool CTRAFFIC_LIGHT::isRed(){
    return this->state == COLOR::red;
}
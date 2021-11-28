#include"CTRUCK.h"
#include"Console.h"
#include<iostream>
#include<stdio.h>
using namespace std;

CTRUCK::CTRUCK(){
    m_X = 0;
    m_Y = 0;
    m_width = 4;
    m_height = 2;
    m_trafficlight.CTRAFFIC_LIGHT::CTRAFFIC_LIGHT();
}

CTRUCK::CTRUCK(int x , int y){
    m_X = x;
    m_Y = y;
    m_width = 4;
    m_height = 2;
    m_trafficlight.CTRAFFIC_LIGHT::CTRAFFIC_LIGHT();
}

void CTRUCK::draw(char ch){
    if(isHitBorder())
        return ;
    
    for(int i = 0 ; i < m_width ; i++){
        GotoXY(m_X + i , m_Y);
        printf("%c",ch);
    }

    for(int i = 1 ; i < m_width - 1 ; i++){
        GotoXY(m_X + i , m_Y + 1);
        printf("%c",ch);
    }
}


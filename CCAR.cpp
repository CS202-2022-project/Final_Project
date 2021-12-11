#include"CCAR.h"
#include"Console.h"
#include<iostream>
#include<stdio.h>
using namespace std;


CCAR::CCAR(){
    mX = 0;
    mY = 0;
    sprite.push_back(" ___ ");
    sprite.push_back("/___\\");
}

CCAR::CCAR(int x, int y){
    mX = x;
    mY = y;
    sprite.push_back(" ___ ");
    sprite.push_back("/___\\");
}

void CCAR::draw(int x, int y){
    std::vector<std::string>::iterator ptr;
    for (ptr = sprite.begin(); ptr < sprite.end(); ptr++){
        GotoXY(x,y++);
        cout << *ptr;
    }
}
// FIRST EDITION
// CCAR::CCAR(){
//     m_X = 0;
//     m_Y = 0;
//     m_height = 2;
//     m_width = 3;
//     m_trafficlight.CTRAFFIC_LIGHT::CTRAFFIC_LIGHT();
// }

// CCAR::CCAR(int x, int y){
//     m_X = x;
//     m_Y = y;
//     m_width = 3;
//     m_height = 2;
//     m_trafficlight.CTRAFFIC_LIGHT::CTRAFFIC_LIGHT();
// }

// void CCAR::draw(char ch){
//     if(isHitBorder())
//         return;

//     for(int i = 0 ; i < m_width ; i++){
//         GotoXY(m_X + i , m_Y);
//         printf("%c",ch);
//     }

//     for(int i = 1 ; i < m_width ; i++){
//         GotoXY(m_X + i , m_Y + 1);
//         printf("%c",ch);
//     }
// }

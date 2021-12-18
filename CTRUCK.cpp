#include"CTRUCK.h"
#include"Console.h"
#include<iostream>
#include<stdio.h>
using namespace std;

CTRUCK::CTRUCK(){
    mX = 0;
    mY = 0;
    sprite.push_back("_____     ");
    sprite.push_back("|   |____ ");
    sprite.push_back("|        |");
    sprite.push_back("|__o__o__|");
}

CTRUCK::CTRUCK(int x, int y){
    mX = x;
    mY = y;
    sprite.push_back("_____     ");
    sprite.push_back("|   |____ ");
    sprite.push_back("|        |");
    sprite.push_back("|__o__o__|");
}

bool CTRUCK::Up(int step){
if (mY - step < Y_START) return false;
	GotoXY(mX, mY);
	deDraw();
	mY -= step;
	GotoXY(mX, mY);
	draw();
    return true;
}
bool CTRUCK::Down(int step){
if (mY + step + 2 > Y_END) return false;
	GotoXY(mX, mY);
	deDraw();
	mY += step;
	GotoXY(mX, mY);
	draw();
    return true;
}

void CTRUCK::draw(){
    vector<std::string>::iterator ptr;
    int i = 0;
    for (ptr = sprite.begin(); ptr < sprite.end(); ptr++, i++){
        GotoXY(mX,mY+i);
        cout << *ptr;
    }
}

void CTRUCK::deDraw() {
    int y = this->mY;
    for (int i = 0; i < 4; ++i) {
        GotoXY(mX, y + i);
        cout << "          ";
    }
}
// CTRUCK::CTRUCK(){
//     m_X = 0;
//     m_Y = 0;
//     m_width = 4;
//     m_height = 2;
//     m_trafficlight.CTRAFFIC_LIGHT::CTRAFFIC_LIGHT();
// }

// CTRUCK::CTRUCK(int x , int y){
//     m_X = x;
//     m_Y = y;
//     m_width = 4;
//     m_height = 2;
//     m_trafficlight.CTRAFFIC_LIGHT::CTRAFFIC_LIGHT();
// }

// void CTRUCK::draw(char ch){
//     if(isHitBorder())
//         return ;
    
//     for(int i = 0 ; i < m_width ; i++){
//         GotoXY(m_X + i , m_Y);
//         printf("%c",ch);
//     }

//     for(int i = 1 ; i < m_width - 1 ; i++){
//         GotoXY(m_X + i , m_Y + 1);
//         printf("%c",ch);
//     }
// }
int CTRUCK::getWidth() {
    int max = 0;
    vector<std::string>::iterator ptr;
    for (ptr = sprite.begin(); ptr < sprite.end(); ptr++) {
        if (ptr->length() > max) max = ptr->length();
    }
    return max;
}
int CTRUCK::getHeight() {
    return sprite.size();
}
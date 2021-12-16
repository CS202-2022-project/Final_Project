#include"CANIMAL.h"
#include<thread>

CANIMAL::CANIMAL():mX(0),mY(0){
}

void CANIMAL::Move(int x, int y){
  mX=x;
  mY=y;
  GotoXY(mX,mY);
}

int CANIMAL::getX() {
    return this->mX;
}
int CANIMAL::getY() {
    return this->mY;
}
void CANIMAL::deDraw(){
   for(int i=0;i<4;i++)
    {
        GotoXY(mX,mY+i);
        cout<<"     ";
    }
}


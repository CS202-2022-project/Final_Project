#include"CANIMAL.h"
#include<thread>

CANIMAL::CANIMAL():mX(0),mY(0){
}

void CANIMAL::Move(int x, int y){
  mX=x;
  mY=y;
  GotoXY(mX,mY);
}
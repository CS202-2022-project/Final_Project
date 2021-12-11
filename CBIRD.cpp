#include"CBIRD.h"

// it will cause the error if i draw the first design :((
CBIRD::CBIRD():CANIMAL(){
    string temp;
    temp ="__ __";
    sprite.push_back(temp);
    temp= " \\ / ";
    sprite.push_back(temp);
    temp="  o  ";
    sprite.push_back(temp);
}
/*
    _   _
     \ /
      o
        
*/
void CBIRD::draw(){
    for(int i=0;i<3;i++)
    {
        GotoXY(mX,mY+i);
        cout<<sprite[i];
    }
}
void CBIRD::tell(){
    bool played= PlaySound(TEXT("sounds/bird_roar.wav"),NULL,SND_ASYNC);
}

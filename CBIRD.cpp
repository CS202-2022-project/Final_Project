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
void CBIRD::Draw(){
    for(int i=0;i<3;i++)
    {
        GotoXY(mX,mY+i);
        cout<<sprite[i];
    }
}

void CBIRD::tell(){
    bool played= PlaySound(TEXT("sounds/bird_roar.wav"),NULL,SND_ASYNC);
}
bool CBIRD::Up(int step){
if (mY - step < Y_START) return false;
	GotoXY(mX, mY);
	deDraw();
	mY -= step;
	GotoXY(mX, mY);
	Draw();
    return true;
}
bool CBIRD::Down(int step){
if (mY + step + 1 > Y_END) return false;
	GotoXY(mX, mY);
	deDraw();
	mY += step;
	GotoXY(mX, mY);
	Draw();
    return true;
}
int CBIRD::getWidth() {
    int max = 0;
    vector<std::string>::iterator ptr;
    for (ptr = sprite.begin(); ptr < sprite.end(); ptr++) {
        if (ptr->length() > max) max = ptr->length();
    }
    return max;
}
int CBIRD::getHeight() {
    return sprite.size();
}
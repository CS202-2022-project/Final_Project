#include"CDINAUSOR.h"

CDINAUSOR::CDINAUSOR():CANIMAL(){
    string temp;
    temp ="__   ";
    sprite.push_back(temp);
    temp= "L_|_ ";
    sprite.push_back(temp);
    temp=" L__|";
    sprite.push_back(temp);
    temp="  I I";
    sprite.push_back(temp);
}

void CDINAUSOR::Draw(){
for(int i=0;i<4;i++)
    {
        GotoXY(mX,mY+i);
        cout<<sprite[i];
    }
    
}
bool CDINAUSOR::Up(int step){
if (mY - step < Y_START) return false;
	GotoXY(mX, mY);
	deDraw();
	mY -= step;
	GotoXY(mX, mY);
	Draw();
    return true;
}
bool CDINAUSOR::Down(int step){
if (mY + step + 2 > Y_END) return false;
	GotoXY(mX, mY);
	deDraw();
	mY += step;
	GotoXY(mX, mY);
	Draw();
    return true;
}
void CDINAUSOR::tell(){
    bool played= PlaySound(TEXT("sounds/trex_road.wav"),NULL,SND_ASYNC);
}

int CDINAUSOR::getWidth() {
    int max = 0;
    vector<std::string>::iterator ptr;
    for (ptr = sprite.begin(); ptr < sprite.end(); ptr++) {
        if (ptr->length() > max) max = ptr->length();
    }
    return max;
}
int CDINAUSOR::getHeight() {
    return sprite.size();
}
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

void CDINAUSOR::draw(){
for(int i=0;i<4;i++)
    {
        GotoXY(mX,mY+i);
        cout<<sprite[i];
    }
    
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
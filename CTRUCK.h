#ifndef _CTRUCK_H_
#define _CTRUCK_H_

#include"CVEHICLE.h"

class CTRUCK : public CVEHICLE{
public:
    CTRUCK();
    CTRUCK(int x, int y);
    void draw();
    int getWidth();
    int getHeight();
    bool Up(int);
    bool Down(int);
    void deDraw();
    //void updatePos(int, int);
private:
    //std::vector<std::string> sprite;
};

#endif
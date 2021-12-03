#ifndef _CTRUCK_H_
#define _CTRUCK_H_

#include"CVEHICLE.h"
#include<vector>

class CTRUCK : public CVEHICLE{
public:
    CTRUCK();
    CTRUCK(int x, int y);
    void draw(int x, int y);
    //void updatePos(int, int);
private:
    vector<string> sprite;
};

#endif
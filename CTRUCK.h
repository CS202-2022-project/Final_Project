#ifndef _CTRUCK_H_
#define _CTRUCK_H_

#include"CVEHICLE.h"
class CTRUCK : public CVEHICLE{
public:
    CTRUCK();
    CTRUCK(int y, int x);
    void draw(char ch);
    void updatePos(int, int);
};

#endif
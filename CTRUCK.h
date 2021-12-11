#ifndef _CTRUCK_H_
#define _CTRUCK_H_

#include"CVEHICLE.h"
#include<vector>
#include<string>

class CTRUCK : public CVEHICLE{
public:
    CTRUCK();
    CTRUCK(int x, int y);
    void draw();
    //void updatePos(int, int);
private:
    std::vector<std::string> sprite;
};

#endif
#ifndef _CCAR_H_

#define _CCAR_H_

#include"CVEHICLE.h"

class CCAR : public CVEHICLE{
public:
    CCAR();
    CCAR(int x, int y);
    void draw();
    int getWidth();
    int getHeight();
    void deDraw();
    bool Up(int);
    bool Down(int);
    //void updatePos(int, int);
private:
    //std::vector<std::string> sprite ;
};

#endif
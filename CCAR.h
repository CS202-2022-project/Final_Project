#ifndef _CCAR_H_

#define _CCAR_H_

#include"CVEHICLE.h"

class CCAR : public CVEHICLE{
public:
    CCAR();
    CCAR(int x, int y);
    void draw(char ch);
    void updatePos(int, int);
};

#endif
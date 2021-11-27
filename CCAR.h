#ifndef _CCAR_H_

#define _CCAR_H_

#include"CVEHICLE.h"

class CCAR : public CVEHICLE{
public:
    CCAR();
    CCAR(int y);
    void draw(char ch);
};

#endif
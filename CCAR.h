#ifndef _CCAR_H_

#define _CCAR_H_

#include"CVEHICLE.h"
#include<vector>

class CCAR : public CVEHICLE{
public:
    CCAR();
    CCAR(int x, int y);
    void draw(int x, int y);
    //void updatePos(int, int);
private:
    vector<string> sprite ;
};

#endif
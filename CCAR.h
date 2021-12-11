#ifndef _CCAR_H_

#define _CCAR_H_

#include"CVEHICLE.h"
#include<vector>
#include<string>

class CCAR : public CVEHICLE{
public:
    CCAR();
    CCAR(int x, int y);
    void draw(int x, int y);
    //void updatePos(int, int);
private:
    std::vector<std::string> sprite ;
};

#endif
#ifndef _CVEHICLE_H_
#define _CVEHICLE_H_

#include"CTRAFFIC_LIGHT.h"

class CVEHICLE{
public:
    bool isStop();
    void updatePos(int, int);
    virtual void draw();
protected:
    int mX, mY;
    int m_width, m_height;
    CTRAFFIC_LIGHT m_trafficlight;
};

#endif
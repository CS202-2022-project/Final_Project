#ifndef _CVEHICLE_H_
#define _CVEHICLE_H_

#include"CTRAFFIC_LIGHT.h"

class CVEHICLE{
public:
    bool isStop();
    void drawTrafficLight(const CTRAFFIC_LIGHT& tLight);
    //bool isHitBorder();
    void move(int x, int y);
    virtual void draw(int x, int y) = 0;
protected:
    int mX, mY;    // the bottom left point
    // int m_width, m_height;
    CTRAFFIC_LIGHT m_trafficlight;
};

#endif
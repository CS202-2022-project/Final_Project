#ifndef _CVEHICLE_H_
#define _CVEHICLE_H_

#include <string>
#include <vector>

#include"CTRAFFIC_LIGHT.h"

class CVEHICLE{
public:
    bool isStop();
    void drawTrafficLight(const CTRAFFIC_LIGHT& tLight);
    //bool isHitBorder();
    void move(int x, int y);
    virtual void draw() = 0;
    virtual void deDraw() = 0;
    int getX();
    int getY();
    virtual int getWidth() = 0;
    virtual int getHeight() = 0;
    friend class CPEOPLE;
    
protected:
    int mX, mY;    // the top left point
    // int m_width, m_height;
    CTRAFFIC_LIGHT m_trafficlight;
    std::vector<std::string> sprite;
};

#endif
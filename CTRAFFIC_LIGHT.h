#ifndef _CTRAFFIC_LIGHT_H_
#define _CTRAFFIC_LIGHT_H_


#define GRAY 7
#define RED 12
#define GREEN 10

class CTRAFFIC_LIGHT {
private:
    enum COLOR{red,green};
    int state;     // 0:RED OR 1:GREEN
    int coutingTime;
    int timeInterval;
    int m_x, m_y;
    int m_width, m_height;
public:
    CTRAFFIC_LIGHT();
    CTRAFFIC_LIGHT(int x, int y , int timeInterval);
    void increaseTime();
    void draw(char);
    void updateState(char ch);
    bool isRed();
};

#endif

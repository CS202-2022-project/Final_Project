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
    int mX, mY;
    int mWidth, mHeight;
    friend class CPEOPLE;
    
public:
    CTRAFFIC_LIGHT();
    CTRAFFIC_LIGHT(int x, int y , int timeInterval);
    void increaseTime(); //This is the function to increase the time of shifting color of traffic light
    void draw(char); //This is to draw up the traffic light onto the screen
    void updateState(char ch); //This is to update the current state of the traffic light
    bool isRed(); // This is to check if the traffic light is red or not currently
    int getcountingTime(); // This is to get the counting time
    int gettimeInterval(); // This is the function to get the time interval
    int getstate(); //This is the function to get the current state
    void updateLoadTraffic(int, int, int); // This is the function to update the traffic light
};

#endif

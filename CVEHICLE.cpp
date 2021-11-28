#include"Console.h"
#include"CVEHICLE.h"
#include<iostream>
#include<stdio.h>
using namespace std;

bool CVEHICLE::isStop(){
    return this->m_trafficlight.isRed();
}

void CVEHICLE::drawTrafficLight(const CTRAFFIC_LIGHT& tLight){
    this->m_trafficlight = tLight;
    this->m_trafficlight.draw(254);
}

bool CVEHICLE::isHitBorder(){
    return (m_X == X_START + 1 || m_X + m_width == X_END);
}


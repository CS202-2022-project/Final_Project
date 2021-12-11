#ifndef _CANIMAL_H_
#define _CANIMAL_H_
#include<iostream>
#include<string>
#include<vector>
#include<windows.h>
#include<mmsystem.h>
#include"console.h"
using namespace std;

class CANIMAL {
protected:
	int mX, mY;
	vector<string> sprite;
public:
	CANIMAL();
    void Move(int x, int y);
	virtual void tell() =0;
	virtual void draw(int x, int y)=0;
};
#endif // !_CANIMAL_H_

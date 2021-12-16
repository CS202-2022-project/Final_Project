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
	int getX();
	int getY();
	void deDraw();
	virtual bool Up(int) =0;
	virtual bool Down(int) =0;
	virtual void tell() =0;
	virtual void Draw()=0;
	virtual int getWidth() = 0;
	virtual int getHeight() = 0;

	friend class CPEOPLE;
};
#endif // !_CANIMAL_H_

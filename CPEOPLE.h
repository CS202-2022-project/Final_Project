#ifndef cppl
#define cppl
#include"Console.h"
#include<iostream>
#include<vector>
using namespace std;

class CPEOPLE {
	int mX, mY;
	vector<string> sprite;
	bool mState;
public:
	CPEOPLE();
	void deDraw();
	void Draw();
	void Up(int);
	void Left(int);
	void Right(int);
	void Down(int);
	void Move(int x, int y);
	//bool isImpact(CVEHICLE* v);
	//bool isImpact(CANIMAL* v);
	bool isFinish(int);
	bool isDead();

	void setState(bool b);
};
#endif
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
	//bool isImpact(const CVEHICLE*&);
	//bool isImpact(const CANIMAL*&);
	bool isFinish();
	bool isDead();
};
#endif
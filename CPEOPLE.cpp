#include"CPEOPLE.h"
CPEOPLE::CPEOPLE() {
	mX = 0;
	mY = 0;
	mState = true;
};
void CPEOPLE::Up(int step) {
	if (mY == BOARD_STARTY) return;
	GotoXY(mX, mY);
	cout << " " << endl;
	mY -= step;
	GotoXY(mX, mY);
	cout << "Y" << endl;
}
void CPEOPLE::Left(int step){
	if (mX == BOARD_STARTX) return;
	GotoXY(mX, mY);
	cout << " " << endl;
	mX -= step;
	GotoXY(mX, mY);
	cout << "Y" << endl;
}
void CPEOPLE::Right(int step){
	if (mX == BOARD_ENDX) return;
	GotoXY(mX, mY);
	cout << " " << endl;
	mX += step;
	GotoXY(mX, mY);
	cout << "Y" << endl;
}
void CPEOPLE::Down(int step) {
	if (mX == BOARD_ENDY) return;
	GotoXY(mX, mY);
	cout << " " << endl;
	mY += step;
	GotoXY(mX, mY);
	cout << "Y" << endl;

}
//bool CPEOPLE::isImpact(const CVEHICLE*&);
//bool CPEOPLE::isImpact(const CANIMAL*&);
bool CPEOPLE::isFinish(){
	if (mY == BOARD_STARTY) return true;
	return false;
}
bool CPEOPLE::isDead() {
	return mState;
}
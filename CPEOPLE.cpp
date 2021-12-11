#include"CPEOPLE.h"
CPEOPLE::CPEOPLE() {
	mX = 20;
	mY = 20;
	mState = true;
	sprite.push_back("/ \\");
	sprite.push_back(" |\\");
	sprite.push_back("\\o ");	
};
void CPEOPLE::Draw() {
	int y = mY;
	for (int i = 0; i < 3; i++)
	{
		GotoXY(mX,y--);
		cout << sprite[i];
	}
}
void CPEOPLE::deDraw() {
	int y = mY;
	for (int i = 0; i < 3; i++)
	{
		GotoXY(mX, y--);
		cout << "   ";
	}
}
void CPEOPLE::Up(int step) {
	if (mY == Y_START) return;
	GotoXY(mX, mY);
	deDraw();
	mY -= step;
	GotoXY(mX, mY);
	Draw();
}
void CPEOPLE::Left(int step){
	if (mX == X_START) return;
	GotoXY(mX, mY);
	deDraw();
	mX -= step;
	GotoXY(mX, mY);
	Draw();
}
void CPEOPLE::Right(int step){
	if (mX == X_END) return;
	GotoXY(mX, mY);
	deDraw();
	mX += step;
	GotoXY(mX, mY);
	Draw();
}
void CPEOPLE::Down(int step) {
	if (mX == Y_END) return;
	GotoXY(mX, mY);
	deDraw();
	mY += step;
	GotoXY(mX, mY);
	Draw();

}
//bool CPEOPLE::isImpact(const CVEHICLE*&);
//bool CPEOPLE::isImpact(const CANIMAL*&);
bool CPEOPLE::isFinish(){
	if (mY == Y_START) return true;
	return false;
}
bool CPEOPLE::isDead() {
	return mState;
}
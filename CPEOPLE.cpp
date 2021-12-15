#include"CPEOPLE.h"
#include"CVEHICLE.h"
#include"CANIMAL.h"
CPEOPLE::CPEOPLE() {
	mX = 0;
	mY = 0;
	mState = true;
	sprite.push_back("  o  ");	
	sprite.push_back("--|--");
	sprite.push_back(" / \\ ");
};
void CPEOPLE::Draw() {
	int y = mY;
	for (int i = 0; i < 3; i++)
	{
		GotoXY(mX, y + i);
		cout << sprite[i];
	}
}
void CPEOPLE::deDraw() {
	int y = mY;
	for (int i = 0; i < 3; i++)
	{
		GotoXY(mX, y + i);
		cout << "     ";
	}
}
void CPEOPLE::Up(int step) {
	if (mY - step < Y_START) return;
	GotoXY(mX, mY);
	deDraw();
	mY -= step;
	GotoXY(mX, mY);
	Draw();
}
void CPEOPLE::Left(int step){
	if (mX - step < X_START) return;
	GotoXY(mX, mY);
	deDraw();
	mX -= step;
	GotoXY(mX, mY);
	Draw();
}
void CPEOPLE::Right(int step){
	if (mX + step > X_END) return;
	GotoXY(mX, mY);
	deDraw();
	mX += step;
	GotoXY(mX, mY);
	Draw();
}
void CPEOPLE::Down(int step) {
	if (mY + step + 1 > Y_END) return;
	GotoXY(mX, mY);
	deDraw();
	mY += step;
	GotoXY(mX, mY);
	Draw();

}

/*
bool CPEOPLE::isImpact(CVEHICLE* v) {
	for (int i = 0; i < 10; i++)	//estimated 10 vehicles
	{		
		if (this->mX+4 <= (v[i].getX() + v[i].getWidth() -1) && this->mX+4 >=v[i].getX() ||		//check if step in the lane
			(this->mX >= v[i].getX() && this->mX <= (v[i].getX() + v[i].getWidth() - 1)))		//check if still in the lane
		{	
				if (this->mY >= v[i].getY() && this->mY <= (v[i].getY() + v[i].getHeight() - 1) ||			//head got hit
					(this->mY + 2 >= v[i].getY() && this->mY + 2 <= (v[i].getY() + v[i].getHeight() - 1)))	//foot got hit
					return true;
		}
	}
	return false;
}
bool CPEOPLE::isImpact(CANIMAL* v) {
	for (int i = 0; i < 10; i++)	//estimated 10 vanimals
	{
		if (this->mX + 4 <= (v[i].getX() + v[i].getWidth() - 1) && this->mX + 4 >= v[i].getX() ||		//check if step in the lane
			(this->mX >= v[i].getX() && this->mX <= (v[i].getX() + v[i].getWidth() - 1)))				//check if still in the lane
		{
			if (this->mY >= v[i].getY() && this->mY <= (v[i].getY() + v[i].getHeight() - 1) ||				//head gets hit
				(this->mY + 2 >= v[i].getY() && this->mY + 2 <= (v[i].getY() + v[i].getHeight() - 1)))		//foot gets hit
				return true;
		}
	}
	return false;
}
*/

void CPEOPLE::Move(int x, int y) {
	GotoXY(mX, mY);
	deDraw();
	mX = x;
	mY = y;
	GotoXY(mX, mY);
	Draw();
}

bool CPEOPLE::isFinish(int x){
	if (mX >= x) return true;
	return false;
}
bool CPEOPLE::isDead() {
	return mState;
}

void CPEOPLE::setState(bool b) {
	mState = b;
}
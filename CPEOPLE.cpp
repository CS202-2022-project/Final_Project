#include"CPEOPLE.h"
CPEOPLE::CPEOPLE() {
	mX = 0;
	mY = 0;
	mState = true;
	sprite.push_back("  o  ");	
	sprite.push_back("--|--");
	sprite.push_back(" / \\ ");
};

int CPEOPLE::getX(){
	return mX;
}
int CPEOPLE::getY(){
	return mY;
}
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

// Code nay hoi dai, nen t sua lai the nay cho ngan hon nhe
// CPEOPLE la friend class cua CVEHICLE va CANIMAL
// Lonk >:(

bool CPEOPLE::isImpact(CVEHICLE* v) {
	for (int i = 0; i < sprite.size(); i++)				// loop people sprite row
		for (int j = 0; j < sprite[i].size(); j++)			// loop column sprite row
			for (int x = 0; x < v -> sprite.size(); x++)		// loop vehicle sprite row
				for (int y = 0; y < v -> sprite[x].size(); y++)	// loop vehicle sprite column
					if (mX + j == v->mX + y && mY + i == v->mY + x && sprite[i][j] != ' ' && v -> sprite[x][y] != ' ')	// check if conflict with a valid sprite
						return true;
	return false;
}
bool CPEOPLE::isImpact(CANIMAL* v) {
	for (int i = 0; i < sprite.size(); i++)				// loop people sprite row
		for (int j = 0; j < sprite[i].size(); j++)			// loop column sprite row
			for (int x = 0; x < v -> sprite.size(); x++)		// loop animal sprite row
				for (int y = 0; y < v -> sprite[x].size(); y++)	// loop animal sprite column
					if (mX + j == v->mX + y && mY + i == v->mY + x && sprite[i][j] != ' ' && v -> sprite[x][y] != ' ')	// check if conflict with a valid sprite
						return true;
	return false;
}


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
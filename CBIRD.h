#ifndef _CBIRD_H_
#define _CBIRD_H_
#include "CANIMAL.h"

class CBIRD :public CANIMAL {
public:
	CBIRD();
	void Draw(); //This is for the sound of bird
	bool Up(int); // This is to draw up the bird on the screen
	bool Down(int); // This is for the moving up of the bird
	void tell(); //This is for the moving down of the bird
	int getWidth();  // This is to get width of the bird's position
	int getHeight();// This is to get height of the bird's position
}; 
#endif // !_CBIRD_H_

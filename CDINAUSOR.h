#ifndef _CDINAUSOR_H_
#define _CDINAUSOR_H_
#include "CANIMAL.h"

class CDINAUSOR : public CANIMAL {
public:
	CDINAUSOR();
	void tell(); //This is for the sound of dinausor
	void Draw(); // This is to draw up the dinausor on the screen
	bool Up(int); // This is for the moving up of the dinausor
	bool Down(int); //This is for the moving down of the dinausor
	int getWidth(); // This is to get width of the dinausor's position
	int getHeight(); // This is to get height of the dinausor's position
};
#endif // !_CDINAUSOR_H_

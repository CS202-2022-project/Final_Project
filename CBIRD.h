#ifndef _CBIRD_H_
#define _CBIRD_H_
#include "CANIMAL.h"

class CBIRD :public CANIMAL {
public:
	CBIRD();
	void Draw();
	void Up(int);
	void Down(int);
	void tell();
	int getWidth();
	int getHeight();
};
#endif // !_CBIRD_H_

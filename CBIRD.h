#ifndef _CBIRD_H_
#define _CBIRD_H_
#include "CANIMAL.h"

class CBIRD :public CANIMAL {
public:
	CBIRD();
	void draw(int x, int y);
	void tell();
};
#endif // !_CBIRD_H_

#ifndef _CBIRD_H_
#define _CBIRD_H_
#include "CANIMAL.h"

class CBIRD :public CANIMAL {
private:
	int m_width, m_height;
public:
	CBIRD();
	void draw(char);
	void Upheight(int);
	void Downheight(int);
};
#endif // !_CBIRD_H_

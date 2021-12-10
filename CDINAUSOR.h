#ifndef _CDINAUSOR_H_
#define _CDINAUSOR_H_
#include "CANIMAL.h"

class CDINAUSOR : public CANIMAL {
public:
	CDINAUSOR();
	void tell();
	void draw(int x, int y);
};
#endif // !_CDINAUSOR_H_

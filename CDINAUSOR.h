#ifndef _CDINAUSOR_H_
#define _CDINAUSOR_H_
#include "CANIMAL.h"

class CDINAUSOR : public CANIMAL {
public:
	CDINAUSOR();
	void tell();
	void Draw();
	void Up(int);
	void Down(int);
	int getWidth();
	int getHeight();
};
#endif // !_CDINAUSOR_H_

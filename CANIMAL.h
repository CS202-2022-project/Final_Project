#ifndef _CANIMAL_H_
#define _CANIMAL_H_

class CANIMAL {
protected:
	int mX, mY;
public:
	CANIMAL();
	bool isStop();
	virtual void draw(char) = 0;
	void Up(int);
	void Down(int);
	void right(int);
	void left(int);
};
#endif // !_CANIMAL_H_

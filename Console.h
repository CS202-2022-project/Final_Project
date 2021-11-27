#ifndef _CONSOLE_H_

#define _CONSOLE_H_

#include <Windows.h>

const int BOARD_STARTX = 0;  // estimated, will be updated later.
const int BOARD_STARTY = 2;
const int BOARD_ENDX = 90;
const int BOARD_ENDY = 28;

void FixConsoleWindow();
void GotoXY(int x, int y);
void TextColor(int x); // ham to mau

#endif
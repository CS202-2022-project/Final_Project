#ifndef _CONSOLE_H_

#define _CONSOLE_H_

#include <Windows.h>

const int BOARD_X_START = 0;  // estimated, will be updated later.
const int BOARD_Y_START = 2;
const int BOARD_X_END = 90;
const int BOARD_Y_END = 28;

void FixConsoleWindow();
void GotoXY(int x, int y);
void TextColor(int x); // ham to mau

#endif
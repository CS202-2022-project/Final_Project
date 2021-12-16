#ifndef _CONSOLE_H_

#define _CONSOLE_H_

#include <Windows.h>
#include <string>
#include <iostream>
#include <utility>

const int X_START = 0;  // estimated, will be updated later.
const int Y_START = 0;
const int X_END = 105;
const int Y_END = 28;

void FixConsoleWindow();
void GotoXY(int x, int y);
void TextColor(int x); // ham to mau
int GetColor();
void SetMusic(bool b);
void hideCursor();
void clrscr();
void drawBoard(int xTrai, int yTrai, int xPhai, int yPhai);
void ShowConsoleCursor(bool showFlag);
void playSound(std::string s);
void stopSound();
#endif
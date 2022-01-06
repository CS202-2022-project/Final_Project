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
void GotoXY(int x, int y); //This is the function to navigate to the specified position on the console
void TextColor(int x); // This is the function to colorize
int GetColor(); //This is the function to get the color
void SetMusic(bool b); //This is the function to set the music for the game
void hideCursor(); // This is the function to hide the cursor of the console
void clrscr(); 
void drawBoard(int xTrai, int yTrai, int xPhai, int yPhai); //This is the function to draw the board
void ShowConsoleCursor(bool showFlag); //This is the fucntion to show up the cursor of the console
void playSound(std::string s); //This is the function for playing the sound for the game
void stopSound(); //This is the function to stop the sound of the game.
#endif
#include "Console.h"
using namespace std;

void FixConsoleWindow() {
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
    SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void GotoXY(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void TextColor(int x) //ham to mau
{
	HANDLE clr;
	clr = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(clr, x);
}

int GetColor() {
	HANDLE clr;
	clr = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	int ret = GetConsoleScreenBufferInfo(clr, &info);
	return ret;
}

void hideCursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void drawBoard(int xTrai, int yTrai, int xPhai, int yPhai)
{
	//vẽ trước 4 góc
	//góc trên bên trái
	GotoXY(xTrai, yTrai); cout << char(218);
	//m_map[yTrai][xTrai] = 218;
	//vẽ góc trên bên phải
	GotoXY(xPhai, yTrai); cout << char(191);
	//m_map[yTrai][xPhai] = 191;
	//vẽ góc dưới bên trái
	GotoXY(xTrai, yPhai); cout << char(192);
	//m_map[yPhai][xTrai] = 192;
	//vẽ góc dưới bên phải
	//m_map[yPhai][xPhai] = 217;
	GotoXY(xPhai, yPhai); cout << char(217);

	//vẽ chiều ngang bên trên
	for (int i = xTrai + 1; i < xPhai; i++) {
		GotoXY(i, yTrai); cout << char(196);
		//m_map[yTrai][i] = 196;
	}
	//vẽ chiều ngang bên dưới
	for (int i = xTrai + 1; i < xPhai; i++) {
		GotoXY(i, yPhai); cout << char(196);
		//m_map[yPhai][i] = 196;
	}
	//vẽ chiều dọc bên trái
	for (int i = yTrai + 1; i < yPhai; i++) {
		GotoXY(xTrai, i); cout << char(179);
		//m_map[i][xTrai] = 179;
	}
	//vẽ chiều dọc bên phải
	for (int i = yTrai + 1; i < yPhai; i++) {
		GotoXY(xPhai, i); cout << char(179);
		//m_map[i][xPhai] = 179;
	}
}

void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = { 0,0 };
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	FillConsoleOutputAttribute(hConsoleOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED, csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}

void ShowConsoleCursor(bool showFlag) {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(out, &cursorInfo);
}

void playSound(std::string s) {
	PlaySound(s.c_str(), NULL, SND_ASYNC);
}

void stopSound() {
	PlaySound(NULL, NULL, SND_NODEFAULT);
}
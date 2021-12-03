#include <string>
#include "Console.h"
#include <conio.h>
#include <io.h>
#include <fcntl.h>
#include <vector>
#include <mmsystem.h>
#include <mciapi.h>

using namespace std;

class Menu{
public:

private:
    

    int mWidth, mHeight;
	int levelStart = 0, music = 0;
	string musicState[2] = { "OFF", "ON" };
	string m_list[4] = { "New game", "Load Game", "Settings", "Exit" };
	string m_settingList[2] = { "Level", "Music" };
	int mX;
	int mY[4] = {12, 16, 20, 24};
};
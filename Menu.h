#include <string>
#include "Console.h"
#include <conio.h>
#include <io.h>
#include <fcntl.h>
#include <vector>
#include <mmsystem.h>
//#include <mciapi.h>

using namespace std;

#define MAX_CHOICE  4

#define ESC 27
#define UP		'W'
#define DOWN	'S'
#define LEFT	'A'
#define RIGHT	'D'
#define KEY_UP		72
#define KEY_DOWN	80
#define KEY_LEFT	75
#define KEY_RIGHT	77
#define KEY_ENTER	13
#define CONSOLE_WIDTH 120
#define	CONSOLE_HEIGHT 30

const int MENU_WIDTH = 15;
const int MENU_HEIGHT = 5;

class Menu {
private:

	vector<string> m_title{
"  #####                                                 ######                        ",
 "#     # #####   ####   ####   ####  # #    #  ####     #     #  ####    ##   #####  ",
 "#       #    # #    # #      #      # ##   # #    #    #     # #    #  #  #  #    # ",
 "#       #    # #    #  ####   ####  # # #  # #         ######  #    # #    # #    # ",
 "#       #####  #    #      #      # # #  # # #  ###    #   #   #    # ###### #    # ",
 "#     # #   #  #    # #    # #    # # #   ## #    #    #    #  #    # #    # #    # ",
"  #####  #    #  ####   ####   ####  # #    #  ####     #     #  ####  #    # #####  "

	};
	int m_width, m_height;
	int levelStart = 0, music = 0;
	string musicState[2] = { "OFF", "ON" };
	string m_list[MAX_CHOICE] = { "New game", "Load Game", "Settings", "Exit" };
	string m_settingList[2] = { "Level", "Music" };
	string listPause[2] = { "Continue", "Exit" };
	int m_x;
	int m_y[MAX_CHOICE] = { 12, 16, 20, 24 };
	void drawTitle();

public:
	Menu();
	void drawPauseScreen();
	void draw();
	int updateChoice();
	void drawSettings();
	void setting();
	void updateSetting();
};
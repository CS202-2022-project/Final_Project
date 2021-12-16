#include "Menu.h"
#include"Console.h"
#include<iostream>
using namespace std;
void Menu::drawTitle()
{
	int y = 0;
	for (int i = 0; i < m_title.size(); i++) {
		int x = (CONSOLE_WIDTH - m_title[i].length()) / 2;
		GotoXY(x, y + i);
		cout << m_title[i];
	}
}

Menu::Menu()
{
	m_width = MENU_WIDTH;
	m_height = MENU_HEIGHT;
	m_x = CONSOLE_WIDTH / 2 - 4;
}

void Menu::draw()
{
	clrscr();
	ShowConsoleCursor(false);
	int xPivot = CONSOLE_WIDTH / 2;
	string str = "       MAIN MENU      ";
	GotoXY((CONSOLE_WIDTH - str.length()) / 2, m_y[0] - 3);
	TextColor(31);  printf("%s", str.c_str()); TextColor(15);
	drawTitle();
	for (int i = 0; i < MAX_CHOICE; i++) {
		drawBoard(xPivot - 8, m_y[i] - 1, xPivot + 7, m_y[i] + 1);
		string s = m_list[i];
		int x = (CONSOLE_WIDTH - s.length()) / 2;
		GotoXY(x, m_y[i]);
		printf("%s", s.c_str());
	}
}

int Menu::updateChoice()
{	
	int i = 0;
	while (1) {
		int x = (CONSOLE_WIDTH - m_list[i].length()) / 2;
		GotoXY(x, m_y[i]);
		TextColor(14);
		printf("%s", m_list[i].c_str());
		switch (_getch()) {
		case KEY_UP: {
			if (i > 0)
			{
				GotoXY(x, m_y[i]);
				TextColor(15);
				printf("%s", m_list[i].c_str());
				i--;
			}
			break;
		}
		case KEY_DOWN: {
			if (i < MAX_CHOICE - 1) {
				GotoXY(x, m_y[i]);
				TextColor(15);
				printf("%s", m_list[i].c_str());
				i++;
			}
			break;
		}
		case KEY_ENTER: {
			TextColor(15);
			return i;
		}
		default: break;
		}
	}
}

void Menu::drawSettings()
{
	clrscr();
	ShowConsoleCursor(false);
	drawTitle();
	string str = "    SETTINGS    ";
	GotoXY(m_x + (10 - str.length()) / 2, m_y[0] - 3);
	TextColor(31);  printf("%s", str.c_str()); TextColor(15);

	drawBoard(m_x - 2, m_y[0] - 1, m_x + 11, m_y[0] + 1);
	GotoXY(m_x, m_y[0]);
	string s = m_settingList[0];
	printf("%s <%d>", s.c_str(), levelStart);

	drawBoard(m_x - 2, m_y[1] - 1, m_x + 11, m_y[1] + 1);
	GotoXY(m_x, m_y[1]);
	s = m_settingList[1];
	printf("%s <%s>", s.c_str(), musicState[music].c_str());
}

void Menu::setting()
{
	drawSettings();
	updateSetting();
}

void Menu::updateSetting()
{
	int i = 0;
	while (1) {
		//GotoXy(m_x - 1, m_y[i]);
		//printf("%c", 175);
		GotoXY(m_x, m_y[i]);
		TextColor(14);
		printf("%s", m_settingList[i].c_str());
		switch (_getch()) {
		case KEY_UP: {
			if (i > 0)
			{
				GotoXY(m_x, m_y[i]);
				TextColor(15);
				printf("%s", m_settingList[i].c_str());
				i--;
			}
			break;
		}
		case KEY_DOWN: {
			if (i < 1) {
				GotoXY(m_x, m_y[i]);
				TextColor(15);
				printf("%s", m_settingList[i].c_str());
				i++;
			}
			break;
		}
		case ESC: {
			TextColor(15);
			return;
		}
		default: break;
		}
	}
}

void Menu::drawPauseScreen() {
	clrscr();
	ShowConsoleCursor(false);
	for (int i = 0; i < 2; i++) {
		int xPivot = CONSOLE_WIDTH / 2;
		drawBoard(xPivot - 6 , m_y[i] - 1, xPivot + 5, m_y[i] + 1);
		string s = listPause[i];
		int x = (CONSOLE_WIDTH - s.length()) / 2;
		GotoXY(x, m_y[i]);
		printf("%s", s.c_str());
	}
}

int Menu::updatePause() {
	int i = 0;
	while (1) {
		int x = (CONSOLE_WIDTH - listPause[i].length()) / 2;
		GotoXY(x, m_y[i]);
		TextColor(14);
		printf("%s", listPause[i].c_str());
		switch (_getch()) {
		case KEY_UP: {
			if (i > 0)
			{
				GotoXY(x, m_y[i]);
				TextColor(15);
				printf("%s", listPause[i].c_str());
				i--;
			}
			break;
		}
		case KEY_DOWN: {
			if (i < 2 - 1) {
				GotoXY(x, m_y[i]);
				TextColor(15);
				printf("%s", listPause[i].c_str());
				i++;
			}
			break;
		}
		case KEY_ENTER: {
			TextColor(15);
			return i;
		}
		default: break;
		}
	}

}
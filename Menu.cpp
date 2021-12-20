#include "Menu.h"


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
	//drawTitle();
	int xPivot = CONSOLE_WIDTH / 2;
	string str = "      SETTINGS      ";
	GotoXY((CONSOLE_WIDTH - str.length())/2, m_y[0] - 3);
	TextColor(31);  printf("%s", str.c_str()); TextColor(15);

	drawBoard(xPivot - 8, m_y[0] - 1, xPivot + 7, m_y[0] + 1);
	string s = m_settingList[0];
	GotoXY(m_x - 1, m_y[0]);
	printf("%s <%d>", s.c_str(), levelStart);

	drawBoard(xPivot - 8, m_y[1] - 1, xPivot + 7, m_y[1] + 1);
	s = m_settingList[1];
	GotoXY(m_x - 1, m_y[1]);
	printf("%s %s", s.c_str(), musicState[music].c_str());


	string esc = "press ESC to return";
	GotoXY((CONSOLE_WIDTH - esc.length()) / 2, m_y[1] + 6);
	printf("%s", esc.c_str());
}


pair<int,int> Menu::updateSetting()
{   
	int i = 0 , j = levelStart - 1 , k = music;
	while (1) {
		GotoXY(m_x - 1, m_y[i]);
		TextColor(14);
		printf("%s", m_settingList[i].c_str());
		switch (_getch()) {
		case KEY_UP: {
			if (i > 0)
			{
				GotoXY(m_x - 1, m_y[i]);
				TextColor(15);
				printf("%s", m_settingList[i].c_str());
				i--;
			}
			break;
		}
		case KEY_DOWN: {
			if (i < 1) {
				GotoXY(m_x - 1, m_y[i]);
				TextColor(15);
				printf("%s", m_settingList[i].c_str());
				i++;
			}
			break;
		}
		case KEY_LEFT: {
			if (i == 0) {
				if (j > 0)
				{
					GotoXY(m_x - 1 + 6, m_y[i]);
					TextColor(15);
					j--;
					printf("%s", level[j].c_str());
				}
			}
			else {
				if (k > 0) {
					GotoXY(m_x - 1 + 6, m_y[i]);
					TextColor(15);
					k--;
					printf("%s", musicState[k].c_str());
				}
			}
			break;
		}
		case KEY_RIGHT: {
			if (i == 0) {
				if (j < 3) {
					GotoXY(m_x - 1 + 6, m_y[i]);
					TextColor(15);
					j++;
					printf("%s", level[j].c_str());
				}
			}
			else {
				if (k < 1) {
					GotoXY(m_x - 1 + 6, m_y[i]);
					TextColor(15);
					k++;
					printf("%s", musicState[k].c_str());
				}
			}
			break;
		}

		case ESC: {
			TextColor(15);
			levelStart = j + 1, music = k;
			return make_pair(j + 1, k);
		}
		default: break;
		}
	}
}
                                                
void Menu::drawPauseScreen() {
	//clrscr();
	
	int xPivot = CONSOLE_WIDTH / 2;
	
	for (int i = xPivot - 10; i <= xPivot + 10; i++) {
		for (int j = m_y[0] - 5; j <= m_y[1] + 5; j++) {
			GotoXY(i, j);
			cout << ' ';
		}
	}
	
	drawBoard(xPivot - 11, m_y[0] - 3, xPivot + 10, m_y[1] + 3);
	ShowConsoleCursor(false);
	//drawTitle();
	for (int i = 0; i < 2; i++) {
		drawBoard(xPivot - 8 , m_y[i] - 1, xPivot + 7, m_y[i] + 1);
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

int Menu::drawAndUpdateSave(bool b[3]) {
	clrscr();
	ShowConsoleCursor(false);
	//drawTitle();
	int xPivot = CONSOLE_WIDTH / 2;
	string str = "       SAVE SLOTS      ";
	GotoXY((CONSOLE_WIDTH - str.length()) / 2, m_y[0] - 3);
	TextColor(31);  printf("%s", str.c_str()); TextColor(15);
	for (int i = 0; i < 3; i++) {
		int xPivot = CONSOLE_WIDTH / 2;
		drawBoard(xPivot - 8, m_y[i] - 1, xPivot + 7, m_y[i] + 1);
		string slotI = "Slot " + to_string(i+1);
		string s = b[i] ? slotI : "Empty ";
		int x = (CONSOLE_WIDTH - s.length()) / 2;
		GotoXY(x, m_y[i]);
		printf("%s", s.c_str());
	}
	
	int i = 0;
	while (1) {
		int x = (CONSOLE_WIDTH - 6) / 2;
		GotoXY(x, m_y[i]);
		TextColor(14);
		string slotI = "Slot " + to_string(i+1);
		string s = b[i] ? slotI : "Empty ";
		printf("%s", s.c_str());
		switch (_getch()) {
		case KEY_UP: {
			if (i > 0)
			{
				GotoXY(x, m_y[i]);
				TextColor(15);
				string slotI = "Slot " + to_string(i+1);
				string s = b[i] ? slotI : "Empty ";
				printf("%s", s.c_str());
				i--;
			}
			break;
		}
		case KEY_DOWN: {
			if (i < 2) {
				GotoXY(x, m_y[i]);
				TextColor(15);
				string slotI = "Slot " + to_string(i+1);
				string s = b[i] ? slotI : "Empty ";
				printf("%s", s.c_str());
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

			
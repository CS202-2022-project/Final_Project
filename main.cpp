#include <thread>
#include <conio.h>
#include <iostream>
#include "Console.h"
#include "CVEHICLE.h"
#include "CCAR.h"
#include "CTRUCK.h"
#include "CTRAFFIC_LIGHT.h" 
#include "CPEOPLE.h"
#include "CANIMAL.h"
#include "CBIRD.h"
#include "CDINAUSOR.h"
#include "CGAME.h"
#include "Menu.h"

using namespace std;

CGAME cg;
bool IN_GAME = true;
bool IS_RUNNING = false;
bool CRASH = false;
bool PAUSE = false;
char MOVING = ' ';
Menu MENU;

void SubThread() {
    while (IN_GAME) { // Still in the menu
        bool FIRST = true;
        while (IS_RUNNING) { // Still in the game
            if (PAUSE) continue;
            if (FIRST) { // Draw for first time
                cg.resetGame();
                FIRST = false;
            }
            if (MOVING != ' ')
                cg.updatePosPeople(MOVING);
            MOVING = ' ';       

            // Update pos according to time cycle
            cg.updatePosVehicle();
            cg.updatePosAnimal();     

            cg.drawGame();
            
            if (cg.isImpact()) {
                IS_RUNNING = false;
                CRASH = true;
                break;

                // Impact then playing sound and stuff    
            }
            
            if (cg.isFinish()) { // Cross the finish line
                if (!cg.nextLevel()) {
                    IS_RUNNING = false;
                    break;
                }
                else
                    FIRST = true;
            }
            //Sleep(100);
        }    
        FIRST = true;
    }
}

int main() {
    //cg.testSprite();

    int temp;
    FixConsoleWindow();
    hideCursor();

    thread t1(SubThread); // Create a subthread for updating position

    while(1){
        // This is where the game take place
        if (cg.getPeople().isDead()) {
            // Show up menu here  
            system("cls"); 
            MENU.draw();
        }

        int temp = MENU.updateChoice();
        if (temp == 0) { // Start new game
            cg.startGame();
            IS_RUNNING = true;
        }
        else if (temp == 1) { // Load game file
        }
        else if (temp == 2) { // Do some settings
            MENU.drawSettings();
            MENU.updateSetting();
        }
        else if (temp == 3) { // Exit the game
            IS_RUNNING = false;
            IN_GAME = false;
            cg.exitGame((HANDLE)t1.native_handle());
            break;
        }
        
        if (!cg.getPeople().isDead()) {
            while (IS_RUNNING) {
                int temp = getch();

                if (temp == 'p') {
                    // Show up some Pause menu here
                    cg.pauseGame((HANDLE)t1.native_handle());
                    PAUSE = true;
                    Sleep(100); // Add buffer for showing up menu
                    
                    TextColor(7);
                    MENU.drawPauseScreen();
                    int pChoice = MENU.updatePause();

                    TextColor(7);
                    system("cls");
                    cg.getPeople().Draw();
                    cg.drawGuide();
                    PAUSE = false;

                    if (pChoice == 0) {
                        cg.resumeGame((HANDLE)t1.native_handle());
                    }
                    else {
                        IS_RUNNING = false;
                        cg.exitGame((HANDLE)t1.native_handle());
                        system("cls");
                        break;                        
                    }
                }
                else {
                    // Update movement
                    MOVING = toupper(temp);
                }
                //Sleep(20); // Add Buffer to movement
            }
            if (CRASH) {
                // Impact here
                system("cls");
                cout << "CRASH";
                system("pause");
                CRASH = false;
            }
            if (cg.getLevel() == 5) {
                system("cls");
                while(1) {
                    GotoXY(37, 13); 
                    cout << "Congratulation!! You've cleared the game!!";
                    GotoXY(41, 14); 
                    cout << "Press Enter to return to main menu.";
                    int temp = _getch();
                    if (temp == KEY_ENTER) break;
                }                    
            }
        }
    }
    t1.join();
    return 0;
}
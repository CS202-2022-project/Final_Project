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
int startLevel=1;
CGAME cg;
bool IN_GAME = true;
bool IS_RUNNING = false;
bool CRASH = false;
bool PAUSE = false;
bool PLAYSOUND = false;
char MOVING = ' ';
bool FIRST = true;
Menu MENU;

void SubThread() {
    while (IN_GAME) { // Still in the menu
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
            cg.updateLight();

            cg.drawGame();
            
            if (cg.isImpact(PLAYSOUND)) {
                IS_RUNNING = false;
                CRASH = true;
                break;
            }
            
            if (cg.isFinish()) { // Cross the finish line
                if (!cg.nextLevel()) {
                    IS_RUNNING = false;
                    break;
                }
            }
            //Sleep(100);
        }    
    }
}

int main() {
    int temp;
    FixConsoleWindow();
    hideCursor();

    cg.loadData();    

    thread t1(SubThread); // Create a subthread for updating position

    while(IN_GAME){
        // This is where the game take place

        // Show up menu here  
        if (PLAYSOUND) playSound("sounds/menu_startgame.wav");
        else stopSound();

        system("cls"); 
        MENU.draw();

        int temp = MENU.updateChoice();
        if (temp == 0) { // Start new game
            cg.startGame();
            FIRST = true;
            IS_RUNNING = true;
        }
        else if (temp == 1) { // Load game file
            int slot = MENU.drawAndUpdateSave(cg.getSaveSlot());
            // cg.getSaveSlot() is an array with 3 element
            // cg.getSaveSlot()[i] is the i'th element
            if (cg.getSaveSlot()[slot]) {
                FIRST = false; // already played the game
                cg.loadGame(slot);
                cg.startGame();
                IS_RUNNING = true;
            }
        }
        else if (temp == 2) { // Do some settings
            MENU.drawSettings();
            pair<int, int> p = MENU.updateSetting();
            cg.setLevel(p.first);
            startLevel=p.first;
            PLAYSOUND = p.second;
        }
        else if (temp == 3) { // Exit the game
            IS_RUNNING = false;
            IN_GAME = false;
            cg.exitGame((HANDLE)t1.native_handle());
            break;
        }
        
        while (!cg.getPeople().isDead()) {
            if (PLAYSOUND)
                playSound("sounds/In_game.wav");
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

                    if (pChoice == 0) {
                        cg.resumeGame((HANDLE)t1.native_handle());
                        cg.getPeople().Draw();
                        cg.drawGuide();
                        PAUSE = false;
                    }
                    else {
                        IS_RUNNING = false;
                        cg.exitGame((HANDLE)t1.native_handle());
                        //system("cls");
	                    cg.setLevel(startLevel);
                        PAUSE = false;
                        break;                        
                    }
                }
                else if (temp == 'l') { // Could change to choose option from pause menu
                    // Show up the save slots
                    cg.pauseGame((HANDLE)t1.native_handle());
                    PAUSE = true;
                    Sleep(100); // Add buffer for showing up save menu

                    TextColor(7);
                    int slot = MENU.drawAndUpdateSave(cg.getSaveSlot());
                    cg.saveGame(slot);
                    cg.setSaveSlot(slot);                    

                    system("cls");     
                    TextColor(7);

                    // Ask the user to continue or not
                    GotoXY(52, 4);
                    cout << "SAVE COMPLETE!!";
                    GotoXY(35, 6);
                    cout << "Would you like to continue or return to main menu?";
                    MENU.drawPauseScreen();
                    int pChoice = MENU.updatePause();

                    TextColor(7);
                    system("cls");

                    if (pChoice == 0) {
                        cg.resumeGame((HANDLE)t1.native_handle());
                        cg.getPeople().Draw();
                        cg.drawGuide();
                        PAUSE = false;
                    }
                    else {
                        IS_RUNNING = false;
                        cg.exitGame((HANDLE)t1.native_handle());
                        //system("cls");
                        PAUSE = false;
                        break;                        
                    }
                }
                else if (temp == 't') {
                    // Show up the load menu
                    cg.pauseGame((HANDLE)t1.native_handle());
                    PAUSE = true;
                    Sleep(100); // Add buffer for showing up load menu

                    TextColor(7);
                    int slot = MENU.drawAndUpdateSave(cg.getSaveSlot());
                    // cg.getSaveSlot() is an array with 3 element
                    // cg.getSaveSlot()[i] is the i'th element
                    system("cls");

                    if (cg.getSaveSlot()[slot])
                        cg.loadGame(slot);

                    PAUSE = false;                        
                }
                else {
                    // Update movement
                    MOVING = toupper(temp);
                }
                //Sleep(20); // Add Buffer to movement
            }
            if (CRASH) {
                // Impact here
                Sleep(2000);
                // Need to add animation here
                if (PLAYSOUND)
                    playSound("sounds/super-mario-death-sound-sound-effect.wav");                
                cg.playDeathAnimation();                 
                //system("cls");
                    for (int x = 38; x <= 78; x++)
                        for (int y = 11; y <= 16; y++) {
                            GotoXY(x, y);
                            cout << ' ';
                        }
                    drawBoard(38, 11, 78, 16);
                    GotoXY(52, 13); 
                    cout << "You're Dead!!";
                    /*GotoXY(41, 14); 
                    cout << "Press Enter to return to main menu.";
                    int temp = _getch();
                    if (temp == KEY_ENTER) break;*/
                    Sleep(1000);
                    system("cls");
                    int dChoice=MENU.drawAndUpdateRetry(); 
                    if (dChoice == 0) {
                         cg.startGame();
                         FIRST =true;
                         IS_RUNNING=true;
                         CRASH = false;
                         continue;
                    }
                    else {
                        IS_RUNNING = false;
                        cg.exitGame((HANDLE)t1.native_handle());
                        //system("cls");
                        cg.setLevel(startLevel);                      
                    }       
                cg.setLevel(startLevel);
                CRASH = false;
            }
            if (cg.getLevel() == 5) {
                // Finish the game
                //system("cls");
                if (PLAYSOUND)
                    playSound("sounds/winning_sound.wav");
                while(1) {
                    for (int x = 33; x <= 81; x++)
                        for (int y = 11; y <= 16; y++) {
                            GotoXY(x, y);
                            cout << ' ';
                        }
                    drawBoard(33, 11, 81, 16);
                    GotoXY(37, 13); 
                    cout << "Congratulation!! You've cleared the game!!";
                    GotoXY(41, 14); 
                    cout << "Press Enter to return to main menu.";
                    int temp = _getch();
                    if (temp == KEY_ENTER) break;
                }                    
                cg.setLevel(startLevel);
            }
        }
    }
    t1.join();

    cg.saveData();  
    return 0;
}
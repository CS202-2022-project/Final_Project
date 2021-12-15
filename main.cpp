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

using namespace std;

CGAME cg;
bool IN_GAME = true;
bool IS_RUNNING = false;
char MOVING = ' ';

void SubThread() {
    while (IN_GAME) { // Still in the menu
        bool FIRST = true;
        while (IS_RUNNING) { // Still in the game
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
            /*
            if (cg.getPeople().isImpact(cg.getVehicle()) || cg.getPeople().isImpact(cg.getAnimal())) {
                // Impact then playing sound and stuff    
            }
            */
            if (cg.isFinish()) { // Cross the finish line
                if (!cg.nextLevel()) {
                    IS_RUNNING = false;
                    system("cls");
                    GotoXY(35, 11); 
                    cout << "Congratulation!! You've cleared the game!!";
                    GotoXY(35, 12); 
                    cout << "Press Enter or any key to escape.";
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
            // New game
            // Load game
            // Settings       
            system("cls"); 
            GotoXY(50, 11); 
            cout << "Temporary Menu:\n";
            GotoXY(49, 12);
            cout << "Press 'Y' to play.\n";
            GotoXY(43, 13);
            cout << "Press 'ESC' to quit the game.\n";
        }

        int temp = toupper(getch());

        if (!cg.getPeople().isDead()) { // ESC means 
            if (temp == 27) {
                // Quit to menu screen without pausing
                IS_RUNNING = false;
                cg.exitGame((HANDLE)t1.native_handle());
                system("cls");
            }
            else if (temp == 'P') {
                // Show up some Pause menu here
                IS_RUNNING = false;
                cg.pauseGame((HANDLE)t1.native_handle());
            }
            else {
                // Resume game or update movement
                IS_RUNNING = true;
                cg.resumeGame((HANDLE)t1.native_handle());
                MOVING = temp;
            }
        }
        else {
            // Take some action here and we'll move into the block above

            if (temp == 'Y') { // Start the game, could change 'Y' which choosing option
                cg.startGame();
                IS_RUNNING = true;
            }
            else if (temp == 27) { // Quit the game, could change 'ESC' which choosing option
                IS_RUNNING = false;                
                IN_GAME = false;
                cg.exitGame((HANDLE)t1.native_handle());
                break;
            }
        }
    }
    t1.join();
    return 0;
}
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
bool IS_RUNNING = false;
char MOVING;

void SubThread() {
    while (1) {
        while (IS_RUNNING) {
            if (!cg.getPeople().isDead()) //Alive
                cg.updatePosPeople(MOVING);
            MOVING = ' ';
            cg.updatePosVehicle();
            cg.updatePosAnimal();
            cg.drawGame();
            /*
            if (cg.getPeople().isImpact(cg.getVehicle()) || cg.getPeople().isImpact(cg.getAnimal())) {
                // Impact then playing sound and stuff    
            }
            */
            if (cg.getPeople().isFinish()) {
                // Cross the finish line
            }
            //Sleep(100);
        }    
    }
}

int main() {
    //cg.testSprite();
    int temp;
    FixConsoleWindow();
    hideCursor();
    thread t1(SubThread); // Create a subthread
    while(1){
        int temp = toupper(getch());
        //cerr << temp << ' ' << IS_RUNNING << '\n';
        //cerr << cg.getPeople().isDead() << '\n';

        if (!cg.getPeople().isDead()) {
            if (temp == 27) {
                IS_RUNNING = false;
                cg.exitGame((HANDLE)t1.native_handle());
                break;
            }
            else if (temp == 'P') {
                IS_RUNNING = false;
                cg.pauseGame((HANDLE)t1.native_handle());
            }
            else {
                IS_RUNNING = true;
                cg.resumeGame((HANDLE)t1.native_handle());
                MOVING = temp; // Update movement
            }
        }
        else {
            // Show up menu here
            if (temp == 'Y') {
                IS_RUNNING = true;
                cg.startGame();
            }
            else {
                IS_RUNNING = false;                
                cg.exitGame((HANDLE)t1.native_handle());
                break;
            }
        }
    }
    return 0;
}
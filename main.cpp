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
bool IS_RUNNING = true;
char MOVING;

void SubThread() {
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
       Sleep(1000);
    }        
}

int main() {
    //cg.testSprite();
    int temp;
    FixConsoleWindow();
    cg.startGame();
    thread t1(SubThread); // Create a subthread
    while(1){
        int temp = toupper(getch());
        if (!cg.getPeople().isDead()) {
            if (temp == 27) {
                cg.exitGame((HANDLE)t1.native_handle());
                return 0;
            }
            else if (temp == 'P')
                cg.pauseGame((HANDLE)t1.native_handle());
            else {
                cg.resumeGame((HANDLE)t1.native_handle());
                MOVING = temp; // Update movement
            }
        }
        else {
            if (temp == 'Y') cg.startGame();
            else {
                cg.exitGame((HANDLE)t1.native_handle());
                return 0;
            }
        }
    }
}
#ifndef _CGAME_H_
#define _CGAME_H_

#include "CTRAFFIC_LIGHT.h"
#include "CTRUCK.h"
#include "CCAR.h"
#include "CDINAUSOR.h"
#include "CBIRD.h"
#include "CVEHICLE.h"
#include "CPEOPLE.h"
#include "CANIMAL.h"
#include "Console.h"
#include "winnt.h"
#include <iostream>

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

class CGAME{
    public:
        CGAME(); //Prepare data
        void drawGame(); //Draw game to screen after getting data
        ~CGAME(); // Release the memory
        CPEOPLE getPeople(); // Get people info
        CVEHICLE* getVehicle(); // Get vehicle info
        CANIMAL* getAnimal(); // Get animal info
        void resetGame(); // Reset all data to the initial value
        void exitGame(HANDLE); // Exit from Thread
        void startGame(); // Start the game
        void loadGame(istream); // Load the game
        void saveGame(istream); // Save the game
        void pauseGame(HANDLE); // Pause the Thread
        void resumeGame(HANDLE); // Resume the Thread
        void updatePosPeople(char c); // Movement control
        void updatePosVehicle(); // Change vehicle Position
        void updatePosAnimal(); // Change animal position

        void testSprite();
    protected:
        int levels ;
        CTRUCK* axt = nullptr;
        CCAR* axh = nullptr;
        CDINAUSOR* akl = nullptr;
        CBIRD* ac = nullptr;
        CPEOPLE cn;        
};

#endif
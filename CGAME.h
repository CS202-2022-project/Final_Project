#ifndef _CGAME_H_
#define _CGAME_H_

#include "CTRAFFIC_LIGHT.h"
#include "CTRUCK.h"
#include "CVEHICLE.h"
#include "winnt.h"
#include <iostream>

using namespace std;

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
        void updatePosPeople(char); // Movement control
        void updatePosVehicle(); // Change vehicle Position
        void updatePosAnimal(); // Change animal position
    private:
        CTRUCK* axt;
        CCAR* axh;
        CDINAUSOR* akl;
        CBIRD* ac;
        CPEOPLE cn;        
};

#endif
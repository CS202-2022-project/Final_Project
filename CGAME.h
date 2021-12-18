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

class CGAME{
    public:
        CGAME(); //Prepare data
        void drawGame(); //Draw game to screen after getting data
        ~CGAME(); // Release the memory
        CPEOPLE getPeople(); // Get people info
        //CVEHICLE* getVehicle(); // Get vehicle info
        //CANIMAL* getAnimal(); // Get animal info
        void drawGuide(); // Draw Instructions
        void resetGame(); // Reset all data to the initial value
        void exitGame(HANDLE t); // Exit from Thread
        void startGame(); // Start the game
        void loadGame(istream); // Load the game
        void saveGame(istream); // Save the game
        void pauseGame(HANDLE t); // Pause the Thread
        void resumeGame(HANDLE t); // Resume the Thread
        void updatePosPeople(char c); // Movement control
        void updatePosVehicle(); // Change vehicle Position
        void updatePosAnimal(); // Change animal position
        void updateLight(); // Update traffic light

        bool isImpact(bool PLAYSOUND);
        int getLevel();
        void setLevel(int x);
        bool isFinish();
        bool nextLevel();
        void testSprite();
    protected:
        unsigned int Cycle = 0;
        int levels = 1;
        int f[5] = {0, 23, 54, 75, 96};
        CTRAFFIC_LIGHT adxh1, adxh2, adxt1, adxt2;
        CTRUCK* axt1 = nullptr, *axt2 = nullptr;
        CCAR* axh1 = nullptr, *axh2 = nullptr;
        CDINAUSOR* akl1 = nullptr, *akl2 = nullptr;
        CBIRD* ac1 = nullptr, *ac2 = nullptr;
        CPEOPLE cn; 
};

#endif
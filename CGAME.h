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
#include<fstream>
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
        void loadGame(int slot); // Load the game
        void saveGame(int slot); // Save the game
        bool* getSaveSlot(); // Return the state of the save slots
        void setSaveSlot(int s); // Set the state of the save slot
        void pauseGame(HANDLE t); // Pause the Thread
        void resumeGame(HANDLE t); // Resume the Thread
        void updatePosPeople(char c); // Movement control
        void updatePosVehicle(); // Change vehicle Position
        void updatePosAnimal(); // Change animal position
        void updateLight(); // Update traffic light

        bool isImpact(bool PLAYSOUND); // Check if the person is impacting other objects
        int getLevel(); // return the current level
        void setLevel(int x); // set the current level
        bool isFinish(); // Check if the person crossed the finish line
        bool nextLevel(); // Go to the next level
        void playDeathAnimation(); // Play death animation
        void testSprite(); // Just for testing 
    protected:
        unsigned int Cycle = 0;
        int levels = 1;
        bool b[3] = {false, false, false};
        int f[5] = {0, 23, 54, 75, 96};
        CTRAFFIC_LIGHT adxh1, adxh2, adxt1, adxt2;
        CTRUCK* axt1 = nullptr, *axt2 = nullptr;
        CCAR* axh1 = nullptr, *axh2 = nullptr;
        CDINAUSOR* akl1 = nullptr, *akl2 = nullptr;
        CBIRD* ac1 = nullptr, *ac2 = nullptr;
        CPEOPLE cn; 
};

#endif
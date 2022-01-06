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

        void loadData(); //This is for loading data for the game
        void saveData(); // This is for saving data for the game

        CPEOPLE getPeople(); // This is the function to get data of people
        //CVEHICLE* getVehicle(); // Get data of the vehicle
        //CANIMAL* getAnimal(); // Get data of animal 
        void drawGuide(); // This is the function to draw up the instruction
        void resetGame(); // This is the function to reset the game
        void exitGame(HANDLE t); // This is the function to exit from the thread
        void startGame(); // This is the function to start the new game
        void loadGame(int slot); // This is the function to load the game
        void saveGame(int slot); // This is  the function to save the game in a particular slot
        bool* getSaveSlot(); // This is the function to return the state of the slot
        void setSaveSlot(int s); // This is the function to set the saved slot
        void pauseGame(HANDLE t); // This is the function to pause the thread
        void resumeGame(HANDLE t); // This is the fucntion to resume the thread
        void updatePosPeople(char c); // This is the function to update the position of people
        void updatePosVehicle(); // This is the function to update position of the vehicle
        void updatePosAnimal(); // This is the function to update the position of the animal
        void updateLight(); // This is the function to update the traffic light

        bool isImpact(bool PLAYSOUND); // Check if the person is impacting other objects
        int getLevel(); // this is the function to get the current level
        void setLevel(int x); // this is the function to set the current level
        bool isFinish(); // This is the fucntion to check if it's finished or not
        bool nextLevel(); // This is the function to shift to the next level
        void playDeathAnimation(); // This is the function to play the death animation
        void testSprite(); // Just for test
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
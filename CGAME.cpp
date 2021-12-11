#include "CGAME.h"

CGAME::CGAME() {
    levels = 1;
    axh = new CCAR;
    axh -> move(3, 6);
    axt = new CTRUCK;
    axt -> move(3, 11);
    ac = new CBIRD;
    ac -> Move(3, 16);
    akl = new CDINAUSOR;
    akl -> Move(3, 21);
}

void CGAME::drawGame() { 
    axh -> draw();  
    if (levels >= 2)  
        axt -> draw();
    if (levels >= 3)
        ac -> draw();
    if (levels >= 4)
        akl -> draw();    
}

CGAME::~CGAME() {
    delete axt;
    delete axh;
    delete ac;
    delete akl;
}

CPEOPLE CGAME::getPeople() {
    return cn;
}

CVEHICLE* CGAME::getVehicle() { 
}

CANIMAL* CGAME::getAnimal() {
}

void CGAME::resetGame() {
    delete axt;
    delete axh;
    delete ac;
    delete akl;
    levels = 1;    
    axt = new CTRUCK;
    axh = new CCAR;
    akl = new CDINAUSOR;
    ac = new CBIRD;
}

void CGAME::exitGame(HANDLE) {
}

void CGAME::startGame() {

}

void CGAME::loadGame(istream) {

}

void CGAME::saveGame(istream) {

}

void CGAME::pauseGame(HANDLE) {

}

void CGAME::resumeGame(HANDLE) {

}

void CGAME::updatePosPeople(char) {

}

void CGAME::updatePosVehicle() {
    if (levels >= 2) {

    }
}

void CGAME::updatePosAnimal() {
}

// -------------------------------

void CGAME::testSprite() {
    axh -> move(1, 1);
    axh -> draw();
    axt -> move(1, 5);
    axt -> draw();
    ac -> Move(1, 10);
    ac -> draw();
    akl -> Move(1, 20);
    akl -> draw();
}
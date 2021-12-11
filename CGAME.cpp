#include "CGAME.h"

CGAME::CGAME() {
    axt = new CTRUCK[10];
    axh = new CCAR[10];
    akl = new CDINAUSOR[10];
    ac = new CBIRD[10];
}

void CGAME::drawGame() {

}

CGAME::~CGAME() {

}

CPEOPLE CGAME::getPeople() {

}

CVEHICLE* CGAME::getVehicle() {

}

CANIMAL* CGAME::getAnimal() {

}

void CGAME::resetGame() {

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

}

void CGAME::updatePosAnimal() {

}

// -------------------------------

void CGAME::testSprite() {
    axh -> draw(1, 1);
    axt -> draw(1, 5);
    ac -> draw(1, 15);
    akl -> draw(1, 20);
}
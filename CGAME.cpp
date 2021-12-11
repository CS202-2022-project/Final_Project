#include "CGAME.h"

CGAME::CGAME() {
    levels = 4;
    axh = new CCAR;
    axh -> move(7, 1);
    axt = new CTRUCK;
    axt -> move(14, 1);
    ac = new CBIRD;
    ac -> Move(26, 1);
    akl = new CDINAUSOR;
    akl -> Move(33, 1);
}

void CGAME::drawGame() { 
    int col = 0;
    for (int j = 1; j <= levels; j++) {
        col += (j == 3 ? 12 : 7);
        for (int k = 0; k <= 1; k++)
            for (int i = Y_START; i <= Y_END; i++) {
                GotoXY(col - 2 + k, i);
                cout << '|';
            } 
    }            
    cn.Draw();
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

void CGAME::exitGame(HANDLE t) {
    ::TerminateThread(t, 1);
}

void CGAME::startGame() {
    cn.setState(false);
}

void CGAME::loadGame(istream) {

}

void CGAME::saveGame(istream) {

}

void CGAME::pauseGame(HANDLE t) {
    ::SuspendThread(t);
}

void CGAME::resumeGame(HANDLE t) {
    ::ResumeThread(t);
}

void CGAME::updatePosPeople(char c) {
    if (c == 'W') cn.Up(1);
    if (c == 'D') cn.Right(1);
    if (c == 'S') cn.Down(1);
    if (c == 'A') cn.Left(1); 
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
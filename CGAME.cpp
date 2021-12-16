#include "CGAME.h"

CGAME::CGAME() {
    levels = 1;

    axh1 = new CCAR;
    axh2 = new CCAR;

    axt1 = new CTRUCK;
    axt2 = new CTRUCK;

    ac1 = new CBIRD;
    ac2 = new CBIRD;

    akl1 = new CDINAUSOR;
    akl2 = new CDINAUSOR;
}

void CGAME::drawGame() { 
    //cn.Draw();
    TextColor(10);

    for (int i = 0; i < Y_END + 2; i++) {
        GotoXY(6, i);
        cout << '|';
        GotoXY(19, i);
        cout << '|';
        for (int j = 0; j < 2; j++) {
            GotoXY(12 + j, i);
            cout << '|';
        }          
    }           

    axh1 -> draw(), axh2 -> draw();

    if (levels >= 2) {
        TextColor(9);

        for (int i = 0; i < Y_END + 2; i++) {
            GotoXY(27, i);
            cout << '|';
            GotoXY(50, i);
            cout << '|';
            for (int j = 0; j < 2; j++) {
                GotoXY(38 + j, i);
                cout << '|';
            }       
        }

        axt1 -> draw(), axt2 -> draw();
    }        
    if (levels >= 3) {
        TextColor(14);
        
        for (int i = 0; i < Y_END + 2; i++) {
            GotoXY(58, i);
            cout << '|';
            GotoXY(71, i);
            cout << '|';
            for (int j = 0; j < 2; j++) {
                GotoXY(64 + j, i);
                cout << '|';
            }      
        }       

        ac1 -> draw(), ac2 -> draw();
    }        
    if (levels >= 4) {
        TextColor(12); 

        for (int i = 0; i < Y_END + 2; i++) {
            GotoXY(79, i);
            cout << '|';
            GotoXY(92, i);
            cout << '|';
            for (int j = 0; j < 2; j++) {
                GotoXY(85 + j, i);
                cout << '|';
            }     
        }       

        akl1 -> draw(), akl2 -> draw();   
    }        

    for (int i = 0; i < Y_END + 2; i++)
        for (int j = f[levels]; j < f[levels] + 5; j++) {
            GotoXY(j, i);
            if ((i + j - f[levels]) % 2) {
                TextColor(255); cout << ' ';
            }    
            else {
                TextColor(0); cout << ' ';
            }
        }

    TextColor(7); // Reset Colour        
}

CGAME::~CGAME() {
    delete axt1, axt2;
    delete axh1, axh2;
    delete ac1, ac2;
    delete akl1, akl2;
}

CPEOPLE CGAME::getPeople() {
    return cn;
}

/*
CVEHICLE* CGAME::getVehicle() { 
}

CANIMAL* CGAME::getAnimal() {
}
*/

void CGAME::drawGuide() {
    GotoXY(105, 1);
    cout << "Level: " << levels;
    GotoXY(105, 3);
    cout << "Control:";
    GotoXY(105, 4);
    cout << "W: Go Up";
    GotoXY(105, 5);
    cout << "S: Go Down";
    GotoXY(105, 6);
    cout << "A: Go Left";
    GotoXY(105, 7);
    cout << "D: Go Right";

    drawBoard(103, 0, 119, 8);
}

void CGAME::resetGame() {
    system("cls");

    drawGuide();

    cn.Move(0, 11);

    axh1 -> move(7, 0);
    axh2 -> move(14, 28);

    axt1 -> move(28, 0);
    axt2 -> move(40, 26);

    ac1 -> Move(59, 0);
    ac2 -> Move(66, 27);  

    akl1 -> Move(80, 0);
    akl2 -> Move(87, 26);  
}

void CGAME::exitGame(HANDLE t) {
    cn.setState(true);
}

void CGAME::startGame() {
    levels = 1;
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

bool CGAME::isImpact() {
    bool B = false;
    if (cn.isImpact(axt1) || cn.isImpact(axt2) ||
    cn.isImpact(axh1) || cn.isImpact(axh2) ||
    cn.isImpact(ac1) || cn.isImpact(ac2) ||
    cn.isImpact(akl1) || cn.isImpact(akl2)) B = true;
    if (B) cn.setState(true);
    return B;
}

bool CGAME::isFinish() {
    return cn.isFinish(f[levels]);
}

int CGAME::getLevel() {
    return levels;
}

bool CGAME::nextLevel() {
    levels++;
    if (levels == 5) {
        cn.setState(true);
        return false;
    }
    else {
        resetGame();
        return true;
    }
}

// -------------------------------

void CGAME::testSprite() {
    axh1 -> move(1, 1);
    axh1 -> draw();
    axt1 -> move(1, 5);
    axt1 -> draw();
    ac1 -> Move(1, 10);
    ac1 -> draw();
    akl1 -> Move(1, 20);
    akl1 -> draw();
}
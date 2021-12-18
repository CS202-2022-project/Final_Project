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

    adxh1 = CTRAFFIC_LIGHT(5, 1, 100);
    adxh2 = CTRAFFIC_LIGHT(20, 29, 90);
    adxt1 = CTRAFFIC_LIGHT(26, 1, 80);
    adxt2 = CTRAFFIC_LIGHT(51, 29, 70);
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

        ac1 -> Draw(), ac2 -> Draw();
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

        akl1 -> Draw(), akl2 -> Draw();   
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

    // Draw traffic light 
    adxh1.draw(254); 
    adxh2.draw(254);
    if (levels >= 2) {
        adxt1.draw(254); 
        adxt2.draw(254);
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
    cn.setState(false);
}

void CGAME::loadGame(int id) {

}

void CGAME::saveGame(int id) {

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
    Cycle++;
    if (!adxh1.isRed()) { // Green light
        if (Cycle % 6 == 0) {
            axh1 -> deDraw();
            if (!axh1 -> Down(1)) axh1 -> move(7, 0);
        }
    }
    if (!adxh2.isRed()) {
        if (Cycle % 5 == 0) {
            axh2 -> deDraw();                      
            if (!axh2 -> Up(1)) axh2 -> move(14, 28);
        }
    }
    if (levels >= 2) { // Truck
        if (!adxt1.isRed()) {
            if (Cycle % 6 == 0) {
                axt1 -> deDraw();
                if (!axt1 -> Down(1)) axt1 -> move(28, 0);
            }
        }
        if (!adxt2.isRed()) {
            if (Cycle % 5 == 0) {
                axt2 -> deDraw();                      
                if (!axt2 -> Up(1)) axt2 -> move(40, 26);
            }
        }
    }
}

void CGAME::updatePosAnimal() {
    if (levels >= 3) { // Bird
        if (Cycle % 4 == 0) {
            ac1 -> deDraw();
            if (!ac1 -> Down(2)) ac1 -> Move(59, 0);
        }
        if (Cycle % 5 == 0) {
            ac2 -> deDraw();                      
            if (!ac2 -> Up(2)) ac2 -> Move(66, 27);
        }
    }
    if (levels >= 4) { //Dinosaur
        if (Cycle % 5 == 0) {
            akl1 -> deDraw();
            if (!akl1 -> Down(3)) akl1 -> Move(80, 0);
        }
        if (Cycle % 4 == 0) {
            akl2 -> deDraw();                      
            if (!akl2 -> Up(3)) akl2 -> Move(87, 26);
        }
    }
}

void CGAME::updateLight() {
    adxh1.increaseTime();
    adxh2.increaseTime();

    if (levels >= 2) {
        adxt1.increaseTime();
        adxt2.increaseTime();
    }
}

bool CGAME::isImpact(bool PLAYSOUND) {
    bool B = false;
    if (cn.isImpact(axt1) || cn.isImpact(axt2) ||cn.isImpact(axh1) || cn.isImpact(axh2)) {
        if (PLAYSOUND)
            playSound("sounds/impact_car_crash.wav");
        B = true;
    }
    else if (cn.isImpact(ac1) || cn.isImpact(ac2)) {
        if (PLAYSOUND)
            playSound("sounds/Eagle_sfx.wav");
        B = true;
    }
    else if (cn.isImpact(akl1) || cn.isImpact(akl2)) {
        if (PLAYSOUND)
            playSound("sounds/trex_roar.wav");
        B = true;
    }
    if (B) cn.setState(true);
    return B;
}

bool CGAME::isFinish() {
    return cn.isFinish(f[levels]);
}

int CGAME::getLevel() {
    return levels;
}

void CGAME::setLevel(int x) {
    levels = x;
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
    ac1 -> Draw();
    akl1 -> Move(1, 20);
    akl1 -> Draw();
}
#include <thread>
#include <conio.h>

using namespace std;

bool IS_RUNNING = true;

void exitGame(thread* t) {
    system("cls");
    IS_RUNNING = false;
    t -> join();
}

void ThreadFunc1() {
    while (IS_RUNNING) {
        //... Print to console all objects in the game
    }
}

int main() {
    //...
    thread t1(ThreadFunc1); // Create a subthread
    while(1){
        int temp = toupper(getch());
        //...
        if(temp == 27) { // 27 = ESC, meaning exit
            exitGame(&t1); 
            return 0;
        }
    }
    //...
}
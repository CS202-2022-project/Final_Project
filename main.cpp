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
        //...
    }
}

int main() {
    //...
    thread t1(ThreadFunc1);
    while(1){
        int temp = toupper(getch());
        //...
        if(temp == 27) {
            exitGame(&t1); 
            return 0;
        }
    }
    //...
}
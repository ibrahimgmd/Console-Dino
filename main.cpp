#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
using namespace std;

const int SCREEN_WIDTH = 30;
const int SCREEN_HEIGHT = 10;

int dinoY = SCREEN_HEIGHT - 2;
int dinoX = 2;

int obstacleX = SCREEN_WIDTH - 1;
bool isjumping = false;             
int jumpheight = 0;                 
int jumpspeed = 2;

void render() {
    system("cls");

    for (int y = 0; y < SCREEN_HEIGHT; y++) {
        for (int x = 0; x < SCREEN_WIDTH; x++) {
            if (x == dinoX && y == dinoY - jumpheight) {  // Fixed this line
                cout << "#";
            } else if (x == obstacleX && y == SCREEN_HEIGHT - 2) {
                cout << "$";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void MoveDinoAss() {
    if (_kbhit()) {
        char key = _getch();
        if (key == ' ' && !isjumping) {
            isjumping = true;
            jumpheight = 0;
        }
    }
}

void updateJump() {
    if (isjumping) {
        if (jumpheight < 3) {
            jumpheight++; 
        } else {
            isjumping = false;  
        }
    } else {
        if (jumpheight > 0) {
            jumpheight--; 
        }
    }
}

void UpdateObs() {
    if (obstacleX <= 0) {
        obstacleX = SCREEN_WIDTH - 1;
    } else {
        obstacleX--;
    }
}

void checkcollison() {
    if (obstacleX == dinoX && dinoY - jumpheight == SCREEN_HEIGHT - 2) {  // Fixed this line
        cout << "gameover dawg" << endl;
        exit(0);
    }
}

int main() {
    srand((0));
    while (true) {
        MoveDinoAss();
        updateJump();
        UpdateObs();
        checkcollison();
        render();
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    return 0;
}

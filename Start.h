// Start.h
#ifndef START_H
#define START_H

#include <iostream>
#include <cstdlib>
#include <conio.h>
using namespace std;

class Start {
public:
    // selected level of difficulty
    static int level;

    // shows starting menu on the screen
    static void showMenu();

private:
    // gets keyboard input from user
    static int getKey();
};

int Start::level = 0;

void Start::showMenu() {
    system("cls");
    cout << "*** MINESWEEPER ***" << endl;
    cout << "1. EASY mode" << endl;
    cout << "2. NORMAL mode" << endl;
    cout << "3. HARD mode" << endl;
    cout << "4. EXIT" << endl;
    cout << "\nPress a number\n" << endl;
    
    while (true) {
        int input = getKey();
        if (input == 0) {
            cout << "Wrong input!" << endl;
        } else if (input == 4) {
            exit(0);
        } else {
            level = input;
            break;
        }
    }
}

int Start::getKey() {
    char key;
    key = _getch();

    switch (key) {
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    default:
        return 0;
    }
}

#endif
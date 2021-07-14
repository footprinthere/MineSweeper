// main function
// Minesweeper.cpp

#include <iostream>
#include <conio.h>
using namespace std;

#include "Start.h"
#include "Game.h"

int main() {
    int sizeArr[3] = {10, 18, 24};
    int numArr[3] = {10, 40, 100};

    // start menu & game setting
    Start::showMenu();
    int size = sizeArr[Start::level - 1];
    int numMine = numArr[Start::level - 1];

    // loop for restart
    while (true) {
        // gameboard setting
        Game game(size, numMine);
        game.fill();

        // loop for each turn
        while (true) {
            game.print();
            game.getKey();
            game.checkWon();

            // if won
            if (game.isWon()) {
                game.print();
                cout << endl;
                cout << "***** YOU WON *****" << endl;
                cout << "Press any key to restart" << endl;
                cout << "Press E to exit" << endl;

                char ch = _getch();
                if (ch == 'E' || ch == 'e') {
                    return 0;
                } else {
                    break;
                }
            }

            // if over
            if (game.isOver()) {
                game.print();
                cout << endl;
                cout << "***** GAME OVER *****" << endl;
                cout << "Press any key to restart" << endl;
                cout << "Press E to exit" << endl;

                char ch = _getch();
                if (ch == 'E' || ch == 'e') {
                    return 0;
                } else {
                    break;
                }
            }
        }
        continue;   // restart
    }

    return 0;
}
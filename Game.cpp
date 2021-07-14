// Game.cpp

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
using namespace std;

#include "Game.h"

/* --------------------------------------- */
/* -----------public functions ----------- */
/* --------------------------------------- */

Game::Game(int size, int numMine)
    : size(size), numMine(numMine), board(size, vector<char>(size, '0')),\
    opened(size, vector<bool>(size, false)), marked(size, vector<bool>(size, false)),\
    numMarked(0), curX(0), curY(0), won(false), over(false) { }

void Game::fill() {
    int xrand, yrand;
    int count = 0;

    // randomly fill mines
    srand(time(NULL));
    while (count < numMine) {
        xrand = rand() % size;
        yrand = rand() % size;

        // increase numbers around mines
        if (board[xrand][yrand] != '*') {
            for (int i=-1; i<=1; i++) {
                for (int j=-1; j<=1; j++) {
                    try {
                        if (board.at(xrand+i).at(yrand+j) != '*')
                            board[xrand+i][yrand+j] += 1;
                    } catch (out_of_range ex) { }
                }
            }
            board[xrand][yrand] = '*';
            mines.push_back(vector<int>({xrand, yrand}));
            count++;
        }
    }

    for (int x=0; x<size; x++) {
        for (int y=0; y<size; y++) {
            if (board[x][y] == '0') {
                board[x][y] = '_';
            }
        }
    }
}


void Game::print() const {
    system("cls");

    for (int y=0; y<size; y++) {
        for (int x=0; x<size; x++) {
            if (x == curX && y == curY) {   // cursor position
                textColor(color::YELLOW);
                if (opened[x][y]) {
                    cout << board[x][y] << " ";
                } else {
                    cout << "X ";
                }
            } else if (opened[x][y]) {  // opened cell
                char ch = board[x][y];
                if (ch == '*') {
                    if (marked[x][y])
                        textColor(color::GREEN);
                    else
                        textColor(color::RED);
                    cout << "* ";
                } else {
                    textColor();
                    cout << ch << " ";
                }
            } else if (marked[x][y]) {      // marked cell
                textColor(color::GREEN);
                cout << "X ";
            } else {                    // unopend cell
                textColor(color::DARK);
                cout << "X ";
            }
        }
        cout << endl;
    }
    textColor();
}


void Game::getKey() {
    char input;

    while (true) {
        input = _getch();

        if (input == 'a' || input == 'A') {       // left
            if (curX > 0) curX--;
            break;
        } else if (input == 'd' || input == 'D') {  // right
            if (curX < size-1) curX++;
            break;
        } else if (input == 'w' || input == 'W') {  // up
            if (curY > 0) curY--;
            break;
        } else if (input == 's' || input == 'S') {  // down
            if (curY < size-1) curY++;
            break;
        } else if (input == 'm' || input == 'M') {  // mark
            mark(curX, curY);
            break;
        } else if (input == 'k' || input == 'K') {  // dig
            dig(curX, curY);
            break;
        } else {
            cout << "Wrong Input" << endl;
        }
    }
}


void Game::checkWon() {
    if (numMarked != numMine) {
        return;
    }
    for (int i=0; i<numMine; i++) {
        if (!marked[mines[i][0]][mines[i][1]]) {
            return;
        }
    }
    won = true;
}


bool Game::isWon() const {
    return won;
}
bool Game::isOver() const {
    return over;
}


/* ---------------------------------------- */
/* -----------private functions ----------- */
/* ---------------------------------------- */

void Game::dig(int x, int y) {
    char ch = board[x][y];

    if (ch == '*') {    // a mine digged
        marked[x][y] = false;
        for (int i=0; i<numMine; i++) {
            opened[mines[i][0]][mines[i][1]] = true;    // open all mines
        }
        over = true;
    } else if (ch == '_') {
        extend(x, y);
    } else {
        marked[x][y] = false;
        opened[x][y] = true;
    }
}


void Game::extend(int x, int y) {
    try {
        if (opened.at(x).at(y)) {       // cell opened already
            return;
        }
        opened.at(x).at(y) = true;      // open the selected cell
        if (board.at(x).at(y) != '_') { // non-empty cell
            return;
        }
    } catch (out_of_range& ex) {        // out of range
        return;
    }
    marked[x][y] = false;

    for (int i=-1; i<=1; i++) {
        for (int j=-1; j<=1; j++) {
            extend(x+i, y+j);   // recursive call
        }
    }
}


void Game::mark(int x, int y) {
    if (opened[x][y])
        return;
    if (!marked[x][y]) {
        marked[x][y] = true;
        numMarked++;
    } else {
        marked[x][y] = false;
        numMarked--;
    }
}


void Game::textColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
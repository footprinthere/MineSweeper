// Gameboard.h
#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <iostream>
#include <vector>
using namespace std;

class Gameboard {
public:
    // size of gameboard
    int size;
    // number of mines
    int numMine;
    // 2D char vector for gameboard
    vector<vector<char>> board;
    // x coordinate of cursor
    int curX;
    // y coordinate of cursor
    int curY;

    // constructor
    Gameboard(int size, int numMine);

    // randomly fills board with mines, used inside constructor
    void fill();
    // gets keyboard input from user
    int getKey();
    // checks if there is a mine in a certain space
    // and returns true if there is
    bool check(int x, int y);
    // shows the content of board on the screen
    void show();
};

Gameboard::Gameboard(int size, int numMine)
    : size(size), numMine(numMine), board(size, vector<char>(5, 0)), curX(0), curY(0) { }

void Gameboard::fill() {
    
}

#endif
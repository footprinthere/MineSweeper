// Game.h
#ifndef GAME_H
#define GAME_H

#include <vector>

namespace color {
    enum {GREEN=2, RED=4, DEFAULT=7, DARK=8, YELLOW=14};
}

class Game {
public:
    /* ----public member functions---- */

    // constructor of class Game
    Game(int size, int numMine);
    // fills gameboard with proper information
    void fill();
    // prints gameboard on the screen
    void print() const;
    // receives keyboard input
    void getKey();
    // checks if the player won the game
    void checkWon();
    // returns true if the player won the game
    bool isWon() const;
    // returns true if the player lost the game
    bool isOver() const;

private:
    /* ----private member functions---- */

    // digs a cell to check if there is a mine
    void dig(int x, int y);
    // recursively extends digged cells
    void extend(int x, int y);
    // marks a cell
    void mark(int x, int y);

    // changes the color of texts printed on the screen
    static void textColor(int color=color::DEFAULT);

    /* ----private member variables---- */

    // size of gameboard
    const int size;
    // number of mines
    const int numMine;
    // 2D vector for gameboard
    vector<vector<char>> board;
    // 2D vector to store data of opened cell
    vector<vector<bool>> opened;
    // 2D vector to store data of marked cell
    vector<vector<bool>> marked;
    // number of marked cells
    int numMarked;
    // vector to store the position of mines
    vector<vector<int>> mines;
    // current X position of cursor
    int curX;
    // current Y position of cursor
    int curY;
    // true if the player won the game
    bool won;
    // true if the game is over
    bool over;
};

#endif
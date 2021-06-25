// Main.cpp

#include <iostream>
using namespace std;

#include "Start.h"

int main() {
    Start::showMenu();
    cout << Start::getLevel() << endl;

    return 0;
}
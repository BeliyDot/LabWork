#include "library.h"
#include <iostream>
using namespace std;

Library operator+(const Library &lhs, const Library &rhs) {
    Library result;
    for(Game obj : lhs.games) {
        result.games.push_back(obj);
    }
    for(Game obj : rhs.games) {
        result.games.push_back(obj);
    }
    return result;
}

std::ostream operator<<(std::ostream &os, const Library &obj) {
    cout << "Game Library: " << endl;
    for(Game game : obj.games) {
        cout << game;
    }
}

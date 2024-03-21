#include "library.h"
#include <iostream>
using namespace std;

// Operator overloads

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

std::ostream &operator<<(std::ostream &os, const Library &obj) {
    for(Game game : obj.games) {
        os << game;
    }
    return os;
}

bool Library::hasGame(Game game) {
    for(Game gayme : games) {
        if(gayme == game) return true;
    } 
    return false;
}

// Getting game/index methods

int Library::getIndex(Game game) {
    if(hasGame(game)) {
        for(int i = 0; i < games.size(); i++) {
            if(game == games[i]) return i;
        }
    }
    return -1;
}

Game *Library::getGame(int index) {
    if(0 <= index < games.size()) return &games[index];
    else return nullptr;
}
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

std::ostream &operator<<(std::ostream &os, const Library &obj) {
    os << "Game Library: " << endl;
    for(Game game : obj.games) {
        os << game;
    }
    return os;
}

int Library::getIndex(Game game) {
    for(int i = 0; i < games.size(); i++) {
        if(game == games[i]) return i;
    }
    return -1;
}

Game Library::getGame(int index) {
    if(index < games.size() && index >= 0) return games[index]; 
}
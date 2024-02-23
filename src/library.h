#ifndef LABWORK_LIBRARY_H
#define LABWORK_LIBRARY_H
#include <ostream>
#include <string>
#include <vector>
#include "game.h"
#include <iostream>

class Library {
private:
    vector<Game> games;
    enum filters {
        ALPHABET,
        RELEASE_DATE,
        GENRE,
    };
public:
    void addGame(Game newGame) { games.push_back(newGame); }
    Library filter(filters filter, string tag = "");
    friend Library operator+(const Library &lhs, const Library &rhs);
    friend std::ostream operator<<(std::ostream &os, const Library &lib); 
};


#endif
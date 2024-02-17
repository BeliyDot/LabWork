#ifndef LABWORK_LIBRARY_H
#define LABWORK_LIBRARY_H
#include <string>
#include <vector>
#include "game.h"

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
    void printInfo();
    Library filter(filters filter, string tag = "");
};


#endif
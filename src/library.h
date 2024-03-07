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
        GENRE,
        RELEASED,
        TAGS
    };
    enum sortings {
        ALPHABET,
        RELEASE_DATE,
        PLAYTIME
    };
public:
    void addGame(Game newGame) { games.push_back(newGame); }
    vector<Game> getGames() const { return games; }
    bool hasGame(Game game);
    Game *getGame(int index);
    int getIndex(Game game);
    Library filter(filters filter, string tag = "");
    friend Library operator+(const Library &lhs, const Library &rhs);
    friend std::ostream &operator<<(std::ostream &os, const Library &lib); 
};


#endif
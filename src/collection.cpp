#include "collection.h"
#include "library.h"
#include <string>

Collection::Collection(string &name, Library lib, vector<int> indexes) {
    this->name = new string;
    *this->name = name;

    for(int index : indexes) {
        Game *game = lib.getGame(index);
        if(game != nullptr) this->addGame(*game);
    }
}

Collection::Collection(string &name, Library lib, vector<Game> games) {
    this->name = new string;
    *this->name = name;

    for(Game game : games) {
        if(lib.getIndex(game) != -1) this->addGame(game);
    }
}
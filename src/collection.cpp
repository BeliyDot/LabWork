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
        if(lib.hasGame(game)) this->addGame(game);
    }
}

bool &Collection::operator==(const Collection &rhs) const {
    bool result = this->name == rhs.name && this->getGames() == rhs.getGames();
    return result;
}
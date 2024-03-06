#ifndef LABWORK_DEVGAME_H
#define LABWORK_DEVGAME_H

#include "game.h"

class DevGame : public Game {
private:
    string *version;
    string *pathToBuild;
    bool released = false;
public:
    void release() { released = true; }
    void update(string newVersion) { *version = newVersion; }
    void changePTB(string newPTB) { *pathToBuild = newPTB; }
    
    DevGame(string &name, string &path, string &version, string &pathToBuild): Game(name, path) {
        this->version = new string;
        this->pathToBuild = new string;
        *this->version = version;
        *this->pathToBuild = pathToBuild;
    }
};

#endif
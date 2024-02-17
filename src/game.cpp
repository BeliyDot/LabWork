#include "game.h"
#include <iostream>
#include <ostream>
using namespace std;

void Game::printInfo() {
    cout << "Name: " << name << endl
    << "Genre: " << genre << endl;
    if(!tags.empty()) {
        cout << "Tags: ";
        
        for(int i = 0; i < tags.size(); i++) {
            cout << tags[i];
            if(i == tags.size() - 1)
                cout << '.' << endl;
            else cout << ", ";
        }
    }
}

Game::Game(string &&newName, string &&newPath): Game{newName, newPath, "Unknown"} {}

Game::Game(string &&newName, string &&newPath, string &&newGenre): name{newName}, path{newPath}, genre{newGenre} {}

Game::Game(string &newName, string &newPath): Game{newName, newPath, "Unknown"} {}

Game::Game(string &newName, string &newPath, string &&newGenre): name{newName}, path{newPath}, genre{newGenre} {}
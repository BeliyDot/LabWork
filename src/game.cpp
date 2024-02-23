#include "game.h"
#include <iostream>
#include <ostream>
using namespace std;

ostream operator<<(ostream &os, const Game &obj) {
    cout << "Name: " << *obj.name << endl
    << "Genre: " << *obj.genre << endl;
    if(!obj.tags.empty()) {
        cout << "Tags: ";
        
        for(int i = 0; i < obj.tags.size(); i++) {
            cout << obj.tags[i];
            if(i == obj.tags.size() - 1)
                cout << '.' << endl;
            else cout << ", ";
        }
    }
}

void Game::rename(string &&newName) { *name = newName; }

// Constructors

Game::Game(string &&newName, string &&newPath): Game{newName, newPath, "Unknown"} {}

Game::Game(string &newName, string &newPath): Game{newName, newPath, "Unknown"} {}

Game::Game(string &&name, string &&path, string &&genre) {
    this->name = new string;  
    this->path = new string;
    this->genre = new string;
    *this->name = name;
    *this->path = path;
    *this->genre = genre;
}

Game::Game(string &name, string &path, string &&genre) {
    this->name = new string;  
    this->path = new string;
    this->genre = new string;
    *this->name = name;
    *this->path = path;
    *this->genre = genre;
}

// Deep copy constructor

Game::Game(const Game &other) {
    name = new string;  
    path = new string;
    genre = new string;
    *name = *other.name;
    *path = *other.path;
    *genre = *other.genre;
}

// Move constructor

Game::Game(Game &&other): name{other.name}, path{other.path}, genre{other.genre} {
    other.name = nullptr;
    other.path = nullptr;
    other.genre = nullptr;
}

// Custom destructor

Game::~Game() {
    delete name;
    delete path;
    delete genre;
}
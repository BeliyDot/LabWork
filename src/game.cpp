#include "game.h"
#include <iostream>
#include <ostream>
using namespace std;

void Game::printInfo() {
    cout << "Name: " << *name << endl
    << "Genre: " << *genre << endl;
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
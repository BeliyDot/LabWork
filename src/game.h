#ifndef LABWORK_GAME_H
#define LABWORK_GAME_H

#include <ostream>
#include <vector>
#include <iostream>
using namespace std;

class Game {
private:
    unsigned int id;
    string *name;
    string *path;
    string *genre;
    vector<string> tags; 

public:
    string getGenre() { return *genre; }
    void addTag(string &tag) { tags.push_back(tag); }
    void rename(string &&newName);
    Game(string &&name, string &&path);
    Game(string &&name, string &&path, string &&genre);
    Game(string &name, string &path);
    Game(string &name, string &path, string &&genre);
    Game(const Game &other);
    Game(Game &&other);
    ~Game();
    friend std::ostream &operator<<(std::ostream &os, const Game &obj);
    Game &operator=(const Game &rhs);
};

#endif
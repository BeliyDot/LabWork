#ifndef LABWORK_GAME_H
#define LABWORK_GAME_H

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
    void printInfo();
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
};

#endif
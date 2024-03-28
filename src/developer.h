#ifndef LABWORK_DEVELOPER_H
#define LABWORK_DEVELOPER_H

#include "devgame.h"
#include "library.h"
#include "user.h"

class Developer final : public User {
private:
    vector<DevGame> devLib;
    bool dev = true;
public:
    void addDevGame(DevGame game) { devLib.push_back(game); }

    virtual void description() override { cout << "I am a game library user and also a developer. My username is " << getUsername() << '.' << endl; }
    virtual void hasLibrary() override { cout << "I have a game library. It contains " << library->gameCount() << " games. Also I have " << devLib.size()
    << " games in development." << endl; }

    Developer(): User() {} 
    Developer(string &username, string &email, string &password, unsigned int id = 0, Person persona = Person()):
        User(username, email, password, 1, 0, id, persona) {}
    Developer(string &&username, string &&email, string &&password, unsigned int id = 0, Person persona = Person()):
        User(username, email, password, 1, 0, id, persona) {}
    Developer(string &username, string &email, string &password, bool isDev, bool isAdmin, unsigned int id = 0, Person persona = Person()):
        User(username, email, password, isDev, isAdmin, id, persona) {}
    Developer(string &&username, string &&email, string &&password, bool isDev, bool isAdmin, unsigned int id = 0, Person persona = Person()):
        User(username, email, password, isDev, isAdmin, id, persona) {}
    Developer(const User &other):
        User(other) {}
    virtual ~Developer() { }
};

#endif
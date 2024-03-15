#ifndef LABWORK_DEVELOPER_H
#define LABWORK_DEVELOPER_H

#include "devgame.h"
#include "library.h"
#include "user.h"

class Developer final : public User {
private:
    vector<DevGame> devLib;
public:
    void addDevGame(DevGame game) { devLib.push_back(game); }
    virtual void description() override { cout << "I am a game library user and also a developer. My username is " << getUsername() << '.' << endl; }
    virtual void hasLibrary() override { cout << "I have a game library. It contains " << library->gameCount() << " games. Also I have " << devLib.size()
    << " games in development." << endl; }
    Developer(): User() {} 
    Developer(string &username, string &email, string &password, Person persona = Person()):
        User(username, email, password, persona) {}
    Developer(string &&username, string &&email, string &&password, Person persona = Person()):
        User(username, email, password, persona) {}
    virtual ~Developer() { }
};

#endif
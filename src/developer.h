#ifndef LABWORK_DEVELOPER_H
#define LABWORK_DEVELOPER_H

#include "devgame.h"
#include "user.h"

class Developer final : public User {
private:
    vector<DevGame> devLib;
public:
    void addDevGame(DevGame game) { devLib.push_back(game); }
    Developer(string &username, string &email, string &password, Person persona = Person()):
        User(username, email, password, persona) {}
};

#endif
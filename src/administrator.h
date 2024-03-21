#ifndef LABWORK_ADMINISTRATOR_H
#define LABWORK_ADMINISTRATOR_H

#include "user.h"
#include "developer.h"

class Administrator : public User {
public:
    vector<User> getUsers();
    vector<Game> getGames();
    vector<DevGame> getRequested();

    void printUsers();
    void printGames();
    void printRequested();
    void confirmRelease(Game &requested);
    void rejectRlease(Game &requested, string explanation);

    void ban(User &usr);
    void deleteGame(Game &game);
};


#endif
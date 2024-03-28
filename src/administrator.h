#ifndef LABWORK_ADMINISTRATOR_H
#define LABWORK_ADMINISTRATOR_H

#include "user.h"
#include "developer.h"

class Administrator : public User {
private:
    bool admin = true;
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
    
    Administrator();
    Administrator(string &&newUsername, string &&newEmail, string &&newPassword, unsigned int newId = 0, Person persona = Person());
    Administrator(string &newUsername, string &newEmail, string &newPassword, unsigned int newId = 0, Person persona = Person());
    Administrator(string &&newUsername, string &&newEmail, string &&newPassword, bool isRDev, bool isRAdmin, unsigned int newId = 0, Person persona = Person());
    Administrator(string &newUsername, string &newEmail, string &newPassword, bool isRDev, bool isRAdmin, unsigned int newId = 0, Person persona = Person());
    Administrator(const User &other);

};


#endif
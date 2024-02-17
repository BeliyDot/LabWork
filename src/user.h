#ifndef LABWORK_USER_H
#define LABWORK_USER_H

#include <string>
#include <vector>
#include "library.h"
using namespace std;

class User {
private:
    unsigned int id;
    bool online;
    string username;
    string email;
    string password;
    Library *library = new Library();
public:
    void printLibrary(); 
    void addGame(Game newGame) { library->addGame(newGame); }
    Library getLibrary(); 
    void login(string &name, string &password);
    User();
    User(string &&newUsername, string &&newEmail, string &&newPassword);
    User(string &newUsername, string &newEmail, string &newPassword);
    ~User();
};




#endif
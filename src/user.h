#ifndef LABWORK_USER_H
#define LABWORK_USER_H

#include <string>
#include <vector>
#include "library.h"
#include "person.h"
#include "collection.h"
using namespace std;

class User : public Person {
private:
    unsigned int id;
    bool online;
    string username;
    string email;
    string password;
    vector<Collection> collections;
public:
    Library *library;
    void printLibrary(); 
    void login(string &name, string &password);
    void printInfo();
    void createCollection(string &name, vector<Game> games = {});
    void createCollection(string &name, vector<int> indexes = {});
    void addToCollection(string &name, Game game);
    bool hasCollection(Collection collection);
    void printCollections();
    User();
    User(string &&newUsername, string &&newEmail, string &&newPassword, Person persona = Person());
    User(string &newUsername, string &newEmail, string &newPassword, Person persona = Person());
    User(const User &other);
    ~User();
    User &operator=(const User &rhs);
};




#endif
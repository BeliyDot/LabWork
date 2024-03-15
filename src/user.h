#ifndef LABWORK_USER_H
#define LABWORK_USER_H

#include <istream>
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
    string getUsername() { return username; }
    Library *library;
    virtual void description() override { cout << "I am a game library user. My username is " << username << '.' << endl; }
    virtual void hasLibrary() override { cout << "I have a game library. It contains " << library->gameCount() << " games." << endl; }
    void printLibrary(); 
    void login(string &name, string &password);
    void printInfo();
    void createCollection(string &name, vector<Game> games = {});
    void createCollection(string &name, vector<int> indexes = {});
    void addToCollection(string &name, Game game);
    bool hasCollection(Collection collection);
    void printCollections();
    void sayHi() { cout << "Hi from " << username << endl; }
    User();
    User(string &&newUsername, string &&newEmail, string &&newPassword, Person persona = Person());
    User(string &newUsername, string &newEmail, string &newPassword, Person persona = Person());
    User(const User &other);
    User(const User &other, Person &persona); 
    virtual ~User();
    User &operator=(const User &rhs);
    friend ostream &operator<<(ostream &os, const User &usr);
    friend istream &operator>>(istream &is, User &usr);
};




#endif
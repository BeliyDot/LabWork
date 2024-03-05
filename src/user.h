#ifndef LABWORK_USER_H
#define LABWORK_USER_H

#include <string>
#include <vector>
#include "library.h"
#include "person.h"
using namespace std;

class User : public Person {
private:
    unsigned int id;
    bool online;
    string username;
    string email;
    string password;
public:
    Library *library;
    void printLibrary(); 
    void login(string &name, string &password);
    void printInfo();
    User();
    User(string &&newUsername, string &&newEmail, string &&newPassword, Person persona = Person());
    User(string &newUsername, string &newEmail, string &newPassword, Person persona = Person());
    User(const User &other);
    ~User();
    User &operator=(const User &rhs);
};




#endif
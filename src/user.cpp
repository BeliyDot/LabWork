#include "user.h"
#include "library.h"
#include <string>

void User::login(string &name, string &password) {
    if(name == this->username || name == this->email && password == this->password) online = true;
}

void User::printLibrary() { cout << username << "'s "; library->printInfo(); }

Library User::getLibrary() { return *library; }

User::User(): User{"na", "na", "na"} {}

User::User(string &&newUsername, string &&newEmail, string &&newPassword): username{newUsername}, email{newEmail}, password{newPassword} {} 

User::User(string &newUsername, string &newEmail, string &newPassword): username{newUsername}, email{newEmail}, password{newPassword} {
    id = 0;
} 

User::~User() {
    delete library;
}
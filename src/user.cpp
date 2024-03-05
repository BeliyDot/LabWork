#include "user.h"
#include "library.h"
#include <string>

void User::login(string &name, string &password) {
    if((name == this->username || name == this->email) && password == this->password) online = true;
}

void User::printLibrary() { cout << username << "'s "; cout << *library; }


void User::printInfo() {
    cout << "Username: " << username << endl;
    cout << *this;
}

User::User(): User{"na", "na", "na"} {}

User::User(string &&newUsername, string &&newEmail, string &&newPassword, Person persona): 
    username{newUsername}, email{newEmail}, password{newPassword}, Person(persona) 
    {
    id = 0;
    library = new Library();
} 

User::User(string &newUsername, string &newEmail, string &newPassword, Person persona):
    username{newUsername}, email{newEmail}, password{newPassword}, Person(persona) 
    {
    id = 0;
    library = new Library();
} 

User::~User() {
    delete library;
}

User &User::operator=(const User &rhs) {
    if(this == &rhs) return *this;

    *this->library = *rhs.library;
    this->id = rhs.id;
    this->username = rhs.username;
    this->password = rhs.password;
    this->email = rhs.email;
    
    return *this;
}
#include "user.h"
#include "collection.h"
#include "library.h"
#include <string>

void User::login(string &name, string &password) {
    if((name == this->username || name == this->email) && password == this->password) online = true;
}

void User::printLibrary() { cout << username << "'s game library:" << endl; cout << *library; }


void User::printInfo() {
    cout << "Username: " << username << endl;
    cout << *this;
}

bool User::hasCollection(Collection collection) {
    for(Collection coll : collections) {
        if(coll == collection) return true;
    }
    return false;
}

void User::createCollection(string &name, vector<Game> games) {
    collections.push_back(Collection(name, *library, games));
}

void User::createCollection(string &name, vector<int> indexes) {
    collections.push_back(Collection(name, *library, indexes));
}

void User::addToCollection(string &name, Game game) {
    for(Collection collection : collections) {
        if(collection.getName() == name && library->hasGame(game)) { collection.addGame(game); }
    }
}

void User::printCollections() {
    cout << username << "'s collections:" << endl;
    for(Collection collection : collections) {
        cout << collection.getName() << ": " << collection << endl;
    }
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

User::User(const User &other): username{other.username}, email{other.email}, password{other.password}, id{other.id} {
    library = new Library();
    *library = *other.library;
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
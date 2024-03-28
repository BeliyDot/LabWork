#include "user.h"
#include "collection.h"
#include "library.h"
#include <ostream>
#include <string>
#include <fstream>

bool User::login(string &name, string &password) {
    if((name == this->username || name == this->email) && password == this->password) {
        online = true;
        return true;
    }
    return false;
}

// Collection management methods

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
    for(int i = 0; i < collections.size(); i++) {
        if(collections[i].getName() == name && library->hasGame(game)) { 
            collections[i].addGame(game); 
            break;
        }
    }
}

// Printable methods

void User::printCollections() {
    cout << username << "'s collections:" << endl;
    for(Collection collection : collections) {
        cout << collection.getName() << ": " << endl << collection << endl;
    }
}

void User::printLibrary() { cout << username << "'s game library:" << endl; cout << *library; }

void User::printInfo() {
    cout << "Username: " << username << endl;
    cout << *this;
}

// Constructors & destructor

User::User(): User{"na", "na", "na", 0, 0} {}

User::User(string &&newUsername, string &&newEmail, string &&newPassword, bool isRDev, bool isRAdmin, Person persona): 
    username{newUsername}, email{newEmail}, password{newPassword}, dev{isRDev}, admin{isRAdmin}, Person(persona) 
    {
    ifstream users("data/users.txt", ios::ate);
    if(users.is_open()) {
        users >> id;
    } else id = 0; 
    library = new Library();
} 


User::User(string &newUsername, string &newEmail, string &newPassword, Person persona):
 User(newUsername, newEmail, newPassword, 0, 0, persona) {}
 
User::User(string &&newUsername, string &&newEmail, string &&newPassword, Person persona):
 User(newUsername, newEmail, newPassword, 0, 0, persona) {}

User::User(string &newUsername, string &newEmail, string &newPassword, bool isRDev, bool isRAdmin, Person persona):
    username{newUsername}, email{newEmail}, password{newPassword}, dev{isRDev}, admin{isRAdmin}, Person(persona) 
    {
    ifstream users("data/users.txt", ios::ate);
    if(users.is_open()) {
        users >> id;
    } else id = 0; 
    library = new Library();
} 

User::User(const User &other): 
        username{other.username}, email{other.email}, password{other.password}, id{other.id}, dev{other.dev}, admin{other.admin} {
    library = new Library();
    *library = *other.library;
}

User::User(const User &other, Person &persona): 
        Person(persona), username{other.username}, email{other.email}, password{other.password}, id{other.id}, dev{other.dev}, admin{other.admin}{
    library = new Library();
    *library = *other.library;
}

User::~User() {
    delete library;
}

// Operator overloads

User &User::operator=(const User &rhs) {
    if(this == &rhs) return *this;

    *this->library = *rhs.library;
    this->id = rhs.id;
    this->username = rhs.username;
    this->password = rhs.password;
    this->email = rhs.email;
    this->admin = rhs.admin;
    this->dev = rhs.dev;
    
    return *this;
}

ostream &operator<<(ostream &os, const User &usr) {
    os << "Username: " << usr.username << endl
    << "Email: " << usr.email << endl
    << usr;
    return os;
}

istream &operator>>(istream &is, User &usr) {
    string username, email, password;
    bool isDev, isAdmin;
    
    is >> username >> email >> password >> isDev >> isAdmin;
    usr = User(username, email, password, isDev, isAdmin);

    return is;
}
#include "console.h"
#include <iostream>
#include <fstream>

using namespace std;

void Console::start() {
    cout << "Not Steam At All (NSAA) CLI, v0.1" << endl;
    User *usr = nullptr;
    while(usr == nullptr) {
        string username, password;
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        usr = login(username, password);
    }
    while(true) {
        string request;
        cout << usr->getUsername() << "> ";
        cin >> request;
        int index = 0;
        for(int i = 0; i < request.size(); i++) {
            if(request[i] == ' ' || i == request.size() - 1) {
                Commands command = commands[request.substr(index, i-1)];
                switch(command) {
                    case help:
                        printHelp();
                        break;
                    default:
                        cout << "Invalid command!";
                        break;
                }
            }
        }
    }
}

User *Console::login(string &login, string &password) {
    ifstream users("data/users.txt"); 
    User *usr = new User();
    if(users.is_open()) {
        while(users.eof()) {
            users >> *usr;
            if(usr->login(login, password))
                return usr;
        }
        cout << "Invalid login or password. Please try again." << endl;
    }

    return nullptr;
}
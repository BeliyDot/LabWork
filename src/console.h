#ifndef LABWORK_CONSOLE_H
#define LABWORK_CONSOLE_H

#include "user.h"

class Console {
private:
    enum Commands {
        help,
        info,
        me,
        buy,
        launch,
        library,
        quit,
        exit
    };
    enum AdminCommands {
        addusr,
        getusers,
        delgame,
        getrequests,
        ban
    };
public:
    static void start();
    static void launchGame(Game game);
    static void printInfo();
    static void printHelp();
    static void addUser(User &usr);
    static User login(string &username, string &password);
};

#endif
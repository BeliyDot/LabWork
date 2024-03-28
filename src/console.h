#ifndef LABWORK_CONSOLE_H
#define LABWORK_CONSOLE_H

#include "user.h"
#include <unordered_map>

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
        exit,
        addusr,
        getusers,
        delgame,
        getrequests,
        ban
    };
    inline static unordered_map<string, Commands> commands = {
        {"help", help},
        {"info", info},
        {"me", me},
        {"buy", buy},
        {"launch", launch},
        {"library", library},
        {"quit", quit},
        {"exit", exit},
        {"addusr", addusr},
        {"getusers", getusers},
        {"delgame", delgame},
        {"getrequests", getrequests},
        {"ban", ban}
    };
public:
    static void start();
    static void launchGame(Game game);
    static void printInfo();
    static void printHelp();
    static void addUser(User &usr);
    static User *login(string &username, string &password);
};

#endif
#include <iostream>
#include "user.h"
#include "library.cpp"
#include "game.cpp"
#include "user.cpp"
using namespace std;

int main()
{
    cout << "Example program." << endl;
    cout << "another example." << endl;
    User dummy;
    dummy.printLibrary();
    User someone("Ub1y Canegrov", "someone@mymail.com", "123452");
    someone.printLibrary();
    Game game1("Minecraft", "path/to/minecraft.exe");
    someone.library->addGame(game1);
    someone.printLibrary();
}

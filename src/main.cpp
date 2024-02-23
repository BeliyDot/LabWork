#include <iostream>
#include "user.h"
using namespace std;

int main()
{
    User dummy;
    dummy.printLibrary();
    
    User someone("Ub1y Canegrov", "someone@mymail.com", "123452");
    someone.printLibrary();
    
    Game game1("Minecraft", "path/to/minecraft.exe");
    const Game game2("Need For Speed Most Wanted", "path/to/speed.exe", "Racing");
    // game2.rename("Need For Speed Underground");
    
    someone.library->addGame(game1);
    someone.library->addGame(game2);
    someone.printLibrary();
}

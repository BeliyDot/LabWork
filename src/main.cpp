#include <iostream>
#include "user.h"
#include "developer.h"
using namespace std;


void print(Person &pers) {
    cout << pers;
}

int main()
{
    User dummy;
    dummy.printLibrary();
    dummy.printInfo();
    
    User someone("Ub1y Canegrov", "someone@mymail.com", "123452");
    someone.printLibrary();
    
    Game game1("Minecraft", "path/to/minecraft.exe");
    Game game2("Need For Speed Most Wanted", "path/to/speed.exe", "Racing");
    // game2.rename("Need For Speed Underground");
    
    someone.library->addGame(game1);
    someone.library->addGame(game2);
    someone.printLibrary();
    
    cout << someone.library->hasGame(game1);

    Person artem = Person("Artem", "Biliakov", "Evgenovich");
    User belDot("beldot", "bruhers@gmai.com", "1234", artem);
    belDot.printInfo();
    belDot.printLibrary();
    belDot.printCollections();
    
    belDot.library->addGame(game1);
    belDot.library->addGame(game2);

    string name = "Need For Speed";
    belDot.createCollection(name, vector<Game>());
    cout << belDot.library->hasGame(game2) << endl;
    belDot.addToCollection(name, game2);

    belDot.printInfo();
    belDot.printLibrary();
    belDot.printCollections();
    
    artem.sayHi();
    belDot.sayHi();
    
    Person *example = new User;
    example->sayHi();
    
    example->description();
    example->hasLibrary();
    
    Person *anotherExample = new Developer();
    anotherExample->description();
    anotherExample->hasLibrary();
    
    Person john = Person("John", "Carmack", "Doom");
    Developer carmack("carmack1993", "john.carmack@aol.com", "0p3n-s0urc3", Person("John", "Carmack", ""));

    print(belDot);
    print(carmack);
    print(john);

    delete example;
    delete anotherExample;
}

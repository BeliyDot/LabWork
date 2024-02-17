#include "library.h"
#include <iostream>
using namespace std;

void Library::printInfo() {
    cout << "Game Library: " << endl;
    for(int i = 0; i < games.size(); i++) {
        cout << i + 1 << ". ";
        games[i].printInfo();
    }
}

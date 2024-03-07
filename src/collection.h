#ifndef LABWORK_COLLECTION_H
#define LABWORK_COLLECTION_H

#include "library.h"

class Collection : public Library {
private:
    string *name;
public:
    string getName() { return *name; }
    Collection(string &name) {
        this->name = new string;
        *this->name = name;
    }
    Collection(string &&name) {
        this->name = new string;
        *this->name = name;
    }
    Collection(string &name, Library lib, vector<int> indexes);
    Collection(string &name, Library lib, vector<Game> games);
    bool &operator==(const Collection &rhs) const;
};


#endif
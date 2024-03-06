#ifndef LABWORK_COLLECTION_H
#define LABWORK_COLLECTION_H

#include "library.h"

class Collection : public Library {
private:
    string *name;
public:
    Collection(string &name) {
        this->name = new string;
        *this->name = name;
    }
    Collection(string &&name) {
        this->name = new string;
        *this->name = name;
    }
};

#endif
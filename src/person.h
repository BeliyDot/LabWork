#ifndef LABWORK_PERSON_H
#define LABWORK_PERSON_H

#include <string>
#include <iostream>

using namespace std;

class Person {
private:
    string *firstName;
    string *secondName;
    string *thirdName;
    int birthYear;
    int birthMonth;
    int birthDay;
public:
    Person(string newFirstName = "Unknown", string newSecondName = "Unknown", string newThirdName = "Unknown");
    Person(string &firstName, string &secondName, string newThirdName = "Unknown");
    Person(string &newFirstName, string &newSecondName, string &newThirdName);
    Person(string &firstName, string &secondName, string &thirdName, int newBirthYear, int newBirthMonth, int newBirthDay);
    ~Person();
    friend ostream &operator<<(ostream &os, const Person &obj);
};

#endif
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
    void sayHi() { cout << "Hi from " << *firstName << endl; }

    virtual void description() { cout << "I am a Person. My name is " << *firstName << '.' << endl; }
    virtual void hasLibrary() { cout << "I don't have any library." << endl; }

    Person(string newFirstName = "Unknown", string newSecondName = "Unknown", string newThirdName = "Unknown");
    Person(string &firstName, string &secondName, string newThirdName = "Unknown");
    Person(string &newFirstName, string &newSecondName, string &newThirdName);
    Person(string &firstName, string &secondName, string &thirdName, int newBirthYear, int newBirthMonth, int newBirthDay);
    Person(const Person &obj);
    virtual ~Person();

    Person &operator=(const Person &rhs);
    friend ostream &operator<<(ostream &os, const Person &obj);
};

#endif
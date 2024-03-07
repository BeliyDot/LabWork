#include "person.h"
#include <ostream>
#include <string>
#include <iostream>
using namespace std;


Person::Person(string &newFirstName, string &newSecondName, string &newThirdName):
    Person{newFirstName, newSecondName, newThirdName, 0, 0, 0} {}

Person::Person(string &newFirstName, string &newSecondName, string newThirdName):
    Person{newFirstName, newSecondName, newThirdName, 0, 0, 0} {}
    
Person::Person(string newFirstName, string newSecondName, string newThirdName):
    Person{newFirstName, newSecondName, newThirdName, 0, 0, 0} {}
    
Person::Person(const Person &obj): birthDay{obj.birthDay}, birthMonth{obj.birthMonth}, birthYear{obj.birthYear} {
    firstName = new string;
    secondName = new string;
    thirdName = new string;
    *firstName = *obj.firstName;
    *secondName = *obj.secondName;
    *thirdName = *obj.thirdName;
}

Person::Person(std::string &firstName, std::string &secondName, std::string &thirdName, int newBirthYear, int newBirthMonth, int newBirthDay):
    birthYear{newBirthYear}, birthMonth{newBirthMonth}, birthDay{newBirthDay} {
   this->firstName = new string; 
   this->secondName = new string;
   this->thirdName = new string;
   *this->firstName = firstName;
   *this->secondName = secondName;
   *this->thirdName = thirdName;
}

Person::~Person() {
    delete firstName;
    delete secondName;
    delete thirdName;
}    

ostream &operator<<(ostream &os, const Person &obj) {
    os << "First name: " << *obj.firstName << endl
    << "Second name: " << *obj.secondName << endl
    << "Third name: " << *obj.thirdName << endl
    << "Date of birth: ";
    if(obj.birthYear == 0) os << "Unknown" << endl;
    else os << obj.birthDay << '/' << obj.birthMonth << '/' << obj.birthYear << '/' << endl;
    return os;    
}

Person &Person::operator=(const Person &rhs) {
    if(this == &rhs) return *this;

    *this->firstName = *rhs.firstName;
    *this->secondName = *rhs.secondName;
    *this->thirdName = *rhs.thirdName;
    this->birthDay = rhs.birthDay;
    this->birthYear = rhs.birthYear;
    this->birthMonth = rhs.birthMonth;

    return *this;
}
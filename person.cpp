#include "person.h"

using namespace std;

string Person::name() const {
    return _name;
}

void Person::setName(const string &name) {
    if (_name != name)
        _name = name;
}

int Person::age() const {
    return _age;
}

void Person::setAge(const int &age) {
    if (age >= 0 && _age != age)
        _age = age;
}
int Person::sallary() const {
    return _sallary;
}

void Person::setSallary(const int &sallary) {
    if (sallary >= 0 && _sallary != sallary)
        _sallary = sallary;
}

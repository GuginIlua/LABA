#pragma once
#include <string>
#include <iostream>
#include <ostream>
class Person{
private:
    std::string _name;
    int _age =0;
    int _sallary =0;
public:
    std::string name() const;
    void setName(const std::string &name);
    int age() const;
    void setAge(const int &age);
    int sallary() const;
    void setSallary(const int &sallary);
    std::string getName()  { return _name; }
    int getAge()  { return _age; }
    int getSallary() { return _sallary; }

};



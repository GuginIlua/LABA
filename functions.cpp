#include <iostream>
#include <fstream>
#include <string>

#include "functions.h"

using namespace std;

void functions::save(Person *arr, const int &n) {
    ofstream file("text.txt");
    if (!file.is_open()) {
        cout << "save: file error" << endl;
        return;
    }
    file << n << endl;
    for (int i = 0; i < n; i++)
        file << arr[i].name() << " " << arr[i].age() << " " << arr[i].sallary() <<endl;
    file.close();
}

Person * functions::load(int &n) {
    ifstream file("text.txt");
    if (!file.is_open()) {
        cout << "load: file error" << endl;
        return nullptr;
    }
    file >> n;
    if (n <= 0) {
        cout << "load: n error" << endl;
        return nullptr;
    }

    Person* arr = new Person[n];
    for (int i = 0; i < n; i++) {
        string name;
        int age;
        int sallary;
        file >> name >> age>> sallary;
        arr[i].setName(name);
        arr[i].setAge(age);
        arr[i].setSallary(sallary);
    }
    file.close();
    return arr;
}

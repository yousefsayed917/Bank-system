#pragma once
#include <iostream>
#include<string>
using namespace std;
class Person
{
protected:
    int id;
    string name, password;
public:
    Person() {
        id = 0;
    }
    Person(int id, string name, string password) {
        this->id = id;
        this->name = name;
        this->password = password;
    }
    void setId(int id) {
        this->id = id;
    }
    void setName(string name) {
        this->name = name;
    }
    void setPassword(string password) {
        this->password = password;
    }
    int getId() {
        return this->id;
    }
    string getName() {
        return this->name;
    }
    string getPassword() {
        return this->password;
    }
    void Display() {

    }
};
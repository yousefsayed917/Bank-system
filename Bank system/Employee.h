#pragma once
#include<iostream>
#include <vector>
#include <iterator>
#include"Client.h"
using namespace std;
class Employee : public Person
{
protected:
	double salary;
public:
	Employee() : Person() {
		salary = 0;
	}
	Employee(int id, string name, string password, double salary) : Person(id, name, password) {
		setSalary(salary);
	}
	Employee(string name, string password, double salary) {
		this->name = name;
		this->password = password;
		setSalary(salary);
	}
	void setSalary(double salary) {
			this->salary = salary;
	}
	double getSalary() {
		return salary;
	}
	void Display() {
		Person::Display();
		cout << "Salary : " << getSalary() << endl;
		cout << "================\n";
	}
};
static vector<Employee> employees;
static vector<Employee>::iterator eIt;

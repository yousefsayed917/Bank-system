#pragma once
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

	void addClient(Client& client) {
		clients.push_back(client);
	}

	Client* searchClient(int id) {
		for (cIt = clients.begin(); cIt != clients.end(); cIt++) {
			if (cIt->getId() == id) return cIt._Ptr;
		}
		return nullptr;
	}

	void listClient() {
		for (cIt = clients.begin(); cIt != clients.end(); cIt++) {
			cIt->Display();
		}
	}

	void editClient(int id, string name, string password, double balance) {
		searchClient(id)->setName(name);
		searchClient(id)->setPassword(password);
		searchClient(id)->setBalance(balance);
	}

	void Display() {
		Person::Display();
		cout << "Salary : " << getSalary() << endl;
		cout << "-------------\n";
	}
};
static vector<Employee> employees;
static vector<Employee>::iterator eIt;
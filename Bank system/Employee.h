#pragma once
#include<iostream>
#include <vector>
#include <iterator>
#include "Client.h"
using namespace std;
class Employee : public Person
{
private:
	double salary;
public:
	Employee() : Person() {
		salary = 0;
	}
	Employee(int id, string name, string password, double salary) : Person(id, name, password) {
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
		for (int i = 0; i < clients.size(); i++) {
			if (clients[i].getId() == id) {
				Client* p = &clients[i];
				return p;
			}
		}
		cout << " this client is not found \n";
		return nullptr;
	}
	void listClient() {
		for (cIt = clients.begin(); cIt != clients.end(); cIt++) {
			cIt->Display();
			cout << "===========================\n";
		}
	}
	void editClient(int id, string name, string password, double balance) {

		Client* p = searchClient(id);

		if (p != nullptr) {
			p->setName(name);
			p->setPassword(password);
			p->setBalance(balance);
		}
		else {
			cout << " this client is not found \n";
		}
	}
	void Display() {
		cout << " Name : " << getName() << endl;
		cout << " id : " << getId() << endl;
		cout << "Salary : " << getSalary() << endl;
		cout << "====================================== \n";
	}
};
static vector<Employee> employees;
static vector<Employee>::iterator eIt;

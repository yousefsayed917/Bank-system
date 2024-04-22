#pragma once
#include <vector>
#include <iterator>
#include "Person.h"
using namespace std;
class Client : public Person
{
	double balance;

public:

	Client() {
		this->balance = 0.0;
	}
	Client(int id, string name, string password, double balance) :Person(id, name, password) {
		this->balance = balance;
	}
	void setBalance(double balance) {
		this->balance = balance;
	}
	double getBalance() {          // or check balance
		return this->balance;
	}
	void deposit(double amount) {
		if (amount > 0)
			this->balance += amount;
	}
	void withdraw(double amount) {
		if (amount <= balance) {
			this->balance -= amount;
		}
		else {
			cout << " Amount exceeded balance " << endl;
		}
	}
	void transfareTo(Client& c, double amount) {
		if (amount <= balance) {
			balance -= amount;
			c.deposit(amount);
		}
		else {
			cout << " Amount exceeded balance " << endl;
		}
	}
	void checkBalance() {
		cout << getBalance() << endl;
	}
	void Display() {
		cout << " Name : " << getName() << endl;
		cout << " id : " << getId() << endl;
		cout << " Balance : " << getBalance() << endl;
		cout << "====================================== \n";
	}
};
static vector<Client> clients;
static vector<Client>::iterator cIt;
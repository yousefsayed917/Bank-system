#pragma once
#include "Employee.h"

#define E_FILE_PATH "data/employees.txt"
#define EID_FILE_PATH "data/employees_id.txt"
class Admin : public Employee
{
public:
	Admin() : Employee() {

	}
	Admin(int id, string name, string password, double salary) : Employee(id, name, password, salary) {

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
		Client* p = searchClient(id);
		if (p != nullptr) {
			p->setName(name);
			p->setPassword(password);
			p->setBalance(balance);
		}
	}
	void addEmployee(Employee& employee) {
		employees.push_back(employee);
	}
	Employee* searchEmployee(int id) {
		for (eIt = employees.begin(); eIt != employees.end(); eIt++) {
			if (eIt->getId() == id) return eIt._Ptr;
		}
		return nullptr;
	}
	void listEmployee() {
		for (eIt = employees.begin(); eIt != employees.end(); cIt++) {
			eIt->Display();
		}
	}
	void editEmployee(int id, string name, string password, double salary) {

		Employee* p = searchEmployee(id);

		if (p != nullptr) {
			p->setName(name);
			p->setPassword(password);
			p->setSalary(salary);
		}
	}
};
static vector<Admin> admins;
static vector<Admin>::iterator aIt;


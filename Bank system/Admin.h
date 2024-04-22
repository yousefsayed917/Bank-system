#pragma once
#include "Employee.h"
class Admin : public Employee
{
public:
	Admin() : Employee() {

	}
	Admin(int id, string name, string password, double salary) : Employee(id, name, password, salary) {

	}
	void addEmployee(Employee& employee) {
		employees.push_back(employee);
	}
	Employee* searchEmployee(int id) {
		for (int i = 0; i < employees.size(); i++) {
			if (employees[i].getId() == id) {
				Employee* p = &employees[i];
				return p;
			}
		}
		cout << " this client is not found \n";
		return nullptr;
	}
	void listEmployee() {
		for (eIt = employees.begin(); eIt != employees.end(); cIt++) {
			eIt->Display();
			cout << "===========================\n";
		}
	}
	void editEmployee(int id, string name, string password, double salary) {

		Employee* p = searchEmployee(id);

		if (p != nullptr) {
			p->setName(name);
			p->setPassword(password);
			p->setSalary(salary);
		}
		else {
			cout << " this client is not found \n";
		}
	}

};
static vector<Admin> admins;
static vector<Admin>::iterator aIt;


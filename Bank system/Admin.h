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
		for (eIt = employees.begin(); eIt != employees.end(); eIt++) {
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
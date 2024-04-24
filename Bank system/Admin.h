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
};
static vector<Admin> admins;
static vector<Admin>::iterator aIt;


#pragma once
#include "SuperEmployee.h"
#include "SuperAdmin.h"
using namespace std;
class EmployeeManager
{
public:
	static void printEmployeeMenu() {
		cout << " (1) Display my info \n";
		cout << " (2) Update Password \n";
		cout << " (3) Add new client \n";
		cout << " (4) Search for client \n";
		cout << " (5) List all clients \n";
		cout << " (6) Edit client info \n";
		cout << " (7) Logout \n";
	}
	static void UpdatePassword(Employee* employee) {
		string newpassword;
		cout << " enter the new password \n";
		cin >> newpassword;
		employee->setPassword(newpassword);
		Fileshelper::ClearFile(E_FILE_PATH, EID_FILE_PATH);
		for (eIt = employees.begin(); eIt != employees.end(); eIt++) {
			Fileshelper::saveEmployee(*eIt);
		}
		cout << "password updated successfully" << endl;
	}
	static Employee* Login(int id, string password) {
		SuperAdmin SA;
		Employee* p = SA.searchEmployee(id);
		if (p != nullptr) {
			if (p->getPassword() == password)
				return p;
			else
			{
				cout << "invalid password" << endl;
				return nullptr;
			}
		}
		else {
			return nullptr;
		}
	}
	static void newClient(Employee* employee) {
		string name;
		cout << " enter the name \n";
		cin >> name;
		string password;
		cout << " enter the password \n";
		cin >>password;
		double balance;
		cout << " enter the balance \n";
		cin >> balance;
		Client c(name, password, balance);
		SuperEmployee SE;
		SE.addClient(c);
	}
	static void listAllClients(Employee* employee) {
		SuperEmployee SE;
		SE.listClient();
	}
	static void searchForClient(Employee* employee) {
		cout << " enter id : \n";
		int x;
		cin >> x;
		SuperEmployee SE;
		Client* p = SE.searchClient(x);
		if (p != nullptr) 
			p->Display();
	}
	static void editClientInfo(Employee* employee) {
		int id;
		cout << " enter id : \n";
		cin >> id;
		string name;
		cout << " enter the new name \n";
		cin >> name;
		string password;
		cout << " enter the new password \n";
		cin >> password;
		double balance;
		cout << " enter the new balance \n";
		cin >> balance;
		SuperEmployee SE;
		SE.editClient(id, name, password, balance);
	}
	static bool employeeOptions(Employee* employee) {
		int x;
		cout << " your choice is : ";
		cin >> x;
		switch (x)
		{
		case 1: {
			system("cls");
			employee->Display();
			return true;
			break;
		}
		case 2: {
			system("cls");
			UpdatePassword(employee);
			return true;
			break;
		}
		case 3: {
			system("cls");
			newClient(employee);
			return true;
			break;
		}
		case 4: {
			system("cls");
			searchForClient(employee);
			return true;
			break;
		}
		case 5: {
			system("cls");
			listAllClients(employee);
			return true;
			break;
		}
		case 6: {
			system("cls");
			editClientInfo(employee);
			return true;
			break;
		}
		case 7: {
			return false;
			break;
		}
		default: {
			return true;
		}
		}
	}
};


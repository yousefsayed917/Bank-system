#pragma once
#include "Admin.h"
#include "Validation.h"
#include "Fileshelper.h"
#include "FileManager.h"
class AdminManager
{
public:
	static void printAdminMenu() {
		cout << " (1) Display my info \n";
		cout << " (2) Update Password \n";
		cout << " (3) Add new client \n";
		cout << " (4) Search for client \n";
		cout << " (5) List all clients \n";
		cout << " (6) Edit client info \n";
		cout << " (7) Add new employee \n";
		cout << " (8) Search for employee \n";
		cout << " (9) List all employees \n";
		cout << " (10) Edit employee info \n";
		cout << " (11) Logout \n";
	}
	static void UpdatePassword(Admin* admin) {
		string newpassword;
		cout << " enter the new password \n";
		cin >> newpassword;
		admin->setPassword(newpassword);
		cout << "password updated successfully" << endl;
	}
	static Admin* Login(int id, string password) {
		Admin* p = nullptr;
		for (aIt = admins.begin(); aIt != admins.end(); aIt++) {
			if (aIt->getId() == id) 
				p = aIt._Ptr;
			else
				p = nullptr;
		}
		if (p != nullptr && p->getPassword() == password) {
			return p;
		}
		else
		{
			cout << "invalid password or ID" << endl;
			return nullptr;
		}
	}
	static void newClient(Admin* admin) {
		string name, password;
		double balance;
		int id = Fileshelper::getLast(CID_FILE_PATH);
		do {
			cout << "enter the name \n";
			cin >> name;
		} while (!Validation::validName(name));
		do {
			cout << "enter the password \n";
			cin >> password;
		} while (!Validation::ValidPassword(password));
		do {
			cout << " enter the balance \n";
			cin >> balance;
		} while (!Validation::ValidBalance(balance));
		Client c;
		c.setId(id);
		Fileshelper::saveLast(CID_FILE_PATH, id + 1);
		c.setName(name);
		c.setPassword(password);
		c.setBalance(balance);
		admin->addClient(c);
		cout << "the client is added successfully" << endl;
	}
	static void listAllClients(Admin* admin) {
		admin->listClient();
	}
	static void searchForClient(Admin* admin) {
		cout << " enter id : \n";
		int x;
		cin >> x;
		Client* p = admin->searchClient(x);
		if (p != nullptr)
			p->Display();
	}
	static void editClientInfo(Admin*admin) {
		int id;
		string name, password;
		double balance;
		cout << "Enter id : \n";
		cin >> id;
		do {
			cout << "enter the name \n";
			cin >> name;
		} while (!Validation::validName(name));
		do {
			cout << "enter the password \n";
			cin >> password;
		} while (!Validation::ValidPassword(password));
		do {
			cout << " enter the balance \n";
			cin >> balance;
		} while (!Validation::ValidBalance(balance));
		admin->editClient(id, name, password, balance);
	}
	static void newEmployee(Admin* admin) {
		string name, password;
		double salary;
		int id = Fileshelper::getLast(EID_FILE_PATH);
		do {
			cout << "enter the name \n";
			cin >> name;
		} while (!Validation::validName(name));
		do {
			cout << "enter the password \n";
			cin >> password;
		} while (!Validation::ValidPassword(password));
		do {
			cout << " enter the balance \n";
			cin >> salary;
		} while (!Validation::ValidSalary(salary));
		Employee e;
		e.setId(id);
		Fileshelper::saveLast(EID_FILE_PATH, id + 1);
		e.setName(name);
		e.setPassword(password);
		e.setSalary(salary);
		admin->addEmployee(e);
		cout << "the client is added successfully" << endl;
	}
	static void listAllEmployees(Admin* admin) {
		admin->listEmployee();
	}
	static void searchForEmployee(Admin* admin) {
		cout << " enter id : \n";
		int x;
		cin >> x;
		Employee* p = admin->searchEmployee(x);
		if (p != nullptr)
			p->Display();
	}
	static void editEmployeeInfo(Admin* admin) {
		int id;
		string name, password;
		double salary;
		cout << "Enter id : \n";
		cin >> id;
		do {
			cout << "enter the name \n";
			cin >> name;
		} while (!Validation::validName(name));
		do {
			cout << "enter the password \n";
			cin >> password;
		} while (!Validation::ValidPassword(password));
		do {
			cout << " enter the balance \n";
			cin >> salary;
		} while (!Validation::ValidSalary(salary));
		admin->editEmployee(id, name, password, salary);
	}
	static bool AdminOptions(Admin* admin) {
		int x;
		cout << " your choice is : ";
		cin >> x;
		switch (x)
		{
		case 1: {
			system("cls");
			admin->Display();
			return true;
			break;
		}
		case 2: {
			system("cls");
			UpdatePassword(admin);
			FileManager::UpdateAdminTXT();
			return true;
			break;
		}
		case 3: {
			system("cls");
			newClient(admin);
			FileManager::UpdateClientTXT();
			return true;
			break;
		}
		case 4: {
			system("cls");
			searchForClient(admin);
			return true;
			break;
		}
		case 5: {
			system("cls");
			listAllClients(admin);
			return true;
			break;
		}
		case 6: {
			system("cls");
			editClientInfo(admin);
			FileManager::UpdateClientTXT();
			return true;
			break;
		}
		case 7: {
			system("cls");
			newEmployee(admin);
			FileManager::UpdateEmployeeTXT();
			return true;
			break;
		}
		case 8: {
			system("cls");
			searchForEmployee(admin);
			return true;
			break;
		}
		case 9: {
			system("cls");
			listAllEmployees(admin);
			return true;
			break;
		}
		case 10: {
			system("cls");
			editEmployeeInfo(admin);
			FileManager::UpdateEmployeeTXT();
			return true;
			break;
		}
		case 11: {
			return false;
			break;
		}
		default: {
			return true;
		}
		}
	}
};


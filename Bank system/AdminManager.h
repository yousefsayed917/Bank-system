#pragma once
#include "SuperAdmin.h"
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
		Fileshelper::ClearFile(A_FILE_PATH, AID_FILE_PATH);
		for (aIt = admins.begin(); aIt != admins.end(); aIt++) {
			Fileshelper::saveAdmin(*aIt);
		}
		cout << "password updated successfully" << endl;
	}
	static Admin* Login(int id, string password) {
		Admin* p = nullptr;
		for (aIt = admins.begin(); aIt != admins.end(); aIt++) {
			if (aIt->getId() == id) {
				p = aIt._Ptr;
			}
			else
			{
				cout << " this Admin is not found \n";
				p = nullptr;
			}
		}
		if (p != nullptr) {
			if (p->getPassword() == password) {
				return p;
			}
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
	static void newClient(Admin* admin) {
		string name;
		cout << " enter the name \n";
		cin >> name;
		string password;
		cout << " enter the password \n";
		cin >> password;
		double balance;
		cout << " enter the balance \n";
		cin >> balance;
		Client c(name, password, balance);
		SuperAdmin SA;
		SA.addClient(c);
	}
	static void listAllClients(Admin* admin) {
		SuperAdmin SA;
		SA.listClient();
	}
	static void searchForClient(Admin* admin) {
		cout << " enter id : \n";
		int x;
		cin >> x;
		SuperAdmin SA;
		Client* p = SA.searchClient(x);
		if (p != nullptr)
			p->Display();
	}
	static void editClientInfo(Admin*admin) {
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
		SuperAdmin SA;
		SA.editClient(id, name, password, balance);
	}
	static void newEmployee(Admin* admin) {
		string name;
		cout << " enter the name \n";
		cin >> name;
		string password;
		cout << " enter the password \n";
		cin >> password;
		double balance;
		cout << " enter the balance \n";
		cin >> balance;
		Employee E(name, password, balance);
		SuperAdmin SA;
		SA.addEmployee(E);
	}
	static void listAllEmployees(Admin* admin) {
		SuperAdmin SA;
		SA.listEmployee();
	}
	static void searchForEmployee(Admin* admin) {
		cout << " enter id : \n";
		int x;
		cin >> x;
		SuperAdmin SA;
		Employee* p = SA.searchEmployee(x);
		if (p != nullptr)
			p->Display();
	}
	static void editEmployeeInfo(Admin* admin) {
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
		SuperAdmin SA;
		SA.editEmployee(id, name, password, balance);
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
			return true;
			break;
		}
		case 3: {
			system("cls");
			newClient(admin);
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
			return true;
			break;
		}
		case 7: {
			system("cls");
			newEmployee(admin);
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


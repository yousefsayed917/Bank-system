#pragma once
#include "Employee.h"
#include "Admin.h"
#include"ClientManager.h"
#include"Validation.h"
#include "Fileshelper.h"
#include "FileManager.h"
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

	static Employee* Login(int id, string password) {
		Admin A;
		Employee* p = A.searchEmployee(id);
		if (p != nullptr && p->getPassword() == password) {
			return p;
		}
			else
			{
				cout << "Invalid password or ID" << endl;
				return nullptr;
			}
		
	}
	static void newClient(Employee* employee) {
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
		employee->addClient(c);
		cout << "the client is added successfully" << endl;
	}
	static void listAllClients(Employee* employee) {
		employee->listClient();
	}
	static void searchForClient(Employee* employee) {
		cout << "enter id : \n";
		int x;
		cin >> x;
		Client* p = employee->searchClient(x);
		if (p != nullptr) 
			p->Display();
	}
	static void editClientInfo(Employee* employee) {
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
		employee->editClient(id, name, password, balance);
	}
	static bool employeeOptions(Employee* employee) {
		int x;
		cout << "your choice is : ";
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
				ClientManager::UpdatePassword(employee);
				FileManager::UpdateEmployeeTXT();
				return true;
				break;
			}
			case 3: {
				system("cls");
				newClient(employee);
				FileManager::UpdateClientTXT();
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
				FileManager::UpdateClientTXT();
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


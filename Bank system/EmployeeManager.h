#pragma once
#include "SuperEmployee.h"
#include "SuperAdmin.h"
#include"ClientManager.h"
#include"Validation.h"
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
		SuperAdmin SA;
		Employee* p = SA.searchEmployee(id);
		if (p != nullptr) {
			if (p->getPassword() == password)
				return p;
			else
			{
				cout << "Invalid password" << endl;
				return nullptr;
			}
		}
		else {
			cout << "Not found" << endl;
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
		SuperEmployee SE;
		SE.addClient(c);
		cout << "the client is added successfully" << endl;
	}
	static void listAllClients(Employee* employee) {
		SuperEmployee SE;
		SE.listClient();
	}
	static void searchForClient(Employee* employee) {
		cout << "enter id : \n";
		int x;
		cin >> x;
		SuperEmployee SE;
		Client* p = SE.searchClient(x);
		if (p != nullptr) 
			p->Display();
	}
	static void editClientInfo(Employee* employee) {
		int id;
		cout << "Enter id : \n";
		cin >> id;
		string name;
		cout << "enter the new name \n";
		cin >> name;
		string password;
		cout << "enter the new password \n";
		cin >> password;
		double balance;
		cout << "enter the new balance \n";
		cin >> balance;
		SuperEmployee SE;
		SE.editClient(id, name, password, balance);
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
				Fileshelper::ClearFile(E_FILE_PATH, EID_FILE_PATH);
				for (eIt = employees.begin(); eIt != employees.end(); eIt++) {
					Fileshelper::saveEmployee(*eIt);
				}
				Fileshelper::ClearFile(C_FILE_PATH, CID_FILE_PATH);
				for (cIt = clients.begin(); cIt != clients.end(); cIt++) {
					Fileshelper::saveClient(*cIt);
				}
				return false;
				break;
			}
			default: {
				return true;
			}
		}
	}
};


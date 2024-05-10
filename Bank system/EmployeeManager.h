#pragma once
#include"ClientManager.h"

class EmployeeManager
{
	static void printEmployeeMenu() {
		cout << "(1) Display my info \n";
		cout << "(2) Update Password \n";
		cout << "(3) Add new client \n";
		cout << "(4) Search for client \n";
		cout << "(5) List all clients \n";
		cout << "(6) Edit client info \n";
		cout << "(7) Logout \n";
	}

	static void back_exit(Employee* employee) {
		int c;
		do {
			cout << "\n\n(1) Options\t\t(0) Exit\n";
			cout << "..::Enter Choice: ";
			cin >> c;
			switch (c)
			{
			case 0:
				exit(0);
				break;
			case 1:
				system("cls");
				employeeOptions(employee);
				break;
			default:
				cout << "Invalid!" << endl;
				break;
			}
		} while (c < 0 || c > 1);
	}

public:

	static Employee* Login(int id, string password) {
		Admin A;
		Employee* p = A.searchEmployee(id);
		if (p != nullptr && p->getPassword() == password) {
			return p;
		}
		else {
			return nullptr;
		}
	}

	static void newClient(Employee* employee) {
		string name, password;
		double balance;
		int id = Fileshelper::getLast(CID_FILE_PATH) + 1;
		cout << "Client info: " << endl;
		cout << "-------------" << endl;
		do {
			cout << "Name: ";
			cin >> name;
		} while (!Validation::validName(name));
		do {
			cout << "Password: ";
			cin >> password;
		} while (!Validation::ValidPassword(password));
		do {
			cout << "Balance: ";
			cin >> balance;
		} while (!Validation::ValidBalance(balance));

		Client c;
		c.setId(id);
		Fileshelper::saveLast(CID_FILE_PATH, id);
		c.setName(name);
		c.setPassword(password);
		c.setBalance(balance);

		employee->addClient(c);

		FileManager::addClient(c);

		cout << "Added successfully" << endl;
	}

	static void searchForClient(Employee* employee) {
		int id;
		cout << "Client ID: ";
		cin >> id;
		Client* c = employee->searchClient(id);
		if (c != nullptr) {
			cout << "\nFounded\n" << endl;
			c->Display();
		}
		else
			cout << "Not founded" << endl;
	}

	static void editClientInfo(Employee* employee) {
		int id;
		string name;
		string password;
		double balance;

		cout << "Cilent ID: ";
		cin >> id;
		if (employee->searchClient(id) != nullptr) {
			do {
				cout << "Client name: ";
				cin >> name;
			} while (!Validation::validName(name));

			do {
				cout << "Client Password: ";
				cin >> password;
			} while (!Validation::ValidPassword(password));

			do {
				cout << "Client Balance: ";
				cin >> balance;
			} while (!Validation::ValidBalance(balance));

			employee->editClient(id, name, password, balance);
			FileManager::updateClientsTXT();
		}

		else
			cout << "Not founded" << endl;
	}

	static bool employeeOptions(Employee* employee) {
		system("cls");
		printEmployeeMenu();
		int opt;
		cout << "\nYour choice: ";
		cin >> opt;
		switch (opt)
		{
		case 1:
			system("cls");
			employee->Display();
			break;
		case 2:
			system("cls");
			ClientManager::UpdatePassword(employee);
			FileManager::updateEmployeesTXT();
			break;
		case 3:
			system("cls");
			newClient(employee);
			break;
		case 4:
			system("cls");
			searchForClient(employee);
			break;
		case 5:
			system("cls");
			employee->listClient();
			break;
		case 6:
			system("cls");
			editClientInfo(employee);
			FileManager::updateClientsTXT();
			break;
		case 7:
			return false;
			break;
		default:
			system("cls");
			employeeOptions(employee);
			return true;
		}
		back_exit(employee);
		return true;
	}

};
#pragma once
#include"EmployeeManager.h"
using namespace std;
class AdminManager
{
	static void printAdminMenu() {
		cout << "(1) Display my info \n";
		cout << "(2) Update Password \n";
		cout << "(3) Add new client \n";
		cout << "(4) Search for client \n";
		cout << "(5) List all clients \n";
		cout << "(6) Edit client info \n";
		cout << "(7) Add new employee \n";
		cout << "(8) Search for employee \n";
		cout << "(9) List all employees \n";
		cout << "(10) Edit employee info \n";
		cout << "(11) Logout \n";
	}

	static void back_exit(Admin* admin) {
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
				AdminOptions(admin);
				break;
			default:
				cout << "Invalid!" << endl;
				break;
			}
		} while (c < 0 || c > 1);
	}

public:
	static Admin* Login(int id, string password) {
		for (aIt = admins.begin(); aIt != admins.end(); aIt++) {
			if (aIt->getId() == id && aIt->getPassword() == password) return aIt._Ptr;
		}
		return nullptr;
	}

	static void newEmployee(Admin* admin) {
		string name, password;
		double salary;
		int id = (Fileshelper::getLast(EID_FILE_PATH) + 1);
		cout << "Employee info: " << endl;
		cout << "---------------" << endl;
		do {
			cout << "Name: ";
			cin >> name;
		} while (!Validation::validName(name));
		do {
			cout << "Password: ";
			cin >> password;
		} while (!Validation::ValidPassword(password));
		do {
			cout << "Salary: ";
			cin >> salary;
		} while (!Validation::ValidSalary(salary));

		Employee e;
		Fileshelper::saveLast(CID_FILE_PATH, id);
		e.setName(name);
		e.setPassword(password);
		e.setSalary(salary);

		admin->addEmployee(e);

		FileManager::updateEmployeesTXT();

		cout << "Added successfully" << endl;
	}

	static void searchForEmployee(Admin* admin) {
		int id;
		cout << "Employee ID: ";
		cin >> id;
		Employee* e = admin->searchEmployee(id);
		if (e != nullptr) {
			cout << "Founded" << endl;
			e->Display();
		}
		else
			cout << "Not founded" << endl;
	}

	static void editEmployeeInfo(Admin* admin) {
		int id;
		string name;
		string password;
		double salary;

		cout << "Employee ID: ";
		cin >> id;
		if (admin->searchClient(id) != nullptr) {
			do {
				cout << "Employee name: ";
				cin >> name;
			} while (!Validation::validName(name));

			do {
				cout << "Employee password: ";
				cin >> password;
			} while (!Validation::ValidPassword(password));

			do {
				cout << "Employee salary: ";
				cin >> salary;
			} while (!Validation::ValidSalary(salary));

			admin->editEmployee(id, name, password, salary);
			FileManager::updateEmployeesTXT();
		}

		else
			cout << "Not founded" << endl;
	}

	static bool AdminOptions(Admin* admin) {
		system("cls");
		printAdminMenu();
		int opt;
		cout << "\nYour choice: ";
		cin >> opt;
		switch (opt)
		{
		case 1:
			system("cls");
			admin->Display();
			break;
		case 2:
			system("cls");
			ClientManager::UpdatePassword(admin);
			FileManager::updateAdminTXT();
			break;
		case 3:
			system("cls");
			EmployeeManager::newClient(admin);
			break;
		case 4:
			system("cls");
			EmployeeManager::searchForClient(admin);
			break;
		case 5:
			system("cls");
			admin->listClient();
			break;
		case 6:
			system("cls");
			EmployeeManager::editClientInfo(admin);
			break;
		case 7:
			system("cls");
			newEmployee(admin);
			break;
		case 8:
			system("cls");
			searchForEmployee(admin);
			break;
		case 9:
			system("cls");
			admin->listEmployee();
			break;
		case 10:
			system("cls");
			editEmployeeInfo(admin);
			break;
		case 11:
			return false;
			break;
		default:
			system("cls");
			AdminOptions(admin);
			return true;
		}
		back_exit(admin);
		return true;
	}
};
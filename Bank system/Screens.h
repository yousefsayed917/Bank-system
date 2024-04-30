#pragma once
#include<iostream>
#include<thread>
#include<chrono>
#include "ClientManager.h"
#include "EmployeeManager.h"
#include "AdminManager.h"
using namespace std;
class Screens {
public:
	static void bankName() {
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
		cout << "\t\t\t\t    ## #                 ##  ##         ## #" << endl;
		cout << "\t\t\t\t    ## #####    #####    ##  ##      ## ##   ##   ##" << endl;
		cout << "\t\t\t\t    ####   ##       ##   ##  ##  ## ##  ##   ##   ##" << endl;
		cout << "\t\t\t\t  #########################  ##  ###################" << endl;
		cout << "\t\t\t\t                                                #" << endl;

	}
	static void welcome() {
		int t = 150;
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
		cout << "\t\t\t\t\t     ##" << endl;
		this_thread::sleep_for(chrono::milliseconds(t));
		cout << "\t\t\t\t\t     ##" << endl;
		this_thread::sleep_for(chrono::milliseconds(t));
		cout << "\t\t\t\t\t     ##         ###           #####" << endl;
		this_thread::sleep_for(chrono::milliseconds(t));
		cout << "\t\t\t\t\t     ##   ##      ##   ##    ##   ##" << endl;
		this_thread::sleep_for(chrono::milliseconds(t));
		cout << "\t\t\t\t\t     ###############   #############" << endl;
		this_thread::sleep_for(chrono::milliseconds(t));
		cout << "\t\t\t\t\t           #           ##" << endl;
		this_thread::sleep_for(chrono::milliseconds(t));
		cout << "\t\t\t\t\t                      ##" << endl;
		this_thread::sleep_for(chrono::milliseconds(t));
		cout << "\t\t\t\t\t                    ##" << endl;
		cout << "\n\n\n\n\n\n\n\n\n\n";
	}
	static void  loginOptions() {
		cout << "(1) Client \n";
		cout << "(2) Employee \n";
		cout << "(3) Admin \n\n";
	}
	static int loginAs() {
		cout << "Enter choise: ";
		int x;
		cin >> x;
		if (x > 0 && x <= 3)
			return x;
		else {
			cout << " invalid choise \n";
			loginAs();
			return x;
		}
	}

	static void Invalid(int x) {
		if (x > 0 && x <= 7)
			return;
		cout << " invalid choise \n";
	}

	static void Logout() {
		system("cls");
		loginOptions();
		LoginScreen(loginAs());
	}

	static void LoginScreen(int x) {
		int opt;
		switch (x)
		{
		case 1: {
			system("cls");
			int id;
			string password;
			cout << "Enter id: ";
			cin >> id;
			cout << "Enter password: ";
			cin >> password;
			Client* p = ClientManager::Login(id, password);
			if (p != nullptr) {
				system("cls");
				ClientManager::PrintClientMenu();
				if (!ClientManager::ClientOptions(p))
					Logout();
				else {
					do {
						cout << "[1] Client menu\t\t[0] Exit\n";
						cout << "..::Enter the Choice: ";
						cin >> opt;
						switch (opt)
						{
						case 0:
						{
							Fileshelper::ClearFile(C_FILE_PATH, CID_FILE_PATH);
							for (cIt = clients.begin(); cIt != clients.end(); cIt++) {
								Fileshelper::saveClient(*cIt);
							}
							exit(0);
						}
							break;
						case 1:
							system("cls");
							ClientManager::PrintClientMenu();
							if (!ClientManager::ClientOptions(p))
								Logout();
							break;
						default:
							cout << "Invalid choise!" << endl;
							break;
						}
					} while (opt == 1);
				}
			}
			break;
		}
		case 2: {
			system("cls");
			int id;
			string password;
			cout << "Enter id: ";
			cin >> id;
			cout << "Enter password: ";
			cin >> password;
			Employee* p = EmployeeManager::Login(id, password);
			if (p != nullptr) {
				system("cls");
				EmployeeManager::printEmployeeMenu();
				if (!EmployeeManager::employeeOptions(p))
					Logout();
				else {
					do {
						cout << "[1] Employee menu\t\t[0] Exit\n";
						cout << "..::Enter the Choice: ";
						cin >> opt;
						switch (opt)
						{
						case 0: {
							Fileshelper::ClearFile(E_FILE_PATH, EID_FILE_PATH);
							for (eIt = employees.begin(); eIt != employees.end(); eIt++) {
								Fileshelper::saveEmployee(*eIt);
							}
							Fileshelper::ClearFile(C_FILE_PATH, CID_FILE_PATH);
							for (cIt = clients.begin(); cIt != clients.end(); cIt++) {
								Fileshelper::saveClient(*cIt);
							}
							exit(0);
						}
							break;
						case 1:
							system("cls");
							EmployeeManager::printEmployeeMenu();
							if (!EmployeeManager::employeeOptions(p))
								Logout();
							break;
						default:
							cout << "\nInvalid choise!" << endl;
							break;
						}
					} while (opt == 1);
				}
			}
			break;
		}
		case 3: {
			system("cls");
			int id;
			string password;
			cout << "Enter id: ";
			cin >> id;
			cout << "Enter password: ";
			cin >> password;
			Admin* p = AdminManager::Login(id, password);
			if (p != nullptr) {
				system("cls");
				AdminManager::printAdminMenu();
				if (!AdminManager::AdminOptions(p))
					Logout();
				else {
					do {
						cout << "[1] Client menu\t\t[0] Exit\n";
						cout << "..::Enter the Choice: ";
						cin >> opt;
						switch (opt)
						{
						case 0:exit(0);
							break;
						case 1:
							system("cls");
							AdminManager::printAdminMenu();
							if (!AdminManager::AdminOptions(p))
								Logout();
							break;
						default:
							cout << "\n\t\t\t\t\t\t\t\t\t\tInvalid choise!" << endl;
							break;
						}
					} while (opt == 1);
				}
			}
			break;
		}
		}
	}
};

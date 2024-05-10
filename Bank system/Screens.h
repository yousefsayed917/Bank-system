#pragma once
#include<iostream>
#include <windows.h>
#include"AdminManager.h"
class Screens
{
	static void bankName() {
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
		cout << "\t\t\t\t    ## #                 ##  ##         ## #" << endl;
		cout << "\t\t\t\t    ## #####    #####    ##  ##      ## ##   ##   ##" << endl;
		cout << "\t\t\t\t    ####   ##       ##   ##  ##  ## ##  ##   ##   ##" << endl;
		cout << "\t\t\t\t  #########################  ##  ###################" << endl;
		cout << "\t\t\t\t                                                #" << endl;
		Sleep(2000);
	}

	static void welcome() {
		system("cls");
		int t = 150;
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
		cout << "\t\t\t\t\t     ##" << endl;
		Sleep(t);
		cout << "\t\t\t\t\t     ##" << endl;
		Sleep(t);
		cout << "\t\t\t\t\t     ##         ###           #####" << endl;
		Sleep(t);
		cout << "\t\t\t\t\t     ##   ##      ##   ##    ##   ##" << endl;
		Sleep(t);
		cout << "\t\t\t\t\t     ###############   #############" << endl;
		Sleep(t);
		cout << "\t\t\t\t\t           #           ##" << endl;
		Sleep(t);
		cout << "\t\t\t\t\t                      ##" << endl;
		Sleep(t);
		cout << "\t\t\t\t\t                    ##" << endl;
		cout << "\n\n\n\n\n\n\n\n\n\n";
		Sleep(1000);
		system("cls");
	}

	static void loginOptions() {
		cout << "(1) Admin \n";
		cout << "(2) Employee \n";
		cout << "(3) Client \n\n";
	}

	static int loginAs() {
		system("cls");
		loginOptions();
		cout << "Login as: ";
		int x;
		cin >> x;
		if (x > 0 && x <= 3)
			return x;
		else {
			system("cls");
			cout << "Invalid choice" << endl;
			return loginAs();
		}
	}

	static void logout() {
		system("cls");
		loginScreen(loginAs());
	}

	static void invalid() {
		cout << "\nInvalid ID or password!" << endl;
		Sleep(2000);
		loginScreen(loginAs());
	}

	static void loginScreen(int choice) {
		int id;
		string password;

		system("cls");
		cout << "ID: ";
		cin >> id;
		cout << "Password: ";
		cin >> password;

		switch (choice)
		{
		case 1:
			if (AdminManager::Login(id, password) != nullptr) {
				while (AdminManager::AdminOptions(AdminManager::Login(id, password)) != false);
				logout();
			}
			else {
				invalid();
			}
			break;

		case 2:
			if (EmployeeManager::Login(id, password) != nullptr) {
				while (EmployeeManager::employeeOptions(EmployeeManager::Login(id, password)) != false);
				logout();
			}
			else {
				invalid();
			}
			break;

		case 3:
			if (ClientManager::Login(id, password) != nullptr) {
				while (ClientManager::ClientOptions(ClientManager::Login(id, password)) != false);
				logout();
			}
			else {
				invalid();
			}
			break;
		default:
			system("cls");
			loginScreen(loginAs());
		}
	}

public:
	static void runApp() {
		FileManager::getAllData();
		bankName();
		welcome();
		loginScreen(loginAs());
	}
};
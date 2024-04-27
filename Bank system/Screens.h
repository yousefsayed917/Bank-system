#pragma once
#include<iostream>
#include<thread>
#include<chrono>
#include "ClientManager.h"
using namespace std;
class Screens
{
public:
	static void bankName() {
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
		cout << "\t\t\t\t    ## #                 ##  ##         ## #" << endl;
		cout << "\t\t\t\t    ## #####    ######   ##  ##      ## ##   ##   ##" << endl;
		cout << "\t\t\t\t    ####   ##       ##   ##  ##  ## ##  ##   ##   ##" << endl;
		cout << "\t\t\t\t  #########################  ##  ###################" << endl;
	
		cout << "\t\t\t\t                                               #" << endl;

	}
	static void welcome() {
		int t = 150;
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
		cout << "\t         ##             ##  #######  ##         #######    #######    ####   ####  #######" << endl;
		this_thread::sleep_for(chrono::milliseconds(t));
		cout << "\t          ##           ##   ##       ##        ##         ##     ##   ## ## ## ##  ##" << endl;
		this_thread::sleep_for(chrono::milliseconds(t));
		cout << "\t           ##   ###   ##    #######  ##       ##         ##       ##  ##  #### ##  #######" << endl;
		this_thread::sleep_for(chrono::milliseconds(t));
		cout << "\t            ## ## ## ##     ##       ##        ##         ##     ##   ##       ##  ##" << endl;
		this_thread::sleep_for(chrono::milliseconds(t));
		cout << "\t             ###   ###      #######  #######    #######    #######    ##       ##  #######" << endl;
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
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
		loginAs();
	}
	static void LoginScreen(int x) {
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
				ClientManager::ClientOptions(p);
			}
			break;
		}
			
		default:
			break;
		}
	}
};
//switch (x)
//{
//case 1: {
//	system("cls");
//	int id;
//	string password;
//	cout << "Enter id: ";
//	cin >> id;
//	cout << "Enter password: ";
//	cin >> password;
//	Client* p = ClientManager::Login(id, password);
//	if (p != nullptr) {
//		system("cls");
//		ClientManager::PrintClientMenu();
//		ClientManager::ClientOptions(p);
//	}
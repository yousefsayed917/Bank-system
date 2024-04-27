#pragma once
#include "Client.h"
#include "SuperEmployee.h"
class ClientManager
{
public:
	static void PrintClientMenu() {
		cout << " (1) Display my info \n";
		cout << " (2) Check balance \n";
		cout << " (3) Update Password \n";
		cout << " (4) Withdraw \n";
		cout << " (5) Deposit \n";
		cout << " (6) Transfar amount \n";
		cout << " (7) Logout \n";
	}
	static void UpdatePassword(Person* person) {
		string newpassword;
		cout << " enter the new password \n";
		cin >> newpassword;
		person->setPassword(newpassword);
		Fileshelper::ClearFile(C_FILE_PATH, CID_FILE_PATH);
		for (cIt = clients.begin(); cIt != clients.end(); cIt++) {
			Fileshelper::saveClient(*cIt);
		}
		cout << "password updated successfully" << endl;
	}
	static Client* Login(int id,string password) {
		SuperEmployee SE;
		Client* p = SE.searchClient(id);
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
		else
			cout << "Not found" << endl;
			return nullptr;
	}
	static void ClientOptions(Client* client) {
		int opt;
		while(true)
		{
			int x;
			cout << " your choice is : ";
			cin >> x;
			switch (x)
			{
			case 1: {
				system("cls");
				client->Display();
				break;
			}
			case 2: {
				system("cls");
				client->checkBalance();
				break;
			}
			case 3: {
				system("cls");
				Person* p = new Client;
				p = client;
				UpdatePassword(p);
				break;
			}
			case 4: {
				system("cls");
				double amount;
				cout << "  the amount is : ";
				cin >> amount;
				client->withdraw(amount);
			}
				  break;
			case 5: {
				double amount;
				cout << "  the amount is : ";
				cin >> amount;
				client->deposit(amount);
			}
				  break;
			case 6: {
				int id;
				cout << " enter id of the account you will transfar to it ";
				cin >> id;
				double amount;
				cout << "  the amount is : ";
				cin >> amount;
				for (cIt = clients.begin(); cIt != clients.end(); cIt++) {
					if (cIt->getId() == id) {
						client->transfareTo(*cIt, amount);
						Fileshelper::ClearFile(C_FILE_PATH, CID_FILE_PATH);
						for (cIt = clients.begin(); cIt != clients.end(); cIt++) {
							Fileshelper::saveClient(*cIt);
						}
						break;
					}
					else {
						cout << " this account is nout found \n";
						break;
					}
				}
			}
				  break;
			case 7:
				system("cls");
				//Screens::loginOptions();
				
				break;
			}
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
					PrintClientMenu();
					continue;
					break;
				default:
					cout << "\n\t\t\t\t\t\t\t\t\t\tInvalid chois!" << endl;
					break;
				}

			} while (opt < 0 || opt > 1);
		}
	}
	
};


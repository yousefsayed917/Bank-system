#pragma once
#include "Client.h"
#include "SuperEmployee.h"
using namespace std;
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

	/*static void UpdatePassword(Client*client) {
		string newpassword;
		cout << " enter the new password \n";
		cin >> newpassword;
		client->setPassword(newpassword);
		Fileshelper::ClearFile(C_FILE_PATH, CID_FILE_PATH);
		for (cIt = clients.begin(); cIt != clients.end(); cIt++) {
			Fileshelper::saveClient(*cIt);
		}
		cout << "password updated successfully" << endl;
	}*/

	static void UpdatePassword(Person* person) {
		string newpassword;
		cout << " enter the new password \n";
		cin >> newpassword;
		person->setPassword(newpassword);
		cout << "password updated successfully" << endl;
	}
	static Client* Login(int id, string password) {
		SuperEmployee SE;
		Client* p = SE.searchClient(id);
		if (p != nullptr) {
			if (p->getPassword() == password) {
				return p;
			}
			else
			{
				cout << "Invalid password" << endl;
				return nullptr;
			}
		}
		else
		{
			cout << "Not found" << endl;
			return nullptr;
		}
	}

	static bool ClientOptions(Client* client) {
		int x;
		cout << " your choice is : ";
		cin >> x;
		switch (x)
		{
		case 1: {
			system("cls");
			client->Display();
			return true;
			break;
		}
		case 2: {
			system("cls");
			client->checkBalance();
			return true;
			break;
		}
		case 3: {
			system("cls");
			UpdatePassword(client);
			return true;
			break;
		}
		case 4: {
			system("cls");
			double amount;
			cout << "  the amount is : ";
			cin >> amount;
			client->withdraw(amount);
			return true;
			break;
		}
		case 5: {
			system("cls");
			double amount;
			cout << "  the amount is : ";
			cin >> amount;
			client->deposit(amount);
			return true;
			break;
		}
		case 6: {
			system("cls");
			int id;
			cout << "Enter id of the account you will transfar to it ";
			cin >> id;
			double amount;
			cout << "The amount is : ";
			cin >> amount;
			for (cIt = clients.begin(); cIt != clients.end(); cIt++) {
				if (cIt->getId() == id) {
					client->transfareTo(*cIt, amount);
					break;
				}
				else {
					cout << "This account is nout found \n";
					break;
				}
			}
			return true;
			break;
		}
		case 7: {
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



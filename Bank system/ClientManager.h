#pragma once
#include "Client.h"
#include "Employee.h"
#include "Fileshelper.h"
#include "Validation.h"
#include "FileManager.h"
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
	static void UpdatePassword(Person* person) {
		string newPassword;
		do {
			cout << " enter the new password \n";
			cin >> newPassword;
		} while (!Validation::ValidPassword(newPassword));
		person->setPassword(newPassword);
		cout << "password updated successfully" << endl;
	}
	static Client* Login(int id, string password) {
		Employee E;
		Client* p = E.searchClient(id);
		if (p != nullptr && p->getPassword() == password) {
			return p;
		}
		else
		{
			cout << "Invalid password or ID" << endl;
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
			FileManager::UpdateClientTXT();
			return true;
			break;
		}
		case 4: {
			system("cls");
			double amount;
			cout << "  the amount is : ";
			cin >> amount;
			client->withdraw(amount);
			FileManager::UpdateClientTXT();
			return true;
			break;
		}
		case 5: {
			system("cls");
			double amount;
			cout << "  the amount is : ";
			cin >> amount;
			client->deposit(amount);
			FileManager::UpdateClientTXT();
			return true;
			break;
		}
		case 6: {
			system("cls");
			Employee e;
			int id;
			cout << "Enter id of the recipient ";
			cin >> id;
			while (e.searchClient(id) == nullptr) {
				cout << "Invalid id.\n";
				cout << "\nEnter id of the recipient: ";
				cin >> id;
			}
			double amount;
			cout << "Enter the amount : ";
			cin >> amount;
			client->transfareTo(*cIt, amount);
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



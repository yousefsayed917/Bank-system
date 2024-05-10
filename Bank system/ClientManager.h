#pragma once
#include"FileManager.h"
#include"Validation.h"
class ClientManager
{
	static void PrintClientMenu() {
		cout << "(1) Display my info \n";
		cout << "(2) Check balance \n";
		cout << "(3) Update Password \n";
		cout << "(4) Withdraw \n";
		cout << "(5) Deposit \n";
		cout << "(6) Transfar amount \n";
		cout << "(7) Logout \n";
	}

	static void back_exit(Client* client) {
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
				ClientOptions(client);
				break;
			default:
				cout << "Invalid!" << endl;
				break;
			}
		} while (c < 0 || c > 1);
	}

public:
	static void UpdatePassword(Person* person) {
		string newPass;
		do {
			cout << "New Password: ";
			cin >> newPass;
		} while (!Validation::ValidPassword(newPass));
		person->setPassword(newPass);
		cout << "Updated" << endl;
	}

	static Client* Login(int id, string password) {
		Employee E;
		Client* p = E.searchClient(id);
		if (p != nullptr && p->getPassword() == password) {
			return p;
		}
		else
		{
			return nullptr;
		}
	}

	static bool ClientOptions(Client* client) {
		system("cls");
		PrintClientMenu();
		int x;
		cout << "\nYour choice: ";
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
			UpdatePassword(client);
			FileManager::updateClientsTXT();
			break;
		}
		case 4: {
			system("cls");
			double amount;
			cout << "Enter amount: ";
			cin >> amount;
			client->withdraw(amount);
			FileManager::updateClientsTXT();
			break;
		}
		case 5: {
			system("cls");
			double amount;
			cout << "Enter amount: ";
			cin >> amount;
			client->deposit(amount);
			FileManager::updateClientsTXT();
			break;
		}
		case 6: {
			system("cls");
			int id;
			double amount;
			Employee e;

			cout << "User ID: ";
			cin >> id;

			cout << "Enter amount: ";
			cin >> amount;

			Client* user = e.searchClient(id);

			if (user != nullptr) {
				client->transfareTo(*user, amount);
				FileManager::updateClientsTXT();
			}
			else
				cout << "User not found";
			break;
		}
		case 7: {
			return false;
			break;
		}
		default: {
			system("cls");
			ClientOptions(client);
			return true;
		}
		}
		back_exit(client);
		return true;
	}
};
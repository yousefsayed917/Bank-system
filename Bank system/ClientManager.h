#pragma once
#include "Client.h"
#include "Employee.h"
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
	}
	static Client* Login(int id,string password) {
		if (Employee::searchClient(id)) {
			Client* p = Employee::searchClient(id);
			if (p->getPassword() == password) {
				return p;
			}
		}
		return nullptr;
	}
	static bool ClientOptions(Client* client) {
		int x;
		cout << " your choice is : "; 
		cin>>x;
		switch (x)
		{
		case 1: {
			client->Display();
			break;
		}
		case 2: {
			client->checkBalance();
			break;
		}
		case 3: {
			UpdatePassword(client);
			break;
		}
		case 4: {
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
					break;
				}
				else {
					cout << " this account is nout found \n";
					break;
				}
			}
			break;
		}	  
		case 7:

			break;
		}
	}
};


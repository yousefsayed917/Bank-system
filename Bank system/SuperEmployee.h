#pragma once
#include"Employee.h"
#include"Fileshelper.h"

class SuperEmployee : public Employee
{
public:
	SuperEmployee() {

	}
	SuperEmployee(int id, string name, string password, double salary) : Employee(id, name, password, salary) {

	}
	void addClient(Client& client) {
		clients.push_back(client);
		Fileshelper::saveClient(client);
	}
	Client* searchClient(int id) {

		for (cIt = clients.begin(); cIt != clients.end(); cIt++) {
			if (cIt->getId() == id) return cIt._Ptr;
		}
		cout << " this client is not found \n";
		return nullptr;
	}

	void listClient() {
		for (cIt = clients.begin(); cIt != clients.end(); cIt++) {
			cIt->Display();
		}
	}
	void editClient(int id, string name, string password, double balance) {
		Client* p = searchClient(id);
		if (p != nullptr) {
			p->setName(name);
			p->setPassword(password);
			p->setBalance(balance);
			Fileshelper::ClearFile(C_FILE_PATH, CID_FILE_PATH);
			for (cIt = clients.begin(); cIt != clients.end(); cIt++) {
				Fileshelper::saveClient(*cIt);
			}
		}
	}
	
};



#pragma once
#include <iostream>
#include <string>
using namespace std;
class Validation
{
public:
	static bool validName(string name) {
		if (!(name.size() >= 5 && name.size() <= 20)) {
			cout << "the size of name must be >=5 and <=20\n";
			return false;
		}

		for (int i = 0; i < name.size(); i++) {
			if (!(name[i] >= 'a' && name[i] <= 'z' || name[i] >= 'A' && name[i] <= 'Z')) {
				cout << "The name must be alphabtic character " << endl;
				return false;
			}
		}
		return true;
	}
	static bool ValidPassword(string password)
	{
		if (password.size() >= 8 && password.size() <= 20) {
			return true;
		}
		else
		{
			cout << "The password must be >= 8 And <= 20\n";
			return false;
		}
	}
	static bool ValidBalance(double balance)
	{
		if (balance >= 1500) {
			return true;
		}
		else {
			cout << "Min balance is 1500 " << endl;;
			return false;
		}

	}
	static bool ValidSalary(double salary)
	{
		if (salary >= 5000) {
			return true;
		}
		else {
			cout << "Min salary is 5000"<<endl;
		}
	}
};


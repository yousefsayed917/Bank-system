#pragma once
#include <iostream>
#include <string>
using namespace std;
class Validation
{
public:
	static bool validName(string name) {
		if (!(name.size() >= 5 && name.size() <= 20)) {
			cout << "\nthe size of name must be >=5 and <=20!\n" << endl;
			return false;
		}

		for (int i = 0; i < name.size(); i++) {
			if (!(name[i] >= 'a' && name[i] <= 'z' || name[i] >= 'A' && name[i] <= 'Z')) {
				cout << "\nThe name must be alphabtic character!\n " << endl;
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
			cout << "\nThe password must be >= 8 And <= 20! \n" << endl;
			return false;
		}
	}
	static bool ValidBalance(double balance)
	{
		if (balance >= 1500) {
			return true;
		}
		else {
			cout << "\nMin balance is 1500! \n" << endl;;
			return false;
		}

	}
	static bool ValidSalary(double salary)
	{
		if (salary >= 5000) {
			return true;
		}
		else {
			cout << "Min salary is 5000" << endl;
			return false;
		}
	}
};
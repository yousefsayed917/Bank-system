#pragma once
#include <iostream>
#include <string>
using namespace std;
class Validation
{
public:
	static bool ValidName(string name)
	{
		if (name.length() < 5 || name.length() > 20)
		{
			cout << "the size of name must be >=5 and <=20\n";
			return false;
		}
		for (char c : name)
		{
			if (!isalpha(c))
				return false;
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
			cout << " the password must be >= 8 And <= 20\n";
			return false;
		}
	}
	static bool ValidBalance(double balance)
	{
		return balance >= 1500;
	}
	static bool ValidSalary(double salary)
	{
		return salary >= 5000;
	}
};


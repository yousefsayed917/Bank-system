#include <iostream>
#include"Fileshelper.h"
#include"Screens.h"
using namespace std;

int main()
{

	Fileshelper::getClients();
	Fileshelper::getEmployees();
	Fileshelper::getAdmins();
	Screens::bankName();
	this_thread::sleep_for(chrono::milliseconds(2000));
	system("cls");
	Screens::welcome();
	this_thread::sleep_for(chrono::milliseconds(2000));
	system("cls");
	Screens::loginOptions();
	Screens::LoginScreen(Screens::loginAs());


}
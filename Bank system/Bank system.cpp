#include <iostream>
#include"Fileshelper.h"
#include"Screens.h"
using namespace std;

int main()
{

	Fileshelper::getClients();
	Screens::bankName();
	this_thread::sleep_for(chrono::milliseconds(2000));
	system("cls");
	Screens::welcom();
	this_thread::sleep_for(chrono::milliseconds(2000));
	system("cls");
	Screens::loginOptions();
	Screens::loginAs();
}
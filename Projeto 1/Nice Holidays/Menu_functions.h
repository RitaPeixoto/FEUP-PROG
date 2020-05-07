#pragma once
#include <iostream>
#include<vector>
#include<string>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include<algorithm>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
using namespace std;


int showMenu() { // its shows the  Main Menu options to the user and receives its answer returning the number of the option chosen
	int option_num;
	system("CLS");
	cout << endl;
	cout << "*******Menu*******" << endl;
	cout << "1: Clients Management" << endl;
	cout << "2: Packs Management" << endl;
	cout << "3: View Data" << endl;
	cout << "4: Buy package" << endl;
	cout << "0: Exit" << endl;
	cout << endl;
	cout << "Choose an option from the menu(number):";
	cin >> option_num;

	while (cin.fail() || option_num >4 || option_num<0) {
		cin.clear();
		cout << "Invalid operation, please insert a valid one: ";
		cin.ignore(1000, '\n');
		cin >> option_num;
	}
	return option_num;
}
int ShowMenuClients() {// its shows the Clients Menu options to the user and receives its answer returning the number of the option chosen
	int option_client;
	system("CLS");
	cout << "*******Client Menu********" << endl;
	cout << endl;
	cout << "1: Create Client" << endl;
	cout << "2: Modify Client" << endl;
	cout << "3: Remove Client" << endl;
	cout << "4: Return to the Main Menu" << endl;
	cout << "0: Exit" << endl;
	cout << endl;
	cout << "Choose an option from the menu(number): ";
	cin >> option_client;

	while (cin.fail() || (option_client > 4) || option_client <0) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid operation, please insert a valid one: ";
		cin >> option_client;
	}
	return option_client;
}
int ShowMenuPacks() {// its shows the  Packs Menu options to the user and receives its answer returning the number of the option chosen
	int option_pack;
	system("CLS");
	cout << "********Packs Menu********" << endl;
	cout << endl;
	cout << "1: Create Pack" << endl;
	cout << "2: Modify Pack" << endl;
	cout << "3: Remove Pack" << endl;
	cout << "4: Return to the Main Menu" << endl;
	cout << "0: Exit" << endl;
	cout << endl;

	cout << "Choose an option from the menu(number): ";
	cin >> option_pack;

	while (cin.fail() || (option_pack > 4) || (option_pack<0)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid operation, please insert a valid one: ";
		cin >> option_pack;
	}
	return option_pack;
}

int ShowMenuViewData() {// its shows the Data Menu options to the user and receives its answer returning the number of the option chosen
	int option_data;
	system("CLS");
	cout << "******Information Menu*******" << endl;
	cout << endl;
	cout << "1: View Client Information" << endl;
	cout << "2: View All Clients" << endl;
	cout << "3: View Available Package" << endl;
	cout << "4: View Sold Packages" << endl;
	cout << "5: View Total Revenue" << endl; //receita
	cout << "6: Return to Main Menu" << endl;
	cout << "0: Exit" << endl;
	cout << endl;
	cout << "Choose an option from the menu(number): ";
	cin >> option_data;

	while (cin.fail() || (option_data > 6) || (option_data <0)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid operation, please insert a valid one: " << endl;
		cin >> option_data;
	}
	return option_data;
}

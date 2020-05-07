#include "Menu.h"
//Neste ficheiro encontram-se todos os menus e todos eles aceitam o 'crtl-z'

int MainMenu() { // mostrar o Menu principal
	int option;
	system("cls");

	cout << "---------------- MENU ----------------" << endl<<endl;
	cout << "1. Clients Management" << endl;
	cout << "2. Travel Packs Management" << endl;
	cout << "3. Data View " << endl;
	cout << "4. Buy pack" << endl;
	cout << "0. Exit" << endl;

	cout << endl << "Choose an option from the menu(integer number): ";
	cin >> option;

	while (cin.fail() || option > 4 || option < 0) {
		if (cin.eof()) {//caso de ter sido introduzido o 'crtl-z'
			cin.clear();
			cout << "Invalid operation, please insert a valid one: ";
			cin >> option;
		}
		else {//qualquer outro caso que nao corresponda ao input pretendido
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid operation, please insert a valid one: ";
			cin >> option;
		}
			
	}

	cin.ignore(1000, '\n');
	return option;
}

int ClientsMenu() { //mostrar o menu de clientes

	int option;
	system("cls");

	cout << "---------------- CLIENTS MANAGEMENT ----------------" << endl<<endl;
	cout << "1. Create Client" << endl;
	cout << "2. Modify Client" << endl;
	cout << "3. Remove Client " << endl;
	cout << "4. Return to Main Menu" << endl;
	cout << "0. Exit" << endl;

	cout << endl << "Choose an option from the menu(integer number): ";
	cin >> option;

	while (cin.fail() || option > 4 || option < 0)
	{
		if (cin.eof()) {
			cin.clear();
			cout << "Invalid operation, please insert a valid one: ";
			cin >> option;
		}
		else {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid operation, please insert a valid one: ";
			cin >> option;
		}
	}
	cin.ignore(1000, '\n');
	return option;
}

int PacksMenu() { //mostrar o menu dos pacotes

	int option;
	system("cls");

	cout << "---------------- TRAVEL PACKS MANAGEMENT ----------------" << endl<<endl;
	cout << "1. Create Pack" << endl;
	cout << "2. Modify Pack" << endl;
	cout << "3. Remove Pack" << endl;
	cout << "4. Return to Main Menu" << endl;
	cout << "0. Exit"<<endl,

	cout << endl << "Choose an option from the menu (integer number): ";
	cin >> option;

	while (cin.fail() || option > 4 || option < 0)
	{
		if (cin.eof()) {
			cin.clear();
			cout << "Invalid operation, please insert a valid one: ";
			cin >> option;
		}
		else {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid operation, please insert a valid one: ";
			cin >> option;
		}
	}
	cin.ignore(1000, '\n');
	return option;
}

int ViewInformationMenu() { // mostrar menu de informação

	system("cls");
	int option;

	cout << "---------------- INFORMATION MENU ----------------" << endl<<endl;
	cout << "1. View Agency Information" << endl;
	cout << "2. View Client Information" << endl;
	cout << "3. View All Clients" << endl;
	cout << "4. View Available Packs" << endl;
	cout << "5. View Sold Packs" << endl;
	cout << "6. View Total Revenue" << endl;
	cout << "7. View N most visited destinations" << endl; // acrescentar dentro desta opçao um menu com all ou a o objetivo 10
	cout << "8. Return to Main Menu" << endl;
	cout << "0. Exit" << endl;

	cout << endl << "Choose an option from the menu(integer number): ";
	cin >> option;

	while (cin.fail() || option > 8 || option < 0)
	{
		if (cin.eof()) {
			cin.clear();
			cout << "Invalid operation, please insert a valid one: ";
			cin >> option;
		}
		else {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid operation, please insert a valid one: ";
			cin >> option;
		}
	}
	cin.ignore(1000, '\n');
	return option;
}


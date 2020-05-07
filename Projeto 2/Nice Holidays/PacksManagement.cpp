#include "PacksManagement.h"

using namespace std;

int create_pack(vector <Pack> &Packs, string name_file) { //criar pacote, atualizar o vector e o ficheiro dos pacotes

	Pack new_pack;
	string aux;
	int option;
	Date date_today;
	int number ;


	system("cls");

	cout << "-------------- CREATE PACK --------------" << endl;

	cout << "What is the travel destination (Region - PlaceA, PlaceB, PlaceC, ...)? Insert 'Ctrl-Z' to cancel. ";
	getline(cin, aux);
	aux = cleaning_invalid_characters(aux);
	while (cin.fail() || aux == "" || aux == "0") {
		if (cin.eof() || aux == "0") {
			system("cls");
			cin.clear();
			cout << "Operation was canceled! " << endl << endl;
			cout << "1. Return to Main Menu. " << endl;
			cout << "2. Return to Travel Packs Management. " << endl;


			cout << endl << "Choose what you want to do (integer number): ";
			cin >> option;


			while (cin.fail() || option > 2 || option <= 0) {
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
		else {
			cout << "Invalid operation. Please insert a valid one: ";
			getline(cin, aux);
			aux = cleaning_invalid_characters(aux);
		}
	}
	aux = formatting_string(aux);
	aux = resize_function(aux); 

	while (verifying_Destination(aux) == false) {
		cout << "Invalid operation, please insert a valid one. Insert 'Ctrl-Z' to cancel. ";
		getline(cin, aux);
		aux = cleaning_invalid_characters(aux);
		while (cin.fail() || aux == "" || aux == "0") {
			if (cin.eof() || aux == "0") {
				system("cls");
				cin.clear();
				cout << "Operation was canceled! " << endl << endl;
				cout << "1. Return to Main Menu. " << endl;
				cout << "2. Return to Travel Packs Management. " << endl;


				cout << endl << "Choose what you want to do (integer number): ";
				cin >> option;


				while (cin.fail() || option > 2 || option <= 0) {
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
		}
		aux = formatting_string(aux);
		aux = resize_function(aux);
	}


	new_pack.setDestination(aux);

	cout << "What is the departure date of the travel pack (YYYY / MM / DD)? Insert 'Ctrl-Z' to cancel. ";
	getline(cin, aux);
	aux = cleaning_invalid_characters(aux);

	while (cin.fail() || aux == "" || !verifying_date(aux)) {
		if (cin.eof()) {
			system("cls");
			cin.clear();
			cout << "Operation was canceled! " << endl << endl;
			cout << "1. Return to Main Menu. " << endl;
			cout << "2. Return to Travel Packs Management. " << endl;


			cout << endl << "Choose what you want to do (integer number): ";
			cin >> option;


			while (cin.fail() || option > 2 || option <= 0) {
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
		else {
			cout << "Invalid operation. Please insert a valid one: ";
			getline(cin, aux);
			aux = cleaning_invalid_characters(aux);
		}
	}

	aux = resize_function(aux);
	
	new_pack.setBeginDate(aux);

	while (!new_pack.getBeginDate().isValid() || !new_pack.getBeginDate().isAfter(date_today)) {
		cout << "Invalid operation, please insert a valid one. Today is ";
		visualize_date(date_today);
		cout << ". Insert 'Ctrl-Z' to cancel. ";			
		getline(cin, aux);
		aux = cleaning_invalid_characters(aux);
		while (cin.fail() || aux == "" || !verifying_date(aux)) {
			if (cin.eof()) {
				system("cls");
				cin.clear();
				cout << "Operation was canceled! " << endl << endl;
				cout << "1. Return to Main Menu. " << endl;
				cout << "2. Return to Travel Packs Management. " << endl;


				cout << endl << "Choose what you want to do (integer number): ";
				cin >> option;


				while (cin.fail() || option > 2 || option <= 0) {
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
			else {
				cout << "Invalid operation. Please insert a valid one: ";
				getline(cin, aux);
				aux = cleaning_invalid_characters(aux);
			}
		}

		aux = resize_function(aux);
		new_pack.setBeginDate(aux);
	}
	

	cout << "What is the arrival date of the travel pack (YYYY / MM / DD)? Insert 'Ctrl-Z' to cancel. ";
	getline(cin, aux);
	aux = cleaning_invalid_characters(aux);

	while (cin.fail() || aux == "" || !verifying_date(aux)) {
		if (cin.eof()) {
			system("cls");
			cin.clear();
			cout << "Operation was canceled! " << endl << endl;
			cout << "1. Return to Main Menu. " << endl;
			cout << "2. Return to Travel Packs Management. " << endl;


			cout << endl << "Choose what you want to do (integer number): ";
			cin >> option;


			while (cin.fail() || option > 2 || option <= 0) {
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
		else {
			cout << "Invalid operation. Please insert a valid one: ";
			getline(cin, aux);
			aux = cleaning_invalid_characters(aux);
		}
	}
	aux = resize_function(aux);
	new_pack.setEndDate(aux);

	while (!new_pack.getEndDate().isValid() || !new_pack.getEndDate().isAfter(new_pack.getBeginDate()) || new_pack.getEndDate().isEqualTo(new_pack.getBeginDate())) {
		cout << "Invalid operation, please insert a valid one. Insert 'Ctrl-Z' to cancel. ";
		getline(cin, aux);
		aux = cleaning_invalid_characters(aux);
		while (cin.fail() || aux == "" || !verifying_date(aux)) {
			if (cin.eof()) {
				system("cls");
				cin.clear();
				cout << "Operation was canceled! " << endl << endl;
				cout << "1. Return to Main Menu. " << endl;
				cout << "2. Return to Travel Packs Management. " << endl;


				cout << endl << "Choose what you want to do (integer number): ";
				cin >> option;


				while (cin.fail() || option > 2 || option <= 0) {
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
			else {
				cout << "Invalid operation. Please insert a valid one: ";
				getline(cin, aux);
				aux = cleaning_invalid_characters(aux);
			}
		}
		aux = resize_function(aux);
		new_pack.setEndDate(aux);
	}


	cout << "What is the price per person of the travel pack? Insert 'Ctrl-Z' to cancel. ";
	getline(cin, aux);
	aux = cleaning_invalid_characters(aux);
	while (cin.fail() || aux == "" || !verifying_INT(aux)) {
		if (cin.eof()) {
			system("cls");
			cin.clear();
			cout << "Operation was canceled! " << endl << endl;
			cout << "1. Return to Main Menu. " << endl;
			cout << "2. Return to Travel Packs Management. " << endl;


			cout << endl << "Choose what you want to do (integer number): ";
			cin >> option;


			while (cin.fail() || option > 2 || option <= 0) {
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
		else {
			cout << "Invalid operation. Please insert a valid one: ";
			getline(cin, aux);
			aux = cleaning_invalid_characters(aux);
		}
	}

	aux = resize_function(aux);
	new_pack.setPricePerPerson(stoi(aux));

	cout << "How many are the initially available spots? Insert 'Ctrl-Z' to cancel. ";
	getline(cin, aux);
	aux = cleaning_invalid_characters(aux);
	while (cin.fail() || aux == "" || !verifying_INT(aux)) {
		if (cin.eof()) {
			system("cls");
			cin.clear();
			cout << "Operation was canceled! " << endl << endl;
			cout << "1. Return to Main Menu. " << endl;
			cout << "2. Return to Travel Packs Management. " << endl;


			cout << endl << "Choose what you want to do (integer number): ";
			cin >> option;


			while (cin.fail() || option > 2 || option <= 0) {
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
		else {
			cout << "Invalid operation. Please insert a valid one: ";
			getline(cin, aux);
			aux = cleaning_invalid_characters(aux);
		}
	}
	aux = resize_function(aux);
	new_pack.setNumberMaxPeople(stoi(aux));


	cout << "How many are the sold spots? Insert 'Ctrl-Z' to cancel. ";
	getline(cin, aux);
	aux = cleaning_invalid_characters(aux);
	while (cin.fail() || aux == "" || !verifying_INT(aux)) {
		if (cin.eof()) {
			system("cls");
			cin.clear();
			cout << "Operation was canceled! " << endl << endl;
			cout << "1. Return to Main Menu. " << endl;
			cout << "2. Return to Travel Packs Management. " << endl;


			cout << endl << "Choose what you want to do (integer number): ";
			cin >> option;


			while (cin.fail() || option > 2 || option <= 0) {
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
		else {
			cout << "Invalid operation. Please insert a valid one: ";
			getline(cin, aux);
			aux = cleaning_invalid_characters(aux);
		}
	}
	aux = resize_function(aux);

	number = stoi(aux);

	while (number > new_pack.getNumberMaxPeople()) {
		cout << "Error ---- The number of sold spots is higher than the number of available spots! Please enter a number lower than " << new_pack.getNumberMaxPeople() << ". Insert 'CTrl-Z' to cancel. ";
		getline(cin, aux);
		aux = cleaning_invalid_characters(aux);
		while (cin.fail() || aux == "" || !verifying_INT(aux)) {
			if (cin.eof()) {
				system("cls");
				cin.clear();
				cout << "Operation was canceled! " << endl << endl;
				cout << "1. Return to Main Menu. " << endl;
				cout << "2. Return to Travel Packs Management. " << endl;


				cout << endl << "Choose what you want to do (integer number): ";
				cin >> option;


				while (cin.fail() || option > 2 || option <= 0) {
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
		}
		number = stoi(aux);
	}


	new_pack.setSoldSpots(number);


	if (new_pack.getNumberMaxPeople() == new_pack.getSoldSpots()) {
		new_pack.setPackNumber(size(Packs)*(-1));
	}
	else {
		new_pack.setPackNumber(size(Packs));
	}

	string cancel;
	cout << endl << endl << "Are you sure you want to create a pack with this information? " << endl << "Insert 'yes' to continue. " << endl << "Insert 'no' to cancel. " << endl << "Answer: ";
	cin >> cancel;
	while (cin.fail()) {
		if (cin.eof()) {
			cin.clear();
			cout << "Invalid operation, please insert a valid one: ";
			cin >> cancel;
		}

	}
	cancel = resize_function(cancel);
	cancel = formatting_string(cancel);

	while (cin.fail() || (cancel != "Yes" && cancel != "No")) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid operation, please insert a valid one: ";
		cin >> cancel;
		while (cin.fail()) {
			if (cin.eof()) {
				cin.clear();
				cout << "Invalid operation, please insert a valid one: ";
				cin >> cancel;
			}
		}

		cancel = resize_function(cancel);
		cancel = formatting_string(cancel);

	}

	if (cancel == "Yes") {
		Packs.push_back(new_pack);

		Packs[0].setLastCreatedPack(size(Packs)-1); //atualizar o numero do ultimo pacote criado (primeira linha do ficheiro 'files')


		update_packs(Packs, name_file);   //guardar informação no respetivo ficheiro
		system("cls");

		cout << "Pack was successfully created!" << endl << endl;
	}
		
	
	else {
		system("cls");

		cout << "Operation was canceled!" << endl << endl;
	}
	
	
	cout << "1. Return to Main Menu. " << endl;
	cout << "2. Return to Travel Packs Management. " << endl;

	
	cout << endl << "Choose what you want to do (integer number): ";
	cin >> option;


	while (cin.fail() || option > 2 || option <= 0) {
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

int modify_pack(vector <Pack> &Packs, string name_file) { //modificar pacote, atualizar vector e ficheiro dos pacotes

	int option, pack_number, number;
	string aux;
	Date today_date;
	system("cls");

	cout << "-------------- MODIFY PACK --------------" << endl;
	cout << "What do you want to modify in your pack's information? " << endl;

	cout << "1. Everything. " << endl;
	cout << "2. Destination. " << endl;
	cout << "3. Departure Date. " << endl;
	cout << "4. Arrival date. " << endl;
	cout << "5. Price per person. " << endl;
	cout << "6. Number of initially available spots. " << endl;
	cout << "7. Number of sold spots. " << endl;
	cout << "8. Return to Main Menu. " << endl;

	cout << endl << "Choose what do you want to do (integer number): ";
	cin >> option;

	while (cin.fail() || option > 8 || option <= 0) {
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
	system("cls");
	if (option == 8) {
		return 1;
	}

	cout << "------- Information Of Packs -------" << endl << endl;
	visualize_packs(Packs);

	cout << endl << endl << "What is the number of the pack you want to modify? Insert 'Ctrl-Z' to cancel. ";
	cin >> pack_number;



	if (cin.fail()) {
		if (cin.eof()) {
			system("cls");
			cin.clear();
			cout << "Operation was canceled! " << endl << endl;
			cout << "1. Return to Main Menu. " << endl;
			cout << "2. Return to Travel Packs Management. " << endl;


			cout << endl << "Choose what you want to do (integer number): ";
			cin >> option;


			while (cin.fail() || option > 2 || option <= 0) {
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
	}

	while (cin.fail() || pack_number > size(Packs) || pack_number <= 0) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid operation, please insert a valid one. Insert 'Ctrl-Z' to cancel. ";
		cin >> pack_number;

		if (cin.fail()) {
			if (cin.eof()) {
				system("cls");
				cin.clear();
				cout << "Operation was canceled! " << endl << endl;
				cout << "1. Return to Main Menu. " << endl;
				cout << "2. Return to Travel Packs Management. " << endl;


				cout << endl << "Choose what you want to do (integer number): ";
				cin >> option;


				while (cin.fail() || option > 2 || option <= 0) {
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
		}
	}

	cin.ignore(1000, '\n');
	system("cls");

	visualize_pack(Packs, pack_number);
	cout << endl;

	switch (option) {
	case 1:
		cout << "What is the travel destination (Region - PlaceA, PlaceB, PlaceC, ...)? Insert 'Ctrl-Z' to cancel. ";
		getline(cin, aux);
		aux = cleaning_invalid_characters(aux);
		while (cin.fail() || aux == "") {
			if (cin.eof()) {
				system("cls");
				cin.clear();
				cout << "Operation was canceled! " << endl << endl;
				cout << "1. Return to Main Menu. " << endl;
				cout << "2. Return to Travel Packs Management. " << endl;


				cout << endl << "Choose what you want to do (integer number): ";
				cin >> option;


				while (cin.fail() || option > 2 || option <= 0) {
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
			else {
				cout << "Invalid operation. Please insert a valid one: ";
				getline(cin, aux);
				aux = cleaning_invalid_characters(aux);
			}
		}

		aux = cleaning_invalid_characters(aux);
		aux = resize_function(aux);

		while (verifying_Destination(aux) == false) {
			cout << "Invalid operation, please insert a valid one. Insert 'Ctrl-Z' to cancel. ";
			getline(cin, aux);
			aux = cleaning_invalid_characters(aux);
			while (cin.fail() || aux == "") {
				if (cin.eof()) {
					system("cls");
					cin.clear();
					cout << "Operation was canceled! " << endl << endl;
					cout << "1. Return to Main Menu. " << endl;
					cout << "2. Return to Travel Packs Management. " << endl;


					cout << endl << "Choose what you want to do (integer number): ";
					cin >> option;


					while (cin.fail() || option > 2 || option <= 0) {
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

				else {
					cout << "Invalid operation. Please insert a valid one: ";
					getline(cin, aux);
					aux = cleaning_invalid_characters(aux);
				}
			}

			aux = cleaning_invalid_characters(aux);
			aux = resize_function(aux);
		}


		Packs[pack_number].setDestination(aux);


		cout << "What is the departure date of the travel pack (YYYY / MM / DD)? Insert 'Ctrl-Z' to cancel. ";
		getline(cin, aux);
		aux = cleaning_invalid_characters(aux);
		while (cin.fail() || aux == "" || !verifying_date(aux)) {
			if (cin.eof()) {
				system("cls");
				cin.clear();
				cout << "Operation was canceled! " << endl << endl;
				cout << "1. Return to Main Menu. " << endl;
				cout << "2. Return to Travel Packs Management. " << endl;


				cout << endl << "Choose what you want to do (integer number): ";
				cin >> option;


				while (cin.fail() || option > 2 || option <= 0) {
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
			else {
				cout << "Invalid operation. Please insert a valid one: ";
				getline(cin, aux);
				aux = cleaning_invalid_characters(aux);
			}
		}

		aux = resize_function(aux);
		Packs[pack_number].setBeginDate(aux);

		while (!Packs[pack_number].getBeginDate().isValid() || (!Packs[pack_number].getEndDate().isAfter(Packs[pack_number].getBeginDate())) || Packs[pack_number].getEndDate().isEqualTo(Packs[pack_number].getBeginDate())) {
			cout << "Invalid operation, please insert a valid one. Insert 'Ctrl-Z' to cancel. ";
			getline(cin, aux);
			aux = cleaning_invalid_characters(aux);
			while (cin.fail() || aux == "" || !verifying_date(aux)) {
				if (cin.eof()) {
					system("cls");
					cin.clear();
					cout << "Operation was canceled! " << endl << endl;
					cout << "1. Return to Main Menu. " << endl;
					cout << "2. Return to Travel Packs Management. " << endl;


					cout << endl << "Choose what you want to do (integer number): ";
					cin >> option;


					while (cin.fail() || option > 2 || option <= 0) {
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
				else {
					cout << "Invalid operation. Please insert a valid one: ";
					getline(cin, aux);
					aux = cleaning_invalid_characters(aux);
				}
			}
			aux = resize_function(aux);
			Packs[pack_number].setBeginDate(aux);
		}

		cout << "What is the arrival date of the travel pack (YYYY / MM / DD)? Insert 'Ctrl-Z' to cancel. ";
		getline(cin, aux);
		aux = cleaning_invalid_characters(aux);
		while (cin.fail() || aux == "" || !verifying_date(aux)) {
			if (cin.eof()) {
				system("cls");
				cin.clear();
				cout << "Operation was canceled! " << endl << endl;
				cout << "1. Return to Main Menu. " << endl;
				cout << "2. Return to Travel Packs Management. " << endl;


				cout << endl << "Choose what you want to do (integer number): ";
				cin >> option;


				while (cin.fail() || option > 2 || option <= 0) {
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
			else {
				cout << "Invalid operation. Please insert a valid one: ";
				getline(cin, aux);
				aux = cleaning_invalid_characters(aux);
			}
		}
		aux = resize_function(aux);
		Packs[pack_number].setEndDate(aux);

		while (!Packs[pack_number].getEndDate().isValid() || !Packs[pack_number].getEndDate().isAfter(Packs[pack_number].getBeginDate()) || Packs[pack_number].getEndDate().isEqualTo(Packs[pack_number].getBeginDate())) {
			cout << "Invalid operation, please insert a valid one. Insert 'Ctrl-Z' to cancel. ";
			getline(cin, aux);
			aux = cleaning_invalid_characters(aux);
			while (cin.fail() || aux == "" || !verifying_date(aux)) {
				if (cin.eof()) {
					system("cls");
					cin.clear();
					cout << "Operation was canceled! " << endl << endl;
					cout << "1. Return to Main Menu. " << endl;
					cout << "2. Return to Travel Packs Management. " << endl;


					cout << endl << "Choose what you want to do (integer number): ";
					cin >> option;


					while (cin.fail() || option > 2 || option <= 0) {
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
				else {
					cout << "Invalid operation. Please insert a valid one: ";
					getline(cin, aux);
					aux = cleaning_invalid_characters(aux);
				}
			}


			aux = resize_function(aux);
			Packs[pack_number].setEndDate(aux);
		}


		cout << "What is the price per person of the travel pack? Insert 'Ctrl-Z' to cancel. ";
		getline(cin, aux);
		aux = cleaning_invalid_characters(aux);
		while (cin.fail() || aux == "" || !verifying_INT(aux)) {
			if (cin.eof()) {
				system("cls");
				cin.clear();
				cout << "Operation was canceled! " << endl << endl;
				cout << "1. Return to Main Menu. " << endl;
				cout << "2. Return to Travel Packs Management. " << endl;


				cout << endl << "Choose what you want to do (integer number): ";
				cin >> option;


				while (cin.fail() || option > 2 || option <= 0) {
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
			else {
				cout << "Invalid operation. Please insert a valid one: ";
				getline(cin, aux);
				aux = cleaning_invalid_characters(aux);
			}
		}
		aux = resize_function(aux);
		Packs[pack_number].setPricePerPerson(stoi(aux));

		cout << "How many are the initially available spots? Insert 'Ctrl-Z' to cancel. ";
		getline(cin, aux);
		aux = cleaning_invalid_characters(aux);
		while (cin.fail() || aux == "" || !verifying_INT(aux)) {
			if (cin.eof()) {
				system("cls");
				cin.clear();
				cout << "Operation was canceled! " << endl << endl;
				cout << "1. Return to Main Menu. " << endl;
				cout << "2. Return to Travel Packs Management. " << endl;


				cout << endl << "Choose what you want to do (integer number): ";
				cin >> option;


				while (cin.fail() || option > 2 || option <= 0) {
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
			else {
				cout << "Invalid operation. Please insert a valid one: ";
				getline(cin, aux);
				aux = cleaning_invalid_characters(aux);
			}
		}
		aux = resize_function(aux);
		Packs[pack_number].setNumberMaxPeople(stoi(aux));


		cout << "How many are the sold spots? Insert 'Ctrl-Z' to cancel. ";
		getline(cin, aux);
		aux = cleaning_invalid_characters(aux);
		while (cin.fail() || aux == "" || !verifying_INT(aux)) {
			if (cin.eof()) {
				system("cls");
				cin.clear();
				cout << "Operation was canceled! " << endl << endl;
				cout << "1. Return to Main Menu. " << endl;
				cout << "2. Return to Travel Packs Management. " << endl;


				cout << endl << "Choose what you want to do (integer number): ";
				cin >> option;


				while (cin.fail() || option > 2 || option <= 0) {
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
			else {
				cout << "Invalid operation. Please insert a valid one: ";
				getline(cin, aux);
				aux = cleaning_invalid_characters(aux);
			}
		}
		aux = resize_function(aux);

		number = stoi(aux);


		while (number > Packs[pack_number].getNumberMaxPeople()) {
			cout << "Error ---- The number of sold spots is higher than the number of available spots! Please enter a number lower than " << Packs[pack_number].getNumberMaxPeople() << ". Insert 'Ctrl-Z' to cancel. ";
			getline(cin, aux);
			aux = cleaning_invalid_characters(aux);
			while (cin.fail() || aux == "" || !verifying_INT(aux)) {
				if (cin.eof()) {
					system("cls");
					cin.clear();
					cout << "Operation was canceled! " << endl << endl;
					cout << "1. Return to Main Menu. " << endl;
					cout << "2. Return to Travel Packs Management. " << endl;


					cout << endl << "Choose what you want to do (integer number): ";
					cin >> option;


					while (cin.fail() || option > 2 || option <= 0) {
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
				else {
					cout << "Invalid operation. Please insert a valid one: ";
					getline(cin, aux);
					aux = cleaning_invalid_characters(aux);
				}
			}
			number = stoi(aux);
		}

		Packs[pack_number].setSoldSpots(number);


		if (Packs[pack_number].getNumberMaxPeople() == Packs[pack_number].getSoldSpots() && Packs[pack_number].getPackNumber() > 0) {
			Packs[pack_number].setPackNumber(Packs[pack_number].getPackNumber()*(-1));

		}
		else if (Packs[pack_number].getNumberMaxPeople() != Packs[pack_number].getSoldSpots() && Packs[pack_number].getPackNumber() < 0) {
			Packs[pack_number].setPackNumber(Packs[pack_number].getPackNumber()*(-1));
		}
		break;

	case 2:
		cout << "What is the travel destination (Region - PlaceA, PlaceB, PlaceC, ...)? Insert 'Ctrl-Z' to cancel. ";
		getline(cin, aux);
		aux = cleaning_invalid_characters(aux);
		while (cin.fail() || aux == "") {
			if (cin.eof()) {
				system("cls");
				cin.clear();
				cout << "Operation was canceled! " << endl << endl;
				cout << "1. Return to Main Menu. " << endl;
				cout << "2. Return to Travel Packs Management. " << endl;


				cout << endl << "Choose what you want to do (integer number): ";
				cin >> option;


				while (cin.fail() || option > 2 || option <= 0) {
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
			else {
				cout << "Invalid operation. Please insert a valid one: ";
				getline(cin, aux);
				aux = cleaning_invalid_characters(aux);
			}
		}
		aux = cleaning_invalid_characters(aux);
		aux = resize_function(aux);
		while (verifying_Destination(aux) == false) {
			cout << "Invalid operation, please insert a valid one. Insert 'Ctrl-Z' to cancel. ";
			getline(cin, aux);
			aux = cleaning_invalid_characters(aux);
			while (cin.fail() || aux == "") {
				if (cin.eof()) {
					system("cls");
					cin.clear();
					cout << "Operation was canceled! " << endl << endl;
					cout << "1. Return to Main Menu. " << endl;
					cout << "2. Return to Travel Packs Management. " << endl;


					cout << endl << "Choose what you want to do (integer number): ";
					cin >> option;


					while (cin.fail() || option > 2 || option <= 0) {
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
				else {
					cout << "Invalid operation. Please insert a valid one: ";
					getline(cin, aux);
					aux = cleaning_invalid_characters(aux);
				}
			}
			aux = cleaning_invalid_characters(aux);
			aux = resize_function(aux);
		}
		Packs[pack_number].setDestination(aux);
		break;

	case 3:
		cout << "What is the departure date of the travel pack (YYYY / MM / DD)? Insert 'Ctrl-Z' to cancel. ";
		getline(cin, aux);
		aux = cleaning_invalid_characters(aux);
		while (cin.fail() || aux == "" || !verifying_date(aux)) {
			if (cin.eof()) {
				system("cls");
				cin.clear();
				cout << "Operation was canceled! " << endl << endl;
				cout << "1. Return to Main Menu. " << endl;
				cout << "2. Return to Travel Packs Management. " << endl;


				cout << endl << "Choose what you want to do (integer number): ";
				cin >> option;


				while (cin.fail() || option > 2 || option <= 0) {
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
			else {
				cout << "Invalid operation. Please insert a valid one: ";
				getline(cin, aux);
				aux = cleaning_invalid_characters(aux);
			}
		}
		aux = resize_function(aux);
		Packs[pack_number].setBeginDate(aux);


		while (!Packs[pack_number].getBeginDate().isValid() || !Packs[pack_number].getEndDate().isAfter(Packs[pack_number].getBeginDate())) {
			cout << "Invalid operation! The arrival date of the travel pack is ";
			visualize_date(Packs[pack_number].getEndDate());
			cout << ". Please insert a valid information. Insert 'Ctrl-Z' to cancel. ";
			getline(cin, aux);
			aux = cleaning_invalid_characters(aux);

			while (cin.fail() || aux == "" || !verifying_date(aux)) {
				if (cin.eof()) {
					system("cls");
					cin.clear();
					cout << "Operation was canceled! " << endl << endl;
					cout << "1. Return to Main Menu. " << endl;
					cout << "2. Return to Travel Packs Management. " << endl;


					cout << endl << "Choose what you want to do (integer number): ";
					cin >> option;


					while (cin.fail() || option > 2 || option <= 0) {
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
				else {
					cout << "Invalid operation. Please insert a valid one: ";
					getline(cin, aux);
					aux = cleaning_invalid_characters(aux);
				}
			}
			aux = resize_function(aux);
			Packs[pack_number].setBeginDate(aux);
		}

		if (!Packs[pack_number].getBeginDate().isAfter(today_date) && Packs[pack_number].getPackNumber() > 0) {
			Packs[pack_number].setPackNumber(Packs[pack_number].getPackNumber()*(-1));

		}
		else if (Packs[pack_number].getNumberMaxPeople() != Packs[pack_number].getSoldSpots() && Packs[pack_number].getPackNumber() < 0) {
			Packs[pack_number].setPackNumber(Packs[pack_number].getPackNumber()*(-1));
		}


		break;

	case 4:
		cout << "What is the arrival date of the travel pack (YYYY / MM / DD)? Insert 'Ctrl-Z' to cancel. ";
		getline(cin, aux);
		aux = cleaning_invalid_characters(aux);
		while (cin.fail() || aux == "" || !verifying_date(aux)) {
			if (cin.eof()) {
				system("cls");
				cin.clear();
				cout << "Operation was canceled! " << endl << endl;
				cout << "1. Return to Main Menu. " << endl;
				cout << "2. Return to Travel Packs Management. " << endl;


				cout << endl << "Choose what you want to do (integer number): ";
				cin >> option;


				while (cin.fail() || option > 2 || option <= 0) {
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
			else {
				cout << "Invalid operation. Please insert a valid one: ";
				getline(cin, aux);
				aux = cleaning_invalid_characters(aux);
			}
		}
		aux = resize_function(aux);
		Packs[pack_number].setEndDate(aux);

		while (!Packs[pack_number].getEndDate().isValid() || !Packs[pack_number].getEndDate().isAfter(Packs[pack_number].getBeginDate())) {
			cout << "Invalid operation! The departure date of the travel pack is ";
			visualize_date(Packs[pack_number].getBeginDate());
			cout << ". Please insert a valid information. Insert 'Ctrl-Z' to cancel. ";
			getline(cin, aux);
			aux = cleaning_invalid_characters(aux);

			while (cin.fail() || aux == "" || !verifying_date(aux)) {
				if (cin.eof()) {
					system("cls");
					cin.clear();
					cout << "Operation was canceled! " << endl << endl;
					cout << "1. Return to Main Menu. " << endl;
					cout << "2. Return to Travel Packs Management. " << endl;


					cout << endl << "Choose what you want to do (integer number): ";
					cin >> option;


					while (cin.fail() || option > 2 || option <= 0) {
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
				else {
					cout << "Invalid operation. Please insert a valid one: ";
					getline(cin, aux);
					aux = cleaning_invalid_characters(aux);
				}
			}
			aux = resize_function(aux);
			Packs[pack_number].setEndDate(aux);
		}
		break;


	case 5:
		cout << "What is the price per person of the travel pack? Insert 'Ctrl-Z' to cancel. ";
		getline(cin, aux);
		aux = cleaning_invalid_characters(aux);
		while (cin.fail() || aux == "" || !verifying_INT(aux)){
			if (cin.eof()) {
				system("cls");
				cin.clear();
				cout << "Operation was canceled! " << endl << endl;
				cout << "1. Return to Main Menu. " << endl;
				cout << "2. Return to Travel Packs Management. " << endl;


				cout << endl << "Choose what you want to do (integer number): ";
				cin >> option;


				while (cin.fail() || option > 2 || option <= 0) {
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
			else {
				cout << "Invalid operation. Please insert a valid one: ";
				getline(cin, aux);
				aux = cleaning_invalid_characters(aux);
			}
			}
		aux = resize_function(aux);
		Packs[pack_number].setPricePerPerson(stoi(aux));
		break;

	case 6:
		cout << "How many are the initially available spots? Insert 'Ctrl-Z' to cancel. ";
		getline(cin, aux);
		aux = cleaning_invalid_characters(aux);
		while (cin.fail() || aux == "" || !verifying_INT(aux)) {
			if (cin.eof()) {
				system("cls");
				cin.clear();
				cout << "Operation was canceled! " << endl << endl;
				cout << "1. Return to Main Menu. " << endl;
				cout << "2. Return to Travel Packs Management. " << endl;


				cout << endl << "Choose what you want to do (integer number): ";
				cin >> option;


				while (cin.fail() || option > 2 || option <= 0) {
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
			else {
				cout << "Invalid operation. Please insert a valid one: ";
				getline(cin, aux);
				aux = cleaning_invalid_characters(aux);
			}
		}
		aux = resize_function(aux);
		number = stoi(aux);

		while (number < Packs[pack_number].getSoldSpots()) {
			cout << "Error ---- The number of sold spots is higher than the number of available spots! Please enter a number higher than " << Packs[pack_number].getSoldSpots() << ". Insert 'Ctrl-Z' to cancel. ";
			getline(cin, aux);
			aux = cleaning_invalid_characters(aux);
			while (cin.fail() || aux == "" || !verifying_INT(aux)) {
				if (cin.eof()) {
					system("cls");
					cin.clear();
					cout << "Operation was canceled! " << endl << endl;
					cout << "1. Return to Main Menu. " << endl;
					cout << "2. Return to Travel Packs Management. " << endl;


					cout << endl << "Choose what you want to do (integer number): ";
					cin >> option;


					while (cin.fail() || option > 2 || option <= 0) {
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
				else {
					cout << "Invalid operation. Please insert a valid one: ";
					getline(cin, aux);
					aux = cleaning_invalid_characters(aux);
				}
			}

			number = stoi(aux);
		}

		Packs[pack_number].setSoldSpots(number);

		if (Packs[pack_number].getNumberMaxPeople() == Packs[pack_number].getSoldSpots() && Packs[pack_number].getPackNumber() > 0) {
			Packs[pack_number].setPackNumber(Packs[pack_number].getPackNumber()*(-1));

		}
		else if (Packs[pack_number].getNumberMaxPeople() != Packs[pack_number].getSoldSpots() && Packs[pack_number].getPackNumber() < 0) {
			Packs[pack_number].setPackNumber(Packs[pack_number].getPackNumber()*(-1));
		}

		break;

	case 7:
		cout << "How many are the sold spots? Insert 'Ctrl-Z' to cancel. ";
		getline(cin, aux);
		aux = cleaning_invalid_characters(aux);

		while (cin.fail() || aux == "" || !verifying_INT(aux)) {
			if (cin.eof()) {
				system("cls");
				cin.clear();
				cout << "Operation was canceled! " << endl << endl;
				cout << "1. Return to Main Menu. " << endl;
				cout << "2. Return to Travel Packs Management. " << endl;


				cout << endl << "Choose what you want to do (integer number): ";
				cin >> option;


				while (cin.fail() || option > 2 || option <= 0) {
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
			else {
				cout << "Invalid operation. Please insert a valid one: ";
				getline(cin, aux);
				aux = cleaning_invalid_characters(aux);
			}
		}
		aux = resize_function(aux);

		number = stoi(aux);

		while (number > Packs[pack_number].getNumberMaxPeople()) {
			cout << "Error ---- The number of sold spots is higher than the number of available spots! Please enter a number lower than " << Packs[pack_number].getNumberMaxPeople() << ". Insert 'Ctrl-Z' to cancel. ";
			getline(cin, aux);
			aux = cleaning_invalid_characters(aux);

			while (cin.fail() || aux == "" || !verifying_INT(aux)) {
				if (cin.eof()) {
					system("cls");
					cin.clear();
					cout << "Operation was canceled! " << endl << endl;
					cout << "1. Return to Main Menu. " << endl;
					cout << "2. Return to Travel Packs Management. " << endl;


					cout << endl << "Choose what you want to do (integer number): ";
					cin >> option;


					while (cin.fail() || option > 2 || option <= 0) {
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

				else {
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "Invalid operation, please insert a valid one: ";
					cin >> option;
				}
			}

			number = stoi(aux);
		}

		Packs[pack_number].setSoldSpots(number);

		if (Packs[pack_number].getNumberMaxPeople() == Packs[pack_number].getSoldSpots() && Packs[pack_number].getPackNumber() > 0) {
			Packs[pack_number].setPackNumber(Packs[pack_number].getPackNumber()*(-1));

		}
		else if (Packs[pack_number].getNumberMaxPeople() != Packs[pack_number].getSoldSpots() && Packs[pack_number].getPackNumber() < 0) {
			Packs[pack_number].setPackNumber(Packs[pack_number].getPackNumber()*(-1));
		}

		break;
	}


	string cancel;
	cout << endl << endl << "Are you sure you want to modify this pack with this information? " << endl << "Insert 'yes' to continue. " << endl << "Insert 'no' to cancel. " << endl << "Answer: ";
	cin >> cancel;
	while (cin.fail()) {
		if (cin.eof()) {
			cin.clear();
			cout << "Invalid operation, please insert a valid one: ";
			cin >> cancel;
		}

	}
	cancel = resize_function(cancel);
	cancel = formatting_string(cancel);

	while (cin.fail() || (cancel != "Yes" && cancel != "No")) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid operation, please insert a valid one: ";
		cin >> cancel;
		while (cin.fail()) {
			if (cin.eof()) {
				cin.clear();
				cout << "Invalid operation, please insert a valid one: ";
				cin >> cancel;
			}
		}

		cancel = resize_function(cancel);
		cancel = formatting_string(cancel);

	}

	if (cancel == "Yes") {
		update_packs(Packs, name_file);   //guardar informação no respetivo ficheiro
		system("cls");

		cout << "Pack was successfully modified!" << endl << endl;
	}
	else {
		system("cls");
		cout << "Operation was canceled!" << endl << endl;
	}
	

	cout << "1. Return to Main Menu. " << endl;
	cout << "2. Return to Travel Packs Management. " << endl;


	cout << endl << "Choose what you want to do (integer number): ";
	cin >> option;


	while (cin.fail() || option > 2 || option <= 0) {
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

int remove_pack(vector <Pack> &Packs, string name_file) {  //remove  o pacote, atualiza o vetor e o ficheiro dos pacotes

	int pack_number, option;
	string aux;

	system("cls");

	cout << "------- Information Of Packs -------" << endl << endl;
	
	for (int i = 1; i < size(Packs); i++) {
		if (Packs[i].getPackNumber() > 0) {
			visualize_pack(Packs, i);
		}
	}

	cout << endl << endl << "What is the number of the pack you want to remove? Insert 'Ctrl-Z' to cancel.  ";
	cin >> pack_number;

	while (cin.fail()) {
		if (cin.eof()) {
			system("cls");
			cin.clear();
			cout << "Operation was canceled! " << endl << endl;
			cout << "1. Return to Main Menu. " << endl;
			cout << "2. Return to Travel Packs Management. " << endl;


			cout << endl << "Choose what you want to do (integer number): ";
			cin >> option;


			while (cin.fail() || option > 2 || option <= 0) {
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
		else {
			cout << "Invalid operation. Please insert a valid one: ";
			getline(cin, aux);
			aux = cleaning_invalid_characters(aux);
		}
	}

	while (cin.fail() || pack_number > size(Packs) || pack_number <= 0) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid operation, please insert a valid one. Insert 'Ctrl-Z' to cancel. ";
		cin >> pack_number;
		if (cin.fail()) {
			if (cin.eof()) {
				system("cls");
				cin.clear();
				cout << "Operation was canceled! " << endl << endl;
				cout << "1. Return to Main Menu. " << endl;
				cout << "2. Return to Travel Packs Management. " << endl;


				cout << endl << "Choose what you want to do (integer number): ";
				cin >> option;


				while (cin.fail() || option > 2 || option <= 0) {
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
			else {
				cout << "Invalid operation. Please insert a valid one: ";
				getline(cin, aux);
				aux = cleaning_invalid_characters(aux);
			}
		}
	}

	cin.ignore(1000, '\n');
	

	string cancel;
	cout << endl << endl << "Are you sure you want to remove this pack? " << endl << "Insert 'yes' to continue. " << endl << "Insert 'no' to cancel. " << endl << "Answer: ";
	cin >> cancel;
	while (cin.fail()) {
		if (cin.eof()) {
			cin.clear();
			cout << "Invalid operation, please insert a valid one: ";
			cin >> cancel;
		}

	}
	cancel = resize_function(cancel);
	cancel = formatting_string(cancel);

	while (cin.fail() || (cancel != "Yes" && cancel != "No")) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid operation, please insert a valid one: ";
		cin >> cancel;
		while (cin.fail()) {
			if (cin.eof()) {
				cin.clear();
				cout << "Invalid operation, please insert a valid one: ";
				cin >> cancel;
			}
		}

		cancel = resize_function(cancel);
		cancel = formatting_string(cancel);

	}


	system("cls");
	if (cancel == "Yes") {
		
		Packs[pack_number].setPackNumber(Packs[pack_number].getPackNumber()*(-1));
		update_packs(Packs, name_file); //guardar informação no respetivo ficheiro

		cout << "Pack was successfully removed!" << endl << endl;
	}
	else {
		cout << "Operation was canceled!" << endl << endl;
	}

	   
	

	cout << "1. Return to Main Menu. " << endl;
	cout << "2. Return to Travel Packs Management. " << endl;


	cout << endl << "Choose what you want to do (integer number): ";
	cin >> option;


	while (cin.fail() || option > 2 || option <= 0) {
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
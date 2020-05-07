#include"ClientsManagement.h"
//nao ha verificaçao de input para o nome, rua e distrito 
int create_client(vector <Client> &Clients, string name_file, vector <Pack> Packs) { // //remove o cliente, atualiza o vector dos clientes e o ficheiro dos clientes

	int option;
	string aux;
	Client new_client;
	Address address;

	system("cls");
	cout << "-------------- CREATE CLIENT --------------" << endl;


	cout << "What is the name of the client? Insert 'Ctrl-Z' to cancel. ";
	getline(cin, aux);
	aux = cleaning_invalid_characters(aux);
	while (cin.fail() || aux == ""|| aux =="0") {
		if (cin.eof()|| aux== "0") {
			system("cls");
			cin.clear();
			cout << "Operation was canceled! " << endl << endl;
			cout << "1. Return to Main Menu. " << endl;
			cout << "2. Return to Clients Management. " << endl;


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
	aux = verifying_string(aux);
	new_client.setClientName(formatting_string(aux));

	cout << "What is the NIF of the client? Insert 'Ctrl-Z' to cancel. ";
	getline(cin, aux);
	aux = cleaning_invalid_characters(aux);
	while (cin.fail() || aux == "" || aux == "0") {
		if (cin.eof() || aux == "0") {
			system("cls");
			cin.clear();
			cout << "Operation was canceled! " << endl << endl;
			cout << "1. Return to Main Menu. " << endl;
			cout << "2. Return to Clients Management. " << endl;


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
	new_client.setClientNIF(verifying_NIF(aux));

	cout << "How many members does the client's family has? Insert 'Ctrl-Z' to cancel. ";
	getline(cin, aux);
	aux = cleaning_invalid_characters(aux);
	while (cin.fail() || aux == "" || aux == "0") {
		if (cin.eof() || aux == "0") {
			system("cls");
			cin.clear();
			cout << "Operation was canceled! " << endl << endl;
			cout << "1. Return to Main Menu. " << endl;
			cout << "2. Return to Clients Management. " << endl;


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
	new_client.setNumberOfFamilyMembers(verifying_int(aux));


	cout << "----Information of client's address----" << endl;
	cout << "What is the name of the street? Insert 'Ctrl-Z' to cancel. ";
	getline(cin, aux);
	aux = cleaning_invalid_characters(aux);
	while (cin.fail() || aux == "" || aux == "0") {
		if (cin.eof() || aux == "0") {
			system("cls");
			cin.clear();
			cout << "Operation was canceled! " << endl << endl;
			cout << "1. Return to Main Menu. " << endl;
			cout << "2. Return to Clients Management. " << endl;


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
	address.setStreet(formatting_string(aux));

	cout << "What is the door number? Insert 'Ctrl-Z' to cancel.  ";
	getline(cin, aux);
	aux = cleaning_invalid_characters(aux);
	while (cin.fail() || aux == "" || aux == "0") {
		if (cin.eof()) {
			system("cls");
			cin.clear();
			cout << "Operation was canceled! " << endl << endl;
			cout << "1. Return to Main Menu. " << endl;
			cout << "2. Return to Clients Management. " << endl;


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
	address.setDoorNumber(verifying_int(aux));

	cout << "What is the apartment's door (insert '-' if there isn't an apartment number)? Insert 'Ctrl-Z' to cancel. ";
	getline(cin, aux);
	aux = cleaning_invalid_characters(aux);
	while (cin.fail() || aux == "" || aux == "0") {
		if (cin.eof()) {
			system("cls");
			cin.clear();
			cout << "Operation was canceled! " << endl << endl;
			cout << "1. Return to Main Menu. " << endl;
			cout << "2. Return to Clients Management. " << endl;


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
	aux = verifying_ApartmentDoor(aux);

	if (aux != "-") {
		address.setApartmentNumber(resize_function(aux));
	}
	else {
		address.setApartmentNumber(aux);
	}

	cout << "What is the ZIP code (xxxx-xxx)? Insert 'Ctrl-Z' to cancel.  ";
	getline(cin, aux);
	aux = cleaning_invalid_characters(aux);
	while (cin.fail() || aux == "" || aux == "0") {
		if (cin.eof() || aux == "0") {
			system("cls");
			cin.clear();
			cout << "Operation was canceled! " << endl << endl;
			cout << "1. Return to Main Menu. " << endl;
			cout << "2. Return to Clients Management. " << endl;


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
	string zipcode = verifying_ZIPcode(aux);


	if (zipcode == "1") {
		return 1;
	}
	else if (zipcode == "2") {
		return 2;
	}
	else {
		address.setZIPCode(zipcode);
	}



	

	cout << "What is the province? Insert 'Ctrl-Z' to cancel. ";
	getline(cin, aux);
	aux = cleaning_invalid_characters(aux);
	while (cin.fail() || aux == "" || aux == "0") {
		if (cin.eof() || aux == "0") {
			system("cls");
			cin.clear();
			cout << "Operation was canceled! " << endl << endl;
			cout << "1. Return to Main Menu. " << endl;
			cout << "2. Return to Clients Management. " << endl;


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
	aux = verifying_string(aux);

	if (aux == "1") {
		return 1;
	}
	else if (aux == "2") {
		return 2;
	}
	else {
		address.setProvince(formatting_string(aux));
	}


	new_client.setClientAddress(address);

	cout << "What are the identification numbers of bought packs (separated by ';')? Insert 'Ctrl-Z' to cancel. ";
	getline(cin, aux);
	aux = cleaning_invalid_characters(aux);
	while (cin.fail() || aux==""|| !verifying_bought_packs(aux)) {
		if (cin.eof()) {
			system("cls");
			cin.clear();
			cout << "Operation was canceled! " << endl << endl;
			cout << "1. Return to Main Menu. " << endl;
			cout << "2. Return to Clients Management. " << endl;


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
	if (aux =="\n") {
		new_client.setBoughtPacks(aux);
	}
	
	aux = resize_function(aux);

	new_client.setBoughtPacks(aux);



	bool valid = true;

	for (int i = 0; i < size(new_client.getBoughtPacks()); i++) {
		if (!(new_client.getBoughtPacks()[i] > 0)) {
			valid = false;
		}

		else if (!(new_client.getBoughtPacks()[i] < size(Packs))) {
			valid = false;
		}
	}



	while (valid == false) {//se os pacotes inseridos nao existem nos dados recolhidos dos ficheiros

		valid = true;
		cout << "There aren't any packs in our database corresponding to that ones, please insert a valid input.Insert 'Ctr-Z' to cancel. ";
		getline(cin, aux);
		aux = cleaning_invalid_characters(aux);
		while (cin.fail() || aux == "" || !verifying_bought_packs(aux)) {
			if (cin.eof()) {
				system("cls");
				cin.clear();
				cout << "Operation was canceled! " << endl << endl;
				cout << "1. Return to Main Menu. " << endl;
				cout << "2. Return to Clients Management. " << endl;


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

		new_client.setBoughtPacks(aux);


		for (int i = 0; i < size(new_client.getBoughtPacks()); i++) {
			if (!new_client.getBoughtPacks()[i] > 0 || !new_client.getBoughtPacks()[i] < size(Packs)) {
				valid = false;
			}
		}
	}


	cout << "What is the total purchased? Insert 'Ctrl-Z' to cancel. ";
	getline(cin, aux);
	aux = cleaning_invalid_characters(aux);
	while (cin.fail() || aux == ""|| aux=="0") {
		if (cin.eof() || aux == "0") {
			system("cls");
			cin.clear();
			cout << "Operation was canceled! " << endl << endl;
			cout << "1. Return to Main Menu. " << endl;
			cout << "2. Return to Clients Management. " << endl;


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
	new_client.setTotalPurchased(verifying_int(aux));

	string cancel;
	cout << endl << endl << "Are you sure you want to create a client with this information? " << endl << "Insert 'yes' to continue. " << endl << "Insert 'no' to cancel. " << endl << "Answer: ";
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
		Clients.push_back(new_client); //acrescentar o novo cliente ao vetor dos Clientes

		update_clients(Clients, name_file); //passar nova informação para o ficheiro
		system("cls");

		cout << "Client successfully was created!" << endl << endl;
	}


	else {
		system("cls");

		cout << "Operation was canceled!" << endl << endl;
	}


	cout << "1. Return to Main Menu. " << endl;
	cout << "2. Return to Clients Management. " << endl;


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

int modify_client(vector <Client> &Clients, string name_file, vector <Pack> Packs) { //modifica o cliente, atualiza o vector dos clientes e o ficheiro dos clientes

	int option, client_number;
	string aux;
	Address address;
	int nif;
	string zipcode;

	system("cls");

	cout << "-------------- MODIFY CLIENT --------------" << endl;
	cout << "What do you want to modify in your client's information? " << endl;

	cout << "1. Everything. " << endl;
	cout << "2. Name. " << endl;
	cout << "3. NIF. " << endl;
	cout << "4. Number of family members. " << endl;
	cout << "5. Address. " << endl;
	cout << "6. Packs already bought. " << endl;
	cout << "7. Total purchased. " << endl;
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
	if (option == 8) {
		return 1;
	}

	cin.ignore(1000, '\n');
	system("cls");

	cout << "------- Information Of Clients -------" << endl << endl;
	visualize_clients(Clients);

	cout << endl << endl << "What is the number of the client you want to modify? ";
	cin >> client_number;

	while (cin.fail() || client_number > size(Clients) || client_number <= 0) {
		if (cin.eof()) {
			cin.clear();
			cout << "Invalid operation, please insert a valid one: ";
			cin >> client_number;
		}
		else {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid operation, please insert a valid one: ";
			cin >> client_number;
		}
	}
	cin.ignore(1000, '\n');
	system("cls");

	visualize_client(Clients, client_number - 1);
	cout << endl;

	bool valid;

	switch (option) {
	case 1:
		cout << "What is the name of the client? Insert 'Ctrl-Z' to cancel. ";
		getline(cin, aux);
		aux = cleaning_invalid_characters(aux);
		while (cin.fail() || aux == "" || aux == "0") {
			if (cin.eof() || aux == "0") {
				system("cls");
				cin.clear();
				cout << "Operation was canceled! " << endl << endl;
				cout << "1. Return to Main Menu. " << endl;
				cout << "2. Return to Clients Management. " << endl;


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
		aux = verifying_string(aux);
		Clients[client_number - 1].setClientName(formatting_string(aux));

		cout << "What is the NIF of client? Insert 'Ctrl-Z' to cancel. ";
		getline(cin, aux);
		aux = cleaning_invalid_characters(aux);

		while (aux == "" || cin.fail() || aux == "0") {
			if (cin.eof() || aux == "0") {
				system("cls");
				cin.clear();
				cout << "Operation was canceled! " << endl << endl;
				cout << "1. Return to Main Menu. " << endl;
				cout << "2. Return to Clients Management. " << endl;


				cout << endl << "Choose what you want to do (integer number): ";
				cin >> option;


				while (cin.fail() || option > 2 || option <= 0) {
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "Invalid operation, please insert a valid one: ";
					cin >> option;
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

		nif = verifying_NIF(aux);
		if (nif == 1) {
			return 1;
		}
		else if (nif == 2) {
			return 2;
		}
		else {
			Clients[client_number - 1].setClientNIF(nif);
		}


		cout << "How many members does the client's family has? Insert 'Ctrl-Z' to cancel. ";
		getline(cin, aux);
		aux = cleaning_invalid_characters(aux);
		while (cin.fail() || aux == "" || aux == "0") {
			if (cin.eof() || aux == "0") {
				system("cls");
				cin.clear();
				cout << "Operation was canceled! " << endl << endl;
				cout << "1. Return to Main Menu. " << endl;
				cout << "2. Return to Clients Management. " << endl;


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
		Clients[client_number - 1].setNumberOfFamilyMembers(verifying_int(aux));



		cout << "----Information of client's address----" << endl;
		cout << "What is the name of the street? Insert 'Ctrl-Z' to cancel. ";
		getline(cin, aux);
		aux = cleaning_invalid_characters(aux);
		while (cin.fail() || aux == "" || aux == "0") {
			if (cin.eof() || aux == "0"){
				system("cls");
				cin.clear();
				cout << "Operation was canceled! " << endl << endl;
				cout << "1. Return to Main Menu. " << endl;
				cout << "2. Return to Clients Management. " << endl;


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
			}
		}
		aux = resize_function(aux);
		address.setStreet(formatting_string(aux));

		cout << "What is the door number? Insert 'Ctrl-Z' to cancel.  ";
		getline(cin, aux);
		while (cin.fail() || aux == "" || aux == "0") {
			if (cin.eof() || aux == "0") {
				system("cls");
				cin.clear();
				cout << "Operation was canceled! " << endl << endl;
				cout << "1. Return to Main Menu. " << endl;
				cout << "2. Return to Clients Management. " << endl;


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
		address.setDoorNumber(verifying_int(aux));

		cout << "What is apartment's door (insert '-' if there isn't an apartment number)? Insert 'Ctrl-Z' to cancel. ";
		getline(cin, aux);
		aux = cleaning_invalid_characters(aux);
		while (cin.fail() || aux == "" || aux == "0") {
			if (cin.eof() || aux == "0") {
				system("cls");
				cin.clear();
				cout << "Operation was canceled! " << endl << endl;
				cout << "1. Return to Main Menu. " << endl;
				cout << "2. Return to Clients Management. " << endl;


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
		aux = verifying_ApartmentDoor(aux);

		if (aux != "-") {
			address.setApartmentNumber(resize_function(aux));
		}
		else {
			address.setApartmentNumber(aux);
		}

		cout << "What is the ZIP code (xxxx-xxx)? Insert 'Ctrl-Z' to cancel.  ";
		getline(cin, aux);
		aux = cleaning_invalid_characters(aux);
		while (cin.fail() || aux == "" || aux == "0") {
			if (cin.eof() || aux == "0") {
				system("cls");
				cin.clear();
				cout << "Operation was canceled! " << endl << endl;
				cout << "1. Return to Main Menu. " << endl;
				cout << "2. Return to Clients Management. " << endl;


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
		zipcode = verifying_ZIPcode(aux);

		if (zipcode == "1") {
			return 1;
		}
		else if (zipcode == "2") {
			return 2;
		}
		else {
			address.setZIPCode(zipcode);
		}


		cout << "What is the province? Insert 'Ctrl-Z' to cancel. ";
		getline(cin, aux);
		aux = cleaning_invalid_characters(aux);
		while (cin.fail() || aux == "" || aux == "0") {
			if (cin.eof() || aux == "0") {
				system("cls");
				cin.clear();
				cout << "Operation was canceled! " << endl << endl;
				cout << "1. Return to Main Menu. " << endl;
				cout << "2. Return to Clients Management. " << endl;


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
		aux = verifying_string(aux);

		if (aux == "1") {
			return 1;
		}
		else if (aux == "2") {
			return 2;
		}
		else {
			address.setProvince(formatting_string(aux));
		}
		Clients[client_number - 1].setClientAddress(address);


		cout << "What are the identification numbers of bought packs (separated by ';')? Insert 'Ctrl-Z' to cancel. ";
		getline(cin, aux);
		aux = cleaning_invalid_characters(aux);
		while (cin.fail() || aux == "" || !verifying_bought_packs(aux)) {
			if (cin.eof()) {
				system("cls");
				cin.clear();
				cout << "Operation was canceled! " << endl << endl;
				cout << "1. Return to Main Menu. " << endl;
				cout << "2. Return to Clients Management. " << endl;


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
		Clients[client_number - 1].setBoughtPacks(aux);

		valid = true;

		for (int i = 0; i < size(Clients[client_number - 1].getBoughtPacks()); i++) {
			if (!(Clients[client_number - 1].getBoughtPacks()[i] > 0)) {
				valid = false;
			}

			else if (!(Clients[client_number - 1].getBoughtPacks()[i] < size(Packs))) {
				valid = false;
			}
		}



		while (valid == false) {

			valid = true;
			cout << "There aren't any packs in our database corresponding to that ones, please insert a valid input. Insert 'Ctr-Z' to cancel. B";
			getline(cin, aux);
			aux = cleaning_invalid_characters(aux);
			while (cin.fail() || aux == "" || !verifying_bought_packs(aux)) {
				if (cin.eof()) {
					system("cls");
					cin.clear();
					cout << "Operation was canceled! " << endl << endl;
					cout << "1. Return to Main Menu. " << endl;
					cout << "2. Return to Clients Management. " << endl;


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

			Clients[client_number - 1].setBoughtPacks(aux);


			for (int i = 0; i < size(Clients[client_number - 1].getBoughtPacks()); i++) {
				if (!(Clients[client_number - 1].getBoughtPacks()[i] > 0)) {
					valid = false;
				}

				else if (!(Clients[client_number - 1].getBoughtPacks()[i] < size(Packs))) {
					valid = false;
				}
			}
		}




		cout << "What is the total purchased? Insert 'Ctrl-Z' to cancel. ";
		getline(cin, aux);
		aux = cleaning_invalid_characters(aux);
		while (cin.fail() || aux == "" || aux == "0") {
			if (cin.eof() || aux == "0") {
				system("cls");
				cin.clear();
				cout << "Operation was canceled! " << endl << endl;
				cout << "1. Return to Main Menu. " << endl;
				cout << "2. Return to Clients Management. " << endl;


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
		Clients[client_number - 1].setTotalPurchased(verifying_int(aux));

		break;

	case 2:
		cout << "What is the name of the client? Insert 'Ctrl-Z' to cancel. ";
		getline(cin, aux);
		aux = cleaning_invalid_characters(aux);
		while (cin.fail() || aux=="" || aux == "0"){
			if (cin.eof() || aux == "0") {
				system("cls");
				cin.clear();
				cout << "Operation was canceled! " << endl << endl;
				cout << "1. Return to Main Menu. " << endl;
				cout << "2. Return to Clients Management. " << endl;


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
		aux = verifying_string(aux);
		Clients[client_number - 1].setClientName(formatting_string(aux));

		break;

	case 3:
		cout << "What is the NIF of client? Insert 'Ctrl-Z' to cancel. ";
		getline(cin, aux);
		aux = cleaning_invalid_characters(aux);

		while (aux == "" || cin.fail() || aux == "0") {
			if (cin.eof() || aux == "0") {
				system("cls");
				cin.clear();
				cout << "Operation was canceled! " << endl << endl;
				cout << "1. Return to Main Menu. " << endl;
				cout << "2. Return to Clients Management. " << endl;


				cout << endl << "Choose what you want to do (integer number): ";
				cin >> option;


				while (cin.fail() || option > 2 || option <= 0) {
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "Invalid operation, please insert a valid one: ";
					cin >> option;
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

		nif = verifying_NIF(aux);
		if (nif == 1) {
			return 1;
		}
		else if (nif == 2) {
			return 2;
		}
		else {
			Clients[client_number - 1].setClientNIF(nif);
		}


		break;


	case 4:
		cout << "How many members does the client's family has? Insert 'Ctrl-Z' to cancel. ";
		getline(cin, aux);
		aux = cleaning_invalid_characters(aux);
		if (cin.fail() || aux == "0") {
			if (cin.eof() || aux == "0") {
				system("cls");
				cin.clear();
				cout << "Operation was canceled! " << endl << endl;
				cout << "1. Return to Main Menu. " << endl;
				cout << "2. Return to Clients Management. " << endl;


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
		Clients[client_number - 1].setNumberOfFamilyMembers(verifying_int(aux));
		break;

	case 5:
		cout << "---- Information of client's address ----" << endl;
		cout << "What is the name of the street? Insert 'Ctrl-Z' to cancel. ";
		getline(cin, aux);
		aux = cleaning_invalid_characters(aux);
		while (cin.fail() || aux == "" || aux == "0") {
			if (cin.eof() || aux == "0") {
				system("cls");
				cin.clear();
				cout << "Operation was canceled! " << endl << endl;
				cout << "1. Return to Main Menu. " << endl;
				cout << "2. Return to Clients Management. " << endl;


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
		address.setStreet(formatting_string(aux));

		cout << "What is the door number? Insert 'Ctrl-Z' to cancel.  ";
		getline(cin, aux);
		aux = cleaning_invalid_characters(aux);
		while (cin.fail() || aux == "" || aux == "0") {
			if (cin.eof() || aux == "0") {
				system("cls");
				cin.clear();
				cout << "Operation was canceled! " << endl << endl;
				cout << "1. Return to Main Menu. " << endl;
				cout << "2. Return to Clients Management. " << endl;


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
		address.setDoorNumber(verifying_int(aux));

		cout << "What is apartment's door (insert '-' if there isn't an apartment number)? Insert 'Ctrl-Z' to cancel. ";
		getline(cin, aux);
		aux = cleaning_invalid_characters(aux);
		while (cin.fail()||aux=="" || aux == "0") {
			if (cin.eof() || aux == "0") {
				system("cls");
				cin.clear();
				cout << "Operation was canceled! " << endl << endl;
				cout << "1. Return to Main Menu. " << endl;
				cout << "2. Return to Clients Management. " << endl;


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
		aux = verifying_ApartmentDoor(aux);

		if (aux != "-") {
			address.setApartmentNumber(resize_function(aux));
		}
		else {
			address.setApartmentNumber(aux);
		}

		cout << "What is the ZIP code (xxxx-xxx)? Insert 'Ctrl-Z' to cancel.  ";
		getline(cin, aux);
		aux = cleaning_invalid_characters(aux);
		while (cin.fail() || aux == "" || aux == "0") {
			if (cin.eof() || aux == "0") {
				system("cls");
				cin.clear();
				cout << "Operation was canceled! " << endl << endl;
				cout << "1. Return to Main Menu. " << endl;
				cout << "2. Return to Clients Management. " << endl;


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
		zipcode = verifying_ZIPcode(aux);

		if (zipcode == "1") {
			return 1;
		}
		else if (zipcode == "2") {
			return 2;
		}
		else {
			address.setZIPCode(zipcode);
		}


		cout << "What is the province? Insert 'Ctrl-Z' to cancel. ";
		getline(cin, aux);
		aux = cleaning_invalid_characters(aux);
		while (cin.fail() || aux == "" || aux == "0") {
			if (cin.eof() || aux == "0") {
				system("cls");
				cin.clear();
				cout << "Operation was canceled! " << endl << endl;
				cout << "1. Return to Main Menu. " << endl;
				cout << "2. Return to Clients Management. " << endl;


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
		aux = verifying_string(aux);

		if (aux == "1") {
			return 1;
		}
		else if (aux == "2") {
			return 2;
		}
		else {
			address.setProvince(formatting_string(aux));
		}
		

		Clients[client_number - 1].setClientAddress(address);
		break;

	case 6:
		cout << "What are the identification numbers of bought packs (separated by ';')? Insert 'Ctrl-Z' to cancel. ";
		getline(cin, aux);
		aux = cleaning_invalid_characters(aux);
		while (cin.fail() || aux == "" || !verifying_bought_packs(aux)) {
			if (cin.eof()) {
				system("cls");
				cin.clear();
				cout << "Operation was canceled! " << endl << endl;
				cout << "1. Return to Main Menu. " << endl;
				cout << "2. Return to Clients Management. " << endl;


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
		Clients[client_number - 1].setBoughtPacks(aux);

		valid = true;

		for (int i = 0; i < size(Clients[client_number - 1].getBoughtPacks()); i++) {
			if (!(Clients[client_number - 1].getBoughtPacks()[i] > 0)) {
				valid = false;
			}

			else if (!(Clients[client_number - 1].getBoughtPacks()[i] < size(Packs))) {
				valid = false;
			}
		}



		while (valid == false) {

			valid = true;
			cout << "There aren't any packs in our database corresponding to that ones, please insert a valid input. Insert 'Ctr-Z' to cancel. ";
			getline(cin, aux);
			aux = cleaning_invalid_characters(aux);
			while (cin.fail() || aux == "" || !verifying_bought_packs(aux)) {
				if (cin.eof()) {
					system("cls");
					cin.clear();
					cout << "Operation was canceled! " << endl << endl;
					cout << "1. Return to Main Menu. " << endl;
					cout << "2. Return to Clients Management. " << endl;


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

			Clients[client_number - 1].setBoughtPacks(aux);


			for (int i = 0; i < size(Clients[client_number - 1].getBoughtPacks()); i++) {
				if (!(Clients[client_number - 1].getBoughtPacks()[i] > 0)) {
					valid = false;
				}

				else if (!(Clients[client_number - 1].getBoughtPacks()[i] < size(Packs))) {
					valid = false;
				}
			}
		}

		break;

	case 7:
		cout << "What is the total purchased? Insert 'Ctrl-Z' to cancel. ";
		getline(cin, aux);
		aux = cleaning_invalid_characters(aux);
		while (cin.fail() || aux == "" || aux == "0"){
			if (cin.eof() || aux == "0") {
				system("cls");
				cin.clear();
				cout << "Operation was canceled! " << endl << endl;
				cout << "1. Return to Main Menu. " << endl;
				cout << "2. Return to Clients Management. " << endl;


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
		Clients[client_number - 1].setTotalPurchased(verifying_int(aux));
		break;

	case 8:
		break;
	}
	string cancel;
	cout << endl << endl << "Are you sure you want to modify this client with this information? " << endl << "Insert 'yes' to continue. " << endl << "Insert 'no' to cancel." << endl << "Answer: ";
	cin >> cancel;
	

	while (cin.fail() ) {
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
		update_clients(Clients, name_file);   //guardar informação no respetivo ficheiro


		cout << "Client was successfully modified!" << endl << endl;
	}
	else {
		cout << "Operation was canceled!" << endl << endl;
	}



	cout << "1. Return to Main Menu. " << endl;
	cout << "2. Return to Clients Management. " << endl;


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


int remove_client(vector <Client> &Clients, string name_file) { //remove o cliente, atualiza o vector dos clientes e o ficheiro dos clientes

	int client_number, option;
	system("cls");

	cout << "------- Information Of Clients -------" << endl << endl;
	visualize_clients(Clients);

	cout << endl << endl << "What is the number of the client you want to remove? Insert 'Ctrl-Z' to cancel.";
	cin >> client_number;
	if (cin.fail()) {
		if (cin.eof()) {
			system("cls");
			cin.clear();
			cout << "Operation was canceled! " << endl << endl;
			cout << "1. Return to Main Menu. " << endl;
			cout << "2. Return to Clients Management. " << endl;


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

	while (cin.fail() || client_number > size(Clients) || client_number <= 0) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid operation, please insert a valid one: ";
		cin >> client_number;
		if (cin.eof()) {
			system("cls");
			cin.clear();
			cout << "Operation was canceled! " << endl << endl;
			cout << "1. Return to Main Menu. " << endl;
			cout << "2. Return to Clients Management. " << endl;


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
		}
	}
	cin.ignore(1000, '\n');


	string cancel;
	cout << endl << endl << "Are you sure you want to remove this client? " << endl << "Insert 'yes' to continue. " << endl << "Insert 'no' to cancel. " << endl << "Answer: ";
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

		Clients.erase(Clients.begin() + client_number - 1); //elimina o cliente atraves do indice no vetor
		update_clients(Clients, name_file); //guardar informação no respetivo ficheiro

		cout << "Client was successfully removed!" << endl << endl;
	}
	else {
		cout << "Operation was canceled!" << endl << endl;
	}



	cout << "1. Return to Main Menu. " << endl;
	cout << "2. Return to Clients Management. " << endl;


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
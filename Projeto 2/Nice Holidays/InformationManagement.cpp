#include "InformationManagement.h"

int show_agency(Agency agency) { // funçao chamada no menu quando se quer visualizar a agencia
	
	system("cls");

	visualize_agency(agency);

	cout << endl << endl << endl << "1. Return to Main Menu. " << endl;
	cout << "2. Return to Information Menu. " << endl;

	int option;
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

int show_client(vector <Client> Clients) {// funçao chamada quando se quer visualizar um cliente

	int option;
	system("cls");

	cout << "---------------- View Client Information ----------------" << endl << endl;


	cout << "What do you know about the client? " << endl;
	cout << "1. Name." << endl;
	cout << "2. NIF." << endl;

	cout << endl << "Choose an option please (integer number). Insert 'Ctrl-Z' to cancel. ";
	cin >> option;

	if (cin.fail()) {
		if (cin.eof()) {
			system("cls");
			cin.clear();
			cout << "Operation was canceled! " << endl << endl;
			cout << endl << endl << endl << "1. Return to Main Menu. " << endl;
			cout << "2. Return to Information Menu. " << endl;


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


	while (cin.fail() || option > 2 || option <= 0) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid operation, please insert a valid one. Insert 'Ctrl-Z' to cancel. ";
		cin >> option;

		if (cin.fail()) {
			if (cin.eof()) {
				system("cls");
				cin.clear();
				cout << "Operation was canceled! " << endl << endl;
				cout << endl << endl << endl << "1. Return to Main Menu. " << endl;
				cout << "2. Return to Information Menu. " << endl;


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

	if (option == 1) {
		for (int i = 0; i < size(Clients); i++) {
			cout << i+1 << ". " << Clients[i].getClientName() << endl;
		}
	}
	else if (option == 2) {
		for (int i = 0; i < size(Clients); i++) {
			cout << i+1 << ". " << Clients[i].getClientNIF() << endl;
		}
	}

	cout << endl << "Choose the client you want (integer number). Insert 'Ctrl-Z' to cancel. ";
	cin >> option;


	if (cin.fail()) {
		if (cin.eof()) {
			system("cls");
			cin.clear();
			cout << "Operation was canceled! " << endl << endl;
			cout << endl << endl << endl << "1. Return to Main Menu. " << endl;
			cout << "2. Return to Information Menu. " << endl;


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

	
	while (cin.fail() || option > size(Clients) || option <= 0) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid operation, please insert a valid one. Insert 'Ctrl-Z' to cancel. ";
		cin >> option;


		if (cin.fail()) {
			if (cin.eof()) {
				system("cls");
				cin.clear();
				cout << "Operation was canceled! " << endl << endl;
				cout << endl << endl << endl << "1. Return to Main Menu. " << endl;
				cout << "2. Return to Information Menu. " << endl;


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
		}

		
	}
	cin.ignore(1000, '\n');
	system("cls");

	visualize_client(Clients, option-1);

	cout << endl << endl << endl << "1. Return to Main Menu. " << endl;
	cout << "2. Return to Information Menu. " << endl;


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

int show_all_clients(vector <Client> Clients) {//funçao chamada quando se quer ver todos os clientes
	system("cls");

	cout << "----------------- View All Clients Information -----------------" << endl << endl;
	visualize_clients(Clients);

	cout << endl << endl << endl << "1. Return to Main Menu. " << endl;
	cout << "2. Return to Information Menu. " << endl;

	int option;
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

int show_available_packs(vector <Pack> Packs) {//funçao chamada quando se quer ver os pacotes disponiveis
	string aux;
	int option = 0, counter = 0;
	string line, str;
	Date date_begin, date_end;
	int delimiter;
	bool none;

	bool is_valid1, is_valid2;
	system("cls");

	for (int i = 1; i < size(Packs); i++) {
		if (Packs[i].getPackNumber() < 0) {
			counter++;
		}
	}

	if (counter == size(Packs)) {
		cout << "There aren't available packs!" << endl;

	}
	else {
		cout << "-------- View Available Packs --------" << endl << endl;
		cout << "1. View All Available Packs." << endl;
		cout << "2. Search Avalaible Packs by destination." << endl;
		cout << "3. Search Available Packs by dates. " << endl;
		cout << "4. Search Available Packs by destination and between dates. " << endl;
		cout << "5. Return to Information Menu." << endl;
		cout << "6. Return to Main Menu." << endl;
		

		cout << endl << "Choose an option please (integer number): ";
		cin >> option;
		

		while (cin.fail() || option > 6 || option <= 0) {
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
		counter = 0;

		Date today_date;
		switch (option) {
		case 1:
			cout << "------------------------ View All Available Packs ------------------------" << endl << endl;
			for (int i = 1; i < size(Packs); i++) {//mostra todos os pacotes disponiveis
				if (Packs[i].getPackNumber() > 0) {
					visualize_pack(Packs, i);
				}
			}
			break;
		case 2:
			cout << "-------- Search Avalaible Packs by destination --------" << endl << endl;


			cout << "Which destination do you want (name of the city)? Insert 'Ctrl-Z' to cancel. ";
			getline(cin, line);
			line = cleaning_invalid_characters(line);
			line = verifying_string(line);

			while (cin.fail() || line == "") {
				if (cin.eof()) {
					system("cls");
					cin.clear();
					cout << "Operation was canceled! ";
					cout << endl << endl << endl << "1. Return to Main Menu. " << endl;
					cout << "2. Return to Information Menu. " << endl;
					cout << "3. Return to Available Packs Menu. " << endl;


					cout << endl << "Choose what you want to do (integer number): ";
					cin >> option;


					while (cin.fail() || option > 3 || option <= 0) {
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
					cout << "Invalid operation, please insert a valid one: ";
					getline(cin, line);
					line = cleaning_invalid_characters(line);
				}
			}

			str = resize_function(line);
			str = formatting_string(str);

			system("cls");
			none = true;
			counter = 0;
			

			for (int i = 1; i < size(Packs); i++) {//mostra os pacotes com o destino especificado pelo cliente
				aux = resize_function(Packs[i].getDestination()[0]);
				aux = formatting_string(aux);
				if (str == aux && Packs[i].getPackNumber() > 0) {
					visualize_pack(Packs, i);
					none = false;
				}

			}
			if (none) {//se nao houver nenhum printa esta mensagem
				cout << endl << "There isn't any available pack for that destination!" << endl;
			}
			break;


		case 3:

			cout << "-------- Search Avalaible Packs by dates --------" << endl << endl;

			cout << "What are the dates between which you want to travel (YYYY/MM/DD - YYYY/MM/DD)? Insert 'Ctrl-Z to cancel. ";
			getline(cin, aux);
			aux = cleaning_invalid_characters(aux);


			while (cin.fail() || aux == "") {
				if (cin.eof()) {
					system("cls");
					cin.clear();
					cout << "Operation was canceled! ";
					cout << endl << endl << endl << "1. Return to Main Menu. " << endl;
					cout << "2. Return to Information Menu. " << endl;
					cout << "3. Return to Available Packs Menu. " << endl;


					cout << endl << "Choose what you want to do (integer number): ";
					cin >> option;


					while (cin.fail() || option > 3 || option <= 0) {
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
					cout << "Invalid operation, please insert a valid one: ";
					getline(cin, aux);
					aux = cleaning_invalid_characters(aux);
				}
			}

			aux = resize_function(aux);
			delimiter = aux.find_first_of('-');

			is_valid1 = verifying_date(aux.substr(0, delimiter));
			date_begin.setDate(aux.substr(0, delimiter));

			aux.erase(0, delimiter + 1);
			is_valid2 = verifying_date(aux);
			date_end.setDate(aux);
			
	

			while ( !date_begin.isValid() || !date_end.isAfter(date_begin) || date_end.isEqualTo(date_begin) || !date_end.isAfter(today_date) || !date_begin.isAfter(today_date)) {//verifica a validade da data
				cout << "Invalid operation. Today is ";
				visualize_date(today_date);
				cout << ". Please insert a valid date. Insert 'Ctrl-Z' to cancel. ";
				getline(cin, aux);
				aux = cleaning_invalid_characters(aux);

				while (cin.fail() || aux == "") {
					if (cin.eof()) {
						system("cls");
						cin.clear();
						cout << "Operation was canceled! ";
						cout << endl << endl << endl << "1. Return to Main Menu. " << endl;
						cout << "2. Return to Information Menu. " << endl;
						cout << "3. Return to Available Packs Menu. " << endl;


						cout << endl << "Choose what you want to do (integer number): ";
						cin >> option;


						while (cin.fail() || option > 3 || option <= 0) {
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
						cout << "Invalid operation, please insert a valid one: ";
						getline(cin, aux);
						aux = cleaning_invalid_characters(aux);
					}
				}

				aux = resize_function(aux);
				delimiter = aux.find_first_of('-');

				is_valid1 = verifying_date(aux.substr(0, delimiter));
				date_begin.setDate(aux.substr(0, delimiter));
				

				aux.erase(0, delimiter + 1);
				is_valid2 = verifying_date(aux);
				date_end.setDate(aux);
			}


			none = true; 
			counter = 0;

			for (int i = 1; i < size(Packs); i++) {//se o pacote se encontrar dentro do intervalo de datas especificado pelo cliente é mostrado no ecra
				if (date_end.isAfter(Packs[i].getEndDate()) && date_begin.isBefore(Packs[i].getBeginDate())) {
					if (Packs[i].getPackNumber()>0){
						visualize_pack(Packs, i);
							none = false;
					}
				}

			}
			if (none) {//se nao houver nenhum printa esta mensagem
				cout << endl << "There isn't any available pack between those dates!" << endl;
			}

			break;

		case 4:
			cout << "-------- Search Available Packs by destination and between dates --------" << endl << endl;

			cout << endl << "Which destination do you want (name of the city)? Insert 'Ctrl-Z' to cancel. ";
			getline(cin, line);
			line = cleaning_invalid_characters(line);
			line = verifying_string(line);

			while (cin.fail() || line == "") {
				if (cin.eof()) {
					system("cls");
					cin.clear();
					cout << "Operation was canceled! ";
					cout << endl << endl << endl << "1. Return to Main Menu. " << endl;
					cout << "2. Return to Information Menu. " << endl;
					cout << "3. Return to Available Packs Menu. " << endl;


					cout << endl << "Choose what you want to do (integer number): ";
					cin >> option;


					while (cin.fail() || option > 3 || option <= 0) {
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
					getline(cin, line);
					line = cleaning_invalid_characters(line);
				}
			}

			line = resize_function(line);
			line = formatting_string(line);

			cout << "What are the dates between which you want to travel (YYYY/MM/DD - YYYY/MM/DD)? Insert 'Ctrl-Z' to cancel. ";
			getline(cin, aux);
			aux = cleaning_invalid_characters(aux);

			while (cin.fail() || aux == "") {
				if (cin.eof()) {
					system("cls");
					cin.clear();
					cout << "Operation was canceled! ";
					cout << endl << endl << endl << "1. Return to Main Menu. " << endl;
					cout << "2. Return to Information Menu. " << endl;
					cout << "3. Return to Available Packs Menu. " << endl;


					cout << endl << "Choose what you want to do (integer number): ";
					cin >> option;


					while (cin.fail() || option > 3 || option <= 0) {
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
					cout << "Invalid operation, please insert a valid one: ";
					getline(cin, aux);
					aux = cleaning_invalid_characters(aux);
				}
			}

			aux = resize_function(aux);
			delimiter = aux.find_first_of('-');

			is_valid1 = verifying_date(aux.substr(0, delimiter));
			date_begin.setDate(aux.substr(0, delimiter));

			aux.erase(0, delimiter + 1);
			is_valid2 = verifying_date(aux);
			date_end.setDate(aux);




			while (!is_valid1 || !is_valid2 || !date_begin.isValid() || !date_end.isAfter(date_begin) || date_end.isEqualTo(date_begin)) {
				cout << "Invalid operation, please insert a valid one. Insert 'Ctrl-Z' to cancel. ";
				getline(cin, aux);
				aux = cleaning_invalid_characters(aux);

				while (cin.fail() || aux == "") {
					if (cin.eof()) {
						system("cls");

						cin.clear();
						cout << "Operation was canceled! ";
						cout << endl << endl << endl << "1. Return to Main Menu. " << endl;
						cout << "2. Return to Information Menu. " << endl;
						cout << "3. Return to Available Packs Menu. " << endl;


						cout << endl << "Choose what you want to do (integer number): ";
						cin >> option;


						while (cin.fail() || option > 3 || option <= 0) {
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
						cout << "Invalid operation, please insert a valid one: ";
						getline(cin, aux);
						aux = cleaning_invalid_characters(aux);
					}
				}

				aux = resize_function(aux);
				delimiter = aux.find_first_of('-');

				is_valid1 = verifying_date(aux.substr(0, delimiter));
				date_begin.setDate(aux.substr(0, delimiter));

				aux.erase(0, delimiter + 1);
				is_valid2 = verifying_date(aux);
				date_end.setDate(aux);
			}

			system("cls");

			counter = 0;
			none = true;
			line = formatting_string(line);


			for (int i = 1; i < size(Packs); i++) { ////mostra os pacotes com o destino especificado pelo cliente e o intervalo de datas especificado pelo mesmo
				aux = resize_function(Packs[i].getDestination()[0]);
				aux = formatting_string(aux);
				if (line == aux && Packs[i].getPackNumber() > 0 && date_end.isAfter(Packs[i].getEndDate()) && date_begin.isBefore(Packs[i].getBeginDate())) {
					visualize_pack(Packs, i);
					none = false;
				}

			}
			if (none) {//se nao houver nenhum printa esta mensagem
				cout << endl << "There isn't any available pack for that destination and between those dates!" << endl;
			}

			break;

		case 5:
			return 2;
			break;

		case 6:
			return 1;
			break;
		}
	}


	cout << endl << endl << endl << "1. Return to Main Menu. " << endl;
	cout << "2. Return to Information Menu. " << endl;
	cout << "3. Return to Available Packs Menu. " << endl;


	cout << endl << "Choose what you want to do (integer number): ";
	cin >> option;


	while (cin.fail() || option > 3 || option <= 0) {
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

int show_sold_packs(vector <Pack> Packs, vector <Client> Clients) { //ver pacotes vendidos a um client especifico ou todos os pacotes vendidos

	int option;
	system("cls");

	cout << "-------- View Sold Packs --------" << endl << endl;
	cout << "1. View All Sold Packs." << endl;
	cout << "2. View Sold Packs to a specific client." << endl;
	cout << "3. Return to Information Menu." << endl;
	cout << "4. Return to Main Menu." << endl;

	cout << endl << "Choose an option please (integer number): ";
	cin >> option;


	while (cin.fail() || option > 4 || option <= 0) {
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
	vector<int> clients_identifiers; // vetor que vai conter os numeros de identificaçao dos packs comprados por qualquer cliente
	vector<int> packs_identifiers;//vetor que vai conter os numeros de identificaçao de todos os packs existentes

	if (option == 1) {
		cout << "------------------------ View Sold Packs ------------------------" << endl << endl;
		for (int i = 0; i < size(Clients); i++) {
			for (int j = 0; j < size(Clients[i].getBoughtPacks()); j++) {
				int l = Clients[i].getBoughtPacks()[j];
				if (find(clients_identifiers.begin(), clients_identifiers.end(), l) == clients_identifiers.end()) {
					clients_identifiers.push_back(Clients[i].getBoughtPacks()[j]);
				}
			}
		}
		for (int w = 1; w < Packs.size(); w++) // poe no vetor todos os numeros de identificadores dos packs existentes 
		{
			if (Packs[w].getPackNumber() > 0)
				packs_identifiers.push_back(Packs[w].getPackNumber());
			else if (Packs[w].getPackNumber() < 0)
				packs_identifiers.push_back(-1 * (Packs[w].getPackNumber()));
		}

		for (int k = 0; k < packs_identifiers.size(); k++)//interseta o vetor dos packs comprados pelos clientes com o vetor de todo os packs e printa os que estao nos dois
		{
			
			for (int i = 0; i < clients_identifiers.size(); i++) {
				if (clients_identifiers[i] == packs_identifiers[k]) {
					visualize_pack(Packs, packs_identifiers[k]);
				}

			}
		}
	}
	   
	else if (option == 2) {
		cout << "------------------------ View Sold Packs ------------------------" << endl << endl;
		cout << "What do you know about the client? " << endl;
		cout << "1. Name." << endl;
		cout << "2. NIF." << endl;
		

		cout << endl << "Choose an option please (integer number). Insert 'Ctrl-Z' to cancel. ";
		cin >> option;

		if (cin.fail()) {
			if (cin.eof()) {
				system("cls");

				cin.clear();
				cout << "Operation was canceled! ";
				cout << endl << endl << endl << "1. Return to Main Menu. " << endl;
				cout << "2. Return to Information Menu. " << endl;
				cout << "3. Return to Sold Packs Menu. " << endl;


				cout << endl << "Choose what you want to do (integer number): ";
				cin >> option;


				while (cin.fail() || option > 3 || option <= 0) {
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

		while (cin.fail() || option > 2 || option <= 0) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid operation, please insert a valid one. Insert 'Ctrl-Z' to cancel. ";
			cin >> option;

			if (cin.fail()) {
				if (cin.eof()) {
					system("cls");

					cin.clear();
					cout << "Operation was canceled! ";
					cout << endl << endl << endl << "1. Return to Main Menu. " << endl;
					cout << "2. Return to Information Menu. " << endl;
					cout << "3. Return to Sold Packs Menu. " << endl;


					cout << endl << "Choose what you want to do (integer number): ";
					cin >> option;


					while (cin.fail() || option > 3 || option <= 0) {
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

		if (option == 1) {
			for (int i = 0; i < size(Clients); i++) {
				cout << i+1 << ". " << Clients[i].getClientName() << endl;
			}
		}
		else if (option == 2) {
			for (int i = 0; i < size(Clients); i++) {
				cout << i+1 << ". " << Clients[i].getClientNIF() << endl;
			}
		}

		cout << endl << "Choose the client you want (integer number). Insert 'Ctrl-Z' to cancel. ";
		cin >> option;

		if (cin.fail()) {
			if (cin.eof()) {
				system("cls");

				cin.clear();
				cout << "Operation was canceled! ";
				cout << endl << endl << endl << "1. Return to Main Menu. " << endl;
				cout << "2. Return to Information Menu. " << endl;
				cout << "3. Return to Sold Packs Menu. " << endl;


				cout << endl << "Choose what you want to do (integer number): ";
				cin >> option;


				while (cin.fail() || option > 3 || option <= 0) {
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

		while (cin.fail() || option > size(Clients) || option <= 0) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid operation, please insert a valid one. Insert 'Ctrl-Z' to cancel. ";
			cin >> option;
			if (cin.fail()) {
				if (cin.eof()) {
					system("cls");

					cin.clear();
					cout << "Operation was canceled! ";
					cout << endl << endl << endl << "1. Return to Main Menu. " << endl;
					cout << "2. Return to Information Menu. " << endl;
					cout << "3. Return to Sold Packs Menu. " << endl;


					cout << endl << "Choose what you want to do (integer number): ";
					cin >> option;


					while (cin.fail() || option > 3 || option <= 0) {
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

		cout << "------------------------ View Sold Packs ------------------------" << endl << endl;
		vector<int> was_printed;
		bool something_was_printed=false;
		for (int i = 0; i < size(Clients[option-1].getBoughtPacks()); i++) {
			for (int j = 1; j < size(Packs); j++) {
				if ((Clients[option - 1].getBoughtPacks()[i]) == Packs[j].getPackNumber())
				{
					if (find(was_printed.begin(), was_printed.end(), (Clients[option - 1].getBoughtPacks()[i])) == was_printed.end()) {
						visualize_pack(Packs, Clients[option - 1].getBoughtPacks()[i]);
						was_printed.push_back(Clients[option - 1].getBoughtPacks()[i]);
						something_was_printed = true;
					}
				}
			}
			
		}
		if (something_was_printed == false) {
			cout << "There aren't any packs sold to this client in our database!";
		}
	}


	else if (option == 3) {
		return 2;
	}

	else if (option == 4){
		return 1;
	}
	cout << endl << endl << endl << "1. Return to Main Menu. " << endl;
	cout << "2. Return to Information Menu. " << endl;
	cout << "3. Return to Sold Packs Menu. " << endl;


	cout << endl << "Choose what you want to do (integer number): ";
	cin >> option;


	while (cin.fail() || option > 3 || option <= 0) {
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


int show_total_revenue(vector <Pack> Packs, vector <Client> Clients) {// calcula o total de ganhos bem como o numero de pacotes vendidos

		int counter = 1;
		int result = 0, sold_pack = 0;
		system("cls");

		cout << "-------- View Total Revenue --------" << endl << endl;


		for (int i = 1; i < size(Packs); i++) {//mostra no ecra o numero de lugares vendidos seguido do pack correspondente
			cout << Packs[i].getSoldSpots() << " were sold from pack number " << sqrt(pow(Packs[i].getPackNumber(), 2)) << endl;
			result += Packs[i].getSoldSpots() * Packs[i].getPricePerPerson();//soma o preço do pacote* o numero de lugares vendidos desse pacote 
			sold_pack += Packs[i].getSoldSpots();//soma o numero de lugares vendidos desse pacote
		}

		cout << endl << "The total of sold packs is: " << sold_pack << endl;
		cout << "Which is equivalent to a total revenue of " << result << " euros." << endl << endl;

		cout << endl << endl << endl << "1. Return to Main Menu. " << endl;
		cout << "2. Return to Information Menu. " << endl;

		int option;
		cout << endl << "Choose what do you want to do (integer number): ";
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



map <string,int> most_visited(vector <Pack> Packs) {// ordena alfabeticamente os destinos dos pacotes e mapeia-os com o seus lugares vendidos

  map <string, int> dest_frequency;
 
  for (int i = 1; i < size(Packs); i++) {
	  if (size(Packs.at(i).getDestination()) == 1) {
		  dest_frequency[Packs.at(i).getDestination().at(0)] += Packs[i].getSoldSpots();
	  }
	  else {
		  for (int j = 1; j < size(Packs.at(i).getDestination()); j++) {
			  dest_frequency[Packs.at(i).getDestination().at(j)] += Packs[i].getSoldSpots();
	  }
	  
	  }
  }

	 return dest_frequency;
}

multimap<int, string> reversed(map<string, int> const &mapped) { // inverte a ordem do map, sendo as keys os lugares vendidos e os values os destinos
	multimap<int, string> aux;
	for (auto const &pair : mapped) {
		aux.insert(make_pair(pair.second, pair.first));
	}
	return aux;
}

int show_most_visited_destinations(vector <Pack> Packs, vector <Client> Clients) {
	int option;
	vector<string> all_destinations;
	map<int, string> aux;

	system("cls");

	cout << "-------- View N most visited Destinations --------" << endl << endl;
	cout << "1. View All N most visited." << endl;
	cout << "2. View N most visited referring to a certain client." << endl;

	cout << endl << "Choose an option please (integer number). Insert 'Ctrl-Z' to cancel. ";
	cin >> option;

	if (cin.fail()) {
		if (cin.eof()) {
			system("cls");
			cin.clear();
			cout << "Operation was canceled. ";
			cout << endl << endl << endl << "1. Return to Main Menu. " << endl;
			cout << "2. Return to Information Menu. " << endl;
			cout << "3. Return to most visited Destinations Menu. " << endl;


			cout << endl << "Choose what you want to do (integer number): ";
			cin >> option;


			while (cin.fail() || option > 3 || option <= 0) {
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

	while (cin.fail() || option > 2 || option <= 0) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid operation, please insert a valid one. Insert 'Ctrl-Z' to cancel. ";
		cin >> option;

		if (cin.fail()) {
			if (cin.eof()) {
				system("cls");
				cin.clear();
				cout << "Operation was canceled. " << endl;
				cout << endl << endl << endl << "1. Return to Main Menu. " << endl;
				cout << "2. Return to Information Menu. " << endl;
				cout << "3. Return to most visited Destinations Menu. " << endl;


				cout << endl << "Choose what you want to do (integer number): ";
				cin >> option;


				while (cin.fail() || option > 3 || option <= 0) {
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
	system("cls");

	int n;
	



	most_visited(Packs);
	map<string, int> freqDest = most_visited(Packs); 
	multimap<int, string> final = reversed(freqDest);//map com keys sendo os lugares vendidos e values sendo os destinos correspondentes

	system("cls");

	
	if (option == 1) {

		cout << endl << "How many destinations do you wish to see (integer number)? Insert 'Ctrl-Z'  to cancel. ";
		cin >> n;
		if (cin.fail()) {
			if (cin.eof()) {
				system("cls");
				cin.clear();
				cout << "Operation was canceled. " << endl;
				cout << endl << endl << endl << "1. Return to Main Menu. " << endl;
				cout << "2. Return to Information Menu. " << endl;
				cout << "3. Return to most visited Destinations Menu. " << endl;


				cout << endl << "Choose what you want to do (integer number): ";
				cin >> option;


				while (cin.fail() || option > 3 || option <= 0) {
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

		while (cin.fail() || n <= 0) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid operation, please insert a valid one. Insert 'Ctrl-Z' to cancel. ";
			cin >> n;
			if (cin.fail()) {
				if (cin.eof()) {
					system("cls");
					cin.clear();
					cout << "Operation was canceled. " << endl;
					cout << endl << endl << endl << "1. Return to Main Menu. " << endl;
					cout << "2. Return to Information Menu. " << endl;
					cout << "3. Return to most visited Destinations Menu. " << endl;


					cout << endl << "Choose what you want to do (integer number): ";
					cin >> option;


					while (cin.fail() || option > 3 || option <= 0) {
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

		system("cls");

		cout << endl << endl << "The " << n << " most visited places are: " << endl << endl; 
		
		for (multimap<int, string>::reverse_iterator i = final.rbegin(); i != final.rend(); ++i) {//mostra no ecra os n lugares mais visitados ordenados por ordem decrescente de lugares vendidos 
			
			while (n) {
				cout  <<  i->second << " ----------- Number of visits: " << i->first << endl;
				n--;
				break;
			}
		}

		}

	else {
		vector<int> pacotes;

		cout << endl << "How many destinations do you want to compare with clients' bought packs (integer number)? Insert 'Ctrl-Z'  to cancel. ";
		cin >> n;

		if (cin.fail()) {
			if (cin.eof()) {
				system("cls");
				cin.clear();
				cout << "Operation was canceled. " << endl;
				cout << endl << endl << endl << "1. Return to Main Menu. " << endl;
				cout << "2. Return to Information Menu. " << endl;
				cout << "3. Return to most visited Destinations Menu. " << endl;


				cout << endl << "Choose what you want to do (integer number): ";
				cin >> option;


				while (cin.fail() || option > 3 || option <= 0) {
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

		while (cin.fail() || n <= 0) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid operation, please insert a valid one. Insert 'Ctrl-Z' to cancel. ";
			cin >> n;
			if (cin.fail()) {
				if (cin.eof()) {
					system("cls");
					cin.clear();
					cout << "Operation was canceled. " << endl;
					cout << endl << endl << endl << "1. Return to Main Menu. " << endl;
					cout << "2. Return to Information Menu. " << endl;
					cout << "3. Return to most visited Destinations Menu. " << endl;


					cout << endl << "Choose what you want to do (integer number): ";
					cin >> option;


					while (cin.fail() || option > 3 || option <= 0) {
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

		int counter = n;

		system("cls");
		cout << endl << "Here are the suggestions for all clients: " << endl << endl;
		
		for (multimap<int, string>::reverse_iterator mi = final.rbegin(); mi != final.rend(); ++mi) {//guarda num vetor os numeros dos pacotes dos n destinos mais visitados

			for (int j = 1; j < size(Packs); j++) {
				vector<string> vetor = Packs[j].getDestination();
				if (find(vetor.begin(), vetor.end(), mi->second) != vetor.end() && find(pacotes.begin(), pacotes.end(), j) == pacotes.end()) {
					pacotes.push_back(j);
				}
			}
		counter--;
		
		if (counter == 0) {
			break;
			}
		}
			
		
	


		bool fInd;
		for (int i = 0; i < size(Clients); i++) {//compara o vetor dos pacotes comprados por cada cliente com o vetor dos n destino mais visitados e printa o nome do cliente com um dos destinos mais visitados que ele nao visitou
			fInd = false;
			cout << "Client Name: " << Clients[i].getClientName() << " ---------------";
			for (int j = 0; j < size(pacotes); j++) {
				vector<int> v2 = Clients[i].getBoughtPacks();
				if (find(v2.begin(), v2.end(), pacotes[j]) == v2.end()) {

					cout << " Pack: " << pacotes[j] << "; Destination: " << Packs[pacotes[j]].getDestination()[0];

					if (size(Packs[pacotes[j]].getDestination()) > 1) {
						cout << " - ";
						for (int k = 1; k < size(Packs[pacotes[j]].getDestination()); k++) {
							if (k == size(Packs[pacotes[j]].getDestination()) - 1) {
								cout << Packs[pacotes[j]].getDestination()[k] << endl;
							}
							else {
								cout << Packs[pacotes[j]].getDestination()[k] << ", ";
							}
						}
					}
					else {
						cout << endl;
					}

					fInd = true;
					break;
				}
				
			
			}

			if (!fInd) {
				cout << " Sorry, there isn't any suggestion for this client. " << endl;
			}


		}
		cout << endl << endl << "You should know head to buy pack :)" << endl << endl;

	}
	
	cout << endl << endl << endl << "1. Return to Main Menu. " << endl;
	cout << "2. Return to Information Menu. " << endl;
	cout << "3. Return to most visited Destinations Menu. " << endl;


	cout << endl << "Choose what you want to do (integer number): ";
	cin >> option;


	while (cin.fail() || option > 3 || option <= 0) {
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





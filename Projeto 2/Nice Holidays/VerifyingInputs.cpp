#include "VerifyingInputs.h"

int verifying_int(string &aux) { // verificar se uma dada string pode ser passada para inteiro sem erros
	bool isvalid = true;
	int option;

	for (size_t i = 0; i < aux.size(); i++)
	{

		if (isdigit(aux[i])) {
			isvalid = true;
		}
		else {
			isvalid = false;
			break;
		}
	}

	while (!isvalid) {//caso do input introduzido nao ser de facto um inteiro, é pedido de novo o input
		
		cout << "Invalid operation, please insert a valid one: ";
		getline(cin, aux); 
		aux = cleaning_invalid_characters(aux);

		while (aux == "" || cin.fail()) {
			if (cin.eof()) {
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
				cout << "Invcalid operation. Please insert a valid one: ";
				getline(cin, aux);
				aux = cleaning_invalid_characters(aux);
			}
		}


		isvalid = true;

		for (size_t i = 0; i < aux.size(); i++)
		{

			if (isdigit(aux[i]) || aux[i] == ' ') {
				isvalid = true;
			}

			else {
				isvalid = false;
				break;
			}
		}
	}
	string number = aux;
	int counter = 0;

	for (int i = 0; i < size(aux); i++) {
		if (aux[i] == ' ') {
			number.erase(i - counter);
			counter++;
		}
	}


	return stoi(aux);
}

bool verifying_INT(string aux) {
	bool isvalid = true;
	int option;

	for (size_t i = 0; i < aux.size(); i++)
	{

		if (isdigit(aux[i])) {
			isvalid = true;
		}
		else {
			return false;
		}
	}

	return true;
}


string verifying_string(string &aux) { //verifica se há carateres invalidos numa string, ou seja , so sao aceites letras ou espaços
	bool isvalid = true;
	int option;


	for (size_t i = 0; i < aux.size(); i++)
	{
		if (isalpha(aux[i]) || aux[i] == ' ') {
			isvalid = true;
		}
		else {
			isvalid = false;
			break;
		}

	}
	while (!isvalid) {//caso do input introduzido nao ser apenas letras e espaços, é pedido de novo o input 
		cout << "Invalid operation, please insert a valid one: ";
		getline(cin, aux);
		aux = cleaning_invalid_characters(aux);

		while (aux == "" || cin.fail()) {
			if (cin.eof()) {
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
				return to_string(option);
			}

			else {
				cout << "Invcalid operation. Please insert a valid one: ";
				getline(cin, aux);
				aux = cleaning_invalid_characters(aux);
			}
		}

		isvalid = true;

		for (size_t i = 0; i < aux.size(); i++)
		{
			if (isalpha(aux[i]) || aux[i] == ' ') {
				isvalid = true;
			}
			else {
				isvalid = false;
				break;
			}
		}
	}

	return aux;
}

int verifying_NIF(string &aux) { //verificar se o NIF está correto (se tem 9 digitos)
	bool isvalid = true;
	int option;

	for (size_t i = 0; i < aux.size(); i++)
	{

		if (isdigit(aux[i]) || aux[i] == ' ') {
			isvalid = true;
		}
		else {
			isvalid = false;
			break;
		}
	}

	while (!isvalid || aux.size() != 9) {
		cout << "Invalid operation, please insert a valid one: ";
		getline(cin, aux);
		aux = cleaning_invalid_characters(aux);

		while (aux == "" || cin.fail()) {
			if (cin.eof()) {
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
				cout << "Invcalid operation. Please insert a valid one: ";
				getline(cin, aux);
				aux = cleaning_invalid_characters(aux);
			}
		}



		isvalid = true;



		for (size_t i = 0; i < aux.size(); i++)
		{

			if (isdigit(aux[i]) || aux[i] == ' ') {
				isvalid = true;
			}
			else if (aux.size() != 9) {
				isvalid = false;
				break;
			}
			else {
				isvalid = false;
				break;
			}
		}
	}
	return stoi(aux);
}

string verifying_ZIPcode(string &aux) //verificar se o código de postal respeita a forma indicada XXXX-XXX
{
	string line;
	bool isvalid = true;
	line = aux + '-';
	int option;

	int contador = 0;

	for (size_t i = 0; i < line.size(); i++)
	{

		if (line[i] == '-' && i != line.size() - 1 && contador != 4) {
			isvalid = false;
			break;
		}
		else if (line[i] == '-' && i == line.size() - 1 && contador != 3) {
			isvalid = false;
			break;
		}
		else if (line[i] == '-' && i != line.size() - 1 && contador == 4) {
			contador = -1;
		}
		else if (line[i] == '-' && i == line.size() - 1 && contador == 3) {
			contador = -1;
		}
		contador++;

	}

	while (!isvalid) {// caso nao seja da forma pedida, é pedido de novo o input
		cout << "Invalid operation, please insert a valid one: ";
		getline(cin, aux);
		aux = cleaning_invalid_characters(aux);

		while (aux == "" || cin.fail()) {
			if (cin.eof()) {
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
				return to_string(option);
			}

			else {
				cout << "Invcalid operation. Please insert a valid one: ";
				getline(cin, aux);
				aux = cleaning_invalid_characters(aux);
			}
		}

		isvalid = true;
		contador = 0;
		line = aux + '-';

		for (size_t i = 0; i < line.size(); i++)
		{

			if (line[i] == '-' && i != line.size() - 1 && contador != 4) {
				isvalid = false;
				break;
			}
			else if (line[i] == '-' && i == line.size() - 1 && contador != 3) {
				isvalid = false;
				break;
			}
			else if (line[i] == '-' && i != line.size() - 1 && contador == 4) {
				contador = -1;
			}
			else if (line[i] == '-' && i == line.size() - 1 && contador == 3) {
				contador = -1;
			}
			contador++;

		}
	}
	return aux;
}

bool verifying_Destination(string aux) { // verifica se a string de destination esta de acordo com a formataçao	que é MAINDESTINATION-PLACES TO VISIT(separated by commas)
	aux = cleaning_invalid_characters(aux);
	bool isvalid = true;
	aux = resize_function(aux);

	for (int i = 0; i < size(aux); i++) {
		if (aux[i] != ' ' && aux[i] != '-' && !isalpha(aux[i]) && aux[i] != ',') {
			isvalid = false;
			break;
		}
	}

	return isvalid;
}

string verifying_ApartmentDoor(string &aux) {//verifica se o andar é valido isto é nao mistura letras com numeros
	bool is_valid = true, got_a_letter=false;
	if (aux == "-") {
		is_valid = true;
	}
	else {
		for (int i = 0; i < aux.size(); i++) {
			if (got_a_letter == false) {
				if (isalpha(aux[i])) {
					got_a_letter = true;
				}
			}
			else if (got_a_letter == true) {
				if (isdigit(aux[i])) {
					is_valid = false;
				}
			}
		}
	}
	while (!is_valid)
	{
		cout << "Invalid operation, please insert a valid one: ";
		aux = "";
		do { 
			getline(cin, aux);
			aux = cleaning_invalid_characters(aux);
		} while (aux.length() == 0);
		is_valid = true;
		got_a_letter = false;
		if (aux == "-") {
			is_valid = true;
		}
		else {
			for (int i = 0; i < aux.size(); i++) {
				if (got_a_letter == false) {
					if (isalpha(aux[i])) {
						got_a_letter = true;
					}
				}
				else if (got_a_letter == true) {
					if (isdigit(aux[i])) {
						is_valid = false;
					}
				}
			}
		}
	}
	return resize_function(aux);
}


bool verifying_bought_packs(string aux) {
	bool valid = true;
	string line;
	int delimiter;

	if (!isdigit(aux[size(aux) - 1])) {
		return false;
	}

	string auxiliar = aux;
	int counter = 0;

	for (int i = 0; i < size(aux); i++) {
		if (aux[i] == ' ') {
			auxiliar.erase(i - counter);
			counter++;
		}
	}

	aux = auxiliar;
	for (int i = 0; i < size(aux) - 1; i++) {
		if (!isdigit(aux[i]) && aux[i] != ' ') {
			if (!isdigit(aux[i + 1])) {
				if (aux[i + 1] != ' ') {
					return false;
				}
			}
		}
	}


	aux += ';';

	delimiter = aux.find_first_of(';');




	while (aux != "") {
		line = aux.substr(0, delimiter);
		for (int i = 0; i < size(line); i++) {
			if (!isdigit(line[i])) {
				return false;
			}
		}
		aux.erase(0, delimiter + 1);
		delimiter = aux.find_first_of(';');
	}

	return true;
}

bool verifying_date(string aux) {


	bool valid = true;
	string line;
	int delimiter;


	if (!isdigit(aux[size(aux) - 1])) {
		return false;
	}

	int counter = 0;
	for (int i = 0; i < size(aux); i++) {
		if (aux[i] == '/') {
			counter++;
		}

	}

	if (counter != 2) {
		return false;
	}




	string auxiliar = aux;
	counter = 0;

	for (int i = 0; i < size(aux); i++) {
		if (aux[i] == ' ') {
			auxiliar.erase(i - counter);
			counter++;
		}
	}

	aux = auxiliar;
	for (int i = 0; i < size(aux) - 1; i++) {
		if (!isdigit(aux[i]) && aux[i] != ' ') {
			if (!isdigit(aux[i + 1])) {
				if (aux[i + 1] != ' ') {
					return false;
				}
			}
		}
	}

	aux += '/';

	delimiter = aux.find_first_of('/');

	while (aux != "") {
		line = aux.substr(0, delimiter);
		for (int i = 0; i < size(line); i++) {
			if (!isdigit(line[i])) {
				return false;
			}
		}
		aux.erase(0, delimiter + 1);
		delimiter = aux.find_first_of('/');
	}

	return true;

}
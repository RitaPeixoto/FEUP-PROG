#include "FormattingFunctions.h"

string resize_function(string &str) { //retirar ' ' do inicio e do fim da string
	if (str[0] == ' ' && str[size(str) - 1] == ' ') {//caso de ter espa�o no inicio e no fim
		str = str.substr(1, size(str) - 2);
	}
	else if (str[0] == ' ') {//caso de apenas ter espa�o no inicio
		str = str.substr(1, size(str) - 1);
	}
	else if (str[size(str) - 1] == ' ') {//caso de apenas ter espa�o no fim
		str = str.substr(0, size(str) - 1);
	}
	return str;
}

string cleaning_invalid_characters(string line) { // retirar acentos e cedilhas, susbtituindo pelos caracteres validos correspondentes
	string aux;

	for (int i = 0; i < size(line); i++) {
		if (line[i] == '�' || line[i] == '�' || line[i] == '�' || line[i] == '�') {
			aux += 'a';
		}
		else if (line[i] == '�' || line[i] == '�' || line[i] == '�' || line[i] == '�') {
			aux += 'A';
		}
		else if (line[i] == '�' || line[i] == '�') {
			aux += 'e';
		}
		else if (line[i] == '�' || line[i] == '�') {
			aux += 'E';
		}
		else if (line[i] == '�') {
			aux += 'i';
		}
		else if (line[i] == '�') {
			aux += 'I';
		}
		else if (line[i] == '�' || line[i] == '�' || line[i] == '�') {
			aux += 'o';
		}
		else if (line[i] == '�' || line[i] == '�' || line[i] == '�') {
			aux += 'O';
		}
		else if (line[i] == '�') {
			aux += 'u';
		}
		else if (line[i] == '�') {
			aux += 'U';
		}
		else if (line[i] == '�') {
			aux += 'c';
		}
		else if (line[i] == '�') {
			aux += 'C';
		}
		else if (line[i]=='\x1a') {
			aux = '0';
		}
		else {
			aux += line[i];
		}
	}

	return aux;
}

vector <int> get_packs_client(string line) { //separa os pacotes comprados pelo cliente e adiciona-os a um vector
	vector <int> boughtPacks;
	string aux;
	int number_of_packs = 0, delimiter;

	line += ';';
	delimiter = line.find_first_of(';');//o separador de cada pack number � a virgula

	while (line != "") {
		aux = line.substr(0, delimiter);//coloca em aux o primeiro pack number
		boughtPacks.push_back(stoi(aux));//guarda esse pack number no vetor dos pack numbers
		number_of_packs++;
		aux.clear();
		line.erase(0, delimiter + 1);//apaga esse pack number da string inicial
		delimiter = line.find_first_of(';');
	}
	return boughtPacks;
}

string formatting_string(string &str) { //formatar a string para que todas as letras sejam minusculas menos a primeira letra de cada palavra

	str = cleaning_invalid_characters(str);
	transform(str.begin(), str.end(), str.begin(), ::tolower);//toda a string � colocada em minusculas
	resize_function(str);
	str = " " + str;

	for (int i = 0; i < size(str); i++) {
		if (str[i] == ' ' && isalpha(str[i + 1])) {
			str[i + 1] = toupper(str[i + 1]);// coloca a primeira letra de cada palavra a maiuscula
		}
	}

	return resize_function(str);
}








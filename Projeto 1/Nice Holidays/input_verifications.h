#pragma once
#include <iostream>
#include<vector>
#include<string>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include<algorithm>
#include<iomanip>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <sstream>
using namespace std;
//contem todas as funçoes auxiliares de verificaçao de inputs
// pode ser feita a da morada, nome e destino de forma a que tenha numeros ex. Rua 25 de Abril


string resize_function(string &str) { // retirar os espaços brancos desnecessarios
	if (str[0] == ' ' && str[size(str) - 1] == ' ') {
		str = str.substr(1, size(str) - 2);
	}
	else if (str[0] == ' ') {
		str = str.substr(1, size(str) - 1);
	}
	else if (str[size(str) - 1] == ' ') {
		str = str.substr(0, size(str) - 1);
	}
	return str;
}
string remove_accented_characters(string word) { //remove os acentos das palavras, falta maiusculas
	string aux;
	for (int i = 0; i < word.size(); i++) {
		if (word[i] == 'à' || word[i] == 'á' || word[i] == 'ã' || word[i] == 'â') {
			aux += 'a';
		}
		else if (word[i] == 'é' || word[i] == 'ê') {
			aux += 'e';
		}
		else if (word[i] == 'ó' || word[i] == 'ô') {
			aux += 'ô';
		}
		else if (word[i] == 'í') {
			aux += 'i';
		}
		else if (word[i] == 'ú') {
			aux += 'u';
		}
		else if (word[i] == 'ç') {
			aux += 'c';
		}
		else {
			aux += word[i];
		}
	}
	return aux;
}
string string_input_verification(string &aux) {//verifica o input do tipo string
	bool is_valid = true;
	string help = aux;
	help.erase(remove_if(help.begin(), help.end(), isspace), help.end());
	for (size_t i = 0; i < help.size(); i++)
	{
		if (!isalpha(help[i]))
			is_valid = false;  // character is not a letter
	}

	while (!is_valid) {
		aux = "";
		cout << "Error -- Invalid input! Please try again: ";
		getline(cin, aux);
		is_valid = true;
		string help_2 = aux;
		help_2.erase(remove_if(help_2.begin(), help_2.end(), isspace), help_2.end());

		for (size_t i = 0; i < help_2.size(); i++)
		{
			if (!isalpha(help_2[i]))
				is_valid = false;  // character is not a letter
		}
	}
	return resize_function(aux);
}
string NIF_input_verification(string &nif) {//verifica o input do NIF
	bool is_valid = true;

	if (stoi(nif) < 0 || nif.length() != 9) {
		is_valid = false; // it's a negative number or it doesnt follow the NIF rules
	}
	else {
		for (size_t i = 0; i < nif.size(); i++) {
			if (!isdigit(nif[i])) {
				is_valid = false;// its not a digit
			}
		}
	}
	while (!is_valid)
	{
		cout << "Error -- Invalid input! Please try again: ";
		nif = "";
		getline(cin, nif);
		is_valid = true;
			if (stoi(nif) < 0 || nif.length() != 9) {
				is_valid = false; // it's a negative number or it doesnt follow the NIF rules
			}
			else {
				for (size_t i = 0; i < nif.size(); i++) {
					if (!isdigit(nif[i])) {
						is_valid = false;// its not a digit
					}
				}
			}
		
	}
	return resize_function(nif);
}
string int_input_verification(string &integer) {//verifica o input do tipo int
	bool is_valid = true;

	for (size_t i = 0; i < integer.size(); i++) {
		if (!isdigit(integer[i])) {
			is_valid = false;// its not a digit
		}
	}
	if (is_valid) {
		if (stoi(integer) < 0) {
			is_valid = false; // it's a negative number or it doesnt follow the NIF rules
		}
	}

	while (!is_valid)
	{
		cout << "Error -- Invalid input! Please try again: ";
		integer = "";
		getline(cin, integer);
		is_valid = true;
		for (size_t i = 0; i < integer.size(); i++) {
			if (!isdigit(integer[i])) {
				is_valid = false;// its not a digit
			}
		}
	}
	return resize_function(integer);

}
string floor_input_verification(string &aux) {//verifica o input do andar
	bool is_valid = true;
	if ((isdigit(aux[0]) && !all_of(aux.begin() + 2, aux.end(), isalpha)) || (!isdigit(aux[0])&& all_of(aux.begin() + 2, aux.end(), isalpha))) {
		is_valid = false;
	}
	while (!is_valid)
	{
		cout << "Error -- Invalid input! Please try again: ";
		aux = "";
		getline(cin, aux);
		is_valid = true;
		if ((isdigit(aux[0]) && !all_of(aux.begin() + 2, aux.end(), isalpha)) || (!isdigit(aux[0]) && all_of(aux.begin() + 2, aux.end(), isalpha))) {
			is_valid = false;
		}
	}
	return resize_function(aux);
}
string postal_code_input_verification(string &aux) {//verifica o input do código-postal
	bool is_valid = true;
	if ((!all_of(aux.begin(), aux.end() - 4, isdigit)) || (!all_of(aux.begin() + 5, aux.end(), isdigit)) || aux[4] != '-' || aux.size() != 8) {
		is_valid = false;
	}
	while (!is_valid) //verificaçao do input
	{
		cout << "Error -- Invalid input! Please try again: ";
		aux = "";
		getline(cin, aux);
		is_valid = true;
		if ((!all_of(aux.begin(), aux.end() - 4, isdigit)) || (!all_of(aux.begin() + 5, aux.end(), isdigit)) || aux[4] != '-' || aux.size() != 8) {
			is_valid = false;
		}
	}
	return resize_function(aux);
}
string destination_input_verification(string &aux) {//verifica o input do destino(nao esta a funcionar direito)
	bool is_valid = true;
	string help = aux;
	help.erase(remove_if(help.begin(), help.end(), isspace), help.end());
	for (size_t i = 0; i < help.size(); i++)
	{
		if (!isalpha(help[i]) && help[i] != '-' && help[i] != ',') {
			is_valid = false;  // character is not a letter
		}
			
	}
	while (!is_valid) {
		aux = "";
		cout << "Error -- Invalid input! Please try again: ";
		getline(cin, aux);
		is_valid = true;
		string help_2 = aux;
		help_2.erase(remove_if(help_2.begin(), help_2.end(), isspace), help_2.end());

		for (size_t i = 0; i < help_2.size()-1; i++)
		{
			if (!isalpha(help_2[i]) || help[i] != '-'||help[i]!=',')
				is_valid = false;  // character is not a letter
		}
	}
	return resize_function(aux);
}

string packs_input_verification(string aux) {
	bool is_valid = true;
	aux = resize_function(aux);
	for (size_t i = 0; i < aux.size(); i++) {
		if (!isdigit(aux[i])&& aux[i]!=';') {
			is_valid = false;// its not a digit
		}
	}
	if (is_valid) {
		if (stoi(aux) < 0) {
			is_valid = false; // it's a negative number or it doesnt follow the NIF rules
		}
	}
	
	while (!is_valid)
	{
		cout << "Error -- Invalid input! Please try again: ";
		aux = "";
		getline(cin, aux);
		is_valid = true;
		for (size_t i = 0; i < aux.size(); i++) {
			if (!isdigit(aux[i])&& aux[i]!=';') {
				is_valid = false;// its not a digit
			}
		}
	}
	return resize_function(aux);
}

bool valid_dates_gap(Date begin_date, Date end_date) { //verifies if they are a valid gap of dates, which means the end_date is after the begin_date

	int begin, end;
	ostringstream aux_begin, aux_end;

	aux_begin << to_string(begin_date.year) << setw(2) << setfill('0') << to_string(begin_date.month) << setw(2) << setfill('0') << to_string(begin_date.day);
	aux_end << to_string(end_date.year) << setw(2) << setfill('0') << to_string(end_date.month) << setw(2) << setfill('0') << to_string(end_date.day);

	begin = stoi(aux_begin.str());
	end = stoi(aux_end.str());


	if (begin < end) {
		return true;
	}
	return false;
}

bool leap_year(int year) {   //checks if it is a leap year or not
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		return true;
	}
	return false;
}

int day(int year, int month) {  // calculates the number of day that correspond to a certain day of a certain year(especification beacause of february)
	int days = 3;
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		days = 30;
	}
	else if (month == 2) {
		if (leap_year(year)) {
			days = 29;
		}
		else {
			days = 28;
		}
	}
	return days;
}

bool date_input_verification(Date &date) {   // verificar se a data está na forma correta e se é valida

	if (date.month > 12 || date.month <= 0) {
		return false;
	}
	else if (date.day <= 0 || date.day > day(date.year, date.month)) {
		return false;
	}
	else if (date.year <= 0) {
		return false;
	}
	return true;
}

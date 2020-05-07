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
#include"structs.h"
#include"input_verifications.h"
using namespace std;
//contem todas as funçoes de formataçao de informaçao 

Adress formatting_adress(Adress &Adress, string line) { // formata a morada recebida na forma que deve ser guardada
	int counter = 0;
	string aux;
	int delimiter;
	line += '/';
	delimiter = line.find_first_of('/');

	while (line != "") {
		aux = line.substr(0, delimiter);
		switch (counter) {
		case 0:
			Adress.street = resize_function(aux);
			break;

		case 1:
			aux = resize_function(aux);
			Adress.door_number = stoi(aux);
			break;

		case 2:
			Adress.floor = resize_function(aux);
			break;

		case 3:
			Adress.postal_code = resize_function(aux);
			break;

		case 4:
			Adress.district = resize_function(aux);
			break;
		}
		counter++;
		aux.clear();
		line.erase(0, delimiter + 1);
		delimiter = line.find_first_of('/');
	}


	return Adress;
}

vector <int> GetAdquiredTravelPacks(string line) { // retira o numero de cada pack na linha e poe num vetor
	vector <int> result;
	string auxstring;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == ';') {
			result.push_back(stoi(auxstring));
			auxstring = "";
		}
		else
			auxstring += line[i];
	}
	result.push_back(stoi(auxstring));
	return result;
}

Date GetDate(Date &Date, string line) { // poe a data no formato da struct data 
	int counter = 0;
	string aux_string;

	for (int i = 0; i < line.length(); i++)
	{
		if (line[i] == '/') {
			switch (counter) {
			case 0:
				Date.year = stoi(aux_string);
				break;
			case 1:
				Date.month = stoi(aux_string);
				break;
			}
			aux_string = "";
			counter++;
		}
		else {
			aux_string += line[i];
		}
	}
	Date.day = stoi(aux_string);
	return Date;
}

bool is_before(int year_1, int month_1, int day_1, int year_2, int month_2, int day_2) {
	if (year_1 < year_2)
		return true;

	else if (year_1 == year_2 && month_1 < month_2)
		return true;

	else if (year_1 == year_2 && month_1 == month_2 && day_1 < day_2)
		return true;

	else
		return false;
}

bool is_after(int year_1, int month_1, int day_1, int year_2, int month_2, int day_2) {
	if (year_1 > year_2)
		return true;

	else if (year_1 == year_2 && month_1 > month_2)
		return true;

	else if (year_1 == year_2 && month_1 == month_2 && day_1 > day_2)
		return true;

	else
		return false;
}




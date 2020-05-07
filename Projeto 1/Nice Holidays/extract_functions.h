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
#include"formating_get_auxiliar_functions.h"
using namespace std;
//contem as funçoes de extraçoes de ficheiros

Agency agency_extract(ifstream& in_a) { //extracting the agency information from the file
	string line;
	Agency agency;
	for (int i = 0; i < 6; i++) {
		getline(in_a, line);
		line = remove_accented_characters(line);
		switch (i) {
		case 0:
			agency.name = line;
			break;
		case 1:
			agency.nif = stoi(line);
			break;
		case 2:
			agency.url = line;
			break;
		case 3:
			formatting_adress(agency.morada, line);
			break;
		case 4:
			agency.clients_file = line;
			break;
		case 5:
			agency.packs_file = line;
			break;
		}
	}
	return agency;
}


vector <Client> clients_extract(ifstream& in_c) { // extracting clients information from the file
	vector <Client> client_list;
	Client client;

	int no_lines = 0;
	string line;

	while (getline(in_c, line)) {
		line = remove_accented_characters(line);
		if (line == "::::::::::") {// significa que acabou o cliente anterior
			no_lines = 0;
			client_list.push_back(client); // cria um novo cliente 
		}
		else {
			switch (no_lines) {
			case 0:
				client.name = line;
				no_lines++;
				break;
			case 1:
				client.nif = stoi(line);
				no_lines++;
				break;
			case 2:
				client.nOfPeopleInTheFamily = stoi(line);
				no_lines++;
				break;
			case 3:
				formatting_adress(client.morada, line);
				no_lines++;
				break;
			case 4:
				client.AdquiredTravelPacks = GetAdquiredTravelPacks(line);
				no_lines++;
				break;
			}

		}
	}

	client_list.push_back(client);
	return client_list;
}


vector <Packs> packs_extract(ifstream& in_p) { // extrai a informaçao do ficheiro dos pacotes
	vector <Packs> pack_list;
	Packs pack;

	int no_lines = 0;
	string line;

	getline(in_p, line);
	pack.last_sold_pack = stoi(line);
	while (getline(in_p, line)) {
		line = remove_accented_characters(line);
		if (line == "::::::::::") { // significa que acabou o pacote anterior
			no_lines = 0;
			pack_list.push_back(pack); // cria um novo pacote 
		}
		else {
			switch (no_lines) {
			case 0:
				pack.pack_number = stoi(line);
				no_lines++;
				break;
			case 1:
				pack.destination = line;
				no_lines++;
				break;
			case 2:
				GetDate(pack.begin_date, line);
				no_lines++;
				break;
			case 3:
				GetDate(pack.end_date, line);
				no_lines++;
				break;
			case 4:
				pack.price_for_person = stoi(line);
				no_lines++;
				break;
			case 5:
				pack.available_spots = stoi(line);
				no_lines++;
				break;
			case 6:
				pack.sold_spots = stoi(line);
				no_lines++;
				break;
			}
		}
	}
	pack_list.push_back(pack);
	return pack_list;
}
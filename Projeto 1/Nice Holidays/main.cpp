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
#include"extract_functions.h"
#include"formating_get_auxiliar_functions.h"
#include"clients_functions.h"
#include"Menu_functions.h"
#include"packs_functions.h"
#include"Revenue.h"
#include"input_verifications.h"
using namespace std;
//o programa esta feito para nao serem postos acentos pelo utilizador
//falta verificaçao do n de pacotes comprados pelo cliente
//se tiver tempo por as modificaçoes como menus


int main() {
	Agency agency;
	Client client;
	Packs packs;
	int menu;
	vector<Client> client_list;
	vector<Packs> packs_list;
	string initial_file;

	ifstream agency_file;
	ifstream clients_file;
	ifstream packs_file;
	cout << "Welcome!" << endl << endl;
	cout << "What is the name of the initial file: " << endl;
	getline(cin, initial_file);

	agency_file.open(initial_file); // abrir o ficheiro inicial

	if (agency_file.fail()) { // se der erro ao abrir o ficheiro e lancada uma mensagem de erro
		cerr << "Error opening " << initi  al_file << endl;
		return 1; // exit(1) quer dizer que houve um erro 
	}
	agency = agency_extract(agency_file); // sao obtidas as informaçoes da agencia
	agency_file.close();
	clients_file.open(agency.clients_file); //abre o ficheiro de clientes
	if (clients_file.fail()) { // se der erro ao abrir o ficheiro e lancada uma mensagem de erro
		cerr << "Error opening " << agency.clients_file << endl;
		return 1; // exit(1) quer dizer que houve um erro 
	}
	client_list = clients_extract(clients_file);
	clients_file.close();
	packs_file.open(agency.packs_file);		//abrir ficheiro pedido

	if (packs_file.fail())
	{
		cerr << "Error opening " << agency.packs_file << "\n";
		return 1; // exit(1)
	}
	packs_list = packs_extract(packs_file);
	packs_file.close();
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Implementacao dos menus na main

	do {
		menu = showMenu();
		if (menu == 1) {
			cin.ignore(1000, '\n'); // para limpar o buffer e nao trazer problemas futuros
			int choice;
			choice = ShowMenuClients();
			if (choice == 1) {
				create_Client(agency.clients_file, client_list);
			}
			else if (choice == 2) {
				modify_Client(agency.clients_file);
			}
			else if (choice == 3) {
				remove_client(agency.clients_file);
			}
			else if (choice == 4) {
				continue;
			}
			else if (choice == 0) {
				system("CLS");
				cout << endl;
				cout << "Thank you, goodbye!" << endl;
				return 0;
			}

		}
		else if (menu == 2) {
			cin.ignore(1000, '\n');
			int choice;
			choice = ShowMenuPacks();
			if (choice == 1) {
				create_Pack(agency.packs_file, packs_list);
			}
			else if (choice == 2) {
				modify_Pack(agency.packs_file);
			}
			else if (choice == 3) {
				remove_Pack(agency.packs_file);
			}
			else if (choice == 4) {
				continue;
			}
			else if (choice == 0) {
				system("CLS");
				cout << endl;
				cout << "Thank you, goodbye!" << endl;
				return 0;
			}
		}
		else if (menu == 3) {
			cin.ignore(1000, '\n');
			int choice;
			choice = ShowMenuViewData();
			if (choice == 1) {
				show_client_Information(agency.clients_file);
			}
			else if (choice == 2) {
				system("CLS");
				show_all_clients_information(agency.clients_file);
				system("pause");
			}
			else if (choice == 3) {
				show_available_packages(agency.packs_file);
			}
			else if (choice == 4) {
				show_sold_packages(agency.clients_file, agency.packs_file);
			}
			else if (choice == 5) {
				show_total_revenue(agency.packs_file);
			}
			else if (choice == 6) {
				continue;
			}
			else if (choice == 0) {
				cout << endl;
				cout << "Thank you, goodbye!" << endl;
				return 0;
			}

		}
		else if (menu == 4) {
			cin.ignore(1000, '\n');
			buy_Package(agency.clients_file, agency.packs_file);

		}
	} while (menu != 0);
	system("CLS");
	cout << endl;
	cout <<endl<< "Thank you, goodbye!" << endl;
	return 0;
}
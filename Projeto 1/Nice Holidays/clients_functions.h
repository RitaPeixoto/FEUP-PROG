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
#include"extract_functions.h"
#include"formating_get_auxiliar_functions.h"
using namespace std;

void update_ClientsFile(string &client_file, const vector<Client> &clients_list) //Reescreve o ficheiro, atualizando com as novas alteraçoes
{
	ofstream clients;
	vector <int> aux;

	clients.open("provisorioC.txt");

	for (int i = 0; i < clients_list.size(); i++)
	{
		clients << clients_list[i].name << "\n"
			<< clients_list[i].nif << "\n"
			<< clients_list[i].nOfPeopleInTheFamily << "\n"
			<< clients_list[i].morada.street << " / " << clients_list[i].morada.door_number << " / " << clients_list[i].morada.floor << " / " << clients_list[i].morada.postal_code << " / " << clients_list[i].morada.district << "\n";
		aux = clients_list[i].AdquiredTravelPacks;
		for (int i = 0; i < aux.size(); i++) {
			if (i != aux.size() - 1) {
				clients << aux[i] << " ; ";
			}
			else {
				clients << aux[i];
			}

		}
		if (i != clients_list.size() - 1)
			clients << "\n" << "::::::::::" << "\n";
	}
	clients.close();

	remove(client_file.c_str());
	rename("provisorioC.txt", client_file.c_str());
}

void create_Client(string client_file, vector<Client> client_list) { // adicionar um novo cliente ao ficheiro
	Client client;
	Adress morada;
	string new_name, new_nif, new_family_num, new_adress_street, new_adress_door, new_adress_floor, new_adress_post_code, new_adress_district, new_packs;

	system("CLS");
	cout << "Let's proceed entering new client information" << endl<<endl;
	cin.ignore('1000', '\n');//porque o menu é feito com cin

	cout << "Insert the new client's name (without invalid characters, i.e accented characters): ";
	getline(cin, new_name);
	client.name = string_input_verification(new_name);


	cout << "Insert the new client's NIF: ";
	getline(cin, new_nif);
	client.nif = stoi(NIF_input_verification(new_nif));


	cout << "Insert the number of people in the new client's family: ";
	getline(cin, new_family_num);
	client.nOfPeopleInTheFamily = stoi(int_input_verification(new_family_num));

	cout << "Insert the new client's street (without invalid characters, i.e accented characters): ";
	getline(cin, new_adress_street);
	client.morada.street = string_input_verification(new_adress_street);

	cout << "Insert the new client's door number: ";
	getline(cin, new_adress_door);
	client.morada.door_number = stoi(int_input_verification(new_adress_door));

	cout << "Insert the new client's floor (optional, Number followed by Esq/Dir/Frt without blankspaces, '-' by default): ";
	getline(cin, new_adress_floor);
	if (new_adress_floor == "-")
		client.morada.floor = new_adress_floor;
	else
	{
		client.morada.floor = floor_input_verification(new_adress_floor);
	}

	cout << "Insert the new client's postal code(xxxx-xxx): ";
	getline(cin, new_adress_post_code);
	client.morada.postal_code = postal_code_input_verification(new_adress_post_code);

	cout << "Insert the new client's district(without invalid character, i.e accented characters): ";
	getline(cin, new_adress_district);
	client.morada.district = string_input_verification(new_adress_district);


	cout << "Insert the packages that new client already bought (separate pack numbers by ;): ";
	getline(cin, new_packs);
	new_packs = packs_input_verification(new_packs);
	client.AdquiredTravelPacks = GetAdquiredTravelPacks(new_packs);



	client_list.push_back(client);			//Meter no vetor dos clientes
	update_ClientsFile(client_file, client_list); //chama a funçao que faz o update do ficheiro dos clientes
	cout << "The Client has been successfully created!" << endl;
	system("pause");

}
void show_all_clients_information(string client_file) { //mostra a informaçao de todos os clientes
	ifstream clients;
	vector<Client> clients_list;


	clients.open(client_file);
	clients_list = clients_extract(clients);
	cout << endl;
	for (int i = 0; i < size(clients_list); i++) {
		cout << "Name: " << clients_list[i].name << endl;
		cout << "NIF: " << clients_list[i].nif << endl;
		cout << "Household: " << clients_list[i].nOfPeopleInTheFamily << endl;
		cout << "Adress: " << clients_list[i].morada.street << " / " << clients_list[i].morada.door_number << " / " << clients_list[i].morada.floor << " / " << clients_list[i].morada.postal_code << " / " << clients_list[i].morada.district << endl;
		cout << "Bought trips pack's numbers: ";
		for (int j = 0; j < clients_list[i].AdquiredTravelPacks.size(); j++) {
			if (j == (clients_list[i].AdquiredTravelPacks.size() - 1)) {
				cout << clients_list[i].AdquiredTravelPacks[j] << endl << endl;
				cout << "********************" << endl;
			}
			else {
				cout << clients_list[i].AdquiredTravelPacks[j] << " ; ";

			}

		}

	}

}

void remove_client(string client_file) {//remove um cliente
	ifstream clients;
	vector<Client> clients_list;
	vector<int> clients_nifs;
	string nif_client;
	bool is_valid = false;

	system("CLS");
	clients.open(client_file);
	clients_list = clients_extract(clients);

	for (int i = 0; i < clients_list.size(); i++) //extrai os nifs de todos os clientes existentes para um vetor
	{
		clients_nifs.push_back(clients_list[i].nif);
	}

	cout << "These are current clients in the database:" << endl << endl;
	show_all_clients_information(client_file);
	cin.ignore('1000', '\n');//porque a opçao do menu esta com cin

	cout << "Insert the NIF of the client you'd like to remove: "; //descobrir que cliente é para remover
	getline(cin, nif_client);
	nif_client = NIF_input_verification(nif_client);
	for (int i = 0; i < clients_nifs.size(); i++) {
		if (clients_nifs[i] == stoi(nif_client))
			is_valid = true;
	}
	while (!is_valid)
	{
		nif_client = "";
		cout << "Invalid input / Client does not exist in database\nTry again: ";
		getline(cin, nif_client);
		for (int i = 0; i < clients_nifs.size(); i++) {
			if (clients_nifs[i] == stoi(nif_client))
				is_valid = true;
		}
	}

	for (int i = 0; i < clients_list.size(); i++) //remoçao do cliente
	{
		if (clients_list[i].nif == stoi(nif_client))
			clients_list.erase(clients_list.begin() + i);
	}
	clients.close();
	update_ClientsFile(client_file, clients_list); //chama funçao que faz update do ficheiro dos clientes
	cout << "The Client has been successfully removed!" << endl;
	system("pause");
}


void modify_Client(string client_file) //Modificar Cliente(pode ser feito o update de modificar só um parametro)
{
	ifstream clients;
	vector<Client> clients_list;
	vector<int> clients_nifs;
	string nif_client;
	Adress morada;
	string new_name, new_nif, new_family_num, new_adress_street, new_adress_door, new_adress_floor, new_adress_post_code, new_adress_district, new_packages;
	string copy_name;
	int index = 0;

	system("CLS");
	clients.open(client_file);
	clients_list = clients_extract(clients);

	for (int i = 0; i < clients_list.size(); i++) // coloca o nif de todos os clientes existentes num vetor
	{
		clients_nifs.push_back(clients_list[i].nif);
	}
	cin.ignore(1000, '\n'); // porque a opçao do menu esta com cin

	cout << "These are current clients in the database:" << endl << endl;
	show_all_clients_information(client_file);

	cout << "What is the NIF of the client you want to modify: "; // descobre qual o cliente que vamos modificar
	getline(cin, nif_client);
	nif_client = NIF_input_verification(nif_client);
	cout << nif_client;

	while ((find(clients_nifs.begin(), clients_nifs.end(), stoi(nif_client)) == clients_nifs.end()))// verifica se o input é valido, se o cliente existe na "base de dados"
	{
		nif_client = "";
		cout << "Invalid input! That Client does not exist.Please, try again: ";
		getline(cin, nif_client);
		nif_client = stoi(NIF_input_verification(nif_client));
	}

	for (int i = 0; i < clients_list.size(); i++) // vai descobrir o indice do cliente que vai ser modificado no vetor do nif de todos os clientes e coloca esse indice na variavel index 
	{
		if (clients_list[i].nif == stoi(nif_client))
		{
			index = i;
			break;
		}
	}
	system("CLS");
	cout << "Let's proceed entering the new client information" << endl << endl;


	cout << "Insert the new client name (without invalid characters, i.e accented characters): ";
	getline(cin, new_name);
	clients_list[index].name = string_input_verification(new_name);


	cout << "Insert the new client's NIF: ";
	getline(cin, new_nif);
	clients_list[index].nif = stoi(NIF_input_verification(new_nif));

	cout << "Insert the number of people in the new client's family: ";
	getline(cin, new_family_num);
	clients_list[index].nOfPeopleInTheFamily = stoi(int_input_verification(new_family_num));

	cout << "Insert the new client's street (without invalid characters, i.e accented characters): ";
	getline(cin, new_adress_street);
	clients_list[index].morada.street = string_input_verification(new_adress_street);

	cout << "Insert the new client's door number: ";
	getline(cin, new_adress_door);
	clients_list[index].morada.door_number = stoi(int_input_verification(new_adress_door));

	cout << "Insert the new client's floor (optional,Number followed by Esq/Dir/Frt without blank spaces, '-' by default): ";
	getline(cin, new_adress_floor);
	if (new_adress_floor == "-")
		clients_list[index].morada.floor = new_adress_floor;
	else
	{
		clients_list[index].morada.floor = floor_input_verification(new_adress_floor);
	}

	cout << "Insert the new client's postal code(xxxx-xxx): ";
	getline(cin, new_adress_post_code);
	clients_list[index].morada.postal_code = postal_code_input_verification(new_adress_post_code);


	cout << "Insert the new client's district: ";
	getline(cin, new_adress_district);
	clients_list[index].morada.district = string_input_verification(new_adress_district);

	
	cout << "Packages already bought (separate pack numbers by ;): ";
	getline(cin, new_packages);
	new_packages = packs_input_verification(new_packages);
	clients_list[index].AdquiredTravelPacks = GetAdquiredTravelPacks(new_packages);

	clients.close();
	update_ClientsFile(client_file, clients_list);//chama a funçao que faz o update do ficheiro dos clientes
	cout << "The Client has been successfully modified!" << endl;
	system("pause");
}
void show_client_Information(string client_file) {//mostra a informaçao de um cliente indicado/escolhido pelo utilizador
	ifstream clients;
	vector<Client> clients_list;
	vector <int> clients_nifs;
	string nif;
	int index_c;
	bool is_valid = false;

	system("CLS");
	clients.open(client_file);
	clients_list = clients_extract(clients);
	cin.ignore(1000, '\n');

	for (int i = 0; i < clients_list.size(); i++) //obter todos os nifs dos clientes
	{
		clients_nifs.push_back(clients_list[i].nif);
	}
	cout << "These are the current clients in the data base:" << endl;
	for (int i = 0; i < size(clients_list); i++) {
		cout << "Name: " << clients_list[i].name << endl;
		cout << "NIF: " << clients_list[i].nif << endl<<endl;

		if (i == (clients_list.size() - 1)) {
			cout << endl<< "********************" << endl;
		}
	}
	cout << "What's the NIF of the client you wish to see: "; 
	getline(cin, nif);
	nif = NIF_input_verification(nif);
	for (int i = 0; i < clients_nifs.size(); i++) {
		if (clients_nifs[i] == stoi(nif))
			is_valid = true;
	}

	while (!is_valid)
	{
		nif = "";
		cout << "Invalid input! Client does not exist in database!" << endl << "Try again: ";
		getline(cin, nif);
		for (int i = 0; i < clients_nifs.size(); i++) {
			if (clients_nifs[i] == stoi(nif))
				is_valid = true;
		}
	}
	for (int i = 0; i < clients_list.size(); i++)
	{
		if (clients_list[i].nif == stoi(nif))
		{
			index_c = i;
			break;
		}
	}
	system("CLS"); //limpar o ecra
	cout << "Name: " << clients_list[index_c].name << endl;
	cout << "NIF: " << clients_list[index_c].nif << endl;
	cout << "Household: " << clients_list[index_c].nOfPeopleInTheFamily << endl;
	cout << "Adress: " << clients_list[index_c].morada.street << " / " << clients_list[index_c].morada.door_number << " / " << clients_list[index_c].morada.floor << " / " << clients_list[index_c].morada.postal_code << " / " << clients_list[index_c].morada.district << endl;
	cout << "Bought trips pack's numbers: ";
	for (int i = 0; i < clients_list[index_c].AdquiredTravelPacks.size(); i++) {
		if (i == (clients_list[index_c].AdquiredTravelPacks.size() - 1)) {
			cout << clients_list[index_c].AdquiredTravelPacks[i] << endl<<endl;
		}
		else {
			cout << clients_list[index_c].AdquiredTravelPacks[i] << " ; ";
		}
	}
	system("pause");
}
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
#include"clients_functions.h"
using namespace std;



void update_PacksFile(string &packs_file, const vector<Packs> &packages_list) //Reescreve o ficheiro
{
	ofstream packs;
	fstream file;

	packs.open("provisorioP.txt");

	packs << packages_list[packages_list.size() - 1].pack_number << "\n";

	for (int i = 0; i < packages_list.size(); i++)
	{
		packs << packages_list[i].pack_number << "\n"
			<< packages_list[i].destination << "\n"
			<< packages_list[i].begin_date.year << "/" << packages_list[i].begin_date.month << "/" << packages_list[i].begin_date.day << "\n"
			<< packages_list[i].end_date.year << "/" << packages_list[i].begin_date.month << "/" << packages_list[i].begin_date.day << "\n"
			<< packages_list[i].price_for_person << "\n"
			<< packages_list[i].available_spots << "\n"
			<< packages_list[i].sold_spots << "\n";
		if (i != packages_list.size() - 1)
			packs << "::::::::::" << "\n";
	}
	packs.close();

	file.open("file.txt");
	remove("file.txt");

}
void buy_Package(string client_file, string package_file)		//Comprar pacotes de viagem
{
	ifstream packs, clients;
	vector<Client> client_list;
	vector<int> clients_nifs;
	vector<int> packs_numbers;
	vector<Packs> packs_list;
	string identifier;
	string clients_choice;
	vector<int> client_identifiers;
	int index_p = 0, index_c = 0;
	string nif;
	bool exists = false, is_valid = false,pack_exists=false;

	system("CLS");

	packs.open(package_file);
	packs_list = packs_extract(packs);

	clients.open(client_file);
	client_list = clients_extract(clients);

	for (int j = 0; j < client_list.size(); j++)
	{
		clients_nifs.push_back(client_list[j].nif);
	}
	cout << "These are the current clients in the data base:" << endl;
	show_all_clients_information(client_file);
	cout << "Please insert the client's NIF: ";
	getline(cin, nif);
	nif = NIF_input_verification(nif);
	for (int i = 0; i < clients_nifs.size(); i++) {
		if (clients_nifs[i] == stoi(nif))
			is_valid = true;
	}

	while (!is_valid)//verifica se o nif é valido
	{
		nif = "";
		cout << "Invalid input! Client does not exist in database!" << endl << "Try again: ";
		getline(cin, nif);
		for (int i = 0; i < clients_nifs.size(); i++) {
			if (clients_nifs[i] == stoi(nif))
				is_valid = true;
		}
	}

	for (int i = 0; i < client_list.size(); i++)
	{
		if (client_list[i].nif == stoi(nif))
		{
			index_c = i; // dá-nos qual o indice do cliente no ficheiro de clientes
			break;
		}
	}
	system("CLS");

	cout << "These are the available packs: " <<endl << endl;

	for (int i = 0; i < packs_list.size(); i++)
	{
		if (packs_list[i].pack_number > 0)
		{
			cout << "Pack number: " << packs_list[i].pack_number << endl;
			cout << "Destination: " << packs_list[i].destination << endl;
			cout << "Beginnig date: " << packs_list[i].begin_date.year <<'/' << packs_list[i].begin_date.month << '/' << packs_list[i].begin_date.day << endl;
			cout << "Ending date: " << packs_list[i].end_date.year << '/' << packs_list[i].end_date.month << '/' << packs_list[i].end_date.day << endl;
			cout << "Price (for person): " << packs_list[i].price_for_person << endl;
			cout << "Available spots: " << packs_list[i].available_spots << endl;
			cout << "Sold spots: " << packs_list[i].sold_spots << endl;
			if (i != packs_list.size() - 1)
				cout << "*****************" << endl;
		}
	}


	for (int f = 0; f < packs_list.size(); f++)
	{
		packs_numbers.push_back(packs_list[f].pack_number);
	}

	cout <<endl<< "Choose one of the packs (by pack number): ";
	getline(cin, clients_choice);
	clients_choice = int_input_verification(clients_choice);


	for (int j = 0; j < packs_numbers.size(); j++) {//ver se a escolha do cliente existe 
		if (packs_numbers[j] == stoi(clients_choice)) {
			pack_exists = true;
		}
	}

	while (!pack_exists)//validaçao do input
	{
		clients_choice = "";
		cout << "Invalid input!Package does not exist in database" << endl << "Try again: ";
		getline(cin, clients_choice);
		clients_choice = int_input_verification(clients_choice);
	}

	for (int w = 0; w < packs_list.size(); w++)
	{
		if (packs_list[w].pack_number == stoi(clients_choice))
		{
			index_p = w;// da-nos qual o indice do  pack que vai ser comprado no ficheiro de packs
			break;
		}
	}

	for (int i = 0; i < size(client_list[index_c].AdquiredTravelPacks); i++) {
		if (client_list[index_c].AdquiredTravelPacks[i] == stoi(clients_choice)) {
			exists = true;
		}
	}
	if (!exists) {
		client_list[index_c].AdquiredTravelPacks.push_back(stoi(clients_choice));
	}
	client_list[index_c].AdquiredTravelPacks.push_back(stoi(clients_choice));
	packs_list[index_p].sold_spots = (packs_list[index_p].sold_spots + client_list[index_c].nOfPeopleInTheFamily);//incrementa os packs vendidos pelo agregado familiar
	/*if (packs_list[index_p].sold_spots < 0) {

	}*/ 
	// Falta verificar se a compra nao acabou com o numero de lugares disponiveis ou nao pode ser realizada
	update_ClientsFile(client_file, client_list);//faz o update do ficheiro dos clientes
	update_PacksFile(package_file, packs_list);//faz o udpate do ficheiro dos packs

	cout << "The pack was successfully bought!" << endl;
	system("pause");
}

void create_Pack(string pack_file, vector<Packs> packs_list)		//Criar um novo pacote
{
	Packs pack;
	string new_pack_number, new_destination, new_date_begin, new_date_end, new_price, new_available, new_sold;
	Date begin_new, end_new;
	system("CLS");
	cout << "Let's proceed adding the new pack information! " << endl << endl;
	cin.ignore(1000, '\n');//porque a opçao do menu esta com cin

	cout << "Pack_number: ";
	getline(cin, new_pack_number);
	pack.pack_number = stoi(int_input_verification(new_pack_number));

	cout << "Destination(City name-must see turistic places; atention: without any invalid characters, i.e accented characters): ";
	getline(cin, new_destination);
	new_destination=destination_input_verification(new_destination);
	pack.destination = new_destination;

	cout << "Beginning of trip (YYYY/MM/DD): ";
	getline(cin, new_date_begin);
	new_date_begin = resize_function(new_date_begin);
	begin_new=GetDate(pack.begin_date, new_date_begin);

	while (!date_input_verification(begin_new)) {//verifying the date
		cout << "Error -- Invalid input! Please try again: ";
		getline(cin, new_date_begin);
		new_date_begin = resize_function(new_date_begin);
		begin_new = GetDate(pack.begin_date, new_date_begin);
	}


	cout << "End of trip (YYYY/MM/DD): ";
	getline(cin, new_date_end);
	new_date_end = resize_function(new_date_end);
	end_new= GetDate(pack.end_date, new_date_end);

	while (!date_input_verification(end_new)) {
		cout << "Error -- Invalid input! Please try again: ";
		getline(cin, new_date_end);
		new_date_end = resize_function(new_date_end);
		end_new = GetDate(pack.begin_date, new_date_end);
	}
	while (!date_input_verification(end_new)) {
		cout << "Error -- Invalid input! Please try again: ";
		getline(cin, new_date_end);
		new_date_end = resize_function(new_date_end);
		end_new = GetDate(pack.begin_date, new_date_end);
	}

	while (!valid_dates_gap(begin_new, end_new)) {
		cout << "Error -- Invalid input! Please try again: "<<endl;
		cout << "Beginning of trip (YYYY/MM/DD): ";
		getline(cin, new_date_begin);
		new_date_begin = resize_function(new_date_begin);
		begin_new = GetDate(pack.begin_date, new_date_begin);

		while (!date_input_verification(begin_new)) {//verifying the date
			cout << "Error -- Invalid input! Please try again: "<<endl;
			getline(cin, new_date_begin);
			new_date_begin = resize_function(new_date_begin);
			begin_new = GetDate(pack.begin_date, new_date_begin);
		}

		cout << "End of trip (YYYY/MM/DD): ";
		getline(cin, new_date_end);
		new_date_end = resize_function(new_date_end);
		end_new = GetDate(pack.end_date, new_date_end);

		while (!date_input_verification(end_new)) {
			cout << "Error -- Invalid input! Please try again: " << endl;
			getline(cin, new_date_end);
			new_date_end = resize_function(new_date_end);
			end_new = GetDate(pack.begin_date, new_date_end);
		}
	}

	cout << "Price (for person): ";
	getline(cin, new_price);
	pack.price_for_person = stoi(int_input_verification(new_price));

	cout << "Available spots: ";
	getline(cin, new_available);
	pack.available_spots = stoi(int_input_verification(new_available));

	cout << "Sold spots: ";
	getline(cin, new_sold);
	while(new_sold > new_available) {
		cout<< "You can't have sold more spots than it was originally available!"<<endl;
		cout << "Please insert a valid answer:";
		new_sold = "";
		getline(cin, new_sold);
	}
	pack.sold_spots = stoi(int_input_verification(new_sold));
	if (pack.available_spots == pack.sold_spots) {
		pack.pack_number = ((pack.pack_number)*(-1));
	}

	packs_list.push_back(pack);			//Meter no vetor dos pacotes
	update_PacksFile(pack_file, packs_list);//fazer o update do ficheiro dos packs
	cout << "The package has been successfully created" << endl;
	system("pause");

}

void remove_Pack(string package_file) //Remover Pacote
{
	ifstream packs;
	vector<Packs> pack_list;
	string pack_number;
	int index = 0;

	system("CLS");
	packs.open(package_file);
	pack_list = packs_extract(packs);
	cin.ignore(1000, '\n');//porque a opçao do menu esta com cin
	cout << "These are the current packs: " << endl << endl;
	for (int i = 0; i < pack_list.size(); i++) {
		if (pack_list[i].pack_number > 0) {
			cout << "Pack number: " << pack_list[i].pack_number << endl;
			cout << "Destination: " << pack_list[i].destination << endl;
			cout << "Beggining of the trip: " << pack_list[i].begin_date.year << "/" << pack_list[i].begin_date.month << "/" << pack_list[i].begin_date.day << endl;
			cout << "End of the trip: " << pack_list[i].end_date.year << "/" << pack_list[i].end_date.month << "/" << pack_list[i].end_date.day << endl;
			cout << "Price (for person): " << pack_list[i].price_for_person << endl;
			cout << "Available spots: " << pack_list[i].available_spots << endl;
			cout << "Sold spots: " << pack_list[i].sold_spots << endl;
			if (i == (pack_list.size() - 1)) {
				cout << "********************" << endl;
			}
		}
	}

	system("pause");
	cout << endl << "Whats is the number of the pack you wish to remove? ";
	getline(cin, pack_number);


	for (int i = 0; i < pack_list.size(); i++)//ve o indice a que corresponde o pacote escolhido
	{
		if (pack_list[i].pack_number == stoi(pack_number)) {
			index = i;
			break;
		}
	}
	if (index == 0) {//validaçao do input
		cout << "That pack does not exist!" << endl;
	}
	else {//se existir apaga o pacote
		pack_list.erase(pack_list.begin() + index);
	}

	packs.close();
	update_PacksFile(package_file, pack_list);//faz o update do ficheiro de packs
	cout << "The pack has been successfully removed!" << endl;
	system("pause");
}

void modify_Pack(string package_file) //Modificar Pacote(se tiver tempo alterar para ser como menu)
{
	ifstream packs;
	Packs pack;
	vector<Packs> pack_list;
	string package_number;
	string new_pack_number, new_destination, new_date_begin, new_date_end, new_price, new_available, new_sold;
	int index = 0;
	Date begin_new, end_new;

	system("CLS");
	packs.open(package_file);
	pack_list = packs_extract(packs);
	cin.ignore(1000, '\n');//porque o menu esta com cin
	cout << "These are the current packs: " << endl << endl;
	for (int i = 0; i < pack_list.size(); i++) {
		if (pack_list[i].pack_number > 0) {
			cout << "Pack number: " << pack_list[i].pack_number << endl;
			cout << "Destination: " << pack_list[i].destination << endl;
			cout << "Beggining of the trip: " << pack_list[i].begin_date.year << "/" << pack_list[i].begin_date.month << "/" << pack_list[i].begin_date.day << endl;
			cout << "End of the trip: " << pack_list[i].end_date.year << "/" << pack_list[i].end_date.month << "/" << pack_list[i].end_date.day << endl;
			cout << "Price (for person): " << pack_list[i].price_for_person << endl;
			cout << "Available spots: " << pack_list[i].available_spots << endl;
			cout << "Sold spots: " << pack_list[i].sold_spots << endl;
			if (i == (pack_list.size() - 1)) {
				cout << "********************" << endl;
			}
		}
	}

	system("pause");
	cout << endl << "What is the number of the pack you wish to modify? ";
	getline(cin, package_number);


	for (int i = 0; i < pack_list.size(); i++)
	{
		if (pack_list[i].pack_number == stoi(package_number))
		{
			index = i;
			break;
		}
	}

	pack_list.erase(pack_list.begin() + index);

	cout << "Let's proceed adding the new pack information! " << endl;
	cout << "Pack number: ";
	getline(cin, new_pack_number);
	pack.pack_number = stoi(int_input_verification(new_pack_number));

	cout << "Destination(City name-must see turistic places): ";
	getline(cin, new_destination);
	new_destination=destination_input_verification(new_destination);
	pack.destination = new_destination;

	cout << "Beginning of trip (YYYY/MM/DD): ";
	getline(cin, new_date_begin);
	new_date_begin = resize_function(new_date_begin);
	begin_new = GetDate(pack.begin_date, new_date_begin);

	while (!date_input_verification(begin_new)) {//verifying the date
		cout << "Error -- Invalid input! Please try again: "<<endl;
		getline(cin, new_date_begin);
		new_date_begin = resize_function(new_date_begin);
		begin_new = GetDate(pack.begin_date, new_date_begin);
	}

	cout << "End of trip (YYYY/MM/DD): ";
	getline(cin, new_date_end);
	new_date_end = resize_function(new_date_end);
	end_new = GetDate(pack.end_date, new_date_end);

	while (!date_input_verification(end_new)) {
		cout << "Error -- Invalid input! Please try again: "<<endl;
		getline(cin, new_date_end);
		new_date_end = resize_function(new_date_end);
		end_new = GetDate(pack.begin_date, new_date_end);
	}

	while (!valid_dates_gap(begin_new, end_new)) {
		cout << "Error -- Invalid input! Please try again: "<<endl;
		cout << "Beginning of trip (YYYY/MM/DD): ";
		getline(cin, new_date_begin);
		new_date_begin = resize_function(new_date_begin);
		begin_new = GetDate(pack.begin_date, new_date_begin);

		while (!date_input_verification(begin_new)) {//verifying the date
			cout << "Error -- Invalid input! Please try again: "<<endl;
			getline(cin, new_date_begin);
			new_date_begin = resize_function(new_date_begin);
			begin_new = GetDate(pack.begin_date, new_date_begin);
		}

		cout << "End of trip (YYYY/MM/DD): ";
		getline(cin, new_date_end);
		new_date_end = resize_function(new_date_end);
		end_new = GetDate(pack.end_date, new_date_end);

		while (!date_input_verification(end_new)) {
			cout << "Error -- Invalid input! Please try again: "<<endl;
			getline(cin, new_date_end);
			new_date_end = resize_function(new_date_end);
			end_new = GetDate(pack.begin_date, new_date_end);
		}
	}

	cout << "Price (for person): ";
	getline(cin, new_price);
	pack.price_for_person = stoi(new_price);

	cout << "Available spots: ";
	getline(cin, new_available);
	pack.available_spots = stoi(int_input_verification(new_available));

	cout << "Sold spots: ";
	getline(cin, new_sold);
	while (new_sold > new_available) {
		cout << "You can't have sold more spots than it was originally available!" << endl;
		cout << "Please insert a valid answer:";
		new_sold = "";
		getline(cin, new_sold);
	}
	pack.sold_spots = stoi(int_input_verification(new_sold));

	if (pack.available_spots == pack.sold_spots) {
		pack.pack_number = ((pack.pack_number)*(-1));
	}

	pack_list.push_back(pack);
	packs.close();
	update_PacksFile(package_file, pack_list);
	cout << "The package has been successfully modified!" << endl;
	system("pause");
}



void show_available_packages(string packs_file) {
	ifstream packs;
	Packs pack;
	vector<Packs>pack_list;
	string pack_number;
	string new_pack_number, new_destination, new_begin_date, new_end_date, new_price, new_available_spots, new_sold_spots;
	int index = 0, choice;

	system("CLS");
	packs.open(packs_file);
	pack_list = packs_extract(packs);

	//Menu
	cout << "1: Show all packs" << endl;
	cout << "2: Search by destination" << endl;
	cout << "3: Search between two dates" << endl;
	cout << "4: Search by destination and between two dates" << endl;
	cout << endl;
	cout << "Choose an option from the menu(integer number): ";
	cin >> choice;

	//Menu option verification
	while (cin.fail() || choice > 4) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid input! Please insert a valid option from the menu: ";
		cin >> choice;
	}
	if (choice == 1) {
		system("CLS");
		cout << endl<<endl;
		for (int i = 0; i < pack_list.size(); i++) {
		if (pack_list[i].pack_number < 0) {
				cout << "Availability: " << "NOT AVAILABLE" << endl;
			}
		else {
			cout << "Availability: " << "AVAILABLE" << endl;
		}
				cout << "Pack number: " << pack_list[i].pack_number << endl;
				cout << "Destination: " << pack_list[i].destination << endl;
				cout << "Beggining of the trip: " << pack_list[i].begin_date.year << "/" << pack_list[i].begin_date.month << "/" << pack_list[i].begin_date.day << endl;
				cout << "End of the trip: " << pack_list[i].end_date.year << "/" << pack_list[i].end_date.month << "/" << pack_list[i].end_date.day << endl;
				cout << "Price (for person): " << pack_list[i].price_for_person << endl;
				cout << "Available spots: " << pack_list[i].available_spots << endl;
				cout << "Sold spots: " << pack_list[i].sold_spots << endl;
				cout <<endl<< "********************" << endl;
	
			cout << endl;
		}
		system("pause");
	}
	else if (choice == 2) {
		string destination, aux = "";
		vector<string> destination_list;
		bool exists = false;
		system("CLS");
		cout << "What is the destination you would like to see(city name)? ";
		cin.ignore(1000, '\n');
		getline(cin,destination);

		//vao guardar num vetor apenas o principal local turistico do destino
		for (int i = 0; i < pack_list.size(); i++)
		{
			aux = "";
			for (int j = 0; j < pack_list[i].destination.length(); j++)
			{
				if (pack_list[i].destination[j] == '-')
				{
					destination_list.push_back(resize_function(aux));
					break;
				}
				if (j+1 == size(pack_list[i].destination)) {//destinos com apenas uma palavra
					aux += pack_list[i].destination[j];
					destination_list.push_back(resize_function(aux));
					break;
				}
				aux += pack_list[i].destination[j];
			}
		}

		for (int i = 0; i < destination_list.size(); i++)//percorre a lista dos destinos
		{
			if ((pack_list[i].pack_number > 0) && (destination_list[i] == destination))//vê se o pacote ainda esta disponivel
			{
				exists = true;
				cout << endl<<"Pack number: " << pack_list[i].pack_number << endl;
				cout << "Destination: " << pack_list[i].destination << endl;
				cout << "Beggining of the trip: " << pack_list[i].begin_date.year << "/" << pack_list[i].begin_date.month << "/" << pack_list[i].begin_date.day << endl;
				cout << "End of the trip: " << pack_list[i].end_date.year << "/" << pack_list[i].end_date.month << "/" << pack_list[i].end_date.day << endl;
				cout << "Price (for person): " << pack_list[i].price_for_person << endl;
				cout << "Available spots: " << pack_list[i].available_spots << endl;
				cout << "Sold spots: " << pack_list[i].sold_spots <<endl<< endl;
				if (i > 1)
					cout <<endl<< "********************" << endl;
				
			}
		}
		if (!exists) {
			cout << "There isn't a pack to that destination!" << endl;
		}

		system("pause");
	}
	else if (choice == 3) {
		Date begin_date, end_date;
		string date;
		bool exists = false;

		cin.ignore(1000, '\n');
		system("CLS");
		cout << "Beginning of trip (YYYY/MM/DD): ";
		getline(cin, date);
		GetDate(begin_date,date);

		cout << "Ending of trip(YYYY/MM/DD): ";
		getline(cin, date);
		GetDate(end_date, date);


		while (!date_input_verification(begin_date) || !date_input_verification(end_date) || !valid_dates_gap(begin_date, end_date)) {
			cout << "Error -- Invalid input! Please try again: "<<endl;
			cout << "Beginning of trip (YYYY/MM/DD): ";
			getline(cin, date);
			GetDate(begin_date, date);

			cout << "Ending of trip(YYYY/MM/DD): ";
			getline(cin, date);
			GetDate(end_date, date);
		}
		for (int i = 0; i < size(pack_list); i++) {
			if (is_before(begin_date.year, begin_date.month, begin_date.day, pack_list[i].begin_date.year, pack_list[i].begin_date.month, pack_list[i].begin_date.day) && is_after(end_date.year, end_date.month, end_date.day, pack_list[i].end_date.year, pack_list[i].end_date.month, pack_list[i].end_date.day) && pack_list[i].pack_number > 0) {
				exists = true;
				cout << endl << "Pack number: " << pack_list[i].pack_number << endl;
				cout << "Destination: " << pack_list[i].destination << endl;
				cout << "Beggining of the trip: " << pack_list[i].begin_date.year << "/" << pack_list[i].begin_date.month << "/" << pack_list[i].begin_date.day << endl;
				cout << "End of the trip: " << pack_list[i].end_date.year << "/" << pack_list[i].end_date.month << "/" << pack_list[i].end_date.day << endl;
				cout << "Price (for person): " << pack_list[i].price_for_person << endl;
				cout << "Available spots: " << pack_list[i].available_spots << endl;
				cout << "Sold spots: " << pack_list[i].sold_spots << endl << endl;
				if (i > 1)
					cout << endl << "********************" << endl;

			}
		}


		if (!exists) {
			cout << "There isn't a pack between those dates!" << endl;
		}
		system("pause");
		


	}
	else if (choice == 4) {
		string destiny, available_destiny = "";
		vector<string> destiny_list;
		Date begin_date, end_date;
		string date,aux,destination;
		bool exists = false;
		vector<string> destination_list;

		cin.ignore(1000, '\n');
		system("CLS");
		cout << "Beginning of trip (YYYY/MM/DD): ";
		getline(cin, date);
		GetDate(begin_date, date);

		cout << "Ending of trip(YYYY/MM/DD): ";
		getline(cin, date);
		GetDate(end_date, date);

		while (!date_input_verification(begin_date) || !date_input_verification(end_date) || !valid_dates_gap(begin_date, end_date)) {
			cout << "Error -- Invalid input! Please try again: " << endl;
			cout << "Beginning of trip (YYYY/MM/DD): ";
			getline(cin, date);
			GetDate(begin_date, date);

			cout << "Ending of trip(YYYY/MM/DD): ";
			getline(cin, date);
			GetDate(end_date, date);
		}

		cout << "What is the destination you would like to see(city name)? ";
		getline(cin, destination);

		for (int i = 0; i < size(pack_list); i++) {
			if (is_before(begin_date.year, begin_date.month, begin_date.day, pack_list[i].begin_date.year, pack_list[i].begin_date.month, pack_list[i].begin_date.day) && is_after(end_date.year, end_date.month, end_date.day, pack_list[i].end_date.year, pack_list[i].end_date.month, pack_list[i].end_date.day) && pack_list[i].pack_number > 0) {
				exists = true;
			}
		}

		//vao guardar num vetor apenas o principal local turistico do destino
		for (int i = 0; i < pack_list.size(); i++)
		{
			aux = "";
			for (int j = 0; j < pack_list[i].destination.length(); j++)
			{
				if (pack_list[i].destination[j] == '-')
				{
					destination_list.push_back(resize_function(aux));
					break;
				}
				if (j + 1 == size(pack_list[i].destination)) {//destinos com apenas uma palavra
					aux += pack_list[i].destination[j];
					destination_list.push_back(resize_function(aux));
					break;
				}
				aux += pack_list[i].destination[j];
			}
		}
		if (exists) {
			for (int i = 0; i < destination_list.size(); i++)//percorre a lista dos destinos
			{
				if ((pack_list[i].pack_number > 0) && (destination_list[i] == destination))//vê se o pacote ainda esta disponivel
				{
					exists = true;
					cout << endl << "Pack number: " << pack_list[i].pack_number << endl;
					cout << "Destination: " << pack_list[i].destination << endl;
					cout << "Beggining of the trip: " << pack_list[i].begin_date.year << "/" << pack_list[i].begin_date.month << "/" << pack_list[i].begin_date.day << endl;
					cout << "End of the trip: " << pack_list[i].end_date.year << "/" << pack_list[i].end_date.month << "/" << pack_list[i].end_date.day << endl;
					cout << "Price (for person): " << pack_list[i].price_for_person << endl;
					cout << "Available spots: " << pack_list[i].available_spots << endl;
					cout << "Sold spots: " << pack_list[i].sold_spots << endl << endl;
					if (i > 1)
						cout << endl << "********************" << endl;
					break;
				}
				else {
					exists = false;
				}
			}
		}
		if (!exists) {
			cout << endl<<"There isn't a pack between those dates and to that destination!" << endl;
		}

		system("pause");


	}
}
void show_sold_packages(string client_file, string pack_file) {//Gerar e visualizar de modo formatado os pacotes turísticos vendidos (a um cliente específico, a todos os clientes).

	ifstream packs, clients;
	Packs pack;
	Client client;
	vector<Client> client_list;
	vector<Packs> pack_list;
	int option;

	system("CLS");
	packs.open(pack_file);
	pack_list = packs_extract(packs);

	clients.open(client_file);
	client_list = clients_extract(clients);

	cout << "*******Menu*******" << endl;
	cout << "1:Show all sold packages" << endl;
	cout << "2:Show by client" << endl;
	cout << "Choose an option (number): ";
	cin >> option;

	if (option == 1)		//Mostra todos os pacotes vendidos 
	{
		vector<int> clients_identifiers; // vetor que vai conter os numeros de identificaçao dos packs comprados por qualquer cliente
		vector<int> packs_identifiers;//vetor que vai conter os numeros de identificaçao de todos os packs existentes
		system("CLS");
		for (int x = 0; x < client_list.size(); x++)
		{
			for (int j = 0; j < client_list[x].AdquiredTravelPacks.size(); j++) {
				int l = client_list[x].AdquiredTravelPacks[j];
				if (find(clients_identifiers.begin(), clients_identifiers.end(), l) == clients_identifiers.end()) {
					clients_identifiers.push_back(client_list[x].AdquiredTravelPacks[j]);//se o pack ainda nao estiver na lista dos packs vendidos é acrescentado
				}
			}
		}


		for (int w = 0; w < pack_list.size(); w++) // poe no vetor todos os numeros de identificadores dos packs existentes 
		{
			if (pack_list[w].pack_number > 0)
				packs_identifiers.push_back(pack_list[w].pack_number);
			else if (pack_list[w].pack_number < 0)
				packs_identifiers.push_back(-1 * (pack_list[w].pack_number));
		}

		for (int i = 0; i < clients_identifiers.size(); i++)//interseta o vetor dos packs comprados pelos clientes com o vetor de todo os packs e printa os que estao nos dois
		{
			for (int k = 0; k < packs_identifiers.size(); k++)
			{
				if (clients_identifiers[i] == packs_identifiers[k])
				{
					cout << "Pack number: " <<sqrt(pow( pack_list[k].pack_number,2)) << endl;
					cout << "Destination: " << pack_list[k].destination << endl;
					cout << "Beggining of the trip: " << pack_list[k].begin_date.year << "/" << pack_list[k].begin_date.month << "/" << pack_list[k].begin_date.day << endl;
					cout << "End of the trip: " << pack_list[k].end_date.year << "/" << pack_list[k].end_date.month << "/" << pack_list[k].end_date.day << endl;
					cout << "Price (for person): " << pack_list[k].price_for_person << endl;
					cout << "Available spots: " << pack_list[k].available_spots << endl;
					cout << "Sold spots: " << pack_list[k].sold_spots << endl;
					if (i != clients_identifiers.size() - 1) {
						cout << "*********************" << endl;
					}
				}
			}

		}
		system("pause");


	}
	else if (option == 2)
	{
		vector<int> clients_nifs;
		string nif;
		int index = 0;

		cin.ignore(1000, '\n');//porque no menu esta um cin
		for (int x = 0; x < client_list.size(); x++)
		{
			clients_nifs.push_back(client_list[x].nif);
		}
		cout << endl << "These are the current clients: " << endl << endl;
		show_all_clients_information(client_file);
		system("pause");

		system("CLS");
		cout << "Whats is the NIF of the client: ";
		getline(cin, nif);
		nif = NIF_input_verification(nif);

		while (find(clients_nifs.begin(), clients_nifs.end(), stoi(nif)) == clients_nifs.end())
		{
			nif = "";
			cout << "Invalid input / Client does not exist in database\nTry again: ";
			getline(cin, nif);
			nif = NIF_input_verification(nif);
		}

		system("CLS");

		for (int w = 0; w < client_list.size(); w++)
		{
			if (client_list[w].nif == stoi(nif))
			{
				index = w; //guarda o index do cliente no vetor dos nifs
				break;
			}
		}

		for (int n = 0; n < client_list[index].AdquiredTravelPacks.size(); n++)
		{
			for (int x = 0; x < pack_list.size(); x++)
			{
				int y;

				if (pack_list[x].pack_number > 0)
					y = pack_list[x].pack_number;
				else if (pack_list[x].pack_number < 0)
					y = -1 * (pack_list[x].pack_number);


				if (client_list[index].AdquiredTravelPacks[n] == y)
				{
					cout << "Pack number: " << pack_list[x].pack_number << endl;
					cout << "Destination: " << pack_list[x].destination << endl;
					cout << "Beggining of the trip: " << pack_list[x].begin_date.year << "/" << pack_list[x].begin_date.month << "/" << pack_list[x].begin_date.day << endl;
					cout << "End of the trip: " << pack_list[x].end_date.year << "/" << pack_list[x].end_date.month << "/" << pack_list[x].end_date.day << endl;
					cout << "Price (for person): " << pack_list[x].price_for_person << endl;
					cout << "Available spots: " << pack_list[x].available_spots << endl;
					cout << "Sold spots: " << pack_list[x].sold_spots << endl;
					if (n != client_list[index].AdquiredTravelPacks.size() - 1)
						cout << "*********************" << endl;
				}
			}
		}
		cout << endl;
		system("pause");
	}

}
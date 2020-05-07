#pragma once
#include "BuyPack.h"

using namespace std;

//Comprar pacote para a familia do cliente, atualiza ficheiros dos pacotes e dos clientes
//Avisa quando não há lugares suficientes para a família do cliente 


int buy_pack(vector<Client> &Clients, vector <Pack> &Packs, string packs_file, string clients_file) {

	int pack_number, option, counter = 0;
	string aux;
	vector<int> available_packs;
	system("cls");

	cout << "-------- View All Available Packs --------" << endl << endl;
	for (int i = 1; i < size(Packs); i++) {//mostra todos os packs existentes na forma formatada pretendida
		if (Packs[i].getPackNumber() > 0) {
			visualize_pack(Packs, i);
			available_packs.push_back(i);
			counter++;
		}
	}

	cout << endl << endl << "What is the number of the pack the client wants to buy? Insert 'Ctrl-Z' to cancel. ";
	cin >> pack_number;

	if (cin.fail()) {
		if (cin.eof()) {
			system("cls");
			cin.clear();
			return 1;
		}
	}


	while (cin.fail() || find(available_packs.begin(), available_packs.end(), pack_number) == available_packs.end() || pack_number <= 0) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid input, please insert a valid one. Insert 'Ctrl-Z' to cancel. ";
		cin >> pack_number;
		if (cin.fail()) {
			if (cin.eof()) {
				system("cls");
				cin.clear();
				return 1;
			}
		}
	}

	cin.ignore(1000, '\n');
	system("cls");

	cout << endl << endl << "What do you know about the client that wants to buy a pack? " << endl;//dá duas formas de escolher o cliente, atraves do seu nome ou do seu nif
	cout << "1. Name." << endl;
	cout << "2. NIF." << endl;

	cout << endl << "Choose an option please (integer number). Insert 'Ctrl-Z' to cancel. ";
	cin >> option;

	if (cin.fail()) {
		if (cin.eof()) {
			system("cls");
			cin.clear();
			return 1;
		}
	}

	while (cin.fail() || option > 2 || option <= 0) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid input, please insert a valid one. Insert 'Ctrl-Z' to cancel. ";
		cin >> option;
		if (cin.fail()) {
			if (cin.eof()) {
				system("cls");
				cin.clear();
				return 1;
			}
		}
	}
	cin.ignore(1000, '\n');
	system("cls");


	if (option == 1) {
		for (int i = 0; i < size(Clients); i++) {
			cout << i + 1 << ". " << Clients[i].getClientName() << endl;
		}
	}
	else if (option == 2) {
		for (int i = 0; i < size(Clients); i++) {
			cout << i + 1 << ". " << Clients[i].getClientNIF() << endl;
		}
	}

	cout << endl << "Choose the client that wants to buy the pack(integer number). Insert 'Ctrl-Z' to cancel. ";
	cin >> option;

	if (cin.fail()) {
		if (cin.eof()) {
			system("cls");
			cin.clear();
			return 1;
		}
	}

	while (cin.fail() || option > size(Clients) || option <= 0) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid input, please insert a valid one. Insert 'Ctrl-Z' to cancel. ";
		cin >> option;
		if (cin.fail()) {
			if (cin.eof()) {
				system("cls");
				cin.clear();
				return 1;
			}
		}


	}
	cin.ignore(1000, '\n');
	system("cls");
	string cancel;
	int number_of_seats = Packs[pack_number].getSoldSpots() + Clients[option - 1].getNumberOfFamilyMembers();

	int canbuy = 1;

	if (number_of_seats > Packs[pack_number].getNumberMaxPeople()) {//caso de nao haver lugares disponiveis suficientes, nao é possivel comprar
		canbuy = 0;
		cout << "It isn't possible to buy this pack. There aren't enough available spots for everyone!" << endl;//mensagem de indisponibilidade de compra
		system("pause");
	}
	
	else if (number_of_seats == Packs[pack_number].getNumberMaxPeople()) {//caso de o n de lugares disponiveis acabar com esta compra é necessario por o pacote indisponivel
		if (canbuy == 1) {
			
			visualize_client(Clients, option - 1);
			cout << endl;
			visualize_pack(Packs, pack_number);


			cout << endl << endl << "Are you sure this client wants to buy this pack? " << endl << "Insert 'yes' to continue. " << endl << "Insert 'no' to cancel. " << endl << "Answer: ";
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
		}

		Packs[pack_number].setSoldSpots(number_of_seats);//atualiza os lugares vendidos
		Packs[pack_number].setPackNumber((-1)*(pack_number));//poe o pack indisponivel
		vector<int> aux = Clients[option - 1].getBoughtPacks();
		aux.push_back(pack_number);
		Clients[option-1].setBoughtPacks(aux);//acrescenta-se o pacote a ser comprado aos pacotes comprados pelo cliente
		Clients[option-1].setTotalPurchased(Clients[option - 1].getTotalPurchased() + Packs[pack_number].getPricePerPerson()*Clients[option - 1].getNumberOfFamilyMembers());//acrescentar valor do pack ao valor total de compras do cliente
	}
	else {//caso sem problemas
			if (canbuy == 1) {
				visualize_client(Clients, option - 1);
				cout << endl;
				visualize_pack(Packs, pack_number);


				cout << endl << endl << "Are you sure this client wants to buy this pack? " << endl << "Insert 'yes' to continue. " << endl << "Insert 'no' to cancel. " << endl << "Answer: ";
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
			}
		Packs[pack_number].setSoldSpots(number_of_seats);//atualiza os lugares vendidos
		vector<int> aux = Clients[option - 1].getBoughtPacks();
		aux.push_back(pack_number);
		Clients[option - 1].setBoughtPacks(aux); //acrescenta-se o pacote a ser comprado aos pacotes comprados pelo cliente
		Clients[option - 1].setTotalPurchased(Clients[option - 1].getTotalPurchased() + Packs[pack_number].getPricePerPerson()*Clients[option - 1].getNumberOfFamilyMembers());//acrescentar valor do pack ao valor total de compras do cliente
	}
	
		if (cancel == "Yes") {//so se a compra efetivamente for realizada é que sao atualizados os ficheiros
			update_clients(Clients, clients_file); //passar nova informação para os ficheiros
			update_packs(Packs, packs_file);
			system("cls");
			cout << "Pack was successfully bought!" << endl << endl;
		}


		else {
			system("cls");
			cout << "Operation was canceled!" << endl << endl;
		}
	

	return 1;
}


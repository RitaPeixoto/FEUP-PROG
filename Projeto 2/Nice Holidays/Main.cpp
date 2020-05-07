#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "SavingInformation.h"
#include "VisualizeInformation.h"
#include "PacksManagement.h"
#include "Menu.h"
#include "InformationManagement.h"
#include "ClientsManagement.h"
#include "BuyPack.h"

#include <Windows.h>

using namespace std;

//Neste ficheiro apenas se encontra a main()

int main() {

	SetConsoleOutputCP(1254);
	SetConsoleCP(1254);
	string main_file;
	ifstream agency_file;
	Agency agency;
	vector <Client> clients;
	vector <Pack> packs;


	

	cout << "--------------------- WELCOME ---------------------" << endl << endl;

	cout << "What is the name of the agency file? ";
	getline(cin, main_file);


	agency_file.open(main_file);

	if (!agency_file.is_open()) {
		cerr << endl << endl << "File " << main_file << " not found";
		return 1;
	}

	agency = agency_extract(agency_file);
	clients = clients_extract(agency.getClientsFile());
	packs = packs_extract(agency.getPacksFile());

	agency_file.close();

	

	int menu;
	do {
		menu = MainMenu();
		if (menu == 1) {
			int choice;
			do {
				choice = ClientsMenu();

				if (choice == 1) {
					if (create_client(clients, agency.getClientsFile(), packs) == 1) {
						choice = 4;
					}
				}
				else if (choice == 2) {
					if (modify_client(clients, agency.getClientsFile(), packs) == 1) {
						choice = 4;
					}
				}
				else if (choice == 3) {
					if (remove_client(clients, agency.getClientsFile()) == 1) {
						choice = 4;
					}
				}
				else if (choice == 0) {
					system("CLS");
					cout << endl;
					cout << "Thank you, goodbye!" << endl;
					return 0;
				}

			} while (choice != 4);

		}
		else if (menu == 2) {
			int choice;
			do {
				choice = PacksMenu();
				if (choice == 1) {
					if (create_pack(packs, agency.getPacksFile()) == 1) {
						choice = 4;
					}
				}
				else if (choice == 2) {
					if (modify_pack(packs, agency.getPacksFile()) == 1) {
						choice = 4;
					}
				}
				else if (choice == 3) {
					if (remove_pack(packs, agency.getPacksFile()) == 1) {
						choice = 4;
					}
				}
				else if (choice == 0) {
					system("CLS");
					cout << endl;
					cout << "Thank you, goodbye!" << endl;
					return 0;
				}
			} while (choice != 4);
		}
		else if (menu == 3) {
			int choice;
			do {
				choice = ViewInformationMenu();
				if (choice == 1) {
					if (show_agency(agency) == 1) {
						choice = 8;
					}
				}
				else if (choice == 2) {
					if (show_client(clients) == 1) {
						choice = 8;
					}
				}
				else if (choice == 3) {
					if (show_all_clients(clients) == 1){
						choice = 8;
					}
				}

				else if (choice == 4) {
					int choice1;
					do {
						choice1 = show_available_packs(packs);
						if (choice1 == 1) {
							choice = 8;
							break;
						}
						
					} while (choice1 != 2);
					
				}
				else if (choice == 5) {
					int choice2;
					do {
						choice2 = show_sold_packs(packs, clients);
						if (choice2 == 1) {
							choice = 8;
							break;
						}
					} while (choice2 != 2);
	
				}
				else if (choice == 6) {
					if (show_total_revenue(packs, clients) == 1) {
						choice = 8;
					}
				}
				
				else if (choice == 7) {
					int choice3;
					do {
						choice3 = show_most_visited_destinations(packs, clients);
						if (choice3 == 1) {
							choice = 8;
							break;
						}

					} while (choice3 != 2);
				}

				else if (choice == 0) {
					cout << endl;
					cout << "Thank you, goodbye!" << endl;
					return 0;
				}
			} while (choice != 8);

		}
		else if (menu == 4) {
			buy_pack(clients,packs,agency.getPacksFile(), agency.getClientsFile());
		}

	} while (menu != 0);
	system("CLS");
	cout << endl;
	cout << endl << "Thank you, goodbye!" << endl;

	

	
	
	return 0;

}
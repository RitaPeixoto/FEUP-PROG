#include "VisualizeInformation.h"

void visualize_address(Address address) {// mostra no ecra a morada na forma formatada pretendida

	cout << address.getStreet() << " / " <<
		address.getDoorNumber() << " / " <<
		address.getApartmentNumber() << " / " <<
		address.getZIPCode() << " / " <<
		address.getProvince() << endl;
}

void visualize_date(Date date) {// mostra no ecra a data na forma formatada pretendida
	cout << setw(2) << setfill('0') << date.getYear() << " / "
		<< setw(2) << setfill('0') << date.getMonth() << " / "
		<< setw(2) << setfill('0') << date.getDay();
}

void visualize_agency(Agency agency) {// mostra no ecra a agencia na forma formatada pretendida

	cout << "----------------------- Agency Information -----------------------" << endl;

	cout << "Name: " << agency.getName() << endl;
	cout << "NIF: " << agency.getNIF() << endl;
	cout << "Address: ";
	visualize_address(agency.getAddress());
	cout << "URL: " << agency.getURL() << endl;
	cout << "Clients File: " << agency.getClientsFile() << endl;
	cout << "Packs File: " << agency.getPacksFile() << endl;

}

void visualize_client(vector <Client> clients, int number_client) {// mostra no ecra um cliente na forma formatada pretendida

	
	cout << "----------------------- Client Number " << number_client+1 << " -----------------------" << endl;
	cout << "Name: " << clients[number_client].getClientName() << endl;
	cout << "NIF: " << clients[number_client].getClientNIF() << endl;
	cout << "Number of family members: " << clients[number_client].getNumberOfFamilyMembers() << endl;
	cout << "Address: ";
	visualize_address(clients[number_client].getClientAddress());
	cout << "Packs already bought: ";
	for (int j = 0; j < size(clients[number_client].getBoughtPacks()); j++) {
		if (j == size(clients[number_client].getBoughtPacks()) - 1 && number_client != clients.size() - 1) {
			cout << clients[number_client].getBoughtPacks()[j] << endl;
		}
		else if (j == size(clients[number_client].getBoughtPacks()) - 1 && number_client == clients.size() - 1) {
			cout << clients[number_client].getBoughtPacks()[j] << endl;
		}
		else {
			cout << clients[number_client].getBoughtPacks()[j] << " ; ";
		}
	}
	cout << "Total purchased: " << clients[number_client].getTotalPurchased() << endl;
}

void visualize_clients(vector <Client> clients) {// mostra no ecra todos os clientes na forma formatada pretendida, utilizando a funçao que mostra no ecra apenas um cliente

	for (int i = 0; i < size(clients); i++) {
		visualize_client(clients, i);
		cout << endl;
	}
}

void visualize_pack(vector <Pack> Packs, int pack_number) {// mostra no ecra um pacote na forma formatada pretendida

	cout << endl << "----------------------- " << "Pack Number " << pack_number << " -----------------------" << endl;

	if (Packs[pack_number].getPackNumber() < 0) {
		cout << "Availability: Not Available!" << endl;
	}
	else {
		cout << "Availability: Available!" << endl;
	}

	


	cout << "Destination: " << Packs[pack_number].getDestination()[0];

	if (size(Packs[pack_number].getDestination()) > 1) {
		cout << " - ";
		for (int j = 1; j < size(Packs[pack_number].getDestination()); j++) {
			if (j == size(Packs[pack_number].getDestination()) - 1) {
				cout << Packs[pack_number].getDestination()[j] << endl;
			}
			else {
				cout << Packs[pack_number].getDestination()[j] << ", ";
			}
		}
	}
	else {
		cout << endl;
	}

	cout << "Departure date: ";
	visualize_date(Packs[pack_number].getBeginDate());
	cout << endl << "Arrival date: ";
	visualize_date(Packs[pack_number].getEndDate());
	cout << endl << "Price per person: " << Packs[pack_number].getPricePerPerson() << endl;
	cout << "Initially available spots: " << Packs[pack_number].getNumberMaxPeople() << endl;
	cout << "Sold spots: " << Packs[pack_number].getSoldSpots() << endl << endl;
}

void visualize_packs(vector <Pack> Packs) {// mostra no ecra um pacote na forma formatada pretendida,utilizando a funçao que mostra no ecra apenas um pacote

	for (int i = 1; i < size(Packs); i++) {
		visualize_pack(Packs, i);
		cout << endl;
	}
}

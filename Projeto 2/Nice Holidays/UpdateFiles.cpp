#include "UpdateFiles.h"

//funções onde serão atualizados os ficheiros de texto

void update_clients(vector<Client> client, string name_file) { //atualizar o ficheiro dos clientes


	string new_file = name_file;
	new_file.insert(name_file.find_last_of('.'), "_temp");
	ofstream nfile(new_file);//é criado um ficheiro provisorio

	for (int i = 0; i < client.size(); i++) {//escreve os clientes no ficheiro da forma pretendida
		nfile << client[i].getClientName() << endl;
		nfile << client[i].getClientNIF() << endl;
		nfile << client[i].getNumberOfFamilyMembers() << endl;
		nfile << client[i].getClientAddress().getStreet() << " / " << client[i].getClientAddress().getDoorNumber() << " / " << client[i].getClientAddress().getApartmentNumber() << " / " << client[i].getClientAddress().getZIPCode() << " / " << client[i].getClientAddress().getProvince() << endl;

		for (int j = 0; j < size(client[i].getBoughtPacks()); j++) {
			if (j == size(client[i].getBoughtPacks()) - 1 && i != client.size() - 1) {
				nfile << client[i].getBoughtPacks()[j] << endl;
			}
			else if (j == size(client[i].getBoughtPacks()) - 1 && i == client.size() - 1) {
				nfile << client[i].getBoughtPacks()[j] << endl;
			}
			else {
				nfile << client[i].getBoughtPacks()[j] << " ; ";
			}
		}
		nfile << client[i].getTotalPurchased();

		if (i != client.size() - 1) {
			nfile << endl <<  "::::::::::" << endl;
		}

	}
	nfile.close();
	const char * file_name = name_file.c_str();
	const char * file_new = new_file.c_str();

	remove(file_name);//elimina o ficheiro antigo
	rename(file_new, file_name);//torna o ficheiro provisorio o novo clients_file

}

void update_packs(vector<Pack> Packs, string name_file) { // atualizar o ficheiro dos pacotes


	string new_file = name_file;
	new_file.insert(name_file.find_last_of('.'), "_temp");
	ofstream nfile(new_file);//é criado um ficheiro provisorio

	nfile << Packs[0].getLastCreatedPack() << endl;

	for (int i = 1; i < size(Packs); i++) {//escreve os pacotes no ficheiro da forma pretendida

		nfile << Packs[i].getPackNumber() << endl;

		nfile << Packs[i].getDestination()[0];

		if (size(Packs[i].getDestination()) > 1) {
			nfile << " - ";
			for (int j = 1; j < size(Packs[i].getDestination()); j++) {
				if (j == size(Packs[i].getDestination()) - 1) {
					nfile << Packs[i].getDestination()[j] << endl;
				}
				else {
					nfile << Packs[i].getDestination()[j] << ", ";
				}
			}
		}
		else {
			nfile << endl;
		}

		nfile << Packs[i].getBeginDate().getYear() << " / " << setw(2) << setfill('0') << Packs[i].getBeginDate().getMonth() << " / " << setw(2) << setfill('0') << Packs[i].getBeginDate().getDay() << endl;
		nfile << Packs[i].getEndDate().getYear() << " / " << setw(2) << setfill('0') << Packs[i].getEndDate().getMonth() << " / " << setw(2) << setfill('0') << Packs[i].getEndDate().getDay() << endl;
		nfile << Packs[i].getPricePerPerson() << endl;
		nfile << Packs[i].getNumberMaxPeople() << endl;
		nfile << Packs[i].getSoldSpots();

		if (i != size(Packs) - 1) {
			nfile << endl << "::::::::::" << endl;
		}
	}
	nfile.close();
	const char * file_name = name_file.c_str();
	const char * file_new = new_file.c_str();

	remove(file_name);//elimina o ficheiro antigo
	rename(file_new, file_name);//torna o ficheiro provisorio o novo packs_file
}
#include "SavingInformation.h"

Agency agency_extract(ifstream &AgencyFile) {//extrai a informaçao do ficheiro da agencia
	string line;
	Agency agency;
	int number_of_lines = 0;


	while (getline(AgencyFile, line)) {
		line = cleaning_invalid_characters(line);
		switch (number_of_lines) {
		case 0:
			agency.setName(resize_function(line));
			break;
		case 1:
			agency.setNIF(stoi(line));
			break;
		case 2:
			agency.setURL(resize_function(line));
			break;
		case 3:
			agency.setAddress(Address(line));
			break;
		case 4:
			agency.setClientsFile(resize_function(line));
			break;
		case 5:
			agency.setPacksFile(resize_function(line));
			break;
		}
		number_of_lines++;
	}
	return agency;
}

vector <Client> clients_extract(string clients_file) {//extrai a informaçao do ficheiro dos clientes; cada linha corresponde a um atributo

	ifstream clientsFile;
	string line;
	vector <Client> clients;
	Client client;

	clientsFile.open(clients_file);

	if (!clientsFile.is_open()) {//caso de haver erro ao abrir o ficheiro
		cout << clients_file << " not found";
		exit(1);
	}


	int number_of_lines = 0;
	getline(clientsFile, line);
	line = cleaning_invalid_characters(line);
	line = resize_function(line);


	while (true) {
		if (line == "::::::::::") {//delimitador do fim de um cliente
			clients.push_back(client);
			number_of_lines = 0;
		}

		else {
			switch (number_of_lines) {
			case 0:
				client.setClientName(resize_function(line));
				break;
			case 1:
				client.setClientNIF(stoi(line));
				break;
			case 2:
				client.setNumberOfFamilyMembers(stoi(line));
				break;
			case 3:
				client.setClientAddress(Address(line));
				break;
			case 4:
				client.setBoughtPacks(line);
				break;
			case 5:
				client.setTotalPurchased(stoi(line));
			}
			number_of_lines++;
		}
		if (clientsFile.eof()) {// o ultimo cliente nao tem delimitador pelo que o seu fim é indicado pelo fim do ficheiro
			clients.push_back(client);
			break;
		}
		getline(clientsFile, line);
		line = cleaning_invalid_characters(line);
		line = resize_function(line);

	}
	clientsFile.close();
	return clients;
}

vector <Pack> packs_extract(string packs_file) {//extrai a informaçao do ficheiro de pacotes; cada linha corresponde a um atributo

	ifstream packsFile;
	string line;
	Pack pack;
	vector <Pack> packs;


	packsFile.open(packs_file);

	if (!packsFile.is_open()) {//caso de haver algum erro ao abrir o ficheiro
		cout << packs_file << " not found";
		exit(1);
	}

	int number_of_lines = 0;
	getline(packsFile, line);
	line = cleaning_invalid_characters(line);
	bool firstline = true;

	while (true) {
		line = resize_function(line);


		if (line == "::::::::::") {//delimitador do fim de um pack
			packs.push_back(pack);
			number_of_lines = 0;
		}
		else if (firstline) {
			pack.setLastCreatedPack(stoi(line));
			packs.push_back(pack);
			firstline = false;
		}

		else {
			switch (number_of_lines) {
			case 0:
				pack.setPackNumber(stoi(line));
				break;
			case 1:
				pack.setDestination(line);
				break;
			case 2:
				pack.setBeginDate(line);
				break;
			case 3:
				pack.setEndDate(line);
				break;
			case 4:
				pack.setPricePerPerson(stoi(line));
				break;
			case 5:
				pack.setNumberMaxPeople(stoi(line));
				break;
			case 6:
				pack.setSoldSpots(stoi(line));
				break;
			}
			number_of_lines++;
		}
		if (packsFile.eof()) {// o ultimo pacote nao tem delimitador pelo que o seu fim é indicado pelo fim do ficheiro
			packs.push_back(pack);
			break;
		}
		getline(packsFile, line);
		line = cleaning_invalid_characters(line);
		line = resize_function(line);

	}
	packsFile.close();
	return packs;
}
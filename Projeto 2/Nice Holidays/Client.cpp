#include"Client.h"


Client::Client() {//Default constructor
	newName = "";
	newNIF = 0;
	newNumberOfFamilyMembers = 0;
	newAddress = Address();
	newBoughtPacks = {};
	newTotalPurchased = 0;
}

// GET methods

string Client::getClientName() const {
	return newName;
}

int Client::getClientNIF() const {
	return newNIF;
}

int Client::getNumberOfFamilyMembers() const {
	return newNumberOfFamilyMembers;
}

Address Client::getClientAddress() const {
	return newAddress;
}
vector<int> Client::getBoughtPacks() const {
	return newBoughtPacks;
}
int Client::getTotalPurchased() const {
	return newTotalPurchased;
}

// SET methods

void Client::setClientName(string Name) {
	newName = Name;
}
void Client::setClientNIF(int NIF) {
	newNIF = NIF;
}
void Client::setNumberOfFamilyMembers(int NumberOfFamilyMembers) {
	newNumberOfFamilyMembers = NumberOfFamilyMembers;
}

void Client::setClientAddress(Address Address) {
	newAddress = Address;
}

void Client::setBoughtPacks(string line) {	 //separa os pacotes comprados pelo cliente, sendo o delimitador o ponto e virgula ';' e adiciona-os a um vector
	vector <int> boughtPacks;
	string aux;
	int number_of_packs = 0, delimiter;

	line += ';';
	delimiter = line.find_first_of(';');

	while (line != "") {
		aux = line.substr(0, delimiter);
		boughtPacks.push_back(stoi(aux));
		number_of_packs++;
		aux.clear();
		line.erase(0, delimiter + 1);
		delimiter = line.find_first_of(';');
	}

	newBoughtPacks = boughtPacks;

}

void Client::setBoughtPacks(vector<int>BoughPacks) {
	newBoughtPacks = BoughPacks;
}

void Client::setTotalPurchased(int TotalPurchased) {
	newTotalPurchased = TotalPurchased;
}
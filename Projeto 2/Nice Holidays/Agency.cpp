#include "Agency.h"

Agency::Agency() {//Default constructor
	name = "";
	NIF = 0;
	address = Address();
	newURL = "";
	newClientsFile = "";
	newPacksFile = "";
}



//Get Functions
string Agency::getName() const {
	return name;
}

unsigned Agency::getNIF() const {
	return NIF;
}

Address Agency::getAddress() const {
	return address;
}

string Agency::getURL() const {
	return newURL;
}

string Agency::getClientsFile() const {
	return newClientsFile;
}

string Agency::getPacksFile() const {
	return newPacksFile;
}

//Set functions

void Agency::setName(string n) {
	name = n;
}

void Agency::setNIF(unsigned int nif) {
	NIF = nif;
}

void Agency::setAddress(Address a) {
	address = a;
}

void Agency::setURL(string URL) {
	newURL = URL;
}

void Agency::setClientsFile(string ClientsFile) {
	newClientsFile = ClientsFile;
}

void Agency::setPacksFile(string PacksFile) {
	newPacksFile = PacksFile;
}
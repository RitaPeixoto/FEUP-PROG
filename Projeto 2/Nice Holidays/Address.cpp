#include "Address.h"

Address::Address() {// Default constructor
	newStreet = "";
	newDoorNumber = 0;
	newApartmentNumber = "";
	newZIPCode = "";
	newProvince = "";
}

Address::Address(string address) {// separa a morada pelos subcampos,sendo o delimitador a barra '/'
	int counter = 0;
	string aux;
	int delimiter;

	address += '/';
	delimiter = address.find_first_of('/');

	while (address != "") {
		aux = address.substr(0, delimiter);
		switch (counter) {
		case 0:
			newStreet = resize_function(aux);
			break;

		case 1:
			aux = resize_function(aux);
			newDoorNumber = stoi(aux);
			break;

		case 2:
			newApartmentNumber = resize_function(aux);
			break;

		case 3:
			newZIPCode = resize_function(aux);
			break;

		case 4:
			newProvince = resize_function(aux);
			break;
		}
		counter++;
		aux.clear();
		address.erase(0, delimiter + 1);
		delimiter = address.find_first_of('/');
	}

}


//Get functions

string Address::getStreet() const {
	return newStreet;
}

unsigned int Address::getDoorNumber() const {
	return newDoorNumber;
}

string Address::getApartmentNumber() const {
	return newApartmentNumber;
}

string Address::getZIPCode() const {
	return newZIPCode;
}

string Address::getProvince() const {
	return newProvince;
}

//Set functions

void Address::setStreet(string Street){
	newStreet = Street;
}

void Address::setDoorNumber(int DoorNumber) {
	newDoorNumber = DoorNumber;
}

void Address::setApartmentNumber(string ApartmentNumber) {
	newApartmentNumber = ApartmentNumber;
}

void Address::setZIPCode(string ZIPCode) {
	newZIPCode = ZIPCode;
}

void Address::setProvince(string Province) {
	newProvince = Province;
}
#include "Pack.h"
using namespace std; 


//get functions
int Pack::getLastCreatedPack() const {
	return newLastCreatedPack;
}

int Pack::getPackNumber() const {
	return newPackNumber;
}

vector<string>Pack::getDestination() const {
	return newDestination;
}

Date Pack::getBeginDate() const {
	return newBeginDate;
}

Date Pack::getEndDate() const {
	return newEndDate;
}
double Pack::getPricePerPerson() const {
	return newPricePerPerson;
}

unsigned Pack::getNumberMaxPeople() const {
	return newNumberMaxPeople;
}

unsigned Pack::getSoldSpots() const {
	return newSoldSpots;
}


//set functions

void Pack::setLastCreatedPack(int lastSoldPack) {
	newLastCreatedPack = lastSoldPack;
}

void Pack::setPackNumber(int packNumber) {
	newPackNumber = packNumber;
}
void Pack::setDestination(string line) {// através do input em string cria o vetor destination que contem separadamente os diversos locais a visitar 
	string aux = "";
	vector <string> destination;

	line += ',';

	for (int i = 0; i < size(line); i++) {
		if (line[i] == '-' || line[i] == ',') {// os diversos locais a visitar encontram-se apos um '-' e separados por virgulas ','; antes do '-' encontra-se o destino principal
			aux = resize_function(aux);
			formatting_string(aux);
			destination.push_back(aux);
			aux.clear();
		}
		else {
			aux += line[i];
		}
	}
	this->newDestination = destination;
}
void Pack::setBeginDate(string beginDate) {
	newBeginDate.setDate(beginDate);
}
void Pack::setEndDate(string endDate) {
	newEndDate.setDate(endDate);
}
void Pack::setPricePerPerson(double pricePerPerson) {
	newPricePerPerson = pricePerPerson;
}
void Pack::setNumberMaxPeople(unsigned numberMaxPeople) {
	newNumberMaxPeople = numberMaxPeople;
}

void Pack::setSoldSpots(unsigned soldSpots) {
	newSoldSpots = soldSpots;
}
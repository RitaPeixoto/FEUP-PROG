#ifndef PACK_H
#define PACK_H


#include <iostream>
#include <string>
#include <vector>
#include "Date.h"

using namespace std;

class Pack {
public:

	// GET methods
	int getLastCreatedPack() const; 
	int getPackNumber() const;
	vector<string> getDestination() const;
	Date getBeginDate() const;
	Date getEndDate() const;
	double getPricePerPerson() const;
	unsigned getNumberMaxPeople() const;
	unsigned getSoldSpots() const;

	// SET methods
	void setLastCreatedPack(int lastSoldPack);
	void setPackNumber(int packNumber);  // to set negatve if "deprecated"
	void setDestination(string destination);
	void setBeginDate(string beginDate);
	void setEndDate(string endDate);
	void setPricePerPerson(double pricePerPerson);
	void setNumberMaxPeople(unsigned numberMaxPeople);
	void setSoldSpots(unsigned soldSpots);

private:
	int newLastCreatedPack;
	int newPackNumber; // numero identificador do pack 
	vector<string> newDestination; // touristic places to visit
	Date newBeginDate;  // begin date
	Date newEndDate;  // end date
	double newPricePerPerson; // price per person
	unsigned newNumberMaxPeople; // number of persons still available in the packet (updated whenever the packet is sold to a new client)
	unsigned newSoldSpots; // numero de lugares vendidos 
};

#endif
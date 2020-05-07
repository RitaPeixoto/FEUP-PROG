#ifndef ADDRESS_H
#define ADDRESS_H


#include <iostream>	
#include <string>
#include <vector>
#include "FormattingFunctions.h"

using namespace std;

class Address {
public:
	
	Address(string address);
	Address();
	//Get functions

	string getStreet() const;
	unsigned int getDoorNumber() const;
	string getApartmentNumber() const;
	string getZIPCode() const;
	string getProvince() const;
	
	//Set functions
	void setStreet(string street);
	void setDoorNumber(int doorNumber);
	void setApartmentNumber(string apartmentNumber);
	void setZIPCode(string ZIPCode);
	void setProvince(string province);

private:
	string newStreet;
	int newDoorNumber;
	string newApartmentNumber;
	string newZIPCode;
	string newProvince;
};

#endif


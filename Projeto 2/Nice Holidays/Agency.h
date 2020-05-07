#ifndef AGENCY_H
#define AGENCY_H


#include <iostream>	
#include <string>
#include <vector>
#include "Address.h"

using namespace std;

class Agency {
public:
	
	Agency();

	//Get functions

	string getName() const;
	unsigned int getNIF() const;
	Address getAddress() const;
	string getURL() const;
	string getClientsFile() const ;
	string getPacksFile() const;

	//Set functions

	void setName(string name);
	void setNIF(unsigned int NIF);
	void setAddress(Address address);
	void setURL(string URL);
	void setClientsFile(string ClientsFile);
	void setPacksFile(string PacksFile);



private:
	string name;
	unsigned int NIF;
	Address address;
	string newURL;
	string newClientsFile;
	string newPacksFile;
};


#endif

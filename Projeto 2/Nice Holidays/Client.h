#ifndef CLIENT_H
#define CLIENT_H


#include <iostream>
#include <string>
#include <vector>
#include "Address.h"

using namespace std;


class Client {

public:

	Client();

	// GET methods

	string getClientName() const;
	int getClientNIF() const;
	int getNumberOfFamilyMembers() const;
	Address getClientAddress() const;
	vector<int> getBoughtPacks() const;
	int getTotalPurchased() const;

	// SET methods

	void setClientName(string name);
	void setClientNIF(int NIF);
	void setNumberOfFamilyMembers(int numberOfFamilyMembers);
	void setClientAddress(Address address);
	void setBoughtPacks(string line);
	void setBoughtPacks(vector<int>BoughPacks);
	void setTotalPurchased(int totalPurchased);

	//

private:
	string newName;
	int newNIF;
	int newNumberOfFamilyMembers;
	Address newAddress;
	vector<int> newBoughtPacks;
	int newTotalPurchased;

};

#endif

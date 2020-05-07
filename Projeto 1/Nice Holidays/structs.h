#pragma once
#include <iostream>
#include<vector>
#include<string>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include<algorithm>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
using namespace std;
//definiçao de structs


struct Adress { //estrutura da morada
	string street;
	string floor;
	string postal_code;
	string district;
	int door_number;
};
struct Agency { //estrutura da agencia
	string name;
	string url;
	string clients_file;
	string packs_file;
	Adress morada;
	int  nif;
};

struct Date { // estrutura da data 
	int year;
	int month;
	int day;
};

struct Client { // estrutura do cliente
	Adress morada;
	string name;
	vector <int> AdquiredTravelPacks;
	int  nOfPeopleInTheFamily;
	int nif;
};

struct Packs { // estrutura dos packs
	int pack_number, price_for_person, available_spots, sold_spots, last_sold_pack;
	string destination;
	Date begin_date;
	Date end_date;
};
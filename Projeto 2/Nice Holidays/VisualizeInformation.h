#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include "Address.h"
#include "Date.h"
#include "Agency.h"
#include "Client.h"
#include "Pack.h"

using namespace std;

void visualize_address(Address address);

void visualize_date(Date date);

void visualize_agency(Agency agency);

void visualize_client(vector <Client> clients, int number_client);

void visualize_clients(vector <Client> clients);

void visualize_pack(vector <Pack> Packs, int pack_number);

void visualize_packs(vector <Pack> Packs);


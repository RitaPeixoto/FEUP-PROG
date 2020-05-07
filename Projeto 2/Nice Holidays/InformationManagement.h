#pragma once
#include "Agency.h"
#include "Client.h"
#include "Pack.h"
#include "Date.h"
#include <vector>
#include <string>
#include "VisualizeInformation.h"
#include "VerifyingInputs.h"
#include<map>
#include<iterator>
#include <iomanip>
#include <algorithm>

using namespace std;


int show_agency(Agency agency);
int show_client(vector <Client> Clients);
int show_all_clients(vector <Client> Clients);
int show_available_packs(vector <Pack> Packs);
int show_sold_packs(vector <Pack> Packs, vector <Client> Clients);
int show_total_revenue(vector <Pack> Packs, vector <Client> Clients);
map  <string, int>  most_visited(vector <Pack> Packs);
multimap<int, string> reversed(map<string, int> const &mapped);
int show_most_visited_destinations(vector <Pack> Packs, vector <Client> Clients); //IDK YET about this one



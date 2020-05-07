//#ifndef SAVINGINFORMATION_H
//#define SAVINGINFORMATION_H
#pragma once
#include <iostream>	
#include <fstream>
#include <string>
#include <vector>
#include "Address.h"
#include "Agency.h"
#include "Client.h"
#include "Date.h"
#include "Pack.h"
#include "FormattingFunctions.h"

using namespace std;

Agency agency_extract(ifstream &AgencyFile);

vector <Client> clients_extract(string clients_file);

vector <Pack> packs_extract(string packs_file);
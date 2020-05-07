#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "VerifyingInputs.h"
#include "VisualizeInformation.h"
#include"InformationManagement.h"
#include"Client.h"
#include"Pack.h"
#include "UpdateFiles.h"



int buy_pack(vector<Client> &Clients, vector <Pack> &Packs, string packs_file, string clients_file);
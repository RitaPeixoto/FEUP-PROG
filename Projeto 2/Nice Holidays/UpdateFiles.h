#pragma once
#include <iostream>
#include <string>
#include "Client.h"
#include "Pack.h"
#include <vector>
#include <fstream>
#include <stdio.h>
#include <iomanip>

using namespace std;

void update_clients(vector<Client> client, string name_file);
void update_packs(vector<Pack> Packs, string name_file);

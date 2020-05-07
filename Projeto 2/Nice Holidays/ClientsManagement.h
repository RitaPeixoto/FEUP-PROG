#pragma once
#include <iostream>
#include <string>
#include <vector>
#include"Client.h"
#include"Address.h"
#include"FormattingFunctions.h"
#include"UpdateFiles.h"
#include"VisualizeInformation.h"
#include"VerifyingInputs.h"
#include"Pack.h"
using namespace std;

//todas as funções das opções do menu "Clients menu" está desenvolvida neste ficheiro

int create_client(vector <Client> &Clients, string name_file, vector <Pack> Packs);
int modify_client(vector <Client> &Clients, string name_file, vector <Pack> Packs);
int remove_client(vector <Client> &Clients, string name_file);

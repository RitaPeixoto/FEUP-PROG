#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "FormattingFunctions.h"

using namespace std;


int verifying_int(string &aux);  // verificar se uma dada string pode ser passada para inteiro sem erros
bool verifying_INT(string aux);
int verifying_NIF(string &aux);
string verifying_string(string &aux);
string verifying_ZIPcode(string &aux);
bool verifying_Destination(string aux);
string verifying_ApartmentDoor(string &aux);
bool verifying_bought_packs(string aux);
bool verifying_date(string aux);

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Menu.h"
#include "VerifyingInputs.h"
#include "Pack.h"
#include "UpdateFiles.h"
#include "VisualizeInformation.h"
#include "FormattingFunctions.h"
#include "UpdateFiles.h"


//todas as fun��es das op��es do menu "Packages menu" est� desenvolvida neste ficheiro
//N�O ESQUECER DA VALIDADE DOS PACOTES (data de hoje)


int create_pack(vector <Pack> &Packs, string name_file); //criar pacote, atualizar o vector e o ficheiro dos pacotes

int modify_pack(vector <Pack> &Packs, string name_file); //modificar pacote, atualizar vector e ficheiro dos pacotes

int remove_pack(vector <Pack> &Packs, string name_file);   //remove o pacote, atualiza o vetor e o ficheiro dos pacotes

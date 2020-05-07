#pragma once
#include <iostream>	
#include <string>
#include <vector>
#include <algorithm>
#include<map>



using namespace std;

string resize_function(string &str); //retirar ' ' do inicio e do fim da string

string cleaning_invalid_characters(string line); // retirar acentos e cedilhas, foi só usada ao guardar informação dos ficheiros

vector <int> get_packs_client(string line); //separa os pacotes comprados pelo cliente e adiciona-os a um vector

string formatting_string(string &str); //formatar a string para que todas as letras sejam minusculas menos a primeira letra de cada palavra



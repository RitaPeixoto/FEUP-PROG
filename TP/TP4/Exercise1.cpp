/*a) Escreva uma função bool isHydroxide(char compound[]) que tem uma string de C como parâmetro e devolve true ou false consoante essa string 
terminar ou não com os caracteres OH. Escreva um programa que teste a função com os seguintes dados: KOH, H2O2, NaCl, NaOH, C9H8O4 e MgOH.*/
#include<iostream>
#include<cstring>
using namespace std;

int size(char compound[]) {
	int size = 0;

	for (int i=0; compound[i] != '\0'; i++) {
		size++;

	}
	return size;

}

bool isHydroxide(char compound[]) {
	int size_compound = size(compound);
	if (compound[size_compound - 2] == 'O' && compound[size_compound - 1] == 'H') {
		return true;
	}
	else
		return false;
}

int main() {
	char  quimical_symbol[]= "KOH";

	if (isHydroxide(quimical_symbol)) {
		cout << "It's a hydroxide" << endl;
	}
	else {
		cout << "It's not a hydroxide" << endl;
	}
	return 0;
}
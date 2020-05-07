/*Escreva uma função void decompose(string compound) que tem com parâmetro uma string representando um composto químico e mostra no ecrã os seus
elementos constituintes. Por exemplo, o composto H2O (água) tem como elementos constituintes H e O; o composto NaCl tem como elementos 
constituintes Na e Cl. Teste a função com os seguintes dados: H2O, KOH, H2O2, NaCl, NaOH, C9H8O4 e MgOH.*/

#include <iostream>
#include<string>
using namespace std;

void decompose(string compound) {
	int length = compound.length();
	for (int i = 0; i < length; i++) {
		if (islower(compound[i + 1])) {
			cout << compound[i] << compound[i + 1] << endl;
		}
		else if (isdigit(compound[i + 1])) {
			cout << compound[i] << endl;
		}
		else if (!isdigit(compound[i]) && !islower(compound[i])) {
			cout << compound[i]<<endl;
		}

	}
}

int main() {
	string compound;
	cout << "Insert the compound: ";
	cin >> compound;
	decompose(compound);

	return 0;
}
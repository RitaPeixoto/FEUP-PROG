/*Escreva uma função void removeDuplicates(vector<int> &v) que elimina os elementos repetidos do vector v. A ordem original dos elementos do 
vector deve ser mantida. Escreva um programa de teste dessa função. Sugestão: a eliminação de um elemento pode ser efectuada deslocando todos
os elementos que ocupam as posições seguintes do vector para a posição anterior à que ocupam e alterando o tamanho do vector, usando o método 
resize() da classe vector, para diminuir o tamanho do vector. Nota: existem métodos da classe vector que permitem eliminar elementos de um vector
e algoritmos da STL que permitem eliminar elementos repetidos de um vector; estes métodos serão estudados posteriormente. */

#include<iostream>
#include<string>
#include<vector>

using namespace std;


void removeDuplicates(vector <int> &v) {
	vector <int> AuxVector;

	for (int i1 = 0; i1 < size(v); i1++)
		if (!(find(AuxVector.begin(), AuxVector.end(), v[i1]) != AuxVector.end()))
			AuxVector.push_back(v[i1]);

	v = AuxVector;
}

int main() {
	vector <int> v = { 9, 2, 2, 2, 1, 14, 14, 1, 3 };

	removeDuplicates(v);

	for (int i = 0; i < size(v); i++)
		cout << v[i] << endl;

	return 0;
}

/*void removeDuplicates(vector<int> &v) {
	int counter = 0;

	for (int i = 0; i < size(v); i++) {
		for (int j = i + 1; j < size(v); j++) {
			if (v[i] == v[j]) {
				counter++;
				for (int k = j + 1; k < size(v); k++) {
					v[k - 1] = v[k];
				}
			}
		}
	}
	v.resize(size(v) - counter);
	
}


int main() {
	vector <int> v;
	int aux;

	while (true) {
		cout << "Insert an element for the vector (CTRL-Z to end): ";
		cin >> aux;
		if (cin.fail()) {
			cin.eof();
			break;
		}
		else {
			v.push_back(aux);
		}
	}
	removeDuplicates(v);

	cout << "The result vector is: ";
	for (int i = 0; i < size(v); i++) {
		cout << v[i] << " ";
	}
	

	return 0;
}*/
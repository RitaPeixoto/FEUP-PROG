/*
a) Desenvolver duas funções cujos protótipos são vector<int> union(const vector<int> &v1, const vector<int> &v2); vector<int> intersection(const vector<int> &v1,
const vector<int> &v2); que realizem a reunião e a intersecção dos elementos dos vectores de inteiros v1 e v2, retornando o respectivo resultado. O vector resultante 
não deve ter elementos repetidos e os elementos devem ficar ordenados por ordem crescente. Sugestão: use as funções bubblesort() e removeDuplicates() anteriormente desenvolvidas, 
antes de fazer a reunião/intersecção. 
b) Desenvolver um programa de teste dessas funções
*/

#include <iostream>
#include <vector>
using namespace std;

void bubblesort(vector <int> &v) {
	for (int i1 = 0; i1 < size(v) - 1; i1++) {
		for (int i2 = 0; i2 < size(v) - i1 - 1; i2++) {
			if (v[i2] > v[i2 + 1]) {
				int aux = v[i2];
				v[i2] = v[i2 + 1];
				v[i2 + 1] = aux;
			}
		}
	}
}

void removeDuplicates(vector <int> &v) {
	vector <int> AuxVector;

	for (int i1 = 0; i1 < size(v); i1++)
		if (!(find(AuxVector.begin(), AuxVector.end(), v[i1]) != AuxVector.end()))
			AuxVector.push_back(v[i1]);

	v = AuxVector;
}

vector <int> reunion(const vector<int> &v1, const vector<int> &v2) {
	vector <int> result, lowest, greatest;

	if (size(v1) > size(v2)) {
		greatest = v1;
		lowest = v2;
	}

	else {
		greatest = v2;
		lowest = v1;
	}

	bubblesort(greatest);
	bubblesort(lowest);

	for (int i1 = 0; i1 < size(lowest); i1++) {
		result.push_back(lowest[i1]);
		result.push_back(greatest[i1]);
	}

	for (int i2 = size(lowest); i2 < size(greatest); i2++)
		result.push_back(greatest[i2]);

	removeDuplicates(result);
	bubblesort(result);

	return result;
};

vector<int> intersection(const vector<int> &v1, const vector<int> &v2) {
	vector <int> result, lowest, greatest;

	if (size(v1) > size(v2)) {
		greatest = v1;
		lowest = v2;
	}

	else {
		greatest = v2;
		lowest = v1;
	}

	bubblesort(greatest);
	bubblesort(lowest);

	for (int i1 = 0; i1 < size(lowest); i1++) {
		//WIP
	}

	removeDuplicates(result);
	bubblesort(result);

	return result;
};

int main() {
	const vector <int> v1 = { 1, 2, 3, 3, 3, 4 }, v2 = { 1, 10, 9, 4, 5, 5 };

	for (int i = 0; i < size(reunion(v1, v2)); i++) {
		cout << reunion(v1, v2)[i] << endl;
	}

	return 0;
}
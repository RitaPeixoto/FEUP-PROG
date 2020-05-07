/*a) Repita o problema anterior, usando vectors da STL para guardar os n�meros, em vez de arrays de C. Os prot�tipos das fun��es a desenvolver
s�o, neste caso, os seguintes: void readIntVector(vector<int> &v, int nElem); //OU vector<int> readIntVector(int nElem); 
int searchValueInVector(const vector<int> &v, int value); vector<int> searchMultValuesInIntVector(const vector<int> &v, int value);
b) Escreva novas vers�es de readIntVector()em que o n�mero de elementos n�o tenha de ser especificado como par�metro; o utilizador dever� teclar
CTRL-Z para indicar que terminou a entrada dos elementos do vector. void readIntVector(vector<int> &v); vector<int> readIntVector(); */

#include <iostream>
#include <vector>
using namespace std;

void readIntVector(vector<int> &v, int nElem) {
	cout << "Insert the integer which index is:  " << endl;
	for (int i = 0; i < nElem; i++) {
		int x;
		cout << i << " ";
		cin >> x;
		v.push_back(x);
	}
}

int searchValueInVector(const vector<int> &v, int value) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == value)
			return i;
	}

	return -1;
}

vector<int> searchMultValuesInIntVector(const vector<int> &v, int value) {
	vector<int> index;
	int counter = 0;

	for (int i = 0; i < v.size(); i++) {
		if (v[i] == value) {
			index.push_back(i);
			counter += 1;
		}
	}
	return index;

}

int main() {
	int nElem, value;
	vector<int> v, index;

	cout << "Insert the number of elements that you want to write: ";
	cin >> nElem;

	readIntVector(v, nElem);

	cout << "Insert the value that you want to search: ";
	cin >> value;
	if (searchValueInVector(v, value) == -1) {
		cout << "The value was not found.";
	}
	else {
		cout << "The value was found at index: ";
		index = searchMultValuesInIntVector(v, value);
		for (int j = 0; j < size(index); j++) {
			cout << index[j] << " ";
		}
	}
	return 0;
}
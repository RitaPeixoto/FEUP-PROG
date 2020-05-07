

#include <iostream> 
#include<vector>

using namespace std;

const size_t MAXELEM = 5;

void mystery1(int v[], size_t& nelem) {
	cout << "v[] = {";
	for (size_t i = 0; i < nelem; i++) {
		cout << v[i];
		if (i < nelem - 1)           
			cout << ", ";
	}
	cout << "}\n";
}
void mystery2(int v[], size_t& nelem, int value) {
	size_t i = 0;
	while (i < nelem) {
		if (v[i] == value) {
			for (size_t j = i; j < nelem - 1; j++)
				v[j] = v[j + 1];
			nelem--;
		}       i++;
	}
}

template<class T>

void mystery1(T v[], size_t& nelem) {
	cout << "v[] = {";
	for (size_t i = 0; i < nelem; i++) {
		cout << v[i];
		if (i < nelem - 1)
			cout << ", ";
	}
	cout << "}\n";
}

template<class T>

void mystery2(T v[], size_t& nelem, int value) {
	size_t i = 0;
	while (i < nelem) {
		if (v[i] == value) {
			for (size_t j = i; j < nelem - 1; j++)
				v[j] = v[j + 1];
			nelem--;
		}       i++;
	}
}


void mystery2(vector<int> p, int value) {
	size_t i = 0;
	while (i < p.size()) {
		if (p[i] == value) {
			for (size_t j = i; j < size(p) - 1; j++)
				p.remove(value);
			p.resize(size(p)-1);
		}       i++;
	}
}

int main() {
	int v[MAXELEM]; 
	double d[MAXELEM];
	size_t n = MAXELEM;
	vector<int>p;
	for (size_t j = 0; j < n; j++)
		p.push_back(j + 1);


	for (size_t i = 0; i < n; i++) //cria um vetor com 1,2,3,4,.... valores ate o numero n 
		v[i] = i + 1;
	for (size_t j = 0; j < n; j++)
		d[j] = j + 1;

	mystery2(p, 2);
	for (size_t i = 0; i < n; i++)
		cout << p[i];
	/*mystery1(v, n);
	mystery1(d, n);
	mystery2(v, n, 2);
	mystery2(d, n, 2);
	mystery1(v, n);   
	mystery1(d, n);*/
	return 0;
}
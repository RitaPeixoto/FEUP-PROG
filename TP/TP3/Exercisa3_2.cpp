/* Escreva um programa de teste da função desenvolvida que permita comparar o resultado por ela devolvido com o que se obtém usando a função sqrt() 
da biblioteca de C/C++. */
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double heron_sqrt(double n, double delta, double nMaxIter, double rq = 1) {
	for (nMaxIter; nMaxIter >= 0; nMaxIter--) {
		rq = (rq + n / rq) / 2;
		if (abs(n - pow(rq, 2)) <= delta)
			break;
	}

	return rq;
}

int decCases(double delta) {
	int nCases = 0;

	for (delta; delta < 1; delta *= 10) {
		nCases++;
	}

	return nCases;
}

int main() {
	double n, delta, nMaxIter, dif_precision;

	cout << "Precision: ";
	cin >> delta;
	cout << "Maximum iteration: ";
	cin >> nMaxIter;
	cout << "n? ";
	cin >> n;

	cout << heron_sqrt(n, delta, nMaxIter) << endl << sqrt(n) << endl;
	dif_precision = heron_sqrt(n, delta, nMaxIter) - sqrt(n);
	cout << "A diferenca entre o valor calculado pelo metodo de  Heron de Alexandria e o valor calculado através da funcao sqrt e: " << dif_precision << endl;
	return 0;
}
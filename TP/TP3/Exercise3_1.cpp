/*Reescreva o programa do problema 2.14  por forma a usar uma função para calcular a raíz quadrada pelo método indicado nesse problema. 
Note que esta função deve ter 2 parâmetros: a precisão e o número máximo de iterações. */
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
	double n, delta, nMaxIter;

	cout << "Precision: ";
	cin >> delta;
	cout << "Maximum iteration: ";
	cin >> nMaxIter;
	cout << "n? ";
	cin >> n;

	cout << setprecision(decCases(delta)) << fixed << heron_sqrt(n, delta, nMaxIter) << endl << sqrt(n);
	return 0;
}
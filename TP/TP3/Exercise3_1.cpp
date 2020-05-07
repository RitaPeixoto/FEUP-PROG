/*Reescreva o programa do problema 2.14  por forma a usar uma fun��o para calcular a ra�z quadrada pelo m�todo indicado nesse problema. 
Note que esta fun��o deve ter 2 par�metros: a precis�o e o n�mero m�ximo de itera��es. */
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
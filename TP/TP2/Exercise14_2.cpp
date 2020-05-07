/* Modifique o programa da al�nea anterior por forma a apresentar o resultado com o mesmo n�mero de casas decimais usadas na especifica��o do valor 
de delta (NOVO - exemplo: se delta tiver o valor 0.001, o resultado deve ser apresentado com 3 casas decimais e se tiver o valor 0.000001, o resultado 
deve ser apresentado com 6 casas decimais); para isso dever� encontrar um algoritmo para determinar esse n�mero de casas decimais. Mostre tamb�m o valor
retornado pela fun��o sqrt() da biblioteca de C e compare os valores retornados por esta fun��o e pelo algoritmo de Heron. 
 */

#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;



double heron_sqrt(double n, double delta, double nMaxIter, double rq = 1) { // calculo da raiz quadrada
	for (nMaxIter; nMaxIter >= 0; nMaxIter--) {
		rq = (rq + n / rq) / 2;
		if (abs(n - pow(rq, 2)) <= delta)
			break;
	}

	return rq;
}

int decCases(double delta) { // determina o numero de casas decimais de delta
	int nCases = 0;

	for (delta; delta < 1; delta *= 10) {
		nCases++;
	}

	return nCases;
}

int main() { //fun�ao main
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
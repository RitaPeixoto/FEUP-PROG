/*Série que dá o valor da constante matemática e: */


#include<iostream>
#include<cmath>

using namespace std;

int main() {
	int numero, denominador = 1;
	float result = 1, term =1;

	cout << "Insira o numero de termos que pretende: " << endl;
	cin >> numero;

	for (int iteration = 1; iteration <= numero; iteration ++) {
		term = term / iteration;  // 1*term
		result += term;
		denominador += 2;
	}

	cout << "O valor de e e:  " << result << endl;

	return 0;
}
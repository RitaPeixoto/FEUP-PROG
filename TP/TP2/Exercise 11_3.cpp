/*Série que dá o valor de e-x  (com x real positivo previamente definido): 
     (Sugestão: calcule cada termo a partir do termo imediatamente anterior.) */

#include<iostream>
#include<cmath>

using namespace std;
int main() {
	int numero,denominador=1;
	float x, term =1, result=1;

	cout << "Insira o numero de termos que pretende: " << endl;
	cin >> numero; 
	cout << "Insira o valor de x " << endl;
	cin >> x;

	for (int iteration = 1; iteration <= numero; iteration++) {
		term = pow(-1, iteration) * x * term / iteration;
		result += term;
	}

	cout << "O valor de e: " << endl;



	return 0;
}
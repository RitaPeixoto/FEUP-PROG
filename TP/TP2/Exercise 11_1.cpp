/*Escreva instruções for para calcular a soma dos primeiros n termos (com n inteiro previamente definido) de cada uma das séries seguintes: 
a) Série que dá o valor da constante matemática pi*/

#include<iostream>
#include <cmath>
using namespace std;

int main() {
	int numero, denominador = 1;
	float result = 0;

	cout << "Insira o numero de termos que pretende: "<<endl;
	cin >> numero;
	for (int iteration = 0; iteration <= numero; iteration++) {
		result += pow(-1, iteration)*4.0 / denominador;
	}
	cout << "O valor de pi e:  " << result << endl;

	return 0; 
}


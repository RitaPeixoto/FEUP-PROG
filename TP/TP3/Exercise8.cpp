/*O algoritmo de Euclides para determinar o máximo divisor comum (mdc) entre 2 números, m e n, pode ser definido recursivamente da seguinte forma: 
o se n for divisor de m, o mdc(m,n) é n  o caso contrário, o mdc(m,n) é o mdc(n, resto da divisão de m por n) Escreva uma função recursiva que 
determine o máximo divisor comum de 2 números que lhe são passados como parâmetros. Escreva um programa de teste dessa função. */

#include<iostream>

using namespace std;

int mdc(int m, int n) {

	if (m == 0) {
		return n;
	}
	return mdc(n%m, m);
}

int main() {
	int m, n;
	cout << "Insert two numbers:" << endl;
	cin >> m >> n;

	cout << "The greatest common divisor between these two numbers is: " << mdc(m, n) << endl;
	return 0;
}



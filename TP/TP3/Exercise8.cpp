/*O algoritmo de Euclides para determinar o m�ximo divisor comum (mdc) entre 2 n�meros, m e n, pode ser definido recursivamente da seguinte forma: 
o se n for divisor de m, o mdc(m,n) � n  o caso contr�rio, o mdc(m,n) � o mdc(n, resto da divis�o de m por n) Escreva uma fun��o recursiva que 
determine o m�ximo divisor comum de 2 n�meros que lhe s�o passados como par�metros. Escreva um programa de teste dessa fun��o. */

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



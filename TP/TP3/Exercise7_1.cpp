/*Escreva uma fun��o, factorial_ite(int n),  que determine, de forma iterativa, o factorial de um n�mero. Declare a vari�vel que vai conter o resultado 
como sendo do tipo long. Comece por determinar qual o maior inteiro que pode ser representado numa vari�vel desse tipo e qual o maior n�mero cujo factorial
� inferior esse inteiro. Nota: existe uma constante, LONG_MAX, definida em <climits> que cont�m o valor do maior inteiro represent�vel numa vari�vel do tipo 
long. */
#include<iostream>
#include<climits>
using namespace std;
long factorial_ite(int n) {
	int fact=1;
	for (unsigned i = n ; i >=2; i--) {
		fact = fact * i;
													// FALTA DETERMINAR O MAIOR NUMERO CUJO FATORIAL E REPRESENTAVEL LONG (12)
	}
	return fact;
}

int max_factorial() {
	long l;
	for (int i = 0; true ; i++) {
		if (factorial_ite(i) < 0)
			return i - 1;
	}
}

int main() {
	int n = max_factorial();
	cout << "max factorial: " << n << "!=" << factorial_ite(n) << endl;

	return 0;
	int number;
	long lon = LONG_MAX;
	cout << "Insert a number: " << endl;
	cin >> number;

	cout<< factorial_ite(number)<<endl;

	cout << lon;
}
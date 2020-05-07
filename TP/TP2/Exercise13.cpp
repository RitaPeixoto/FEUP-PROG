/*Escreva um programa que leia um número inteiro e o decomponha em factores (exemplo: 20=2x2x5). */
#include <cmath>
#include <iostream>
using namespace std;


bool prime(int n) {

	double raiz = (int)sqrt(n);
	bool primo = true;

	for (int i = 2; i <= raiz; i++) {

		if ((n % i == 0) && (n != i)) {
			primo = false;
		}

	}
	return primo;
}

int main() {
	int n;

	cout << "Escreva um numero inteiro: ";
	cin >> n;

	if (prime(n)) {

		cout << n << "=" << n;
	}
	else {
		cout << n << " = ";
		while (n != 1) {
			for (int fator = 2; fator <= n; fator++) {
				if (prime(fator)) {
					if (n%fator == 0) {
						n = n / fator;
						if (n == 1) {
							cout << fator << endl;
						}
						else {
							cout << fator << "x";
						}
						break;
					}
				}
			}


		}
	}
	return 0;
}


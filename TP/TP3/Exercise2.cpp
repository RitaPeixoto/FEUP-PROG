/*Reescreva o programa do problema 2.6 (determina��o de n�meros primos) por forma a usar uma fun��o isPrime() que determina se o n�mero que lhe � passado 
como argumento � ou n�o primo. Escolha tipos adequados para o par�metro e para o valor de retorno da fun��o.  */
#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int number) {
	for (int i = 0; i <= (int)pow(number, 0.5); i++) {
		if (number % i == 0)
			return false;
	}

	return true;
}


int main() {
	int n;

	cout << "Insert a number: ";
	cin >> n;

	if (isPrime(n)) {
		cout << "The number is prime.";
	}

	else
		cout << "The number is not prime.";

	return 0;
}
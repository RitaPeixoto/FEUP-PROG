/*Reescreva o programa do problema 2.6 (determinação de números primos) por forma a usar uma função isPrime() que determina se o número que lhe é passado 
como argumento é ou não primo. Escolha tipos adequados para o parâmetro e para o valor de retorno da função.  */
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
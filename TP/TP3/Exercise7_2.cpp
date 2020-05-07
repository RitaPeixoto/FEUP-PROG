/*Escreva uma função, factorial_rec(int n),  que determine, de forma recursiva, o factorial de um número*/

#include<iostream>

using namespace std;

int factorial_rec(int n) {
	if (n == 1 || n == 0) {
		return 1;
	}

	else {
		unsigned long fact = 1;
		fact = n * factorial_rec(n - 1);
			return fact;

	}
}

int main() {
	int number;
	cout << "Insert a number: " << endl;
	cin >> number;

	cout << number << "!= "<<factorial_rec(number) << endl;

	return 0;
}
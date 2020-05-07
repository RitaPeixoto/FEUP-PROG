/* Escreva um programa que leia 3 números e determine o maior e o menor desses números*/

#include <iostream>

using namespace std;

int main() {
	double a, b, c;


	cout << "Insira 3 numeros" << endl;
	cin >> a >> b >> c;
	
	if ((a < b) && (c < b)) {
		cout << b << " e o maior dos numeros inseridos" << endl;
	}
	else if ((a > b) && (a > c)) {
		cout << a << " e o maior dos numeros inseridos" << endl;
	}
	else {
		cout << c << " e o maior dos numeros inseridos" << endl;
	}

	if ((a > b) && (c > b)) {
		cout << b << " e o menor dos numeros inseridos" << endl;
	}
	else if ((a < b) && (a < c)) {
		cout << a << " e o menor dos numeros inseridos" << endl;
	}
	else {
		cout << c << " e o menor dos numeros inseridos" << endl;
	}


	system("pause");
	return 0; 

}
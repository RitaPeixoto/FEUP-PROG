/* Escreva um programa que leia 3 números e os escreva por ordem decrescente de valor. */


#include <iostream>
using namespace std;

int main() {
	double a, b, c;
	double max,medio, min;

	cout << "Insira 3 numeros" << endl;
	cin >> a >> b >> c;

	if ((a < b) && (c < b)) {
		max = b;
	}
	else if ((a > b) && (a > c)) {
		max = a; 
	}
	else {
		max = c;
	}


	if ((a > b) && (c > b)) {
		min = b;
	}
	else if ((a < b) && (a < c)) {
		min = a;
	}
	else {
		min = c; 
	}


	if ((max == a && min == b) || (max == b && min == a)) {
		medio = c;
	}
	else if ((max == a && min == c) || (max == c && min == a)){
		medio = b;
	}
	else {
		medio = c;
	}

	cout << "A ordem descrescente dos numeros e " << max << " "<< medio << " "  << min << endl;

	system("pause");
	return 0;
}
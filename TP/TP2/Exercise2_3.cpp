/*Escreva um programa que leia três valores positivos do tipo double, e determine se esses valores poderiam representar as medidas dos lados 
de um triângulo (nota: não é possível construir um triângulo se a soma do comprimento dos dois lados mais pequenos for inferior ou igual ao 
comprimento do lado maior).*/


#include<iostream>
using namespace std;

int main() {
	double a, b, c;

	cout << "Insira os valores dos lados do triangulo que pretende construir " << endl;
	cin >> a >> b >> c;



	if ((a > b) && (a > c)) {
		if ((b + c) <= a) {
			cout << "Nao e possivel construir um triangulo" << endl;
		}
	}
	else if ((a < b) && (b > c)) {
		if ((a + c) <= b) {
			cout << "Nao e possivel construir um triangulo" << endl;
		}
	}
	else if ((a < c) && (c > b)) {
		if ((a + b) <= c) {
			cout << "Nao e possivel construir um triangulo" << endl;
		}
	}
	else {
		cout << "E possivel construir um triangulo" << endl;
	}





	system("pause");
	return 0;

}
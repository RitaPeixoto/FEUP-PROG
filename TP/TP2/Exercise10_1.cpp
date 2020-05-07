/*Uma capicua é um número ou um texto que se lê da mesma maneira de trás para a frente e da frente para trás.
Por exemplo, os seguintes números são capicuas: 12321, 555, 45554 e 11611.  a) Escreva um programa que leia um inteiro de 3 dígitos 
e determine se é ou não uma capicua (sugestão: use os operadores de divisão e módulo para separar o inteiro nos seus dígitos). */

#include <iostream>

using namespace std;

int main() {
	int num, alg_3,alg_2,alg_1,n;

	cout << "Insira um numero" << endl;
	cin >> num;

	alg_1 = num / 100;
	alg_2 =(num-alg_1*100)/10;
	alg_3 = (num - alg_1 * 100 - alg_2 * 10);

	n = alg_3 * 100 + alg_2 * 10 + alg_1;
	if (n == num) {
		cout << "E uma capicua." << endl;
	}
	else {
		cout << "Nao e uma capicua" << endl;
	}
	system("pause");
	return 0;
}
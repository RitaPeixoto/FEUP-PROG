/*Uma capicua � um n�mero ou um texto que se l� da mesma maneira de tr�s para a frente e da frente para tr�s.
Por exemplo, os seguintes n�meros s�o capicuas: 12321, 555, 45554 e 11611.  a) Escreva um programa que leia um inteiro de 3 d�gitos 
e determine se � ou n�o uma capicua (sugest�o: use os operadores de divis�o e m�dulo para separar o inteiro nos seus d�gitos). */

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
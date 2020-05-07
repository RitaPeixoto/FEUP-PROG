/*Escreva um programa que leia uma sequência de números inteiros, e determine e escreva a soma, a média, o menor e o maior dos números, 
 sendo o comprimento da sequência indicado previamente, pelo utilizador*/

#include <iostream>
#include<iomanip>
using namespace std;

int main() {
	const unsigned RESULT_PRECISION = 2;
	int menor, maior, num, sum = 0, contador = 0, size;
	double media;
	cout << "Indique o tamanho da sequencia: " << endl;
	cin >> size;

	while (contador != size) {
		cout << " Insira um numero inteiro: " << endl;
		cin >> num;
		sum = sum + num;
		if (contador == 0) {
			menor = num;
			maior = num;
		}
		else {
			if (num < menor) {
				menor = num;
			}
			else if (num > maior) {
				maior = num;
			}

		}
		contador++;
		
	}

	media = sum / (double)(contador);
	cout << endl;
	cout << "A soma e  " << sum << endl;
	cout << "A media e " << fixed << setprecision(RESULT_PRECISION) << media << endl;
	cout << "O maior numero e " << maior << endl;
	cout << "O menor numero e " << menor << endl;
	cout << "O comprimento da sequencia e " << contador << endl;

	system("pause");
	return 0;

}
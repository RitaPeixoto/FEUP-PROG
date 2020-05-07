/*Escreva um programa que leia uma sequência de números inteiros, e determine e escreva a soma, a média, o menor e o maior dos números
sendo o fim da sequência indicado quando o utilizador teclar end of input (CTRL-Z em Windows; CTRL-D em Linux)
 */

#include <iostream>
#include<iomanip>
									//Nao esta feito falta adaptar para o ctrl + Z
using namespace std;

int main() {
	const unsigned RESULT_PRECISION = 2;
	int menor, maior, num, sum = 0, contador = 0;
	double media;
	bool AnotherNumber = true;

	cout << " Insira um numero inteiro (CTRL + Z  para TERMINAR A SEQUENCIA): " << endl;
	cin >> num;

	
	while (AnotherNumber) {
		if (cin.fail()) {
			if (cin.eof()) {
				AnotherNumber = false;
			}
		}

		else {
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
			cout << " Insira o numero seguinte (CTRL+ Z para TERMINAR a sequencia): " << endl;
			cin >> num;
		}
	}

	media = sum / (double)(contador);
	cout << "A soma e  " << sum << endl;
	cout << "A media e " << fixed << setprecision(RESULT_PRECISION) << media << endl;
	cout << "O maior numero e " << maior << endl;
	cout << "O menor numero e " << menor << endl;
	cout << "O comprimento da sequencia e " << contador << endl;



	return 0;
}
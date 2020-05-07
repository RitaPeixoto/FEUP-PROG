/*Escreva um programa que leia uma sequ�ncia de n�meros inteiros, e determine e escreva a soma, a m�dia, o menor e o maior dos n�meros, 
a) sendo o fim da sequ�ncia indicado pelo valor 0 (que j� n�o faz parte da sequ�ncia); no final, o programa deve indicar o comprimento da sequ�ncia. */

#include<iostream>
#include<iomanip>
using namespace std;

int main() {
	const unsigned RESULT_PRECISION = 2;
	int menor , maior, num, sum = 0, contador = 0;
	double media;
	
	cout << " Insira um numero inteiro(0 para TERMINAR A SEQUENCIA)" << endl;
	cin >> num;
	while (num != 0) {
		
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
		cout << " Insira o numero seguinte (0 para TERMINAR a sequencia): " << endl;
		cin >> num;
	}

	media = sum / (double)(contador);
	cout << "A soma e  " << sum << endl;
	cout << "A media e " << fixed << setprecision(RESULT_PRECISION) <<media << endl;
	cout << "O maior numero e " << maior << endl;
	cout << "O menor numero e " << menor << endl;
	cout << "O comprimento da sequencia e " << contador << endl;

	system("pause");
	return 0;

}
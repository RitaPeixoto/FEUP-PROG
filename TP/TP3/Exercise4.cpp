/*Na linguagem C/C++, não existe nenhuma função que permita arredondar um número decimal para um número de casas decimais especificado. No entanto, 
é possível consegui-lo recorrendo à função floor. Por exemplo, para arredondar o valor de x para as centésimas (isto é, para 2 casas decimais), pode-se
executar a instrução: y = floor(x * 100 + 0.5) / 100; 
 
Escreva uma função cujo protótipo seja  double round(double x, unsigned n) que arredonde um número em vírgula flutuante, x, para um dado número de casas
decimais, n, retornando o valor arredondado.  Desenvolva um programa de teste dessa função que pergunte ao utilizador os valores de x e n e imprima o valor
de round(x,n). */

#include <iostream>
#include<cmath>
using namespace std;

double round(double x, unsigned n) {
	return floor(x * pow(10, n) + 0.5) / pow(10, n);
}

int main() {
	double number;
	int precision; 
	cout << "Insert a number and a precision: " << endl;
	cin >> number >> precision;
	
	cout << "The rounded value of the number inserted is : " << round(number, precision) << endl;


	return 0;
}
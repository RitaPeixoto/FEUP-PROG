/*Na linguagem C/C++, n�o existe nenhuma fun��o que permita arredondar um n�mero decimal para um n�mero de casas decimais especificado. No entanto, 
� poss�vel consegui-lo recorrendo � fun��o floor. Por exemplo, para arredondar o valor de x para as cent�simas (isto �, para 2 casas decimais), pode-se
executar a instru��o: y = floor(x * 100 + 0.5) / 100; 
 
Escreva uma fun��o cujo prot�tipo seja  double round(double x, unsigned n) que arredonde um n�mero em v�rgula flutuante, x, para um dado n�mero de casas
decimais, n, retornando o valor arredondado.  Desenvolva um programa de teste dessa fun��o que pergunte ao utilizador os valores de x e n e imprima o valor
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
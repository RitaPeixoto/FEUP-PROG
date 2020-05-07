/*Escreva um programa para determinar as raízes da equação quadrática ax2+bx+c=0, sendo os coeficientes a, b e c fornecidos pelo utilizador.
O programa deve indicar se a equação tem 2 raízes reais diferentes, 2 raízes reais iguais ou 2 raízes complexas conjugadas, e os respectivos
valores (com 3 casas decimais). */

#include <iostream>
#include <cmath>
#include <iomanip> 
using namespace std;
int main() {

	double a, b, c;
	double binomio;
	double sol_a, sol_b;
	const unsigned int RESULT_PRECISION = 3;
	cout << " Insira os valores de a,b e c" << endl;
	cin >> a >> b >> c;

	binomio = b * b - 4*a*c;

	if (binomio > 0) {
		sol_a = (-b - sqrt(binomio) / (2 * a));
		sol_b = (-b + sqrt(binomio) / (2 * a));
		cout << fixed << setprecision(RESULT_PRECISION) << "A equacao tem 2 raizes reais :" << sol_a << ", " << sol_b << endl;
	}

	else if (binomio == 0) {
		sol_a = (-b / 2 * a);
		cout << fixed << setprecision(RESULT_PRECISION) << "A equacao tem apenas uma raiz real :" << sol_a << endl;
	}
	else if (binomio < 0){
	sol_a = (-b / (2 * a));
	sol_b = (sqrt(-binomio)/(2*a));
	cout << fixed << setprecision(RESULT_PRECISION) << "A equacao tem duas raizes complexas: " << sol_a << " + " << sol_b << "i e " << sol_a << " - " << sol_b << " i\n";
	}

	else {
		cout << " A equacao nao e valida\n";
	}

	system("pause");
	return 0;
}
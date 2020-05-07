/*Escreva um programa que apresente no ecrã uma tabela dos senos, cosenos e tangentes dos ângulos compreendidos 
entre 0 e 90 graus (considera-se que os extremos estão incluídos), com intervalos de 15 graus, como se ilustra a seguir
(notar o caso particular da última linha, correspondente ao ângulo de 90 graus): */

#define _USE_MATH_DEFINES
#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main() {
	double rad, cosseno, seno, tangente;
	const unsigned int RESULT_PRECISION = 6;


	cout << " ang   sen      cos     tan " << endl;

	for (int i = 0; i < 91; i = i + 15) {
		rad = (i* M_PI) / 180;
		cosseno = cos(rad);
		seno = sin(rad);
		tangente = tan(rad);
		if (i == 0) {
			cout << "   " << i << "  " << fixed << setprecision(RESULT_PRECISION) << seno << "  " << cosseno << "  "<< tangente << endl;
		}
		else if (i == 90) {
			cout << "  " << i << "  " << fixed << setprecision(RESULT_PRECISION) << seno << "  " << cosseno << "  " << "infinito" << endl;
		}
		else {
			cout << "  " << i << "  " << fixed << setprecision(RESULT_PRECISION) << seno << "  " << cosseno << "  " << tangente << endl;

		}
	}




	system("pause");
	return 0;
}

/*/*cout << setw(10) << "ang" << setw(10) << "sen" << setw(10) << "cos" << setw(10) << "tan" << endl;

	for (int ang = 0; ang <= 90; ang += 15) {
		cout << setw(10) << ang << setw(10) << sin(ang * pi / 180.0) << setw(10) << cos(ang * pi / 180.0) << setw(10) << tan(ang * pi / 180.0) << endl;
	}*/*/
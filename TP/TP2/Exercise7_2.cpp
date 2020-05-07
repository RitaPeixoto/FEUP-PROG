/*Altere o programa que desenvolveu na alínea anterior por forma a que os limites do intervalo e o incremento do valor dos ângulos 
constantes da tabela possa ser especificado pelo utilizador (por exemplo, se a gama for [0..1] e o incremento for de 0.1 graus, seria gerada a
tabela para os ângulos de 0, 0.1, 0.2, …, e 1 grau).  
 */

#define _USE_MATH_DEFINES
#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main() {
	double rad, cosseno, seno, tangente;
	double incr, start, stop;
	const unsigned int RESULT_PRECISION = 6;

	cout << "Insira o valor minimo do seu intervalo" << endl;
	cin >> start;
	cout << "Insira o valor maximo do seu intervalo" << endl;
	cin >> stop;
	cout << "Insira o valor do incremento que pretende " << endl;
	cin >> incr;

	cout << "     ang       sen       cos       tan " << endl;

	for (start; start<=stop; start = start + incr) {
		rad = (start* M_PI) / 180;
		cosseno = cos(rad);
		seno = sin(rad);
		tangente = tan(rad);
		if (start == 90) {
			cout<< "  " << fixed << setprecision(RESULT_PRECISION)  << start << "  " << seno << "  " << cosseno <<  "  infinito" << endl;
		}
		else if (start < 10) {
			cout << "   " << fixed << setprecision(RESULT_PRECISION) << start << "  " << seno << "  " << cosseno << "  " << tangente << endl;
		}
		else {
			cout<<"  "<< fixed << setprecision(RESULT_PRECISION)  << start << "  " << seno << "  " << cosseno << "  " << tangente << endl;

		}
	}

	system("pause");
	return 0;
}
/*A massa de uma esfera é dada pela expressão M = 4/3(r3
) em que M, e r representam, respectivamente, a
massa da esfera, a massa específica do material de que ela é feita e o seu raio. Escreva um programa que, dados os
valores de e r, determine o valor de M. Deve ser dada ao utilizador indicação das unidades em que devem ser
introduzidos os dados e em que é apresentado o resultado, respectivamente, Kg/m3
, m e Kg para , r e M. Use uma
constante para representar o valor de . */

#include <iostream>
using namespace std;

int main()
{
	double massa, r, M, pi = 3.14159265359, n= 4.0/3;


	cout << "Indique qual a massa da esfera em kilogramas" << endl;
	cin >> massa;
	cout << "Indique qual o raio da esfera em metros" << endl;
	cin >> r;

	M = (n*pi*r*r*r*massa);

	cout << "A massa da esfera e : " << M << " em kg" << endl;


	system("pause");
	return 0;

}
/*A solu��o de um sistema de equa��es lineares a 2 inc�gnitas (x e y)  a�x + b�y = c  d�x + e�y = f � dada por  x = (c�e - b�f) / (a�e - b�d)  
y = (a�f - c�d) / (a�e - b�d) Escreva um programa que leia os valores de a, b, c, d, e e f e determine a solu��o do sistema de equa��es 
correspondente. Considere apenas situa��es em que a solu��o � poss�vel e determinada. */

#include <iostream>

using namespace std;

int main()
{
	float a, b, c, d, e, f;
	float x, y;

	cout << "Insira o valor de a, b, c, d, e, f\n";
	cin >> a >> b >> c >> d >> e >> f;

	x = (c*e - b * f) / (a*e - b * d);
	y = (a*f - c * d) / (a*e - b * d);

	cout << "O valor de x e " << x << endl;
	cout << "O valor de y e " << y << endl;

	system("pause");
	return 0;

}
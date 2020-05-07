/*A solução de um sistema de equações lineares a 2 incógnitas (x e y)  a·x + b·y = c  d·x + e·y = f é dada por  x = (c·e - b·f) / (a·e - b·d)  
y = (a·f - c·d) / (a·e - b·d) Escreva um programa que leia os valores de a, b, c, d, e e f e determine a solução do sistema de equações 
correspondente. Considere apenas situações em que a solução é possível e determinada. */

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
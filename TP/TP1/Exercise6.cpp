/* A área de um triângulo pode ser determinada pela fórmula de Heron ) )()(( c sbsassárea   em que s, a, b e c representam, 
respectivamente o semi-perímetro e os comprimentos dos 3 lados. Escreva um programa que leia as coordenadas dos vértices de um triângulo 
e calcule a sua área, usando esta fórmula. Recorda-se que a distância entre dois pontos de coordenadas 
(x1,y1) e (x2,y2) é dada por 2 2 ) 12()12( yyxxdistância */


#include <iostream>
#include <cmath>

using namespace std;
int main()
{
	double x1, x2, x3, y1, y2, y3;
	double a, b, c,s, area;


	cout << "Insira as coordenadas do primeiro vertice" << endl;
	cin >> x1 >> y1;
	cout << "Insira as coordenadas do segundo vertice" << endl;
	cin >> x2 >> y2;
	cout << "Insira as coordenadas do terceiro vertice" << endl;
	cin >> x3 >> y3;
	
	

	a = ((x2 - x1)*(x2 - x1)) + ((y2 - y1)*(y2 - y1));
	a = sqrt(a);
	b = ((x3 - x2)*(x3 - x2)) + ((y3 - y2)*(y3 - y2));
	b = sqrt(b);
	c = ((x3 - x1)*(x3 - x1)) + ((y3 - y1)*(y3 - y1));
	c = sqrt(c);

	s = (a + b + c) / 2;

	area = sqrt(s*(s - a)*(s - b)*(s - c));

	cout << "A area deste triangulo e " << area << endl;

	system("pause");
	return 0;


}
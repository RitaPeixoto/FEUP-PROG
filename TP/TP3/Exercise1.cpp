/*Reescreva o programa do problema 1.6 (cálculo da área de um triângulo pela fórmula de Heron) por forma a usar as seguintes funções: o area(double x1, 
double y1, double x2, double y2, double x3, double y3) para calcular a área de um triângulo cujos vértices têm coordenadas (x1,y1), (x2,y2) e (x3,y3); o
distance(double x1, double y1, double x2, double y2) para calcular a distância entre dois pontos cujas coordenadas são (x1,y1) e (x2,y2). */


#include <iostream>
#include <cmath>
using namespace std;

double distance(double x1, double y1, double x2, double y2) {
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	
}
double area(double x1, double y1, double x2, double y2, double x3, double y3) {
	double a = distance(x1, y1, x2, y2), b = distance(x2, y2, x3, y3), c = distance(x1, y1, x3, y3), s = (a + b + c) / 2;

	return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main()
{
	double x1, x2, x3, y1, y2, y3;
	cout << "Insira as coordenadas do primeiro vertice" << endl;
	cin >> x1 >> y1;
	cout << "Insira as coordenadas do segundo vertice" << endl;
	cin >> x2 >> y2;
	cout << "Insira as coordenadas do terceiro vertice" << endl;
	cin >> x3 >> y3;

	cout << "A area deste triangulo e " << area(x1,y1,x2,y2,x3,y3) << endl;

	
	return 0;


}
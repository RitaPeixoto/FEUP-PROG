/*Resolver o problema 1.4 (solu��o de um sistema de equa��es lineares a 2 inc�gnitas), por forma a que quando o sistema for imposs�vel 
ou indeterminado seja apresentada uma mensagem adequada no ecr�: "sistema imposs�vel" ou "sistema indeterminado"*/

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

	if ((c*e - b * f) == 0 && (a*e - b * d)==0) {
		cout << "O sistema e possivel e indeterminado." << endl;
	}
	else if ((a*f - c * d) == 0 && (a*e - b * d)==0) {
		cout << "O sistema e possivel e indeterminado." << endl;
	}
	else if ((a*e - b * d) == 0) {
		cout << "O sistema e impossivel." << endl;
	}
	else {
		cout << "O valor de x e " << x << endl;
		cout << "O valor de y e " << y << endl;
	}

	system("pause");
	return 0;

}
/* Escreva um programa que leia do teclado 3 números inteiros e apresente no ecrã a sua média e a diferença de cada um
dos números em relação à média. O diálogo deve aparecer no ecrã com o seguinte aspecto:
A ? 23
B ? 47
C ? 30
media = 33.333
A-media = -10.333
B-media = 13.667
C-media = -3.333
Experimente usar diferentes tipos de variáveis para guardar os valores de A, B, C e media. Varie os valores
introduzidos e o número de casas decimais usadas para mostrar os resultados. Interprete os resultados. */

#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	float media, amedia, bmedia, cmedia;

	cout << "A ? ";
	cin >> a;
	cout << "B ? ";
	cin >> b;
	cout << "C ? ";
	cin >> c;
	

	media = (a + b + c) /3.0;
	amedia = a - media;
	bmedia = b - media;
	cmedia = c - media;
	
	cout << " media = " << media << endl;
	cout << " A-media = " << amedia << endl;
	cout << " B-media = " << bmedia << endl;
	cout << " C-media = " << cmedia << endl;




	system("pause");
	return 0;

}
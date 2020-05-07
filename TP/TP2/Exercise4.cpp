/*O custo do transporte de uma certa mercadoria é determinado, em função do peso da mesma, do seguinte modo: se o peso  for inferior a 500 
gramas o custo é igual a 5 euros; se o peso estiver compreendido entre 500 gramas e 1000 gramas, inclusivé, o custo é igual a 5 euros mais 
1.5 euros por cada adicional de 100 gramas ou fracção, acima de 500 gramas; se o peso  for superior a 1000 gramas, o custo é 12.5 euros mais 
5 euros por cada adicional de 250 gramas ou fracção, acima de 1000 gramas. Escreva um programa que dado o peso de uma determinada mercadoria 
determine o custo do seu transporte. */

#include <iostream>
using namespace std;

int main() {
	double peso,extra, custo, difference;

	cout << "Insira o peso da mercadoria" << endl;
	cin >> peso;


	if (peso < 500) {
		custo = 5;
	}
	else if (500 <= peso && peso <= 1000) {
		difference = (int)(peso - 500) / 100;
		if ((int)(peso - 500) % 100 == 0) {
			custo = 5 + 1.5*difference;
		}
		else {
			custo = 5 + 1.5*difference + 1.5;
		}

	}
	else if (peso > 1000) {
		difference = ((int)(peso - 1000) / 250);
		if ((int)(peso - 1000) % 250 == 0) {
			custo = 12.5 + difference * 5;
		}
		else {
			custo = 12.5 + difference * 5 + 5;
		}
		
	}
	
	cout << "O custo do transporte da sua mercadoria e de " << custo << " euros." << endl; 
	system("pause");
	return 0;
}
/*custo = 5;
extra = (peso - 500);
while (extra > 0) {
	custo += 1.5;
	extra -= 100;*/

/*custo = 12.5;
		extra = peso - 1000;
		while (extra > 0)
		{
			custo += 5;
			extra -= 250;*/
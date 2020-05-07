/*Escreva um programa que escreva todos os números primos inferiores a 10000. */



#include<iostream>
#include<cmath>

using namespace std;
int main() {
	int contador = 0;

	for (int n = 2; n < 10000; n++) {
		bool primo = true;
		for (int div = 2; div <= (int)sqrt(n); div++) {   //começa em 2 ou seja nao conta o 1
			if ((n%div == 0)) {  // se o numero for divisivel pelo o outro  e nao forem o mesmo numero entao o numero nao e primo
				primo = false;
				break;
			}
		}
		if (primo == true) { // se o numero for primo
			cout << n << " e numero primo " << contador << endl;
			contador++;
		}
	}
	system("pause");
	return 0;
}
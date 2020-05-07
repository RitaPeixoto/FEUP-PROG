/*Escreva um programa que escreva os 100 primeiros números primos. */


#include<iostream>
#include<cmath>

using namespace std;

int main() {
	int n = 2, contador = 0;
	
	while (contador != 100) {
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
		n = n + 1;
	}
		
	
		
	system("pause");
	return 0;
}
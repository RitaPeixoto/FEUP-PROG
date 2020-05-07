/*Um número n é primo se apenas for divisível pela unidade e por si próprio. 
a) Escreva um programa que leia um número e determine se é primo ou não. Note que não é necessário testar todos os divisores
no intervalo [2..n[, basta testar até ao inteiro inferior à raíz quadrada de n. */

#include<iostream>
#include<cmath>

using namespace std;
int main() {
	int n;
	int root;
	cout << "Insira um numero" << endl;
	cin >> n;

	root =(int) sqrt(n);

		if (n == 1) {
			cout << "Nao e um numero primo" << endl;
		}
		else {
			bool primo = true;
			for (int div = 2; div <= (int)sqrt(n); div++) {   //começa em 2 ou seja nao conta o 1
				if ((n%div == 0)) {  // se o numero for divisivel pelo o outro  e nao forem o mesmo numero entao o numero nao e primo
					primo = false;
					break;
				}

			}
			if (primo == true) { // se o numero for primo
				cout << n << " e numero primo " << endl;
			}
			else {
				cout << n << " nao e um numero primo" << endl;

			}
		}

	system("pause");
	return 0;
}
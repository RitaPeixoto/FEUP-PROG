/*Um n�mero n � primo se apenas for divis�vel pela unidade e por si pr�prio. 
a) Escreva um programa que leia um n�mero e determine se � primo ou n�o. Note que n�o � necess�rio testar todos os divisores
no intervalo [2..n[, basta testar at� ao inteiro inferior � ra�z quadrada de n. */

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
			for (int div = 2; div <= (int)sqrt(n); div++) {   //come�a em 2 ou seja nao conta o 1
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
/* Escreva um programa que leia do teclado uma letra e mostre o respectivo código ASCII.*/

#include <iostream>
using namespace std;
int main()
{
	char a;


	cout << "Insira uma letra "; 
	cin >> a;
	cout << "A  letra inserida em codigo ASCII e "<<(int)a << endl;



	system("pause");
	return 0;
}
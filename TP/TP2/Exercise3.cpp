/*Escreva um programa que simule uma calculadora, isto é, que leia do teclado dois números e um carácter (+,,* ou  /) que indica uma 
operação aritmética, no formato "número operação número", e que apresente o resultado da operação indicada.*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {

	const unsigned RESULT_PRECISION = 3;
	double a, b, result;
	char operation;
	bool validOperation = true;
	cout << " Insira a expressao que pretende calcular" << endl;
	cin >> a >> operation >> b;

	switch (operation)
	{
	case '+':
		result = a + b;
		break;
	case '-':
		result = a - b;
		break;
	case '*':
		result = a * b;
		break;
	case '/':
		if (b != 0) {
			result = a / b;
		}
		/*else {
			validOperation = false;*/
		}
		break;
	default:
		validOperation = false;
	}

	if (validOperation)
	{
		cout << a << ' ' << operation << ' ' << b << " =";
		cout << fixed << setprecision(RESULT_PRECISION) << result << endl;
	}
	else
		cerr << "Invalid operation !\n";


	system("pause");
	return 0;

}
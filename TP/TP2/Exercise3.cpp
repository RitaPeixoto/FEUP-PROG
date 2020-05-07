/*Escreva um programa que simule uma calculadora, isto �, que leia do teclado dois n�meros e um car�cter (+,,* ou  /) que indica uma 
opera��o aritm�tica, no formato "n�mero opera��o n�mero", e que apresente o resultado da opera��o indicada.*/

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
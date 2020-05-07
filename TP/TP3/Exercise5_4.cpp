/*d) Escreva funções para realizar as operações básicas (soma, subtracção, multiplicação e divisão) sobre fracções, apresentando o resultado na
forma reduzida. Escolha protótipos adequados para essas funções.
e) Escreva um programa de teste das funções desenvolvidas. */

#include <iostream>
using namespace std;

bool readFracc(int &numerator, int &denominator) {
	char op;
	cin >> numerator >> op >> denominator;
	if (cin.fail() || op != '/' || denominator == 0) {
		numerator = denominator = 0;
		return false;
	}
	return true;
}



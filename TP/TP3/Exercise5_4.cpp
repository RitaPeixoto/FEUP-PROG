/*d) Escreva fun��es para realizar as opera��es b�sicas (soma, subtrac��o, multiplica��o e divis�o) sobre frac��es, apresentando o resultado na
forma reduzida. Escolha prot�tipos adequados para essas fun��es.
e) Escreva um programa de teste das fun��es desenvolvidas. */

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



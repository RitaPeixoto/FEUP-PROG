/*A linguagem C++ n�o disp�e de vari�veis do tipo "frac��o" nem, obviamente, de operadores ou fun��es para manipular frac��es. Pretende-se desenvolver um
conjunto de fun��es que permitam manipular frac��es, representadas, por enquanto, por vari�veis independentes que representam o numerador e o denominador de
cada frac��o (adiante ser� proposto um exerc�cio em que o numerador e o denominador de uma frac��o ser�o representados numa estrutura comum). 
a) Escreva uma fun��o cujo prot�tipo �  bool readFracc(int &numerator, int &denominator) que l� do teclado uma fra��o inteira (fra��o cujo numerador e 
denominador s�o n�meros inteiros), no formato N/D (exemplo: 2/3) e actualiza as vari�veis indicadas por numerator e denominator por forma a conterem esses 
valores. O valor de retorno da fun��o deve ser true caso os valores introduzidos para o numerador e para o denominador sejam v�lidos e o separador tamb�m 
seja v�lido, isto � '/', e false no caso contr�rio. Neste �ltimo caso os valores devolvidos, do numerador e do denominador, devem ser zero. A fun��o n�o 
deve escrever nada no ecr�; qualquer mensagem indicativa dos valores a ler deve ser apresentada ao utilizador antes de invocar a fun��o. */
/* Escreva uma  fun��o cujo prot�tipo � void writeFracc(int numerator, int denominator)  que mostra no ecr� a fra��o cujo numerador e denominador 
lhe forem passados como arugumentos, no formato "numerador/denominador" (ex: 2/3). */
/*c) Escreva uma  fun��o cujo prot�tipo � void reduceFracc(int &numerator, int &denominator) que reduz a frac��o cujo numerador e denominador lhe 
s�o passados como par�metros, dividindo-os pelo seu m�ximo divisor comum. Sugest�o: para determinar o m�ximo divisor comum do numerador e do 
denominador, procure a vers�o n�o recursiva do algoritmo de Euclides e implemente-a. */
/*d) Escreva fun��es para realizar as opera��es b�sicas (soma, subtrac��o, multiplica��o e divis�o) sobre frac��es, apresentando o resultado na 
forma reduzida. Escolha prot�tipos adequados para essas fun��es.
e) Escreva um programa de teste das fun��es desenvolvidas. */
#include<iostream>
#include<cmath>
using namespace std;

bool readFracc(int &numerator, int &denominator) {
	char op;
	cin >> numerator >> op >> denominator;
	if (cin.fail() || op != '/' || denominator ==0) {
		numerator = denominator = 0;
		return false;
	}
	return true;
}

void writeFracc(int numerator, int denominator) {
		cout << numerator << '/' << denominator << endl;
}

int mdc(int numerator, int denominator) {
	int mdc,n=numerator,d=denominator, resto;
	while (d != 0) {
		resto = n % d;
		n = d;
		d = resto;
	}
	return n;
}

void reduceFracc(int &numerator, int &denominator) {
	int gcd;
	gcd=mdc(numerator, denominator);
	numerator = numerator / gcd;
	denominator = denominator / gcd;
	cout << numerator << "/" << denominator;
}
int soma(int n1, int d1, int n2, int d2) {
	int num_soma, den_soma;
	if (d1 == d2) {
		num_soma = n1 + n2;
		den_soma = d1;
	}
	else {
		den_soma = d1 * d2;
		n1 = n1 * d2;
		n2 = n2 * d1;
		num_soma = n1 + n2;
	}
	reduceFracc(num_soma, den_soma);
	return 0;
}
int subtracao(int n1, int d1, int n2, int d2) {

	int num_sub, den_sub;

	if (d1 == d2) {
		num_sub = n1 - n2;
		den_sub = d1;
	}
	else {
		den_sub = d1 * d2;
		n1 = n1 * d2;
		n2 = n2 * d1;
		num_sub = n1 - n2;
	}
	reduceFracc(num_sub, den_sub);

	return 0;
}

int divisao(int n1, int d1, int n2, int d2) {
	int num_div, den_div;

	num_div = n1 * d2;
	den_div = d1 * n2;

	reduceFracc(num_div, den_div);

	return 0;
}

int multiplicacao(int n1, int d1, int n2, int d2) {
	int num_mult, den_mult;

	num_mult = n1 * n2;
	den_mult = d1 * d2;
	reduceFracc(num_mult, den_mult);

	return 0;
}

int main() {

	int n1, d1, n2, d2;
	char operation;

	cout << "Escreva a operacao: ";
	cin >> operation;

	cout << "Escreva o primeiro operando (fracao): ";
	if (!readFracc(n1, d1)) {
		cout << "Carateres invalidos" << endl;
		return 1;
	}

	cout << "Escreva o segundo operando (fracao): ";
	if (!readFracc(n2, d2)) {
		cout << "Carateres invalidos" << endl;
		return 1;
	}

	switch (operation) {
	case '+':
		soma(n1, d1, n2, d2);
		break;
	case '-':
		subtracao(n1, d1, n2, d2);
		break;
	case '*':
		multiplicacao(n1, d1, n2, d2);
		break;
	case '/':
		divisao(n1, d1, n2, d2);
		break;
	}


	return 0;
}
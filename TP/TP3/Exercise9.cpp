/*A "regra dos trapézios" é um método numérico para calcular um valor aproximado para o integral definido. Para calcular o integral dxxf b a )
( a área sob a curva y=f(x) é dividida em n regiões, cada uma com uma largura h=(b-a)/n. A área de cada região é aproximada pela área de um trapézio.
A soma das áreas de todos os trapézios dá um valor aproximado do integral definido. A área do i-ésimo trapézio (i=1,2,…) é dada por
 )())1(( 2 ihafhiaf h   Em geral, a estimativa do integral melhora com o decréscimo de h. Escreva uma função cujo protótipo é double 
integrateTR(double f(double), double a, double b, int n), com parâmetros f ,a, b e n, anteriormente definidos, que implemente o cálculo do integral
usando este método. Escreva um programa de teste dessa função, usando valores de n iguais a 2,4,8,16,32,64 e 128, sobre as funções 
2)( xxg  com 10 ,0  ba          e           2 4)( x xh     com 2 ,2  ba .    A função h define um semi-círculo com raio 2. 
Compare a estimativa obtida com a área real do semi-círculo. */
#include<iostream>
#include<cmath>
using namespace std;
double f(double x) {
	return sqrt(4 - pow(x, 2));
}

double integrateTR(double f(double), double a, double b, int n) {
	double result = 0, h = (b - a) / n;

	for (int i = 1; i <= n; i++) {
		result += (h / 2) * (f(a + (i - 1) * h) + f(a + i * h));
	}

	return result;
}

int main() {
	double a, b;
	int n;

	cout << "Enter the a and b values and the number of intervals of the function f: ";
	cin >> a >> b >> n;
	cout << "The approximate value of the definite integral between " << a << " and " << b << " is " << integrateTR(f, a, b, n) << ".";
	return 0;
}
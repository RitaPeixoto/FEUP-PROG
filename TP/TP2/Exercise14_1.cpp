/* A ra�z quadrada de um n�mero n pode ser calculada atrav�s do seguinte algoritmo, devido a Heron de Alexandria: partindo de uma estimativa inicial do 
valor da ra�z, rq, calcular uma nova estimativa, rqn, usando a seguinte f�rmula, rqn = (rq + n / rq) / 2 ; repetir este c�lculo usando como nova estimativa
de rq o valor de rqn. O quadro seguinte ilustra a evolu��o do c�lculo da ra�z quadrada do n�mero n=20, partindo de uma estimativa inicial rq=1.  rq 
Em geral, este algoritmo converge rapidamente para uma solu��o correcta, mesmo quando a estimativa inicial � fraca. Notar que a diferen�a entre o n�mero n 
e o quadrado da ra�z de n calculada, dif, evolui rapidamente para zero, pelo que se poderia usar o valor de dif como crit�rio de paragem, isto �, terminar as
itera��es quando dif fosse inferior a um valor suficientemente pequeno, delta (por exemplo, delta=0.00001). No entanto, por uma quest�o de "seguran�a", � 
conveniente limitar o n�mero de itera��es, repetindo, nesse caso, os c�lculos at� que seja atingido um valor de dif inferior a delta ou que seja atingido um 
n�mero m�ximo de itera��es, nMaxIter.  Considerando o exemplo apresentado, se delta=0.001 e nMaxIter=3 o resultado final (rqn) seria o calculado ap�s a 3� 
itera��o pois foi atingido o n�mero m�ximo de itera��es especificado, apesar de o valor de delta ainda ser superior a 0.001; mas se delta=0.001 e nMaxIter=10,
o c�lculo terminaria ap�s a 5� itera��o pois nessa itera��o o valor absoluto de dif j� � inferior a 0.001. Escreva um programa que leia os valores de delta e
nMaxIter e que calcule a ra�z quadrada de um n�mero usando o algoritmo descrito anteriormente. Use sempre 1 como estimativa inicial de rq. */


#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;

double heron_sqrt(double n, double delta, double nMaxIter, double rq = 1) { // calculo da raiz quadrada
	for (nMaxIter; nMaxIter >= 0; nMaxIter--) {
		rq = (rq + n / rq) / 2;
		if (abs(n - pow(rq, 2)) <= delta)
			break;
	}

	return rq;
}

int main() { //fun�ao main
	double n, delta, nMaxIter;

	cout << "Precision: ";
	cin >> delta;
	cout << "Maximum iteration: ";
	cin >> nMaxIter;
	cout << "n? ";
	cin >> n;

	cout << heron_sqrt(n, delta, nMaxIter) << endl ;
	return 0;

}
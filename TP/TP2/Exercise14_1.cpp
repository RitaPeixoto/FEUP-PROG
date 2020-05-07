/* A raíz quadrada de um número n pode ser calculada através do seguinte algoritmo, devido a Heron de Alexandria: partindo de uma estimativa inicial do 
valor da raíz, rq, calcular uma nova estimativa, rqn, usando a seguinte fórmula, rqn = (rq + n / rq) / 2 ; repetir este cálculo usando como nova estimativa
de rq o valor de rqn. O quadro seguinte ilustra a evolução do cálculo da raíz quadrada do número n=20, partindo de uma estimativa inicial rq=1.  rq 
Em geral, este algoritmo converge rapidamente para uma solução correcta, mesmo quando a estimativa inicial é fraca. Notar que a diferença entre o número n 
e o quadrado da raíz de n calculada, dif, evolui rapidamente para zero, pelo que se poderia usar o valor de dif como critério de paragem, isto é, terminar as
iterações quando dif fosse inferior a um valor suficientemente pequeno, delta (por exemplo, delta=0.00001). No entanto, por uma questão de "segurança", é 
conveniente limitar o número de iterações, repetindo, nesse caso, os cálculos até que seja atingido um valor de dif inferior a delta ou que seja atingido um 
número máximo de iterações, nMaxIter.  Considerando o exemplo apresentado, se delta=0.001 e nMaxIter=3 o resultado final (rqn) seria o calculado após a 3ª 
iteração pois foi atingido o número máximo de iterações especificado, apesar de o valor de delta ainda ser superior a 0.001; mas se delta=0.001 e nMaxIter=10,
o cálculo terminaria após a 5ª iteração pois nessa iteração o valor absoluto de dif já é inferior a 0.001. Escreva um programa que leia os valores de delta e
nMaxIter e que calcule a raíz quadrada de um número usando o algoritmo descrito anteriormente. Use sempre 1 como estimativa inicial de rq. */


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

int main() { //funçao main
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
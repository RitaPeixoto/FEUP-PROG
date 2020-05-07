/*Escreva um programa para determinar e escrever o montante que um depositante poderá levantar do banco, ao fim de n anos de depósito de uma quantia q, 
sendo j% a taxa de juros anual. Os valores de  n, q e j devem ser especificados pelo utilizador. Admita que os juros no final de cada ano são acumulados 
à quantia depositada. */

#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main() {
	const unsigned RESULT_PRECISION = 2;
	int n_ano;
	double qi, j, qf; //qi e a quantia incial, j os juros e qf a quantia final 

	cout << "Insira os seguintes valores: quantia inicial, taxa de juros anual (em percentagem) e o numero de anos ao fim do qual o dinheiro ira ser levantado.(POR ESTA ORDEM)" << endl;

	cin >> qi >> j >> n_ano;
	qf = qi;
	for (int i = 1; i <= n_ano; i++) {
		qf = qf + qf * (j/100);
	}
	cout << "Ao fim de " << fixed << setprecision(RESULT_PRECISION) <<  n_ano << " anos, a quantia que pode levantar do banco e " << qf << " euros" << endl;
	system("pause");
	return 0;

}
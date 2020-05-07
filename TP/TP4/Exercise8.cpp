/*a) O m�todo bubblesort, para ordenar os elementos de um vector com N elementos, consiste no seguinte: - come�ando no 1� elemento do vector, 
comparar os elementos de �ndices i e i+1 do vector e trocar a sua posi��o se eles estiverem fora de ordem; - repetir o passo anterior para os 
restantes elementos do vector, isto �, come�ando no 2� elemento, depois no 3� elemento, etc., at� ao elemento de �ndice N-1, o qual ser� 
comparado com o elemento de �ndice N; depois destes passos, o maior (ou menor, consoante a ordena��o seja feita por ordem crescente ou
decrescente) elemento do vector estar� na posi��o correcta (a �ltima posi��o do vector); - repetir os passos anteriores, considerando em cada 
itera��o apenas os elementos ainda n�o ordenados do vector; ap�s a 2� itera��o os �ltimos 2 elementos estar�o na posi��o correcta, ap�s a 3� 
itera��o os 3 �ltimos elementos estar�o na posi��o correcta, e assim sucessivamente. Escreva uma fun��o void bubblesort(vector<string> &v) que
implemente este m�todo de ordena��o para ordenar um vector de nomes de pessoas por ordem crescente. Nota: a STL disp�e de algoritmos de ordena��o
que ser�o analisados posteriormente.
b) Escreva um programa de teste dessa fun��o*/

#include<iostream>
#include<vector>
#include<string>
using namespace std; 

void bubblesort(vector<string> &v) { // e passado como referencia porque queremos ordena-lo e que ele fique ordenada
	for (int i = 0; i < size(v)-1; i++) {
		for (int j = 0; j < size(v)-i-1; j++) {
			if (v[j] > v[j+1]){
				string auxiliar=v[j];
				v[j] = v[j + 1];
				v[j + 1] = auxiliar;
			}
		}
	}
}

int main() {
	int nElem;
	vector<string> v;
	string aux;

	cout << "Insert the number of elements that you want to insert: ";
	cin >> nElem;


	for (int i = 0; i < nElem; i++) { // preencher o vetor
		cout << "Insert the element of index " << i << ": ";
		cin >> aux;
		v.push_back(aux);
	}

	bubblesort(v);

	cout << "The ordered vector is ";

	for (int i = 0; i < size(v); i++) // mostrar o vetor 
		cout << v[i] << " ";

	return 0;
}

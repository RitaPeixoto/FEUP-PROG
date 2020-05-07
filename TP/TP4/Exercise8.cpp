/*a) O método bubblesort, para ordenar os elementos de um vector com N elementos, consiste no seguinte: - começando no 1º elemento do vector, 
comparar os elementos de índices i e i+1 do vector e trocar a sua posição se eles estiverem fora de ordem; - repetir o passo anterior para os 
restantes elementos do vector, isto é, começando no 2º elemento, depois no 3º elemento, etc., até ao elemento de índice N-1, o qual será 
comparado com o elemento de índice N; depois destes passos, o maior (ou menor, consoante a ordenação seja feita por ordem crescente ou
decrescente) elemento do vector estará na posição correcta (a última posição do vector); - repetir os passos anteriores, considerando em cada 
iteração apenas os elementos ainda não ordenados do vector; após a 2ª iteração os últimos 2 elementos estarão na posição correcta, após a 3ª 
iteração os 3 últimos elementos estarão na posição correcta, e assim sucessivamente. Escreva uma função void bubblesort(vector<string> &v) que
implemente este método de ordenação para ordenar um vector de nomes de pessoas por ordem crescente. Nota: a STL dispõe de algoritmos de ordenação
que serão analisados posteriormente.
b) Escreva um programa de teste dessa função*/

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

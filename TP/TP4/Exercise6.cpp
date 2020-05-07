/*Escreva uma função, cujo protótipo é void readIntArray(int a[], int nElem), que lê do teclado os elementos de um array de inteiros, a;
o número de elementos a ler é nElem. Antes de ler cada elemento do array, deve ser apresentado no ecrã o respectivo índice. */
/*b) Escreva uma função, cujo protótipo é int searchValueInIntArray(const int a[], int nElem, int value) que pesquisa nos nElem elementos do
array a a ocorrência do valor value. Caso value seja encontrado, a função deve devolver o índice do elemento do array cujo valor é value;  caso
contrário devolve -1. No caso de múltiplas ocorrências de value deve ser retornado o índice da primeira ocorrência*/
/*c) Escreva um programa de teste das funções readIntArray() e searchValueInIntArray(). */
/*d) Modifique a função searchValueInIntArray(), por forma a resultar uma nova função int searchMultValuesInIntArray(const int a[], int nElem,
int value, int index[])que, caso existam múltiplas ocorrências de value em a[], devolva no array index[] os índices das ocorrências de value.
O valor retornado pela função deve ser o número de ocorrências, isto é, o número de elementos válidos de index[]. Nota: esta função também 
poderia chamar-se searchValueInIntArray, como a função anterior; explique porquê. */
/*e) Altere o programa desenvolvido na alínea c) por forma a usar a função searchMultValuesInIntArray(). Nota: o espaço para o vector index[] 
deve ser reservado antes de invocar a função searchMultValuesInIntArray(), tendo em conta o número máximo de ocorrências esperado (no limite, 
deve ter nElem elementos). */
#include<iostream>
#include<string>

using namespace std;
const int LENGTH = 100;

void readIntArray(int a[], int nElem) {
	cout << "Insert the integer which index is:  " << endl;
	for (int i = 0; i < nElem; i++) {
		cout << i << " ";
		cin >> a[i];	
	}
}

int searchValueInIntArray(const int a[], int nElem, int value) {
	for (int i = 0; i < nElem; i++) {
		if (a[i] == value) {
			cout<< i<<endl;
			break;
		}
	}
	return -1;
}

void searchMultValuesInIntArray(const int a[], int nElem, int value, int index[]) {
	int counter = 0;
	for (int i = 0; i < nElem; i++) {
		if (a[i] == value) {
			index[counter] = i;
			counter++;
		}
	}
	int s = sizeof(index) / sizeof(index[0]);
	for (int i = 0; i <counter; i++) {
		cout << index[i]<<endl;
	}

}
int main() {
	int nElem, a[LENGTH],value,index[LENGTH];
	cout << "Insert the size of the array: "<< endl;
	cin >> nElem;

	readIntArray(a, nElem);
	cout << "Insert the value: ";
	cin >> value;
	searchValueInIntArray(a, nElem, value);
	searchMultValuesInIntArray(a, nElem, value, index);

	return 0;
}
/*Escreva uma fun��o, cujo prot�tipo � void readIntArray(int a[], int nElem), que l� do teclado os elementos de um array de inteiros, a;
o n�mero de elementos a ler � nElem. Antes de ler cada elemento do array, deve ser apresentado no ecr� o respectivo �ndice. */
/*b) Escreva uma fun��o, cujo prot�tipo � int searchValueInIntArray(const int a[], int nElem, int value) que pesquisa nos nElem elementos do
array a a ocorr�ncia do valor value. Caso value seja encontrado, a fun��o deve devolver o �ndice do elemento do array cujo valor � value;  caso
contr�rio devolve -1. No caso de m�ltiplas ocorr�ncias de value deve ser retornado o �ndice da primeira ocorr�ncia*/
/*c) Escreva um programa de teste das fun��es readIntArray() e searchValueInIntArray(). */
/*d) Modifique a fun��o searchValueInIntArray(), por forma a resultar uma nova fun��o int searchMultValuesInIntArray(const int a[], int nElem,
int value, int index[])que, caso existam m�ltiplas ocorr�ncias de value em a[], devolva no array index[] os �ndices das ocorr�ncias de value.
O valor retornado pela fun��o deve ser o n�mero de ocorr�ncias, isto �, o n�mero de elementos v�lidos de index[]. Nota: esta fun��o tamb�m 
poderia chamar-se searchValueInIntArray, como a fun��o anterior; explique porqu�. */
/*e) Altere o programa desenvolvido na al�nea c) por forma a usar a fun��o searchMultValuesInIntArray(). Nota: o espa�o para o vector index[] 
deve ser reservado antes de invocar a fun��o searchMultValuesInIntArray(), tendo em conta o n�mero m�ximo de ocorr�ncias esperado (no limite, 
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
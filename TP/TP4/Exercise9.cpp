/*a) O algoritmo de pesquisa binária que se segue pode ser usado para procurar um valor num vector ordenado por ordem crescente:
- fazer bottom igual ao índice do 1º elemento do vector; - fazer top igual ao índice do último elemento do vector; - fazer found igual a falso;
- repetir, enquanto bottom não for maior do que top e found for igual a falso 
- fazer middle igual ao índice do elemento que está a meio caminho
entre bottom e top 
- se o valor que ocupa a posição middle for o valor procurado   
- fazer found igual a verdadeiro     
senão, se o valor que ocupa a posição middle for menor que o valor procurado    
- fazer bottom igual a middle+1   senão    
- fazer top igual a middle-1 
Escreva uma função, int binarySearch(const vector<string> &v, int string value) que implemente este método de pesquisa aplicado ao vector v.
A função deve retornar o índice do elemento cujo valor é value caso ele exista em v ou -1, no caso de ele não existir.
b) Escreva um programa de teste dessa função. 
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int binarySearch(const vector<string> &v, string value) {
	int middle, top= size(v)-1, bottom=0;
	bool found = false;


	do {
		middle = (top + bottom) / 2;
		if (v[middle] == value) {
			return middle;
		}
		else if (v[middle]<value) {
			bottom = middle + 1;
		}
		else{
			top = middle - 1;
		}

	} while ((bottom <= top) && found == false);

	return -1;

}
int main() {
	vector<string> v;
	int nElem;
	string value;

	cout << "Enter the number of elements of the vector: ";
	cin >> nElem;
	
	for (int i = 0; i < nElem; i++) {
		
		cout << "Insert the element of index " << i << ": ";
		string str;
		cin >> str;
		v.push_back(str);
		
	}

	cout << "Insert the value that you want to find: ";
	cin >> value;

	int find = binarySearch(v, value);
	if (find != -1) {
		cout << "The value " << value << " is located on the position " << find << ".";
	}
	else {
		cout << "Sorry, the value isn't here! Try again bitch" << endl;
	}
	return 0;
}
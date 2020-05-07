/*Escreva uma fun��o bool sequenceSearch(string s, int nc, char c) que verifica se na string s existe uma sequ�ncia de nc caracteres 
consecutivos iguais a c, devolvendo true ou false consoante exista ou n�o. Escreva um programa de teste dessa fun��o. */

#include<iostream>
#include<string>
using namespace std;


bool sequenceSearch(string s, int nc, char c) {
	int size = s.length();
	int counter = 0;
	for (int i = 0; i < size; i++) {
		if (s[i] == c) {
			counter++;
		}
		if (counter != 0) {
			if (s[i] == c) {
				counter++;
				if (counter == nc) {
					return true;
				}
			}
			else {
				break;
			}

		}
	}
	return false;

}



int main() {
	string s;
	int nc;
	char c;

	cout << "Insert a string, the number of consecutives characters and a character: ";
	cin >> s >> nc >> c;
	if (sequenceSearch(s, nc, c)) {
		cout << "True";
	}
	else {
		cout << "False";
	}


	return 0;
}
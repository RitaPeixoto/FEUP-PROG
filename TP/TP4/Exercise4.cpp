/*Escreva uma fun��o string normalizeName(string name) para "normalizar" um nome da seguinte forma: espa�os no in�cio ou no fim s�o suprimidos; 
sequ�ncias de v�rios espa�os entre duas palavras s�o substitu�dos por um �nico espa�o; as min�sculas s�o convertidas para mai�sculas; s�o 
removidas as part�culas "DE", "DO", "DA", "DAS", "DOS" e "E". O valor de retorno da fun��o � o nome "normalizado". Sugest�o: use um array de 
strings para guardar as part�culas a remover. */

#include <iostream>
#include<string>

using namespace std;

string normalizeName(string name) {
	int length = name.length(), counter = 0;
	string resultArray[50], word, resultString = ""; // array resultado, auxiliar de passagem do que interessa, resultado final

	for(int i = 0; i < length; i++) {
		if (isalpha(name[i])) { // as minusculas sao convertidas em maiusculas
			word += toupper(name[i]);
		}
		else if (name[i] == ' '  && isalpha(name[i - 1]) && i > 0) { //espa�os no in�cio ou no fim s�o suprimidos; sequ�ncias de v�rios espa�os entre duas palavras s�o substitu�dos por um �nico espa�o
			word += ' ';
			resultArray[counter] = word;
			word = "";
			counter++;
		}
	}
	

	word +=' ';
	resultArray[counter] = word;
	cout << counter;
	word = "";
	counter += 1;

	for (int i = 0; i < 5; i++) {
		cout << resultArray[i] << endl;
	}

	for (int i = 0; i < 50; i++) { // o if ignora o que nao queremos que esteja na string
		if (resultArray[i].compare("DE ") == 0 || resultArray[i].compare("DO ") == 0 || resultArray[i].compare("DA ") == 0 ||
			resultArray[i].compare("DAS ") == 0 || resultArray[i].compare("DOS ") == 0 || resultArray[i].compare("E ") == 0) {
			continue;
		}

		else { // adiciona a string final apenas o que queremos
			resultString += resultArray[i];
		}
	}

	return resultString;

}


int main() {
	string name;
	cout << "Insert a name: ";
	getline(cin,name);
	cout << normalizeName(name);
	return 0;
}
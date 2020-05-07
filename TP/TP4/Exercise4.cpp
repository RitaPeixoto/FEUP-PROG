/*Escreva uma função string normalizeName(string name) para "normalizar" um nome da seguinte forma: espaços no início ou no fim são suprimidos; 
sequências de vários espaços entre duas palavras são substituídos por um único espaço; as minúsculas são convertidas para maiúsculas; são 
removidas as partículas "DE", "DO", "DA", "DAS", "DOS" e "E". O valor de retorno da função é o nome "normalizado". Sugestão: use um array de 
strings para guardar as partículas a remover. */

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
		else if (name[i] == ' '  && isalpha(name[i - 1]) && i > 0) { //espaços no início ou no fim são suprimidos; sequências de vários espaços entre duas palavras são substituídos por um único espaço
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
#include<iostream>
#include<string>//alinea e 
#include<vector>
#include<fstream>
using namespace std;

const string DICTIONARY_FILENAME = "dictionary.txt";


/*c- quando � inserido ctr-Z, quando nao � possivel abrir o ficheiro do dicionario, ou seja quando nao for possivel fazer o cin para uma string*/


bool match(string pattern, string word) // alinea d)
{   
	if (pattern.length() != word.length()) {
		return false;
	}
	else {
		for (unsigned int i = 0; i < pattern.length(); i++) {
			if (pattern[i] != '.') {
				if (pattern[i] != word[i]) {
					return false;
				}
			}
		}
	}
	return true;
}





int main() {
	string word;   
	string pattern;  
	vector<string> dictionary;



	//abrir o ficheiro que cont�m o dicion�rio   // C�DIGO A ESCREVER, na al�nea a)  
	ifstream dict_file(DICTIONARY_FILENAME);
	if (!dict_file.is_open()) {
		cerr << "It is not possible to open " << DICTIONARY_FILENAME << endl;
		return 1;
	}


	//ler do ficheiro para o vector   // C�DIGO A ESCREVER, na al�nea b)  
	while (getline(dict_file, word)) {
		dictionary.push_back(word);
	}
	dict_file.close();






	cout << endl << "Dictionary size = " << dictionary.size() << endl << endl;
	//ler repetidamente um padr�o e tentar encontrar palavras que verificam o padr�o   
	cout << "Pattern (letters and dots)? ";   
	while (cin >> pattern) {     
		int numMatches = 0;     
		for (size_t i=0; i< dictionary.size(); i++)       
			if (match(pattern,dictionary[i])) {         
				cout << "Found: " << dictionary[i] << endl;         
				numMatches++;      
			}       
		cout << "Number of matches = " << numMatches << endl << endl;       
		cout << "Pattern (letters and dots)? ";   
	}  
	return 0; 
}
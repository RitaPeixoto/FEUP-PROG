#include "2014-3.h"

Text::Text(string filename) {
	ifstream in_file(filename);
	string line;
	getline(in_file, line);
	title = line;

	getline(in_file, line);
	author = line;
	while(getline(in_file,line)){
		text.push_back(line);
	}
	in_file.close();
}
string Text::getAuthor() const {
	return author;
}

string Text::getTitle() const {
	return title; 
}
vector<string> Text::getText() const {
	return text;
}
bool Text::existsWord(string word) {
	string aux="";
	// search in author 
	for (int i = 1; i < author.length(); i++) {
		if (author[i]!= ' ' ) {
			aux+= author[i];
		}
		else {
			if (aux == word) {
				return true;
			}
			aux = "";
		}
	}
	aux = "";
	// search in book title
	for (int i = 1; i < title.length(); i++) {
		if (title[i] != ' ') {
			aux += title[i];
		}
		else {
			if (aux == word) {
				return true;
			}
			aux = "";
		}
	}


	//search in text
	aux = "";
	for (int j = 0; j < size(text); j++) {
		for (int i = 0; i < text[j].length()+1; i++) {
			if (text[j][i] != ' ') {
				aux += text[j][i];
			}
			else {
				if (aux == word) {
					return true;
					
				}
				aux = "";
			}
		}
	}

	return false; 
}


bool Text::existsWord(string word, string &where ) {
	string aux = "";
	// search in author 
	for (int i = 1; i < author.length(); i++) {
		if (author[i] != ' ') {
			aux += author[i];
		}
		else {
			if (aux == word) {
				where = "author";
				return true;
			}
			aux = "";
		}
	}
	aux = "";
	// search in book title
	for (int i = 1; i < title.length(); i++) {
		if (title[i] != ' ') {
			aux += title[i];
		}
		else {
			if (aux == word) {
				where = "title";
				return true;
			}
			aux = "";
		}
	}


	//search in text
	aux = "";
	for (int j = 0; j < size(text); j++) {
		for (int i = 0; i < text[j].length() + 1; i++) {
			if (text[j][i] != ' ') {
				aux += text[j][i];
			}
			else {
				if (aux == word) {
					where = "Text";
					return true;

				}
				aux = "";
			}
		}
	}

	return false;
}






int main() {
	string a, word, where;
	cout << "What's the name of the file?";
	cin >> a;

	Text ficheiro(a);

	cout << "What's the word you're looking for?";
	cin >> word;

	if (ficheiro.existsWord(word, where)) {
		cout << "The word " << word << " is in the " << where<<endl;
	}
	else {
		cout << "The word isn't in the file" << endl;
	}


	return 0;
} 
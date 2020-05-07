#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<algorithm>

using namespace std;

void toUpperStr(string &s) { // 1 a)
	for (unsigned int i = 0; i < s.length(); i++) {
		s[i] = toupper(s[i]);
	}
}

string transformLine(string &s) {//1 b)
	for (unsigned int i = 0; i < s.length(); i++) {
		if (!isalpha(s[i])) {
			s[i]= ' ';
		}
	}
	toUpperStr(s);
	return s;
 }

//void decomposeLine(string &line, vector<string> &words) {
//	transformLine(line);
//	string aux;
//	for (unsigned int i = 0; i < line.length(); i++) {
//		if (line[i] != ' ') {
//			aux += line[i];
//		}
//		else {
//			while (line[i + 1] == ' ') {
//				i++;
//			}
//			words.push_back(aux);
//			aux = "";
//		}
//	}
//}
void decomposeLine(string& line, vector <string> &words) { //Exercise 1.c)
	string aux;
	stringstream result;

	line = transformLine(line);

	result << line;

	while (result >> aux)
		words.push_back(aux);
}	

void saveToFile() { //Exercise 1.d)
	ifstream File("words.txt");
	ofstream Fout("hello.txt");
	string line;
	vector<string> words;

	if (!File.is_open()) {
		cout << "Error opening!" << endl;
	}
	
	else {
		while (getline(File, line)) {
			decomposeLine(line, words);
		File.close();
		}
		
		sort (words.begin(), words.end());
		if (Fout.is_open()){
			for (unsigned int i = 0; i < size(words); i++) {
				Fout << words[i] << endl;
			}
			Fout.close();
		}
	}		
	
	}


void decomposeLineRepeated(string& line, vector <string>& words) { //Exercise 1.e)
	string aux;
	stringstream result;

	line = transformLine(line);

	result << line;

	while (result >> aux) {
		bool repeated = false;

		for (int i = 0; i < size(words); i++)
			if (words[i] == aux) {
				repeated = true;
				break;
			}

		if (!repeated)
			words.push_back(aux);
	}
}


int main() {
	vector<string> a;
	string s = "A very, very short sentence!";
	ofstream hello;
	saveToFile();
	for (int i = 0; i < size(a); i++) {
		cout << a[i] << endl;
	}
	hello.open("words.txt");
	string b = "Hello!";
	hello << s<< " " <<b;
	}

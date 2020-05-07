#include <iostream>
#include<string>
#include<fstream>
#include<vector>
#include<map> //alinea c) 
using namespace std;

void simplify(const string &name, string &sname) {//alinea b) 
	vector<string> names; 
	string aux="";

	if (name.find_first_of(' ')== string::npos) {
		sname = name; 
	}
	else {
		for (unsigned int i = 0; i < name.length(); i++) {
			if (name[i] != ' ' ) {// se for um espaço e houver alguma coisa na aux que nao seja um espaço 
				aux += name[i];
			}
			else if (aux.length()>0){
				names.push_back(aux);
				aux = "";
			}
		}
		names.push_back(aux);
		if (size(names) >1) {
			sname = names[0] + " " + names[size(names) - 1];
		}
		else {
			sname = name[0];
		}
		names.clear();
	}
}

int main() {
	ifstream in_file;
	ofstream out_file("people2.txt");
	string file_name = "people1.txt";
	string full_name, simplified_name;
	multimap<string, string> simplified_names;
	string first, last, name;

	in_file.open(file_name);
	if (in_file.fail()) {
		cerr << "people1.txt not found" << endl;
		return 1;
	}
	while (getline(in_file, full_name))
	{
		simplify(full_name, simplified_name);
		for (size_t i = 0; i < simplified_name.length(); i++)
			if (simplified_name[i] == ' ')
			{
				first = simplified_name.substr(0, i);
				last = simplified_name.substr(i + 1, simplified_name.length());
			}
		simplified_names.insert(pair <string, string>(first, last));
	}

	for (auto name : simplified_names)
	{
		if (name.second != "HI ")
			out_file << name.first << " " << name.second << endl;
		else
			out_file << name.first << endl;
	}
	return 0;
}



//Alinea A
//int main() {
//	ifstream in_file;
//	ofstream out_file("people2.txt");
//	string file_name = "people1.txt";
//	string full_name, simplified_name;
//
//
//	in_file.open(file_name);
//	if (in_file.fail()) {
//		cerr << "people1.txt not found" << endl;
//		return 1;
//	}
//
//	while (getline(in_file, full_name)) {
//		simplify(full_name, simplified_name);
//		out_file << simplified_name << endl;
//
//	}
//	
//	return 0;
//}
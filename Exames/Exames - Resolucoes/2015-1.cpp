#include<iostream>
#include<sstream>
#include <fstream>
#include<string>
#include<vector>
using namespace std;



void get_code_sum(const string &code_grades, int num_grades, string &code, double &sum) {//alinea a 
	stringstream aux;
	sum = 0;
	string line, lixo; 
	vector<string> grades;

	aux << code_grades;
	aux >> code;
	aux >> lixo;//tracinho
	while (aux >> line) {
		grades.push_back(line);
	}

	for (int i = 0; i < num_grades; i++) {
		sum += stod(grades[i]);
	}

}


int main() {
	ifstream in_file;
	ofstream out_file;
	string file;
	string line;
	int num_grades;
	string code;
	double sum; 




	cout << "What's the name of the initial file? ";
	cin >> file;
	file=file +".txt";

	in_file.open(file);
	if (!in_file.is_open()) {
		cout << "It wasn't possible to open the given file";
		return 1;
	}
	file.insert(file.find_last_of("."), "_final");
	getline(in_file, line);
	num_grades = stoi(line);
	out_file.open(file);

	while (getline(in_file, line)) {
		get_code_sum(line, num_grades, code, sum);
		if (out_file.is_open()) {
			out_file << code << " - " << sum << endl;
		}

	}


}

//int main() {//main da alinea a
//	string student = "up20141007 -  2.0 1.0 1.0 1.0 1.5 1.5 1.5 2.0 1.0 1.0 ";
//	string code;
//	int num_grades = 10;
//	double sum;
//	get_code_sum(student, num_grades, code, sum);
//	cout << code << endl << sum << endl;
//	return 0;
//}
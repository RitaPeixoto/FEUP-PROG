#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<map>
#include<sstream>
#include <algorithm>
using namespace std;


//vector<string> convertResultList(const vector<unsigned int> &number, const vector<string> &name, const vector<float> &grade) {
//	vector<string> result;
//	stringstream aux;
//	string num, name_aux, grade_aux, finale;
//	cout << "HI";
//
//	for (int i = 0; i < size(number); i++) {
//		num = to_string(number[i]);
//		name_aux = name[i];
//		grade_aux = to_string(grade[i]);
//
//		aux << setw(7) << setfill(' ') << num << " | " << setw(20) << setfill(' ') << name_aux << " | " << setw(4) << grade_aux;
//
//		finale = aux.str();
//
//		result.push_back(finale);
//		aux.str("");
//
//	}
//
//	return result;
//
//}
//
//
//
//int mode(const int number[], unsigned int numElems) {
//	map<int, int> frequency;
//	for (int i = 0; i < numElems; i++) {
//		auto res = frequency.find(number[i]);
//			if (res != frequency.end()) {
//				frequency[number[i]] += 1;
//			}
//			else {
//				frequency.insert(pair<int, int>(number[i], 1));
//
//			}
//	}
//	
//	int auxfreq = 0, aux = 0;
//
//	for (map<int, int>::iterator i = frequency.begin(); i != frequency.end(); i++) {
//		
//		if (auxfreq < i->second) {
//			auxfreq = i->second;
//			aux = i->first;
//		}
//		else if (auxfreq == i->second && aux<i->first) {
//			aux = i->first;
//		}
//	}
//
//	
//	return aux;
//}
//
//
//int main() {
//	/*vector<unsigned int > vetor_1 = { 201806257,201805222,201503969 };
//	vector<string> vetor_2 = { "Antonio", "Rita","Joao" };
//	vector<float> vetor_3 = { 20.0,16.9,15.3 };
//	vector<string> result = convertResultList(vetor_1, vetor_2, vetor_3);
//	cout << "HEllo" << endl;
//
//	for (int i = 0; i < size(result); i++) {
//		cout << result[i] << endl;
//	}*/
//	int a[] = { 2, 2, 2, 1, 2, 9, 1, 7, 1, 1, 1, 1, 2, 2 };
//	int numelem = 14; 
//	int b = mode(a, numelem);
//	cout << b;
//
//	return 0; 
//}
int getValue(const string &msg, int lim1, int lim2) {
	int value;   
	do { 
		cout << msg << " [" << lim1 << ".." << lim2 << "] ? ";       
		while (!(cin >> value)) { 
			cin.clear();          
			cin.ignore(1000, '\n'); 
		} 
	} while (value<lim1 || value> lim2); // enquanto value estiver fora da gama [lim1..lim2]    
	return value;
}


int main() {
	vector<string> code = { "ei06257","ei06543","ei78502" };
	vector<unsigned int> grade;
	unsigned int grad;
	for (int i = 0; i < size(code); i++) {
		grade.push_back(getValue("Classificacao de "+code[i]+" ",0,20));

	}
	vector<pair<string,int>> ola;
	ola.push_back(pair<string, int>("201806257", 20));

	

	return 0; 
}
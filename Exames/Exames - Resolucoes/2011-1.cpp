#include<string>
#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;



int main() {
	string name;  
	int age;
	cout << "Nome ? "; 
	getline(cin, name);
	cout << "Idade ? ";
	cin >> age;
	cout << "Nome = " << name << "/ Idade = " << age << endl;
	return 0;
}

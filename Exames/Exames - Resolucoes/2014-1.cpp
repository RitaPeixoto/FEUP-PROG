#include <iostream>
#include"2014-1.h"


/*aliena c) Nao há constructor sem parametros e como ja existe um construtor com parametros, o compilador ja nao gera automaticamente um */
/*alinea d)-multimap<string,string> position_players    sendo a primeira string a posiçao e a segunda o nome do jogador
iterava-se sobre o multimap de forma a so printar os values com a key da posiçao que queriamos
		*/
using namespace std;

unsigned int countValues(int a[], unsigned int nelem, int value) {//alinea a
	unsigned int i, count = 0;
	for (i = 0; i <= nelem; i++)
		if (a[i] == value)
			count++;
	return count;
}
template<class T>
bool operator==(const T a[], const T value) {
	if(a[0]==value)
	return true;

}




template<class T>

unsigned int countValues_templ(T a[], unsigned int nelem, T value) {//alinea b
	unsigned int i, count = 0;
	for (i = 0; i <= nelem; i++)
		if (a[i] == value)
			count++;
	return count;
}

Person::Person(string name, unsigned int age){
	this->name = name;
	this->age = age; 
}



Player::Player(string name, unsigned int age, string team): Person (name,age) {
	this->team = team; 

}




int main() {
	double a[] = { 23,4,4,4,5,6,7 };
	unsigned int nelem = 7;
	double value = 4;
	//cout << countValues_templ(a, nelem, value);

	int b[] = { 23,4,4,4,5,6,7 };
	unsigned int nel = 7;
	int val = 4;
	//cout << countValues(b, nel, val);


	return 0;
}
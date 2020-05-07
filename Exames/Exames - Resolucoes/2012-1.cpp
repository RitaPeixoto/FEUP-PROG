#include<iostream>
#include<string>
#include<map>
using namespace std;

string cardRankToSymbol(unsigned int rank) {//alinea b first part
	string names[] = { " A"," 2"," 3"," 4"," 5"," 6"," 7"," 8"," 9","10"," J"," Q"," K" };
	if (rank >= 1 && rank <= size(names) / sizeof(int)) {
		return names[rank - 1];
	}
	else {
		return "Invalid card!";
	}
}

string cardRankToSymbol_map(unsigned int rank) {//alinea b second part
	map<unsigned int, string> cards;
	cards.insert(pair<unsigned int, string>(1, " A"));
	cards.insert(pair<int, string>(2, " 2"));
	cards.insert(pair<int, string>(3, " 3"));
	cards.insert(pair<int, string>(4, " 4"));
	cards.insert(pair<int, string>(5, " 5"));
	cards.insert(pair<int, string>(6, " 6"));
	cards.insert(pair<int, string>(7, " 7"));
	cards.insert(pair<int, string>(8, " 8"));
	cards.insert(pair<int, string>(9, " 9"));
	cards.insert(pair<int, string>(10, " 10"));
	cards.insert(pair<int, string>(11, " J"));
	cards.insert(pair<int, string>(12, " Q"));
	cards.insert(pair<int, string>(13, " K"));

	if (!cards[rank].empty()) {
		return cards[rank];
	}
	else
		return "Invalid card ! ";

}

template<class T>
T absolute(T number) {
	if (number < 0) {
		return -number;
	}
	return number;

 }


//int main() {
//	unsigned int card_number;
//	cout << "Insert the card number" << endl;
//	cin >> card_number;
//	string print;
//	//print= cardRankToSymbol(card_number);
//	print = cardRankToSymbol_map(card_number);
//	cout << print; 
//
//
//	int a = -3;
//	float b = -4.0;
//	double c = -5.121;
//
//	cout << absolute(c);
//
//	return 0;
//
//}
#include "2012-3.h"
#include"2012-1.cpp"


/*falta a alinea d*/
Hand::Hand() {//para alinea c 

}

Card::Card() {//alinea a 
	suit = ' ';
	rank = 0;
	points = 0;
	isFaceUp = false;
}

ostream& operator<<(ostream& os, const Card& card) {//alinea b 

	if (!card.isFaceUp) {
		os << "XXXX";
	}
	else {
		os << " " << cardRankToSymbol(card.rank) << "." << card.suit;
	}
	return os;
}

unsigned int Card::getRank() const {
	return rank;
}

unsigned int Hand::getPointsTotal() const {//alinea c 
	map<int, int> points;
	points.insert(pair<int, int>(1, 11));
	points.insert(pair<int, int>(2, 0));
	points.insert(pair<int, int>(3, 0));
	points.insert(pair<int, int>(4, 0));
	points.insert(pair<int, int>(5, 0));
	points.insert(pair<int, int>(6, 0));
	points.insert(pair<int, int>(7, 10));
	points.insert(pair<int, int>(8, 0));
	points.insert(pair<int, int>(9, 0));
	points.insert(pair<int, int>(10, 0));
	points.insert(pair<int, int>(11, 2));
	points.insert(pair<int, int>(12, 3));
	points.insert(pair<int, int>(13, 4));

	unsigned int total=0;
	bool an_ace;

	for (unsigned int i = 0; i < cards.size(); i++) {
		total += points[cards[i].getRank()];
		if (cards[i].getRank() == 1) {
			an_ace = true;
		}
	}
	if ( total > 21 && an_ace) {
		total = total - 10;
	}
	return total;

}



void Hand::show() const {
	for (auto card : cards) {
		cout << card;
	}
}

int main() {


	return 0; 
}


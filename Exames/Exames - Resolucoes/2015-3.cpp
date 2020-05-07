#include "2015-3.h"
#include<map>

int numDaysOfMonth(int month, int year) {
	bool leap_year=false;
	if (year % 4 == 0) {
		if (year % 100 != 0) {
			if (year % 400 == 0) {
				leap_year = true;
			}
		}
	}

	switch (month) {
	case 2: 
		if (leap_year) {
			return 29;
		}
		else {
			return 28;
		}
		break;

	case 4:
		return 30;
		
	case 6: 
		return 30;

	case 9:
		return 30;
	case 11:
		return 30;
	default:
		return 31;
	}
}




Pluviosity::Pluviosity(int year) {
	int aux;
	this->year = year;
	vector<vector<int>> pluv;

	for (int i = 0; i < 12; i++) {
		aux = numDaysOfMonth(i + 1, year);
		vector<int> help;
		for (int j = 0; j < aux; j++) {
			help.push_back(0);
		}
		pluv.push_back(help);
	}
	this->pluv = pluv;
}
int Pluviosity::getPluv(int month, int day) const {
	return pluv[month-1][day-1];
}
int Pluviosity::maxPluv()const {
	return 0; 
}

int main() {
	map<string, vector<vector<int>>> cities;
	Pluviosity no_1(2019);
	cout << no_1.getPluv(2, 23);
	return 0; 


}
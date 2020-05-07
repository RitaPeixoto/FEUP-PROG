#include"2017-2.h"
#include<math.h>


Date::Date(int y, int m , int d) {//alinea a 
	y = y;
	m = m; 
	d = d;

}

bool operator<(const Date& left, const Date& right) {
	int date1, date2;
	date1 = left.y*pow(10, 4) + left.m*pow(10, 2) + left.d;
	date2 = right.y*pow(10, 4) + right.m*pow(10, 2) + right.d;
	if (date1 < date2) {
		return true;
	}
	return false; 
}

istream & operator>>(istream & f, Date & date) {
	char hifen1, hifen2;

	f >> date.y >> hifen1 >> date.m >> hifen2 >> date.d;
	if (hifen1 != '-' || hifen2 != '-' || date.y < 0 || date.m <= 0 || date.d <= 0) {
		runtime_error message("Invalid Date");
		throw message;
	}
	return f;
}
ostream & operator<<(ostream & f, const Date & date) {
	f << date.y << "-" << date.m << "-" << date.d;
	return f;
}

bool operator==(const Date& left, const Date& right) {
	return (left.y == right.y && left.m == right.m && left.d == right.d);
}

int main() {
	Date date1;
	Date date2;
	cout << "Date 1(yyyy-mm-dd)? ";
	try{
		cin >> date1;
	}
	catch(runtime_error message){
		cerr << message.what();
		return 1; 
	}
	

	cout << "Date 2(yyyy-mm-dd)? ";
	try {
		cin >> date1;
	}
	catch (runtime_error message) {
		cerr << message.what();
		return 1;
	}

	cout << date1 << endl;

	cout << date2 << endl;
	if (date1 < date2) {
		cout << " is before";
	}
	else if(date1 == date2) {
		cout << "is equal";
	}
	else {
		cout << "is after";
	}





}




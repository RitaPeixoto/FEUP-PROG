#include <iostream>
#include<string>
#include<ctime>
#include"Exercise1.h"
using namespace std;
// falta alinea g)

#pragma warning(disable : 4996) // por causa de um warning estranho que dava para o ctime

Date::Date() {
	time_t t = time(0);// current date/time based on current system
	tm *now = localtime(&t);// convert t to string form

	year = now->tm_year + 1900;
	month = now->tm_mon + 1;
	day = now->tm_mday;
}

Date::Date(unsigned int year, unsigned int month, unsigned int day) {
	this->year = year;
	this->month = month;
	this->day = day;
}
Date::Date(string yearMonthDay) {
	this->year = stoi(yearMonthDay.substr(0, 4));//susbtr(Position of the first character to be copied as a substring,Number of characters to include in the substring)
	this->month = stoi(yearMonthDay.substr(4, 2));
	this->day = stoi(yearMonthDay.substr(6, 2));
}

void Date::setYear(unsigned int year) { // cria um novo mas apenas acede a um campo
	this->year = year;
}
void Date::setMonth(unsigned int month) {
	this->month = month;
}
void Date::setDay(unsigned int day) {
	this->day = day;
}

void Date::setDate(unsigned int year, unsigned int month, unsigned int day) {
	this->year = year;
	this->month = month;
	this->day = day;
}

unsigned int Date::getYear() const {//mostra o valor
	return year;
}

unsigned int Date::getMonth() const {
	return month;
}

unsigned int Date::getDay() const {
	return day;
}

string Date::getDate() const {
	string str_year = to_string(year), str_month = to_string(month), str_day = to_string(day);
	//caso de faltarem digitos nas componentes das datas
	while (str_year.length() < 4) {

		str_year = "0" + str_year;
	}
	while (str_month.length() < 2) {
		str_month = "0" + str_month;
	}
	while (str_day.length() < 2) {
		str_day = "0" + str_day;
	}

	return str_year + "/" + str_month + "/" + str_day;
}

void Date::show() const {
	cout << Date::getDate();
}

bool Date::leap_year(unsigned int year) {
	if (year % 4 == 0 && year % 100 != 0 && year % 400 == 0) {//forma de determinar se um ano é bissexto ou nao
		return true;
	}
	return false;
}
int Date::numberOfDays(unsigned int month, unsigned int year) {
	switch (month) {
	case 2:
	{
		if (leap_year(year)) {//fevereiro
			return 29;
		}
		else {
			return 28;
		}
	}
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

bool Date::isValid() {
	if (month > 12 ||day>numberOfDays(month,year)) {
		return false;	
	}
	return true;
}
bool Date::isEqualTo(const Date& date) {

	return (date.day == day && date.month == month && date.year == year);
}
bool Date::isNotEqualTo(const Date& date) {
	return (isEqualTo(date));
}

bool Date::isAfter(const Date& date) {
	return (date.year < year || (date.year == year && date.month < month) || (date.year == year && date.month == month && date.day < day));
}
bool Date::isBefore(const Date& date) {
	return (!isAfter(date) && !isEqualTo(date));
}

/*int main() {
	Date d1("2019/08/18"); // nao é possivel sem o default constructor porque todos os construtores que temos necessitavam de argumentos 
	Date d2(2019, 05, 31);
	Date d3;
	Date d4;
	d3.setDay(28);
	d3.setMonth(4);
	d3.setYear(2018);
	d1.show();
	cout << endl;
	d3.show();
	cout << endl;
	cout << d2.isValid() << endl;
	cout << d2.isAfter(d3)<<endl;// se o d2 é depois do d3
	cout << d2.isEqualTo(d3)<<endl;
	cout << d3.isEqualTo(d2) << endl;
	cout << d3.isBefore(d2) << endl;

	return 0;
}*/



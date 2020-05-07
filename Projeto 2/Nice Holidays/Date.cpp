#include"Date.h"

#pragma warning(disable: 4996)


Date::Date() {//Default constructor
	time_t t = time(0);
	tm *now = localtime(&t);
	newYear = now->tm_year + 1900;
	newMonth = now ->tm_mon + 1;
	newDay = now->tm_mday;

}

Date::Date(unsigned int year, unsigned int month, unsigned int day) {
	newYear = year;
	newMonth = month;
	newDay = day;
}


void Date::setYear(unsigned int year) { // cria um novo objeto mas apenas acede a um campo
	newYear = year;
}
void Date::setMonth(unsigned int month) {
	newMonth = month;
}
void Date::setDay(unsigned int day) {
	newDay = day;
}

void Date::setDate(unsigned int year, unsigned int month, unsigned int day) {
	newDay = day;
	newMonth = month;
	newYear = year;
}

void Date::setDate(string date) {// separa a data nos seus campos dia, mês e ano sendo o delimitador a barra '/'
	string aux;
	int delimiter, counter = 0;


	date += '/';
	delimiter = date.find_first_of('/');


	while (date != "") {
		aux = date.substr(0, delimiter);
		aux = resize_function(aux);

		switch (counter) {
		case 0:
			newYear = stoi(aux);
			break;
		case 1:
			newMonth = stoi(aux);
			break;
		case 2:
			newDay = stoi(aux);
			break;
		}
		counter++;
		aux.clear();
		date.erase(0, delimiter + 1);
		delimiter = date.find_first_of('/');
	}
}





unsigned int Date::getYear() const {//mostra o valor
	return newYear;
}

unsigned int Date::getMonth() const {
	return newMonth;
}

unsigned int Date::getDay() const {
	return newDay;
}

string Date::getDate() const { // constroi a string de data tendo em atenção a formatacao YYYY/MM/DD
	string string_year = to_string(newYear), string_month = to_string(newMonth), string_day = to_string(newDay);

	while (string_year.length() < 4) {
		string_year = "0" + string_year;
	}

	while (string_month.length() < 2) {
		string_month = "0" + string_month;
	}

	while (string_day.length() < 2) {
		string_day = "0" + string_day;
	}

	return string_year + '/' + string_month + '/' + string_day;
}



bool Date::leap_year(unsigned int year) { // verifica se é um ano bissexto ou nao
	if (year % 4 == 0 && year % 100 != 0 && year % 400 == 0) {//forma de determinar se um ano é bissexto ou nao
		return true;
	}
	return false;
}
int Date::numberOfDays(unsigned int month, unsigned int year) {// retorna o n de dias que o respetivo mês tem 
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

bool Date::isValid() {// verifica se a data é valida,ou seja, nao tem um n maior de mês do que o possivel e o mesmo com os dias
	if (newMonth > 12 || newDay > numberOfDays(newMonth, newYear)) {
		return false;
	}
	return true;
}
bool Date::isEqualTo(const Date& date) { // verifica se duas datas sao iguais

	return (date.newDay == newDay && date.newMonth == newMonth && date.newYear ==newYear);
}
bool Date::isNotEqualTo(const Date& date) {// verifica se duas datas nao sao iguais
	return (isEqualTo(date));
}

bool Date::isAfter(const Date& date) {// verifica se a data é depois da outra
	return (date.newYear < newYear || (date.newYear == newYear && date.newMonth < newMonth) || (date.newYear == newYear && date.newMonth == newMonth && date.newDay < newDay));
}
bool Date::isBefore(const Date& date) {// verifica se a data é antes da outra
	return (!isAfter(date) && !isEqualTo(date));
}

#ifndef DATE_H
#define DATE_H


#include <string>
#include <iostream>
#include <ctime>
#include "FormattingFunctions.h"

using namespace std;

class Date {
public:  
	Date();
	Date(unsigned int year, unsigned int month, unsigned int day);
	void setDate(string date); // formato YYYY/MM/DD
	void setYear(unsigned int year);
	void setMonth(unsigned int month);
	void setDay(unsigned int day);
	void setDate(unsigned int year, unsigned int month, unsigned int day);
	unsigned int getYear() const;   //o const vem depois nas funçoes
	unsigned int getMonth() const;
	unsigned int getDay() const;
	string getDate() const;
	bool isValid();
	bool isEqualTo(const Date& date);
	bool isNotEqualTo(const Date& date);
	bool isAfter(const Date& date);
	bool isBefore(const Date& date);
private:
	unsigned int newYear;
	unsigned int newMonth;
	unsigned int newDay;
	bool leap_year(unsigned int year);
	int numberOfDays(unsigned int month, unsigned int year);
};

#endif
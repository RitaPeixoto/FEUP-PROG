#include"Exercise_3.h"


Date Person::getBirth() {
	return this->birthdate;
}

string Person::getGender() {
	return this->gender;
}

string Person::getName() {
	return this->name;
}

Person::Person(string name, string gender, Date birthdate) {
	this->name = name;
	this->gender = gender;
	this->birthdate = birthdate;
}
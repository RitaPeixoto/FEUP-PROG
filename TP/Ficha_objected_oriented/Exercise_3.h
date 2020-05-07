#pragma once
#include<string>
#include "Exercise1.h"
using namespace std;

class Person {
	public: Person(string name, string gender, Date birthdate);
			string getName();
			string getGender();
			Date getBirth();


	private:
		string name;
		string gender;
		Date birthdate;

};

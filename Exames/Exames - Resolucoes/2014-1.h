#pragma once
#include<string>
#include<vector>
using namespace std;

class Person {
	template<class T>
	friend bool operator==(const T  a[], const T value);
public:   Person(string name, unsigned int age);   
		  string getName() const;   
		  unsigned int getAge() const;   // other methods 
private:   string name;   
		   unsigned int age; 
};


class Player: public Person {
public: Player();
		Player(string name, unsigned int age, string team);
		string getTeam() const;
		//other methods;
private: string team; 

};



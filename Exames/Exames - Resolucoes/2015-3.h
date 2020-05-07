#pragma once
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Pluviosity {
public:   Pluviosity();  
		  Pluviosity(int year);  
		  bool setPluv(int month, int day, int pluviosity);   
		  int getPluv(int month, int day) const;   // other methods, including maxPluv(), to be defined in question 3.b
		  int maxPluv() const;
private:   unsigned int year;            // year that the pluviosity data refers to
		   vector<vector<int> > pluv;  // pluviosity data, indexed by month & day
};
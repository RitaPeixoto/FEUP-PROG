#pragma once
#include<string>
#include<vector>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<iostream>
using namespace std;

class Student {
public:   Student();
		  Student(const string &code, const string &name);   
		  void setGrades(double shortExam, double project, double exam);   
		  string getCode() const;   
		  string getName() const; 
		  double getExam() const;
		  double getShortExam() const;
		  double getProject()const;
		  int getFinalGrade() const;   // other get and set methods
		  bool isApproved() const; // is the student approved or not ?    
		  static int weightShortExam, weightProject, weightExam;  // weights in percentage (ex:20,30,50) 
		  //Student readStudentData();
private:   string code; // student code
		  string name; // student complete name   double shortExam, project, exam; // grades obtained by the student in the different components
		  double shortExam, project, exam;
		  int finalGrade;
};



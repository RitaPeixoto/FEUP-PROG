#include "Exercise_2.h"
using namespace std;


Student::Student() {

}

Student::Student(const string &code, const string &name) {
	this->code = code;
	this->name = name;
}

void Student::setGrades(double shortExam, double project, double exam) {
	this-> shortExam = shortExam;
	this-> project = project;
	this-> exam = exam;

	weightShortExam=20;
	weightProject=30;
	weightExam=50;

	double aux = (shortExam*(weightShortExam / 100) + project * (weightProject / 100) + exam * (weightExam / 100));
	finalGrade = floor(aux + 0.5);
}

string Student:: getCode() const {
	return code;
}
string Student::getName() const {
	return name;
}
double Student:: getExam() const { // get the exam grade
	return this->exam;
}
double Student::getShortExam() const { //get the short exam grade 
	return this->shortExam;
}
double Student::getProject()const { //get the project grade 
	return this->project;
}
int Student::getFinalGrade() const {
	return finalGrade;
}

bool Student::isApproved() const {
	return (finalGrade >= 10);	
}
int Student::weightShortExam = 20;
int Student::weightProject = 30;
int Student::weightExam = 50;

Student readStudentData() {
	string code,name;
	double shortExam, project, exam;
	cout << "Student code? ";
	cin >> code;
	cin.ignore();
	cout << "Student name? ";
	getline(cin, name);
	Student info(code, name);
	cout << "Short exam grade? ";
	cin >> shortExam;
	cout << "Project grade? ";
	cin >> project;
	cout << "Exam grade? ";
	cin >> exam;

	info.setGrades(shortExam, project, exam);
	return info;
}

string showAboveAvarageStudents(stringstream& out, vector<Student>& m) {  //it shows a list of approved students

	out << left << setw(30) << "ID"
		<< setw(30) << "Name"
		<< setw(25) << "Project"
		<< setw(25) << "ShortExam"
		<< setw(25) << "Exam"
		<< "Final_grade" << endl;

	for (int i = 0; i < m.size(); i++) {
		if (m[i].isApproved())
			out << left << setw(30) << m[i].getCode()
			<< setw(30) << m[i].getName()
			<< setw(25) << m[i].getProject()
			<< setw(25) << m[i].getShortExam()
			<< setw(25) << m[i].getExam()
			<< m[i].getFinalGrade() << endl;

	}
	return out.str();
}

void inputVector(vector<Student>& m) {  // input the information about n students manually
	stringstream out;
	int numStudents;
	cout << "Number of students ? " << endl;
	cin >> numStudents;

	for (int i = 0; i < numStudents; i++) {
		cout << "Student number " << i << endl;
		m.push_back(readStudentData());
	}

	showAboveAvarageStudents(out, m);
}

Student push_student(string text) {  //extract information from a text and return a Student 
	size_t posb = 0;
	size_t pose;
	double shortExamGrade, projectGrade, examGrade;


	pose = text.find(';');
	string code = text.substr(0, pose);

	text[pose] = '-';
	posb = pose;
	pose = text.find(';');

	string name = text.substr(posb + 1, pose - posb - 1);

	Student aux(code, name);
	Student* ptr = &aux;

	text[pose] = '-';
	posb = pose;
	pose = text.find(';');

	shortExamGrade = stof(text.substr(posb + 1, pose - posb - 1));

	text[pose] = '-';
	posb = pose;
	pose = text.find(';');

	projectGrade = stof(text.substr(posb + 1, pose - posb - 1));
	examGrade = stof(text.substr(pose + 1));

	ptr->setGrades(shortExamGrade, projectGrade, examGrade);

	return aux;


}
void readFile(string name, vector<Student>& m) {  //read the file and push_back the information into a Student vector

	string text;
	ifstream file;
	file.open(name);

	if (file.is_open()) {
		while (getline(file, text)) {  //read the file
			m.push_back(push_student(text));  //push_back the information into the vector 
		}

	}
}

void writeFile(string name, string text) {  //write the file with the information 
	ofstream file;
	file.open(name);
	file << text;
}

int main() {
	stringstream out;
	vector<Student> m;
	readStudentData();
	readFile("text.txt", m);
	writeFile("Result.txt", showAboveAvarageStudents(out, m));

	return 0;

}
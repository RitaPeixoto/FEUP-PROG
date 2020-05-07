#include "2015-2.h"


Student::Student() {

}
Student::Student(const string &code, const string &name) {
	this->code = code;
	this->name = name;
}
int Student::weightShortExam = 20;
int Student::weightProject = 30;
int Student::weightExam = 50;

void Student::setGrades(double shortExam, double project, double exam) {//alinea a
	this-> shortExam=shortExam;
	this->project = project;
	this->exam = exam;
	finalGrade = round(((shortExam*weightShortExam) / 100 + (exam*weightExam) / 100 + (project*weightProject) / 100) + 0.5);
}
int Student::getFinalGrade() const {
	return finalGrade;
}

string Student::getName() const {
	return name;
}

Student readStudentData() { //alinea b)
	string code, name;
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

bool isApproved(Student student) {//alinea c
	if (student.getFinalGrade() >= 10) {
		return true;
	}
	return false;
}


void showApproved(ostream &out, const vector <Student> &students) {//alinea c

	for (int i = 0; i < size(students); i++) {
		if (isApproved(students[i])) {
			out << setw(50)<<students[i].getName()<<" " << setw(10) <<students[i].getFinalGrade()<<endl;
		}
	}

}





int main() {
	Student aluno1("up201806257", "Rita"), aluno2("up201806222", "Joana"),aluno;
	vector<Student> students;
	ostringstream out("");

	/*aluno =readStudentData();
    cout << aluno.getFinalGrade()<< " " <<aluno.getName();*/


	aluno1.setGrades(16, 17, 16);
	students.push_back(aluno1);
	aluno2.setGrades(20, 18, 15);
	students.push_back(aluno2);
	showApproved(out, students);

	cout << out.str();


	return 0;
}
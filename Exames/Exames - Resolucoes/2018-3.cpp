#include<vector>
#include<string>
#include<iostream>
using namespace std;


/*
d) Qual a saída do programa? ​ 2 3 ​	2 ​	2 3 
Qual seria a saída do programa se o qualificativo virtual fosse retirado da função show() da classe Base? 2 3 2 2

​O que aconteceria se o qualificativo protected da classe Base fosse substituído por private? 
Justifique brevemente a resposta.
​Não seria possível criar uma classe derivada de Base com o atributo a, uma vez que esta classe não poderia aceder aos atributos da classe de onde deriva,
pois como seriam privados, só a própria classe base lhes poderia aceder.
*/
float average(const int grades[], int numStudents) {
	float av=0;
	for (int i = 0; i < numStudents; i++) {
		av += grades[i];
	}
	return  av / numStudents;
}

void readGrades(int grades[], int numStudents) {

	int grade;
	for (int i = 0; i < numStudents; i++) {
		cout << "What is the grade of student number "<<i+1 <<" ?";
		cin >> grade;
		grades[i] = grade;
	}
	cout << average(grades, numStudents);
}




int main() {
	int num, *p;
	cout << "What is the number os students?";
	cin >> num;
	p = new int[num];
	/*int grades[] = {0};
	int num = 4;
	float a;
	float b;*/
	//b = sizeof(grades) / sizeof(const int);
	//cout << b << endl;
	readGrades(p,num);
	//a = average(grades, num);
	//cout << a << endl;
	return 0;
}

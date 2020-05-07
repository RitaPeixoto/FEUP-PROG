/*Pretende-se desenvolver um programa que mostre, no ecr�, o calend�rio de um dado ano.*/
/*Um ano bissexto � um ano que satisfaz as seguintes condi��es: � divis�vel por 4 mas n�o divis�vel por 100; no entanto, os anos divis�veis por 400,
apesar de serem divis�veis por 100, s�o considerados bissextos (ex: o ano 2000 foi bissexto mas o ano 2100 n�o ser�). Escreva uma fun��o que tenha 
como par�metro um n�mero inteiro representando um ano e retorne um valor booleano, indicando se o ano � ou n�o bissexto (true se for e false se n�o
for). Escreva um programa que teste essa fun��o. */
/* Escreva uma fun��o que tenha como par�metros dois inteiros, representando um m�s e um ano, e devolva o n�mero de dias desse m�s,
nesse ano. Note que apenas o m�s de Fevereiro tem um n�mero de dias vari�vel, consoante o ano seja ou n�o bissexto*/
/*Escreva uma fun��o que tenha como par�metros 3 n�meros inteiros, representando uma data (ano, m�s, dia), e que devolva um inteiro indicando o dia 
da semana correspondente. Escreva um programa que leia uma data e, usando essa fun��o, escreva o nome do dia da semana correspondente (Domingo, 
Segunda-feira, �). */
/*Escreva uma fun��o que, usando a fun��o desenvolvida na al�nea anterior, mostre no ecr� o calend�rio de um m�s/ano especificado pelo utilizador, 
com um formato semelhante ao seguinte: */
/*Finalmente, escreva um programa que, recorrendo �s fun��es anteriormente desenvolvidas e a outras que considere necess�rias, mostre no ecr� o 
calend�rio de todos os meses de um ano indicado pelo utilizador*/
#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

bool leap(int year) { // funcao que determina se o ano e bissexto ou nao
	bool leap_year = false;
	if (year % 4 == 0 && year % 100 != 0) {
			leap_year = true;
	}
	else if (year % 400 == 0) {
			leap_year = true;
		}	
	return leap_year;
}
int days(int year, int month) { // funcao que determina o n de dias que um certo mes de um certo ano tem
	switch (month) {
	case 2:
		if (leap(year) == true) {
			return 29;
		}
		else {
			return 28;
		}
		break;
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

int dayOfTheWeek(int day, int month, int year) { //funcao que determina o codigo do dia da semana
	int c;
	switch (month) {
	case 1:
		if (leap(year)) {
			c = 6;
			break;
		}

		else {
			c = 0;
			break;
		}

	case 2:
		if (leap(year)) {
			c = 2;
			break;
		}

		else {
			c = 3;
			break;
		}

	case 3:
		c = 3;
		break;

	case 4:
		c = 6;
		break;

	case 5:
		c = 1;
		break;

	case 6:
		c = 4;
		break;

	case 7:
		c = 6;
		break;

	case 8:
		c = 2;
		break;

	case 9:
		c = 5;
		break;

	case 10:
		c = 0;
		break;

	case 11:
		c = 3;
		break;

	case 12:
		c = 5;
		break;
	}
	int a = year % 100;
	int s = year / 100;
	return ((int)((5 * a) / 4) + c + day - 2 * (s % 4)) % 7;

}
string day(int number) { // funcao que retorna o dia da semana em string
	switch (number) {
	case 0:
		return "Sat";
	case 1:
		return "Sun";
	case 2:
		return "Mon";
	case 3:
		return "Tue";
	case 4:
		return "Wed";
	case 5:
		return "Thu";
	case 6:
		return "Fri";
	}
}

string month(int number) {// funcao que retorna o mes em string
	switch (number) {
	case 1:
		return " January";
	case 2:
		return " February";
	case 3:
		return " March";
	case 4:
		return " April";
	case 5:
		return " May";
	case 6:
		return " June";
	case 7:
		return " July";
	case 8:
		return " August";
	case 9:
		return " September";
	case 10:
		return " October";
	case 11:
		return " November";
	case 12:
		return " December";
	}
}
int calendar(int month, int year) { //funcao que desenha o calendario
	int width = 10, counter = 1;

	for (counter; counter <= 7; counter++) {
		cout << setw(width) << day(counter % 7); // para desenhar as colunas dos dias da semana
	}

	counter = 1;

	cout << endl;

	for (int i = 1; i <= days(month, year); i++) { // para escrever os dias 
		counter %= 7;

		if (dayOfTheWeek(i, month, year) != counter) {
			i--;
			cout << setw(width) << "";
		}

		else if (counter == 0) {
			cout << setw(width) << i << endl;
		}

		else {
			cout << setw(width) << i;

		}

		counter += 1;
	}
	return 0;
}

int main() {
	int year;

	cout << "Insert a year: ";
	cin >> year;

	for (int u_month = 1; u_month <= 12; u_month++) {
		cout << month(u_month) << '/' << year << endl;
		calendar(u_month, year);
		cout << endl << endl;
	}

	return 0;
}



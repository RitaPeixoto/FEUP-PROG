/*Escreva um programa que permita testar se o utilizador conhece as tabuadas da multiplica��o. O programa deve gerar 2 n�meros aleat�rios (entre 2 e 9), 
apresent�-los ao utilizador, e perguntar o resultado da multiplica��o desses n�meros. Ap�s ler a resposta do utilizador deve apresentar-lhe uma mensagem 
adequada tendo em conta a correc��o da resposta e o tempo que o utilizador demorou a d�-la: se a resposta estiver errada, o utilizador deve receber a 
mensagem "Muito Mau", se responder certo e demorar menos de 5 segundos deve receber a mensagem "Bom", se responder certo mas demorar entre 5 segundos e 
10 segundos (inclusiv�) deve receber a mensagem "Satisfaz", se n�o deve receber a mensagem "Insuficiente". Nota: A fun��o rand() gera um n�mero inteiro
pseudo-aleat�rio no intervalo [0..RAND_MAX] em que RAND_MAX � uma constante simb�lica definida na header file <cstdlib> (o standard ANSI especifica que
RAND_MAX deve ter o valor de pelo menos 32767). Para evitar que o gerador de n�meros pseudo-aleat�rios seja inicializado sempre com o mesmo valor, de cada
vez que o programa for executado, gerando sempre a mesma sequ�ncia de n�meros, inclua a instru��o srand(time(NULL)) no in�cio da fun��o main(); a fun��o 
srand(), que permite especificar a "semente" do gerador de n�meros aleat�rios, est� declarada em <cstdlib> e a fun��o time(), que retorna o n�mero de 
segundos que decorreram desde as zero horas do dia 1/Jan/1970, est� declarada em  <ctime>.  
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
	srand(time(NULL));

	int number1 = rand() % (9 - 2 + 1) + 2, number2 = rand() % (9 - 2 + 1) + 2, guess;

	cout << "Qual e o resultado de :  " << number1 << " * " << number2 << "?" << endl;

	time_t begin = time(0);

	cin >> guess;

	time_t end = time(0);

	time_t interval = end - begin;

	if (guess != number1 * number2) {
		cout << "Muito Mau";
	}

	else if (interval < 5) {
		cout << "Bom";
	}

	else if (interval >= 5 && interval <= 10) {
		cout << "Satisfaz";
	}

	else {
		cout << "Insuficiente";
	}

	return 0;
}
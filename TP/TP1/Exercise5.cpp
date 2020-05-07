/*Escreva um programa que leia dois tempos, expressos em horas, minutos e segundos e que determine a soma desses tempos. O diálogo deve 
aparecer no ecrã com o seguinte aspecto: 
Tempo 1 (horas minutos segundos) ? 10 35 50 
Tempo 2 (horas minutos segundos) ? 15 59 30
Soma dos tempos: 1 dia, 2 horas, 35 minutos e 20 segundos*/

#include <iostream>

using namespace std;

int main()
{
	int h1, m1, s1;
	int h2, m2, s2;
	int t, td, th, tm,ts;


	cout << "Tempo 1 (horas minutos segundos) ? ";
	cin >> h1 >> m1 >> s1;
	cout << "Tempo 2 (horas minutos segundos) ? ";
	cin >> h2 >> m2 >> s2;

	t = h1 * 60 * 60 + m1 * 60 + s1 + h2 * 60 * 60 + m2 * 60 + s2;  // soma dos dois tempos em segundos

	td = t / 86400; // saber o numero de dias 
	t = t % 86400;
	th = t/3600;  // saber o numero de horas
	t = t % 3600;
	tm = t/ 60; // saber o numero de minutos
	t = t % 60;
	ts = t;  // saber o numero de segundos

	cout << "Soma dos tempos : " << td << " dia, " << th << " horas, " << tm << " minutos e " << ts << " segundos "; 







	system("pause");
	return 0;
}
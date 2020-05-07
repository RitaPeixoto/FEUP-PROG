#include<iostream>
#include<string>
using namespace std;

/* Se nao existir um construtor da classe o compilador cria um que preenche os parametros da classe com valores sem significado.
No entanto, se ja existir um isso nao acontece. Neste caso, como j� existe um e este � com parametros, ou se cria um objeto chamando este construtor, ou se for o caso apresentado � apresentado um erro de compila�ao*/
// b) Sim, pois a classe Date possui valores definidos por omiss�o para os seus par�metros quando n�o s�o indicados nenhuns (como � o caso, sendo assim, o ano, m�s e dia de date1 ser�o 1).

//e) Tal n�o � poss�vel, porque a fun��o sort est� definida para receber um par de iteradores, n�o um container.
/*alinea f-o metodo estar definido como virtual na classe base ele torna-se virtual em todas as classes derivadas, tornando possivel de no caso de haver overloading de fun�oes em diferentes classes ser invocada
a fun�ao draw~de acordo com o objeto que invoca a fun�ao
f) O significado dessa defini��o do m�todo draw � que este � uma pure virtual function, ou seja, n�o possui defini��o, tendo esta de ser definida pelas classes derivadas de Shape,
tornando assim esta classe abstrata, ou seja, n�o pode ser declarada.*/

int readNumber(string msg) {//alinea a
	int number;
	cout << msg;
	cin >> number;
	return number;
}

void readNumber(string msg, int &grade) {//alinea a
	int number;
	cout << msg;
	cin >> number;
	grade = number;
}

int main() {//alinea a)
	string msg = "Grade? ";
	int grade;
	//first call
	int a=readNumber(msg);
	cout<< a<<endl;
	//second call
	readNumber(msg, grade);
	cout << grade;
}

/* ALINEA C
class Image {
	public:
		//...
	private:
		int **img; // image representation
		// ... other attributes
};
Seria necess�rio acrescentar um m�todo para alocar o espa�o necess�rio de maneira a que img possua o n�mero de linhas e colunas adequado:

img = new int *[nLins];

for (int i = 0; i < nLins; i++)
	img[i] = new int[nCols];*/

/*ALINEA D
Image::Image(size_t nLins = 0, size_t nCols = 0, int pixVal = 0) {
	this->nLins = nLins;
	this->nCols = nCols;

	for (int y = 0; y < nLins; y++)
		for (int x = 0; x < nCols; x++)
			img[y][x] = pixVal;
}*/
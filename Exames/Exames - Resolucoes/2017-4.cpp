#include<iostream>
#include<string>
using namespace std;

/* Se nao existir um construtor da classe o compilador cria um que preenche os parametros da classe com valores sem significado.
No entanto, se ja existir um isso nao acontece. Neste caso, como já existe um e este é com parametros, ou se cria um objeto chamando este construtor, ou se for o caso apresentado é apresentado um erro de compilaçao*/
// b) Sim, pois a classe Date possui valores definidos por omissão para os seus parâmetros quando não são indicados nenhuns (como é o caso, sendo assim, o ano, mês e dia de date1 serão 1).

//e) Tal não é possível, porque a função sort está definida para receber um par de iteradores, não um container.
/*alinea f-o metodo estar definido como virtual na classe base ele torna-se virtual em todas as classes derivadas, tornando possivel de no caso de haver overloading de funçoes em diferentes classes ser invocada
a funçao draw~de acordo com o objeto que invoca a funçao
f) O significado dessa definição do método draw é que este é uma pure virtual function, ou seja, não possui definição, tendo esta de ser definida pelas classes derivadas de Shape,
tornando assim esta classe abstrata, ou seja, não pode ser declarada.*/

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
Seria necessário acrescentar um método para alocar o espaço necessário de maneira a que img possua o número de linhas e colunas adequado:

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
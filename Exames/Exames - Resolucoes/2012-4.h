#pragma once
#include <vector>
#include <map>

using namespace std;


class Coin {
public:
	Coin(int v, char u);
	void showDescription() const; //mostra descrição da moeda (ex: 1E para um euro ou 2C para 2 cêntimos)
	double getValue() const; //NOTAR o double: retorna o valor da moeda em euros (ex: 0.01 para 1 cênt.)
private:
	int value;
	char unit; // 'E' para 'euro' ou 'C' para 'cêntimo'
};



struct Coins {
	int two_euro;
	int one_euro;
	int fifty_cents;
	int twenty_cents;
};

class Purse { //Exercise 4.a)
public:
	Purse();
	void insertCoin(Coin Coin);
	void insertCoins(vector <Coins> Coins);
	void showCoins() const;
	double getTotalAmount() const;
	Coin removeCoin(Coin Coin);
	vector <Coin> removeAmount(double amount);
	vector <Coin> exchangeCoin(Coin Coin);
private:
	map <Coin Coin, int quantity> coins; //«Coin» é o tipo de moeda e «quantity» é o número de moedas com desse tipo
};
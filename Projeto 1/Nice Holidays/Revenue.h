#pragma once
#include <iostream>
#include<vector>
#include<string>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include<algorithm>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include"structs.h"
#include"formating_get_auxiliar_functions.h"
using namespace std;
//funçao que calcula a receita


void show_total_revenue(string packs_file) {//Calcular e visualizar o número e o valor total de pacotes vendidos. 
	ifstream packs;
	Packs pack;
	vector<Packs>pack_list;
	int index = 0, aux_no, total_of_sold_packs = 0, total_of_money = 0, aux_price, choice;

	system("CLS");
	packs.open(packs_file);
	pack_list = packs_extract(packs);

	for (int i = 0; i < pack_list.size(); i++) {
		cout << pack_list[i].sold_spots << " were sold from pack number " << sqrt(pow(pack_list[i].pack_number, 2)) << endl;
		aux_no = pack_list[i].sold_spots;
		total_of_sold_packs += aux_no;
	}
	for (int j = 0; j < pack_list.size(); j++) {
		aux_no = pack_list[j].sold_spots;
		aux_price = pack_list[j].price_for_person;
		total_of_money += (aux_no*aux_price);
	}
	cout << endl << "The total of sold packs is: " << total_of_sold_packs << endl;
	cout << "Which is equivalent to a total revenue of " << total_of_money << " euros." << endl << endl;
	system("pause");

}
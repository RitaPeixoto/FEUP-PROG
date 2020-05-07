#include<iostream>
#include<string>
#include<vector>
#include "Exercise_6.h"
using namespace std;


int Product::id_number = 0;

Product::Product(string description, int available_quantity) {
	id_number++;
	this->description = description;
	this->available_quantity = available_quantity;
}

int Product::getId() const {
	return id_number;
}
int Product::getAvailableQuantity() const {
	return available_quantity;
}

void Product::reduceAvailableQuantity() {
	available_quantity--;
}

Inventory::Inventory(vector <Product> products) {
	this->products = products;
}

void Inventory::processOrder(int id) {
	if (products[id].getAvailableQuantity() > 0)
		products[id].reduceAvailableQuantity();

	else
		backOrders.push_back(products[id]);
}

/*void Inventory::processShipment(int id) {
	for (int i = 0; i < size(backOrders); i++) {
		if (backOrders[i].getId == id)

	}
}*/
int main() {

	return 0;
}
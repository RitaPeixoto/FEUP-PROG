#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include"Exercise_4.h"
using namespace std;
//CLIENT
Client::Client() {
	name == "";
	address == "";
}

Client::Client(string name, string address) {
	this->name = name;
	this->address = address;
}

string Client::getName() const {
	return name;
}

string Client::getAddress() const {
	return address;
}

//PRODUCT
Product::Product() {
	this->description = "";
	this->price = 0;
}

Product::Product(string description, double price) {
	this->description = description;
	this->price = price;
}

string Product::getDescription()const {
	return description;
}

double Product::getPrice()const {
	return price;
}

//ITEM
unsigned int Item::getQuantity() {
	return quantity;
}

float Item::getTotalPrice() {
	return total_price;
}

Product Item::getProduct() {
	return Product;
}

//INVOICE

void Invoice::showLine(int itemNumber) {
	cout << items[itemNumber].getProduct().getDescription() << setw(23) << " "
		<< items[itemNumber].getProduct().getPrice() << setw(5) << " "
		<< items[itemNumber].getQuantity() << setw(5) << " "
		<< items[itemNumber].getTotalPrice() << setw(8) << endl;
}

void Invoice::show() {
	cout << Client.getName() << endl
		<< Client.getAddress() << endl
		<< "Description" << setw(23) << " " << "Price" << setw(5) << " " << "Qty" << setw(5) << " " << setw(8) << "Total" << endl
		<< "-------------------- ------ ---- - --------" << endl;

	for (int i = 0; i < size(items); i++)
		showLine(i);

	cout << "Amount due: " << amount_due << " euro";
}


int main() {
	Client Client("DEI- FEUP ", "Rua Dr. Roberto Frias, s/n \n4200 - 465 Porto \n");
	Product Product1("Computer", 999.90);
	Product Product2("Printer", 149.90);
	Item Item1(Product1, 10);
	Item Item2(Product2, 1);
	Invoice Invoice(Client, { Item1,Item2 });

	Invoice.show();
	cout << endl;
	return 0;
}
#pragma once
#include<string>
#include<vector>
using namespace std;

class Client {
	public:
		Client();
		Client(string name, string address);
		string getName() const;
		string getAddress() const;
	private:
		string name;
		string address;

};

class Product {
	public:
		Product();
		Product(string description, double price);
		string getDescription()const;
		double getPrice()const;
	private:
		string description;
		double price;
};

class Item {
	public:
		Item(Product Product, unsigned int quantity) {
			this->Product = Product;
			this->quantity = quantity;
			total_price = Product.getPrice() * quantity;
		}
		Product getProduct();
		unsigned int getQuantity();
		float getTotalPrice();
	private:
		Product Product;
		unsigned int quantity;
		float total_price;
};

class Invoice {
	public:
		Invoice(Client Client, vector <Item> items) {
			this->Client = Client;
			this->items = items;
			amount_due = 0;

			for (int i = 0; i < size(items); i++) {
				amount_due += items[0].getTotalPrice();
			}
		}
		void showLine(int itemNumber);
		void show();
	private:
		Client Client;
		vector <Item> items;
		float amount_due;
};
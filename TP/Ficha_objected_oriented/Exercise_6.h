#pragma once
#include<string>
#include<vector>
using namespace std;


class Product {
	public:
		Product(string description, int available_quantity);
		int getId() const;
		int getAvailableQuantity() const;
		void reduceAvailableQuantity();
	private:
		static int id_number;
		string description;
		int available_quantity;
};

class Inventory {
	public:
		Inventory(vector <Product> products);
		void processOrder(int id);
		//void processShipment(int id);
	private:
		vector <Product> products;
		vector <Product> backOrders;
};
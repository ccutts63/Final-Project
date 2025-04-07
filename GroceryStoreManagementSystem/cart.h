#pragma once

#include "product.h"

class Cart
{
private:
	Product** products;
	int* quantity;
	int itemCount;
	double totalCost;
	
public:
	char name[20];
	double price;

	Cart();
	~Cart();

	void AddItem(Product& product, int quantity);

	double GetTotalCost() const;

	void Checkout();

	void DisplayCart() const;

};


#pragma once

#include <iostream>
#include <cstring>
//
class Product
{
private:
	char* name;
	double price;
	int quantity;

public:
	//constructor and destructor
	Product();
	Product(const char* name, double price, int quantity);
	~Product();

	//functions
	const char* GetName() const;
	double GetPrice() const;
	int GetQuantity() const;
	void Set(const char* name, double price, int quantity);

};


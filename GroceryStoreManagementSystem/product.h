#pragma once
class Product
{
private:
	char* name;
	double price;
	int quantity;

public:
	//constructor and destructor
	Product(const char* name, double price, int quantity);
	~Product();

	//functions
	const char* GetName() const;
	double GetPrice() const;
	int GetQuantity() const;
	void SetPrice(double newPrice);
	void SetQuantity(int newQuantity);
	void PrintDetails() const;

};


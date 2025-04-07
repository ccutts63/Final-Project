#include "product.h"


Product::Product() {
	name = new char[20];
	name[0] = '\0';
	price = 0.0;
	quantity = 0;
}

//need more coffee :(
Product::Product(const char* name, double price, int quantity) {
	this->name = new char[20];
	strcpy_s(this->name, 20, name);
	this->price = price;
	this->quantity = quantity;
}

Product::~Product() {
	delete[] name;
}

const char* Product::GetName() const {
	return name;
}

double Product::GetPrice() const {
	return price;
}

int Product::GetQuantity() const {
	return quantity;
}

void Product::Set(const char* name, double price, int quantity) {
	strcpy_s(this->name, 20, name);
	this->price = price;
	this->quantity = quantity;
}

void Product::PrintDetails() const {
	std::cout << "Name: " << name << ", Price: " << price << ". Quantity: "
		<< quantity << std::endl;
}

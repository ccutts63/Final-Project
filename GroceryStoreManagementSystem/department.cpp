#include "department.h"
#include <cstring>
#include <iostream>

Department::Department(const char* name) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

	items = nullptr;
	totalItems = 0;
}

Department::~Department() {
	delete[] name;
	delete[] items;
}

void Department::AddItem(const Product& newItem) {
	Product* newArray = new Product[totalItems + 1];

	for (int i = 0; i < totalItems; ++i) {
		newArray[i] = items[i];
	}

	newArray[totalItems] = newItem;

	delete[] items;

	items = newArray;
	++totalItems;

}

void Department::ListItems() const {
	std::cout << "Items in department: " << name << std::endl;
	for (int i = 0; i < totalItems; ++i) {
		//std::cout << "[" << (i + 1) << "] " << items[i].PrintDetails();
	}
}

const char* Department::GetDepartmentName() const {
	return name;
}

int Department::GetTotalItems() const {
	return totalItems;
}
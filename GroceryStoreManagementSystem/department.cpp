#include "department.h"

Department::Department() {
	name = nullptr;
	items = nullptr;
	totalItems = 0;

}

Department::Department(const char* name) {
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, 20, name);

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
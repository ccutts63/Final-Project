#include "department.h"

Department::Department() {
	name = new char[20];
	name[0] = '\0';
	items = nullptr;
	totalItems = 0;

}

Department::Department(const char* name) {
	this->name = new char[20];
	strcpy_s(this->name, 20, name);
	items = nullptr;
	totalItems = 0;
}


Department::Department(const Department& other) {
	name = new char[20];
	strcpy_s(this->name, 20, other.name);

	totalItems = other.totalItems;

	if (other.items != nullptr) {
		items = new Product[totalItems];
		for (int i = 0; i < totalItems; ++i) {
			items[i] = other.items[i];  // Deep copy items
		}
	}
	else {
		items = nullptr;
	}
}


Department& Department::operator=(const Department& other) {
	if (this != &other) {
		delete[] name;
		name = new char[20];
		strcpy_s(name, 20, other.name);
		items = nullptr;
	}
	return *this;
}


Department::~Department() {
	//delete[] name;
	//delete[] items;

}

void Department::AddItem(const Product& newItem) {

	Product* newArray = new Product[totalItems + 1];

	for (int i = 0; i < totalItems; ++i) {
		newArray[i] = items[i];
	}

	newArray[totalItems] = newItem;

	if (sizeof items / sizeof items[0] > 1) {
		delete[] items;
	}
	

	items = newArray;

	++totalItems;
}


void Department::ListItems() const {
	std::cout << "Items in department: " << name << std::endl;
	for (int i = 0; i < totalItems; ++i) {
		//std::cout << "[" << (i + 1) << "] " << items[i].PrintDetails();
	}
}

const char* Department::GetName() const {
	return name;
}

int Department::GetTotalItems() const {
	return totalItems;
}

void Department::SetDepartmentInfo(const char* depName, Product* P, int pCount) {

	strcpy_s(name, 20, depName);
	AddItem(*P);
}

const Product& Department::GetProduct(int i) const {
	return items[i];
}
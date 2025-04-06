#include "department.h"

Department::Department() {
	name = nullptr;
	items = nullptr;
	totalItems = 0;

}

Department::Department(const char* name) {
	size_t len = strlen(name) + 1;
	this->name = new char[len];
	strcpy_s(this->name, len, name);
	items = nullptr;
	totalItems = 0;
}


Department::Department(const Department& other) {
	size_t len = strlen(other.name) + 1;
	name = new char[len];
	strcpy_s(name, len, other.name);

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
		size_t len = strlen(other.name) + 1;
		name = new char[len];
		strcpy_s(name, len, other.name);
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

const char* Department::GetDepartmentName() const {
	return name;
}

int Department::GetTotalItems() const {
	return totalItems;
}
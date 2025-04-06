#include "department.h"
#include <cstring>
#include <iostream>

Department::Department(const char* name) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

	//items = nullptr;
	totalItems = 0;
}

Department::~Department() {
	delete[] name;
	//delete[] items;
}

//void Department::addItem(const Product* newItem) {
//	//placeholder implementation
//}

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
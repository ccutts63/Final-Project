#include "department.h"
#include <cstring>

Department::Department(const char* name) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
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
	//placeholder implementation
}

const char* Department::GetDepartmentName() const {
	return name;
}

int Department::GetTotalItems() const {
	return totalItems;
}
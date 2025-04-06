#include "product.h"

#pragma once
class Department
{
private:
	
	char* name;
	Product* items;
	int totalItems;
public:
	Department(const char* name);

	~Department();

	void ListItems() const;
	const char* GetDepartmentName() const;
	int GetTotalItems() const;
	void AddItem(const Product& newItem);
};


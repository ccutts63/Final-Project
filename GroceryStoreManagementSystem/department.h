#pragma once

#include <cstring>
#include <iostream>
#include "product.h"



class Department
{
protected:
	
private:
	
	char* name;
	Product* items;
	int totalItems;

public:
	

	Department();
	Department(const char* name);

	~Department();

	void ListItems() const;
	const char* GetDepartmentName() const;
	int GetTotalItems() const;
	void AddItem(const Product& newItem);
};


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
	Department(const Department& other);
	Department& operator=(const Department& other);

	~Department();

	void ListItems() const;
	const char* GetDepartmentName() const;
	int GetTotalItems() const;
	void AddItem(const Product& newItem);
};


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
	
	void SetDepartmentInfo(const char* depName, Product* P, int pCount);

	Department();
	Department(const char* name);
	Department(const Department& other);
	Department& operator=(const Department& other);

	~Department();

	Product& GetProduct(int i);
	void ListItems() const;
	const char* GetName() const;
	int GetTotalItems() const;
	void AddItem(const Product& newItem);
};


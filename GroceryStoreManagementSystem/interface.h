#pragma once

#include "cart.h"
#include "globals.h"
#include <iostream>
#include "department.h"
#include <fstream>
#include <string>
#include <sstream>

class Interface
{
protected:

public:
	Interface();
	virtual ~Interface();
	void ListDepartments() const;
	virtual void run();
};

class Manager : public Interface {
private:
	void AddDepartment();
	void AddItemToDepartment();
	int SaveChangesToCsv();
	int LoadDataFromCsv();

public:
	Manager();
	~Manager();

	void run() override;
};

class Customer : public Interface {
public:
	void run() override;

protected:
	void ShowCart();
	void BrowseDepartments();
};
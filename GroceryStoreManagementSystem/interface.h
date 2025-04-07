#pragma once

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
	const char* GetName() const;
	int GetID() const;
	virtual void run();
};

class Manager : public Interface {
private:
	void ListDepartments() const;
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
	Customer();
	virtual ~Customer();
	void run() override;

protected:

};
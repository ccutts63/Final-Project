#pragma once

#include "globals.h"
#include <iostream>
#include "department.h"

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
	void SaveChangesToCsv();

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
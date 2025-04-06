#pragma once
class Department
{
private:
	char* name;
	//product class items//
	int totalItems;
public:
	Department(const char* name);

	~Department();

	void ListItems() const;
	const char* GetDepartmentName() const;
	int GetTotalItems() const;
	//void addItem(const Product* newItem);
};


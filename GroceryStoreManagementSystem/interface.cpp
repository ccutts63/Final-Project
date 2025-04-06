#include "interface.h"



Interface::Interface(){

}

Interface::~Interface() {

}

void Interface::run() {

}

//MANAGER FUNCTIONS
Manager::Manager() : Interface() {

}

Manager::~Manager() {

}

void Manager::run() {
	int choice;

	while (true) {
		std::cout << "\nManager Menu:\n";
		std::cout << "1. List Departments\n";
		std::cout << "2. Add Department\n";
		std::cout << "3. Add Item to Department\n";
		std::cout << "4. Save Changes to CSV\n";
		std::cout << "5. Exit\n";
		std::cout << "Enter your choice [1-5]: ";

		std::cin >> choice;

		switch (choice) {
		case 1:
			ListDepartments();
			break;
		case 2:
			AddDepartment();
			break;
		case 3:
			AddItemToDepartment();
			break;
		case 4:
			//SaveChangesToCSV();
			break;
		case 5:
			std::cout << "Exiting Manager Interface.\n";
			return;
		default:
			std::cout << "Invalid input." << std::endl;
			break;
		}
	}
}

void Manager::AddDepartment() {
	char depName[20];  // Local buffer safely on the stack

	std::cout << "Enter New Department Name: ";
	std::cin.ignore();
	std::cin.getline(depName, 20);

	if (strlen(depName) < 1) {
		std::cout << "Department name too short";
		return;
	}

	Department* newDepartment = new Department[totalDepartments + 1];

	for (int i = 0; i < totalDepartments; ++i) {
		newDepartment[i] = storeDepartments[i];
	}

	newDepartment[totalDepartments] = Department(depName);

	delete[] storeDepartments;
	storeDepartments = newDepartment;
	++totalDepartments;

	std::cout << "Department added" << std::endl;
}


void Manager::ListDepartments() const {
	std::cout << "Departments: " << std::endl;

	for (int i = 0; i < totalDepartments; ++i) {
		std::cout << "[" << (i + 1) << "] " << storeDepartments[i].GetDepartmentName();
	}
}

void Manager::AddItemToDepartment(){

	int selectedDepartment;
	char itemName[20];
	double itemPrice;
	int itemQuantity;

	std::cout << "Chose a department number:" << std::endl;
	ListDepartments();
	
	std::cin >> selectedDepartment;

	std::cout << "Enter Item Name: ";

	std::cin.ignore();
	std::cin.getline(itemName, 20);

	std::cout << "Enter Item Price: ";

	std::cin >> itemPrice;
	
	std::cout << "Enter Item Quantity: ";

	std::cin >> itemQuantity;

	Product newItem(itemName, itemPrice, itemQuantity);
	storeDepartments[selectedDepartment].AddItem(newItem);

	std::cout << "Item added successfully!" << std::endl;
}

//Customer FUNCTIONS

Customer::Customer() : Interface() {

}

Customer::~Customer() {

}

void Customer::run() {
	// Your implementation for customer menu
	std::cout << "Running customer interface...\n";
}



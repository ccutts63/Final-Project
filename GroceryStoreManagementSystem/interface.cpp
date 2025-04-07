#include "interface.h"

const char* csvFile = ".\grocery.csv";

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
		std::cout << "5. Load Data From CSV\n";
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
			SaveChangesToCsv();
			break;
		case 5:
			LoadDataFromCsv();
			break;
		case 6:
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
		std::cout << "[" << (i + 1) << "] " << storeDepartments[i].GetName();
	}
}

void Manager::AddItemToDepartment(){

	int selectedDepartment = -1;
	char itemName[20] = "";
	double itemPrice = -1;
	int itemQuantity = -1;



	while (selectedDepartment < 0 || selectedDepartment > totalDepartments) {
		ListDepartments();

		std::cout << "\nChose a department number [0 to go back]:" << std::endl;


		std::cin >> selectedDepartment;

		if (selectedDepartment == 0) {
			return;
		}
	}

	while (strlen(itemName) < 1) {
		std::cout << "Enter Item Name: ";

		std::cin.ignore();

		std::cin.getline(itemName, 20);
	}
	
	while (itemPrice < 0) {
		std::cout << "Enter Item Price: ";

		std::cin >> itemPrice;
	}
	
	while (itemQuantity < 0) {
		std::cout << "Enter Item Quantity: ";

		std::cin >> itemQuantity;
	}
	

	Product* newItem = new Product(itemName, itemPrice, itemQuantity);
	storeDepartments[selectedDepartment - 1].AddItem(*newItem);
	delete newItem;

	std::cout << "Item added successfully!" << std::endl;
}

int Manager::LoadDataFromCsv()
{
	std::ifstream file(csvFile);
	if (!file.is_open()) {
		std::cout << "Error opening file" << std::endl;
		return 1;
	}
	std::string line;
	getline(file, line);// the first line is number of departments.
	totalDepartments = stoi(line);
	storeDepartments = new Department[totalDepartments];
	for (int d = 0; d < totalDepartments; d++)
	{
		getline(file, line);
		std::string depName;
		int pCount;

		std::stringstream ss(line);
		getline(ss, depName, ',');
		ss >> pCount;

		Product* P = new Product[pCount];

		for (int i = 0; i < pCount; i++)
		{
			getline(file, line);
			std::string pName;
			float pPrice;
			int pQuantity;

			std::stringstream ss(line);
			getline(ss, pName, ',');
			ss >> pPrice;
			ss.ignore();
			ss >> pQuantity;

			P[i].Set(pName.c_str(), pPrice, pQuantity);
		}
		storeDepartments[d].SetDepartmentInfo(depName.c_str(), P, pCount);
	}
}

int Manager::SaveChangesToCsv()
{
	std::ofstream file(csvFile);
	if (!file.is_open()) {
		std::cout << "Error opening file for writing" << std::endl;
		return 1;
	}

	// Write the total number of departments
	file << totalDepartments << std::endl;

	for (int d = 0; d < totalDepartments; d++)
	{
		const Department& dept = storeDepartments[d];
		const char* depName = dept.GetName();  // Assuming a getter like this exists
		int pCount = dept.GetTotalItems();   // Assuming this returns product count

		// Write department name and product count
		file << depName << "," << pCount << std::endl;

		for (int i = 0; i < pCount; i++)
		{
			const Product& prod = dept.GetProduct(i);  // Assuming this returns a reference to a product

			const char* pName = prod.GetName();   // Assuming a getter like this
			float pPrice = prod.GetPrice();       // Assuming a getter like this
			int pQuantity = prod.GetQuantity();   // Assuming a getter like this

			// Write product details
			file << pName << "," << pPrice << "," << pQuantity << std::endl;
		}
	}

	return 0; // Success
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



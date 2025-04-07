#include "interface.h"

const char* csvFile = "grocery.csv";
Cart* myCart;

Interface::Interface(){

}

Interface::~Interface() {

}

void Interface::run() {

}

void Interface::ListDepartments() const {
	std::cout << "Departments: " << std::endl;

	for (int i = 0; i < totalDepartments; ++i) {
		std::cout << "[" << (i + 1) << "] " << storeDepartments[i].GetName() << std::endl;
	}
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
	return 0;
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
		Department& dept = storeDepartments[d];
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


void Customer::run() {

	int choice = 0;

	while (choice < 1 || choice > 3) {
		std::cout << "\nCustomer Menu:\n";
		std::cout << "1. Show Cart\n";
		std::cout << "2. Browse Departments\n";
		std::cout << "3. Exit\n";
		std::cout << "Enter your choice [1-3]: ";

		std::cin >> choice;

		switch (choice) {
		case 1:
			ShowCart();
			break;
		case 2:
			BrowseDepartments();
			break;
		case 3:
			return;
			break;
		default:
			std::cout << "Invalid Input\n";
			break;
		}
	}

}

void Customer::ShowCart() {
	int choice = 0;

	while (choice < 1 || choice > 3) {
		std::cout << "\nCart Menu:\n";
		std::cout << "1. List Items\n";
		std::cout << "2. Checkout\n";
		std::cout << "3. Exit\n";
		std::cout << "Enter your choice [1-3]: ";

		std::cin >> choice;

		switch (choice) {
		case 1:
			myCart->DisplayCart();
			break;
		case 2:
			myCart->Checkout();
			break;
		case 3:
			return;
			break;
		default:
			std::cout << "Invalid Input\n";
			break;
		}
	}
}

void Customer::BrowseDepartments() {
	int choice = 0;
	int deptNum;
	int itemNum;

	while (choice != 1 && choice != 2) {
		ListDepartments();

		std::cout << "\n[1] List Items of a Department\n";
		std::cout << "[2] Main Menu\n";
		std::cout << "Enter your choice [1, 2]\n";

		std::cin >> choice;

	}
	
	if (choice == 2) {
		return;
	}

	choice = -1;

	while (choice > totalDepartments || choice < 0) {
		std::cout << "Enter Department Number [0 to go Back]\n";


	}

	if (choice == 0) {
		return;
	}

	deptNum = choice;

	storeDepartments[choice].ListItems();

	choice = 0;

	while (choice != 1 && choice != 2) {

		std::cout << "\n[1] Cart an Item\n";
		std::cout << "[2] Back\n";
		std::cout << "Enter your choice [1, 2]\n";

		std::cin >> choice;

	}

	if (choice == 2) {
		return;
	}

	choice = -1;

	while (choice > storeDepartments[deptNum].GetTotalItems() || choice < 0) {
		std::cout << "Enter Item Number to buy [0 to go Back]\n";

	}

	itemNum = choice;

	choice = 0;

	while (choice < 1) {
		std::cout << "Enter Quantity to buy: ";

		
	}

	myCart->AddItem(storeDepartments[deptNum].GetProduct(itemNum), choice);
	
	std::cout << "Item Added to Cart!";

	return;
	
}




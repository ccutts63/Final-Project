#include "department.h"
#include "interface.h"
#include <iostream>
#include "globals.h"


Department* storeDepartments = nullptr;
int totalDepartments = 0;

using namespace std;

int main() {
	int choice;
	Interface* userInterface = nullptr;

	while (true) {
		cout << "\nWelcome to the Grocery Store Management System\n";
		cout << "1. Customer\n";
		cout << "2. Manager\n";
		cout << "3. Exit\n";
		cout << "Enter your choice [1, 2, 3]: ";

		cin >> choice;

		switch (choice) {
		case 1:
			userInterface = new Customer();
			userInterface->run();
			delete userInterface;
			break;
		case 2:
			userInterface = new Manager();
			userInterface->run();
			delete userInterface;
			break;
		case 3:
			cout << "Exiting...";
			return 0;
		default:
			cout << "no good try again";
			break;
		}

	}


	return 0;
}


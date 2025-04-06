#include "department.h"
#include <iostream>

void CustomerInterface();
void ManagerInterface();

extern Department* storeDepartments = nullptr;
extern int totalDepartments = 0;
extern const char* csvFile = "";

using namespace std;

int main() {

	int choice;

	while (true) {
		cout << "Customer [1]" << endl;
		cout << "Manager [2]" << endl;
		cout << "Exit [3]" << endl;
		cout << "choice? ";

		cin >> choice;

		switch (choice) {
		case 1:
			CustomerInterface();
			break;
		case 2:
			ManagerInterface();
			break;
		case 3:
			return 0;
			break;
		default:
			cout << "Invalid choice" << endl;
			break;
		}
	}
}

void CustomerInterface() {
	cout << "Customer Interface" << endl;
	return;
}

void ManagerInterface() {
	int choice;

	while (true) {
		
		cout << "List Departments [1]" << endl;
		cout << "Add Department [2]" << endl;
		cout << "Add Item to Department [3]" << endl;
		cout << "Save Changes to CSV [4]" << endl;
		cout << "Exit [5]" << endl;
		cout << "choice? ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "list department..." << endl;
			break;
		case 2:
			cout << "add department..." << endl;
			break;
		case 3:
			cout << "add item to department..." << endl;
			break;
		case 4:
			cout << "save changes to csv..." << endl;
			break;
		case 5:
			return;
			break;
		default:
			cout << "Invalid choice" << endl;
			break;
		}
	}
}
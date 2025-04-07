#include "cart.h"

Cart::Cart() : products(nullptr), quantity(nullptr) {
	name[0] = '\0';
	price = 0;
	itemCount = 0;
	totalCost = 0.0;

}


void Cart::AddItem(Product& product, int q) {
	Product** temp = new Product * [itemCount + 1];
	int* tempQuantities = new int[itemCount + 1];

	for (int i = 0; i < itemCount; ++i) {
		temp[i] = products[i];
		tempQuantities[i] = quantity[i];
	}

	temp[itemCount] = &product;
	tempQuantities[itemCount] = q;

	delete[] products;
	delete[] quantity;

	products = temp;
	quantity = tempQuantities;

	itemCount++;
	totalCost += product.GetPrice() * q;


}

Cart::~Cart() {
	delete[] products;
	delete[] quantity;
}

double Cart::GetTotalCost() const {
	return totalCost * 1.13;
}

void Cart::DisplayCart() const {

	if (products == nullptr) {
		return;
	}

	std::cout << "Shopping Cart:" << std::endl;

	for (int i = 0; i < itemCount; ++i) {
		std::cout << "Name: " << products[i]->GetName() << " $" << products[i]->GetPrice();
		std::cout << " [x" << quantity[i] << "]" << std::endl;
	}
	std::cout << "SubTotal: $" << totalCost << std::endl;
	std::cout << "Total:    $" << GetTotalCost() << std::endl;
}

void Cart::Checkout() {
	if (itemCount < 1) {
		std::cout << "No items in cart\n";
		return;
	}

	delete[] products;
	products = nullptr;

	std::cout << "Thanks for your Purchase" << std::endl;
}
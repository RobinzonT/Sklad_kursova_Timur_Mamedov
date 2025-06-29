#include "Product.h"

Product::Product(int id, const std::string& name, int qty)
	: id(id), name(name), quantity(qty) { }

int Product::getId() const {
	return id;
}

std::string Product::getName() const {
	return name;
}

int Product::getQuantity() const {
	return quantity;
}

void Product::setQuantity(int qty) {
	quantity = qty;
}
#include "Warehouse.h"
#include <stdexcept>

void Warehouse::addProduct(const Product& product) {
	for (auto& p : products) {
		if (p.getId() == product.getId()) {
			p.setQuantity(p.getQuantity() + product.getQuantity());
			return;
		}
	}
	products.push_back(product);
}

bool Warehouse::checkAvailability(int productId, int requiredQty) const {
	for (const auto& p : products) {
		if (p.getId() == productId && p.getQuantity() >= requiredQty)
			return true;
	}
	return false;
}

void Warehouse::removeProduct(int productId, int qty) {
	for (auto& p : products) {
		if (p.getId() == productId) {
			if (p.getQuantity() < qty)
				throw std::runtime_error("Not enough goods in stock.");
			p.setQuantity(p.getQuantity() - qty);
			return;
		}
	}
	throw std::runtime_error("Goods not found.");
}

const std::vector<Product>& Warehouse::getProducts() const {
    return products;
} 
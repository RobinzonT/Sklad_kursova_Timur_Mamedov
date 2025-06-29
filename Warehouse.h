#pragma once
#include <vector>
#include "Product.h"

class Warehouse {
private:
	std::vector<Product> products;

public:
	void addProduct(const Product& product);
	bool checkAvailability(int productId, int requiredQty) const;
	void removeProduct(int productId, int qty);
	const std::vector<Product>& getProducts() const;
};
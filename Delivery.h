#pragma once
#include <vector>
#include "Product.h"
#include "Warehouse.h"

class Delivery {
private:
	std::vector<Product> deliveredProducts;

public:
	explicit Delivery(const std::vector<Product>& products);
	const std::vector<Product>& getDeliveredProducts() const;
	void deliverTo(Warehouse& warehouse);
};
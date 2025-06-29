#include "Delivery.h"

Delivery::Delivery(const std::vector<Product>& products)
	:deliveredProducts(products){ }

const std::vector<Product>& Delivery::getDeliveredProducts() const {
	return deliveredProducts;
}

void Delivery::deliverTo(Warehouse& warehouse) {
	for (const auto& product : deliveredProducts) {
		warehouse.addProduct(product);
	}
}

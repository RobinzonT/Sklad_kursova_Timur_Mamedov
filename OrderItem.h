#pragma once
#include "Product.h"

class OrderItem {
private:
	Product product;
	int quantity;

public:
	OrderItem(const Product& product, int quantity);
	Product getProduct() const;
	int getQuantity() const;
};
#include "OrderItem.h"

OrderItem::OrderItem(const Product& product, int quantity)
	:product(product),quantity(quantity){ }

Product OrderItem::getProduct()const {
	return product;
}

int OrderItem::getQuantity() const {
	return quantity;
}
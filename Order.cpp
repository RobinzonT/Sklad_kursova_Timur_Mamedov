#include "Order.h"

Order::Order(int id) : id(id), status(OrderStatus::Pending){}

void Order::addItem(const OrderItem& item) {
	items.push_back(item);
}

const std::vector<OrderItem>& Order::getItems() const {
	return items;
}

OrderStatus Order::getStatus() const {
	return status;
}

void Order::setStatus(OrderStatus newStatus) {
	status = newStatus;
}

int Order::getId() const {
	return id;
}
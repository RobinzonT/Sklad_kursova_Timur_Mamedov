#include "Customer.h"

Customer::Customer(const std::string& name) :User(name) { }

void Customer::placeOrder(const Order& order) {
    myOrders.push_back(order);
}

const std::vector<Order>& Customer::getOrders() const {
	return myOrders;
}
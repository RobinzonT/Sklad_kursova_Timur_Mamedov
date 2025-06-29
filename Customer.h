#pragma once
#include <vector>
#include "User.h"
#include "Order.h"

class Customer :public User {
private:
	std::vector<Order> myOrders;

public:
	explicit Customer(const std::string& name);
	void placeOrder(const Order& order);
	const std::vector<Order>& getOrders() const;
};
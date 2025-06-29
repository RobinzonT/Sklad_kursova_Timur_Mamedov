#pragma once
#include <string>

class Product {
private:
	int id;
	std::string name;
	int quantity;

public:
	Product(int id, const std::string& name, int qty);
	int getId() const;
	std::string getName() const;
	int getQuantity() const;
	void setQuantity(int qty);
};
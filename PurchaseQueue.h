#pragma once
#include <map>

class PurchaseQueue {
private:
	std::map<int, int> pending;

public:
	void enqueue(int productId, int quantity);
	const std::map<int, int>& getPending() const;
	void clear();
};
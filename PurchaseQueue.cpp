#include "PurchaseQueue.h"

void PurchaseQueue::enqueue(int productId, int quantity) {
	pending[productId] += quantity;
}

const std::map<int, int>& PurchaseQueue::getPending() const {
	return pending;
}

void PurchaseQueue::clear() {
	pending.clear();
}
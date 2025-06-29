#include "Manager.h"

Manager::Manager(const std::string& name) : User(name) {}

void Manager::addProductToWarehouse(Warehouse& warehouse, const Product& product) {
    warehouse.addProduct(product);
}

void Manager::removeProductFromWarehouse(Warehouse& warehouse, int productId, int qty) {
    warehouse.removeProduct(productId, qty);
}

void Manager::queueMissingItems(const Order& order, const Warehouse& warehouse, PurchaseQueue& queue) const {
    for (const auto& item : order.getItems()) {
        int id = item.getProduct().getId();
        int qty = item.getQuantity();
        if (!warehouse.checkAvailability(id, qty)) {
            queue.enqueue(id, qty);
        }
    }
}

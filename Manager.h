#pragma once
#include "User.h"
#include "Warehouse.h"
#include "PurchaseQueue.h"
#include "Customer.h"

class Manager : public User {
public:
    explicit Manager(const std::string& name);

    void addProductToWarehouse(Warehouse& warehouse, const Product& product);
    void removeProductFromWarehouse(Warehouse& warehouse, int productId, int qty);
    void queueMissingItems(const Order& order, const Warehouse& warehouse, PurchaseQueue& queue) const;
};

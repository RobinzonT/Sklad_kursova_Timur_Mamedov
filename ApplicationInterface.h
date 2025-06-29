#pragma once

#include <vector>
#include "Customer.h"
#include "Manager.h"
#include "Warehouse.h"
#include "PurchaseQueue.h"
#include "Delivery.h"

class ApplicationInterface {
private:
    Warehouse warehouse;
    PurchaseQueue queue;
    Manager manager;
    std::vector<Customer> customers;

    void showManagerMenu();
    void showCustomerMenu();

    void warehouseManagementMenu();
    void printAllOrders() const;
    void printWarehouseInventory() const;
    void createCustomerOrder();

public:
    ApplicationInterface();
    void run(); 
};

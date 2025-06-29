#include "ApplicationInterface.h"
#include <iostream>
#include <limits>
#include <climits>

int safeIntInput(const std::string& prompt, int min = INT_MIN, int max = INT_MAX) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail() || value < min || value > max) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Please enter a number";
            if (min != INT_MIN || max != INT_MAX)
                std::cout << " (" << min << " to " << max << ")";
            std::cout << ".\n";
        }
        else {
            std::cin.ignore(10000, '\n');
            return value;
        }
    }
}

std::string safeStringInput(const std::string& prompt) {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (input.empty()) {
            std::cout << "Input cannot be empty. Try again.\n";
        }
        else {
            return input;
        }
    }
}

ApplicationInterface::ApplicationInterface()
    : manager("System Manager") {
}

void ApplicationInterface::run() {
    bool running = true;
    while (running) {
        std::cout << "\nWarehouse System\n";
        std::cout << "Select user role:\n";
        std::cout << "1. Manager\n";
        std::cout << "2. Customer\n";
        std::cout << "0. Exit\n";

        int role = safeIntInput("Your choice: ", 0, 2);

        switch (role) {
        case 1: showManagerMenu(); break;
        case 2: showCustomerMenu(); break;
        case 0: running = false; break;
        }
    }
}

void ApplicationInterface::showManagerMenu() {
    bool active = true;
    while (active) {
        std::cout << "\nManager Menu\n";
        std::cout << "1. Manage warehouse\n";
        std::cout << "2. View all orders\n";
        std::cout << "3. View warehouse inventory\n";
        std::cout << "0. Back\n";

        int choice = safeIntInput("Choose action: ", 0, 3);
        switch (choice) {
        case 1: warehouseManagementMenu(); break;
        case 2: printAllOrders(); break;
        case 3: printWarehouseInventory(); break;
        case 0: active = false; break;
        }
    }
}

void ApplicationInterface::showCustomerMenu() {
    bool active = true;
    while (active) {
        std::cout << "\nCustomer Menu\n";
        std::cout << "1. Create order\n";
        std::cout << "0. Back\n";

        int choice = safeIntInput("Choose action: ", 0, 1);
        switch (choice) {
        case 1: createCustomerOrder(); break;
        case 0: active = false; break;
        }
    }
}

void ApplicationInterface::warehouseManagementMenu() {
    std::cout << "\nWarehouse Management\n";
    std::cout << "1. Add product\n";
    std::cout << "2. Remove product\n";

    int action = safeIntInput("Choose action: ", 1, 2);
    int id = safeIntInput("Product ID: ", 0);
    std::string name = safeStringInput("Product name: ");
    int qty = safeIntInput("Quantity: ", 1);

    Product prod(id, name, qty);

    try {
        if (action == 1) {
            manager.addProductToWarehouse(warehouse, prod);
        }
        else {
            manager.removeProductFromWarehouse(warehouse, id, qty);
        }
    }
    catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
    }
}

void ApplicationInterface::printWarehouseInventory() const {
    std::cout << "\nWarehouse Inventory\n";
    const auto& products = warehouse.getProducts();
    if (products.empty()) {
        std::cout << "Warehouse is empty.\n";
        return;
    }
    for (const auto& product : products) {
        std::cout << "ID: " << product.getId()
            << ", Name: " << product.getName()
            << ", Quantity: " << product.getQuantity() << '\n';
    }
}

void ApplicationInterface::createCustomerOrder() {
    std::string customerName = safeStringInput("\nEnter customer name: ");
    Customer customer(customerName);
    static int nextOrderId = 1;
    Order order(nextOrderId++);

    char addMore = 'y';
    while (addMore == 'y' || addMore == 'Y') {
        int id = safeIntInput("Product ID: ", 0);
        std::string name = safeStringInput("Product name: ");
        int qty = safeIntInput("Quantity: ", 1);

        Product p(id, name, 0);
        OrderItem item(p, qty);
        order.addItem(item);

        std::cout << "Add another item? (y/n): ";
        std::cin >> addMore;
        std::cin.ignore(10000, '\n');
    }

    customer.placeOrder(order);
    customers.push_back(customer);
    manager.queueMissingItems(order, warehouse, queue);

    std::cout << "Order placed. Missing items (if any) have been queued.\n";
}

void ApplicationInterface::printAllOrders() const {
    std::cout << "\nAll Customer Orders\n";
    for (const auto& customer : customers) {
        std::cout << "Customer: " << customer.getName() << std::endl;
        for (const auto& order : customer.getOrders()) {
            std::cout << "  Order #" << order.getId() << " | Status: ";
            switch (order.getStatus()) {
            case OrderStatus::Pending: std::cout << "Pending"; break;
            case OrderStatus::PartiallyFulfilled: std::cout << "Partially Fulfilled"; break;
            case OrderStatus::Fulfilled: std::cout << "Fulfilled"; break;
            }
            std::cout << std::endl;
        }
    }
}

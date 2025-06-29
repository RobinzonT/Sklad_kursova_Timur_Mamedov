#pragma once
#include <vector>
#include "OrderItem.h"

enum class OrderStatus {
    Pending,
    PartiallyFulfilled,
    Fulfilled
};

class Order {
private:
    int id;
    std::vector<OrderItem> items;
    OrderStatus status;

public:
    Order(int id);
    void addItem(const OrderItem& item);
    const std::vector<OrderItem>& getItems() const;
    OrderStatus getStatus() const;
    void setStatus(OrderStatus newStatus);
    int getId() const;
};
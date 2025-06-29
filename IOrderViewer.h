#pragma once
 
class IOrderViewer {
public:
	virtual void viewOrders() const = 0;
	virtual ~IOrderViewer() = default;
};
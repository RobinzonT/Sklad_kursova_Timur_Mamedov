#pragma once

class IWarehouseUser {
public:
	virtual void accessWarehouse() = 0;
	virtual ~IWarehouseUser() = default;
};
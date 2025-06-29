#pragma once
#include <string>

class User {
protected:
	std::string name;

public:
	explicit User(const std::string& name);
	std::string getName() const;
	virtual ~User() = default;
};
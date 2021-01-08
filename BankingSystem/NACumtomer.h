#pragma once
#include "CUSTOMER.h"
class NACustomer : public Customer {
private:
	int interest;
public:
	NACustomer(int id, std::string name, int reserve, int interest)
		:Customer(id, name, reserve), interest(interest) {}
	double ShowInterestRate() const;
	int GetInterest() const;
};

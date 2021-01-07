#include <string>
#include <iostream>
#include "CUSTOMER.h"
namespace CUSTOMER_INFO{

	Customer::Customer(int id, std::string name, int reserve)
		: id(id), name(name), reserve(reserve) {}

	Customer::Customer()
		: id(), name(), reserve() {}

	Customer::Customer(const Customer& ref)
		: id(ref.id), name(ref.name), reserve(ref.reserve) {}

	bool Customer::IdCheck(int input) const {
		if (input == id) return true;
		else return false;
	}

	void Customer::ReserveIn(int in) {
		reserve += in;
	}

	void Customer::ReserveInterest() {
		reserve = (int)(reserve * ShowInterestRate());
	}

	void Customer::ReserveOut(int out) {
	reserve -= out;
	}

	int Customer::GetId() const {
		return id;
	}

	int Customer::GetReserve() const {
		return reserve;
	}

	std::string Customer::GetName() const {
		return name;
	}

	double NACustomer::ShowInterestRate() const {
		return 1+(GetInterest())/(double)100;
	}

	int NACustomer::GetInterest() const {
		return interest;
	}

	double HCACustomer::ShowInterestRate() const {
		return 1 + (GetInterest())/(double)100;
	}

	int HCACustomer::GetInterest() const {
		return additionalinterest + NACustomer::GetInterest();
	}

}


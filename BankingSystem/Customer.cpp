#include <string>
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

	void Customer::ReserveOut(int out) {
	reserve -= out;
	}

	int Customer::IdReturn() const {
		return id;
	}

	int Customer::ReserveReturn() const {
		return reserve;
	}

	std::string Customer::NameReturn() const {
		return name;
	}

}

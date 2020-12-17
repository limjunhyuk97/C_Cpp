#include <string>
#include "CUSTOMER.h"
namespace CUSTOMER_INFO{

	Customer::Customer(int id, std::string name, int reserve)
		: id(id), name(name), reserve(reserve) {}
	Customer::Customer()
		: id(), name(), reserve() {}
	bool Customer::IdCheck(int input) {
		if (input == id) return true;
		else return false;
	}
	void Customer::ReserveIn(int in) {
		reserve += in;
	}
	void Customer::ReserveOut(int out) {
	reserve -= out;
	}
	int Customer::IdReturn() {
		return id;
	}
	int Customer::ReserveReturn() {
		return reserve;
	}
	std::string Customer::NameReturn() {
		return name;
	}

}

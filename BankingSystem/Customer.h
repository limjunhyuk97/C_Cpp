#include <string>
#pragma once
namespace CUSTOMER_INFO {
	class Customer {
	private:
		int id = 0;
		std::string name;
		int reserve = 0;
	public:
		Customer(int id, std::string name, int reserve);
		Customer();
		Customer(const Customer& ref);
		bool IdCheck(int input) const;
		void ReserveIn(int in);
		void ReserveOut(int out);
		int IdReturn() const;
		int ReserveReturn() const;
		std::string NameReturn() const;
	};

}

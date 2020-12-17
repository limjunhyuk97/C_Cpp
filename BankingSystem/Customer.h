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
		bool IdCheck(int input);
		void ReserveIn(int in);
		void ReserveOut(int out);
		int IdReturn();
		int ReserveReturn();
		std::string NameReturn();
	};

}

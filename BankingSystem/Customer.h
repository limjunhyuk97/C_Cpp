#include <string>
#pragma once
namespace CUSTOMER_INFO {

	namespace CREDIT_LEVEL{
		enum {
			LEVEL_A = 1, LEVEL_B =2, LEVEL_C = 3
		};
	}

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
		void ReserveInterest();
		void ReserveOut(int out);
		int GetId() const;
		int GetReserve() const;
		std::string GetName() const;
		virtual double ShowInterestRate() const = 0;
		virtual int GetInterest() const = 0;
	};

	class NACustomer : public Customer {
	private:
		int interest;
	public:
		NACustomer(int id, std::string name, int reserve, int interest)
			:Customer(id, name, reserve), interest(interest) {}
		double ShowInterestRate() const;
		int GetInterest() const;
	};

	class HCACustomer : public NACustomer {
	private:
		int creditrate;
		int additionalinterest;
	public:
		HCACustomer(int id, std::string name, int reserve, int interest, int creditrate)
			:NACustomer(id, name, reserve, interest), creditrate(creditrate) {
			switch (creditrate) {
			case 1:
				additionalinterest = 7;
				return;
			case 2:
				additionalinterest = 4;
				return;
			case 3:
				additionalinterest = 2;
				return;
			default:
				additionalinterest = 0;
				return;
			}
		}
		double ShowInterestRate() const;
		int GetInterest() const;
	};
}

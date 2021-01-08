#pragma once
#include "NACUSTOMER.h"
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

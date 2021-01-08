#pragma once
#include "BankingCommonDecl.h"
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

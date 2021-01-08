#include "HCACUSTOMER.h"

double HCACustomer::ShowInterestRate() const {
	return 1 + (GetInterest()) / (double)100;
}

int HCACustomer::GetInterest() const {
	return additionalinterest + NACustomer::GetInterest();
}

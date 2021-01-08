#include "NACUSTOMER.h"
double NACustomer::ShowInterestRate() const {
	return 1 + (GetInterest()) / (double)100;
}

int NACustomer::GetInterest() const {
	return interest;
}

#include <iostream>
#include <vector>
#include <string>
#include "CUSTOMER.h"
#include "CONTRACT_MODULE.h"

using namespace std;

int main(void) {

	vector < vector<CUSTOMER_INFO::Customer> > person(50);
	CONTRACT_MODULE::Branch newBranch;

	while (newBranch.ExitLoop()) {
		newBranch.ShowBranch(person);
	}

	return 0;
}

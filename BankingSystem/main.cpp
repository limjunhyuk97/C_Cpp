#include "CONTRACT_MODULE.h"
#include <vector>

using namespace std;

int main(void) {

	vector < vector<Customer *> > person(50);
	CONTRACT_MODULE::Branch newBranch;

	while (newBranch.ExitLoop()) {
		newBranch.ShowBranch(person);
	}

	return 0;
}

#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS {
	enum { CLERK, SENIOR, ASSIST, MANGER };

	void PrintPos(int num) {
		if (num == 0) cout << "사원";
		else if (num == 1) cout << "주임";
		else if (num == 2) cout << "대리";
		else if (num == 3) cout << "과장";
		else cout << "wrong input";
	}
}

class NameCard {
private:
	char* myName;
	char* myCompany;
	char* myNumber;
	int myPosition;
public:
	NameCard(char* name, char* company, char* number, int position) :myPosition(position) {
		this->myName = new char[strlen(name) + 1];
		strcpy_s(myName, strlen(name) + 1, name);
		this->myCompany = new char[strlen(company) + 1];
		strcpy_s(myCompany, strlen(company) + 1, company);
		this->myNumber = new char[strlen(number) + 1];
		strcpy_s(myNumber, strlen(number) + 1, number);
		// this를 사용하면 매개변수와 멤버변수 이름이 겹쳐도 상관없다.
	}
	NameCard(const NameCard& nc) :myPosition(nc.myPosition) {
		// const를 사용하면 값의 변동을 막을 수 있다.
		myName = new char[strlen(nc.myName) + 1];
		strcpy_s(myName, strlen(nc.myName) + 1, nc.myName);
		myCompany = new char[strlen(nc.myCompany) + 1];
		strcpy_s(myCompany, strlen(nc.myCompany) + 1, nc.myCompany);
		myNumber = new char[strlen(nc.myNumber) + 1];
		strcpy_s(myNumber, strlen(nc.myNumber) + 1, nc.myNumber);
	}
	void ShowNameCardInfo() {
		cout << "이름 : " << myName << endl;
		cout << "회사 : " << myCompany << endl;
		cout << "전화번호 : " << myNumber << endl;
		cout << "직급 : ";
		COMP_POS::PrintPos(myPosition);
		cout << endl << endl;
	}

	~NameCard() {
		delete[]myName;
		delete[]myCompany;
		delete[]myNumber;
	}
};

int main(void) {
	struct p {
		char name[15];
		char company[15];
		char number[15];
	};
	p p1{ "Lee" , "ABCEng", "010-1111-2222" }, p2{ "Hong", "Orange", "010-3333-4444" };

	NameCard manClerk(p1.name, p1.company, p1.number, COMP_POS::CLERK);
	NameCard copy1 = manClerk;
	NameCard manSENIOR(p2.name, p2.company, p2.number, COMP_POS::SENIOR);
	NameCard copy2 = manSENIOR;

	copy1.ShowNameCardInfo();
	copy2.ShowNameCardInfo();

	return 0;
}

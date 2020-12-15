#include <iostream>
#include <cstring>
#include <string>
using namespace std;

namespace COMP_POS{
	enum POS{ CLERK, SENIOR, ASSIST, MANAGER};

	string PosToKor(POS value) {
		if (value == CLERK) return "사원";
		else if (value == SENIOR) return "주임";
		else if (value == ASSIST) return "대리";
		else if (value == MANAGER) return "과장";
		else return "잘못된 입력";
	}
}

class NameCard {
private:
	string myName;
	string myCompany;
	string myNumber;
	COMP_POS::POS position;

public:
	NameCard(string name, string cName, string call, COMP_POS::POS pos) {
		myName = name;
		myCompany = cName;
		myNumber = call;
		position = pos;
	}
	void ShowNameCardInfo() {
		cout << "이름 : " << myName << endl;
		cout << "회사 : " << myCompany << endl;
		cout << "전화번호 : " << myNumber << endl;
		cout << "직급 : " << COMP_POS::PosToKor(position)<<endl<<endl;
	}

};

int main(void) {

	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
	manClerk.ShowNameCardInfo();
	manSenior.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();

	return 0;
}

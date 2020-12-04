#include <iostream>
#include <stdio.h>

using namespace std;
inline void message();
int branch(int num);
void makeAccount(void);
void deposit(void);
void withdraw(void);
void printAllAccount(void);
void exitProgram(void);
void errmsg(void);

inline void message() {
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌 개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "선택 : " << endl;
}
int branch(int num) {
	if (num == 1) {
		makeAccount();
		return 0;
	}
	else if (num == 2) {
		deposit();
		return 0;
	}
	else if (num == 3) {
		withdraw();
		return 0;
	}
	else if (num == 4) {
		printAllAccount();
		return 0;
	}
	else if (num == 5) {
		exitProgram();
		return 1;
	}
	else {
		errmsg();
		return 0;
	}
}
void makeAccount(void) {

}
void deposit(void) {

}
void withdraw(void) {

}
void printAllAccount(void) {

}
void exitProgram(void) {

}
void errmsg(void) {

}


int main(void) {

	while (1) {
		message();
		int choose = 0;
		cin >> choose;
		branch(choose);
	}

	return 0;
}

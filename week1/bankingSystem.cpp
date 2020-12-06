#include <iostream>
#include <stdio.h>

using namespace std;

inline void message();
int branch(int num);
void makeAccount();
void deposit(void);
void withdraw(void);
void printAllAccount(void);
void exitProgram(void);
void errmsg(void);
int hashFunction(int num);

struct account {
	int id = 0;
	char name[15] = "";
	int reserve = 0;
};
account member[50][50];

inline void message() {
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌 개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "선택 : ";
}

int branch(int num) {
	if (num == 1) {
		makeAccount();
		return 1;
	}
	else if (num == 2) {
		deposit();
		return 1;
	}
	else if (num == 3) {
		withdraw();
		return 1;
	}
	else if (num == 4) {
		printAllAccount();
		return 1;
	}
	else if (num == 5) {
		exitProgram();
		return 0;
	}
	else {
		errmsg();
		return 1;
	}
}

void makeAccount() {
	int id = 0;
	int cnt = 0;
	int hashValue = 0;
	cout << "\n[계좌개설]\n";
	cout << "계좌 ID : ";
	cin >> id;
	hashValue = hashFunction(id);
	while (1) {
		if (member[hashValue][cnt].id == 0) {
			member[hashValue][cnt].id = id;
			break;
		}
		else ++cnt;
	}
	cout << "이름 : ";
	cin >> member[hashValue][cnt].name;
	cout << "입금액 : ";
	cin >> member[hashValue][cnt].reserve;
	cout << "입금완료 / 잔액 : " << member[hashValue][cnt].reserve << endl << endl;
}

void deposit(void) {
	int findID;
	int hashValue;
	int cnt = 0, tmp = 0;
	cout << "\n계좌 ID : ";
	cin >> findID;
	hashValue = hashFunction(findID);
	while (1) {
		if (member[hashValue][cnt].id == findID) break;
		else ++cnt;
	}
	cout << "입금액 : ";
	cin >> tmp;
	member[hashValue][cnt].reserve += tmp;
	cout << "입금완료 / 잔액 : " << member[hashValue][cnt].reserve << endl << endl;
}

void withdraw(void) {
	int findID;
	int hashValue;
	int cnt = 0, tmp = 0;
	cout << "\n계좌 ID : ";
	cin >> findID;
	hashValue = hashFunction(findID);
	while (1) {
		if (member[hashValue][cnt].id == findID) break;
		else ++cnt;
	}
	cout << "출금액 : ";
	cin >> tmp;
	member[hashValue][cnt].reserve -= tmp;
	cout << "입금완료 / 잔액 : " << member[hashValue][cnt].reserve << endl << endl;
}

void printAllAccount(void) {
	int cnt = 0;
	for (int i = 0; i < 50; ++i) {
		for (int j = 0; j < 50; ++j) {
			if (member[i][j].id != 0) {
				++cnt;
				cout << "\n==============================" << "\n이름 : " << member[i][j].name;
				cout << "\n입금액 : " << member[i][j].reserve;
				cout << "\n입금완료 / 잔액 : " << member[i][j].reserve << endl << "==============================" << endl;
			}
			else continue;
		}
	}
	if (cnt == 0) cout << "\n개설된 계좌가 없습니다!\n\n";
	else cout << endl;
}

void exitProgram(void) {
	cout << "\n감사합니다. 프로그램을 종료합니다.\n\n";
}

void errmsg(void) {
	cout << "\nWrond input number. try again.\n\n";
}

int hashFunction(int num) {
	return num % 50;
}

int main(void) {

	int flag = 1;

	while (flag) {
		message();
		int choose = 0;
		cin >> choose;
		flag = branch(choose);
	}

	return 0;
}

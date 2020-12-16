/*	개선 요구 사항
0. 캡슐화, 정보은닉을 신경써서 class를 만든다.
1. id 입력을 숫자가 아닌 다른 자료형을 넣었을 때 무한루프
2. hash collision 방지를 hash bucket 으로 하기 -> 동적 2차원 배열을 통해서
3. 비슷한 역할 하는 코드를 하나의 덩어리로 묶어서 기능 분화 -> 의존도 떨어뜨리기
4. 헤더파일을 만들어서 파일을 더 보기 좋게 만들기.
*/
/*  확인 및 수정 요구 사항
0. vector 2차원 컨테이너의 함수 전달 방법
1. *iterator의 함수 반환 방법
2. Customer을 반환형으로 쓰려했더니 객체의 생성처럼 받아들이는 문제 발생한 것 같음.
*/

#include <iostream>
#include <vector>
#include <string>
#define ERRMSG "\nWrong input number. Try again.\n\n"
#define TERMSG "\nThank you. Terminating Program.\n\n"

using namespace std;

namespace BANKING_SYSTEM {

	int HashingFunc(int num) {
		return num % 50;
	}

	 auto IdLocatingFunc(int id, int hashedId, vector < vector <Customer> > &container) {
		vector <Customer>::iterator iter;
		bool flag = false;
		for (iter = container[hashedId].begin(); iter < container[hashedId].end(); ++iter) {
			if ((*iter).IdCheck(id)) {
				flag = true;
				break;
			}
		}
		if (flag) return iter;

	 }
	
}

class Customer {
private:
	int id = 0;
	string name;
	int reserve = 0;
public:
	Customer(int id, string name, int reserve)
		: id(id), name(name), reserve(reserve){}
	Customer()
		: id(), name(), reserve(){}
	bool IdCheck(int input) {
		if (input == id) return true;
		else return false;
	}
	void ReserveIn(int in) {
		reserve += in;
	}
	void ReserveOut(int out) {
		reserve -= out;
	}
	int IdReturn() {
		return id;
	}
	int ReserveReturn() {
		return reserve;
	}
	string NameReturn() {
		return name;
	}
};

class Branch {
private:
	int select;
	Account makeAccount;
	Deposit makeDeposit;
	Withdrawal makeWithdrawal;
	PrintAllAccount printIt;

public:
	void ShowBranch(vector< vector <Customer> > &arr) {
		cout << "-----Menu-----" << endl;
		cout << "1. 계좌 개설" << endl;
		cout << "2. 입금" << endl;
		cout << "3. 출금" << endl;
		cout << "4. 계좌정보 전체 출력" << endl;
		cout << "5. 프로그램 종료" << endl;
		cout << "선택 : ";
		cin >> select;
		SelectBranch(select , arr);
	}
	void SelectBranch(int n, vector< vector <Customer> > &arr) {
		switch(n) {
		case 1:
			makeAccount.newAccount(arr);
		case 2:
			makeDeposit.newDeposit(arr);
	    case 3:
			makeWithdrawal.newWithdrawal(arr);
		case 4:
			printIt.NewPrintAllAccount(arr);
		case 5:
			cout << TERMSG;
		default:
			cout << ERRMSG;
		}
	}
	bool ExitLoop() {
		if (select == 5) return false;
		else return true;
	}
};

class Account {
private:
	int id = 0;
	int hashValue = 0;
	int money = 0;
	string name;
public:
	void newAccount(vector< vector<Customer> > &arr) {

		cout << "\n[계좌개설]\n";
		cout << "계좌 ID : ";
		cin >> id;
		hashValue = BANKING_SYSTEM::HashingFunc(id);
		cout << "이름 : ";
		getline(cin, name);
		cin.get();
		cout << "입금액 : ";
		cin >> money;

		Customer client(id, name, money);

		arr[hashValue].push_back(client);

	}
};

class Deposit {
private : 
	int id;
	int money;
public:
	void newDeposit(vector< vector<Customer> > &arr) {

		cout << "\n[계좌입금]\n";
		cout << "계좌 ID : ";
		cin >> id;
		cout << "입금액 : ";
		cin >> money;
		BANKING_SYSTEM::IdLocatingFunc(id, BANKING_SYSTEM::HashingFunc(id), arr).ReserveIn(money);
		cout << "입금완료 / 잔액 : " << BANKING_SYSTEM::IdLocatingFunc(id, BANKING_SYSTEM::HashingFunc(id), arr).ReserveReturn() << endl << endl;
	}

};

class Withdrawal {
private:
	int id;
	int money;
public:
	void newWithdrawal(vector< vector<Customer> >& arr) {
		cout << "\n[계좌출금]\n";
		cout << "계좌 ID : ";
		cin >> id;
		cout << "출금액 : ";
		cin >> money;
		BANKING_SYSTEM::IdLocatingFunc(id, BANKING_SYSTEM::HashingFunc(id), arr).ReserveOut(money);
		cout << "출금완료 / 잔액 : " << BANKING_SYSTEM::IdLocatingFunc(id, BANKING_SYSTEM::HashingFunc(id), arr).ReserveReturn() << endl << endl;
	}
};

class PrintAllAccount {
public:
	void NewPrintAllAccount(vector< vector<Customer> >& arr) {
		int cnt = 0;
		vector <Customer>::iterator iter;
		for (int i = 0; i < 50; ++i) {
			for (iter = arr[i].begin(); iter < arr[i].end(); ++i) {
				cout << "\n==============================" << endl;
				cout << cnt<<". "<< "계좌ID : " << (*iter).IdReturn() << endl;
				cout << "  고객 성함 : " << (*iter).NameReturn() << endl;
				cout << "  고객 잔고 : " << (*iter).ReserveReturn() << endl;
				++cnt;
			}
		}
		if (cnt == 0) cout << "\n개설된 계좌가 없습니다!\n\n";
		else cout << endl;
	}
};

int main(void) {

	vector < vector<Customer> > person(50);
	Branch newBranch;

	while (newBranch.ExitLoop()) {
		newBranch.ShowBranch(person);
	}

	return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include "CUSTOMER.h"
#include "CONTRACT_MODULE.h"
#define ERRMSG_SYS "\nWrong input number. Try again.\n\n"
#define ERRMSG_ID "\nWrong input Id. Try again.\n\n"
#define ERRMSG_TY "\nWrong input type. Try again.\n"
#define TERMSG "\nThank you. Terminating Program.\n\n"
using namespace std;
namespace CONTRACT_MODULE {

	// namespace ERR_MODULE start
	namespace ERR_MODULE {

		bool ErrFilterIdUnknown(int id, int hashValue, std::vector < std::vector <CUSTOMER_INFO::Customer *> > arr) {
			if (CONTRACT_MODULE::IdIndexLocatingFunc(id, hashValue, arr) == -1) return false;
			else return true;
		}

		int ErrFilterIdDataType() {
			int id;
			while (1) {
				cin >> id;
				if (cin.fail()) { cin.clear(); cin.ignore(256, '\n'); cout << ERRMSG_TY << endl << "계좌 ID : "; continue; }
				else { cin.ignore();  return id; };
			}
		}

		int ErrFilterMoneyDataType(int select) {
			int money;
			while (1) {
				cin >> money;
				if (cin.fail()) { cin.clear(); cin.ignore(256, '\n');
					if (select == 1) {
						cout << ERRMSG_TY << endl;
					}
					else if (select == 2) {
						cout << ERRMSG_TY << endl << "입금액 : ";
					}
					else {
						cout << ERRMSG_TY << endl << "출금액 : ";
					}
					continue;
				}
				else { cin.ignore(); return money; };
			}
		}

		void ErrPrintId() {
			cout << ERRMSG_ID;
		}
		
	}
	// namespace ERR_MODULE end

	int IdIndexLocatingFunc(int id, int hashedId, std::vector < std::vector <CUSTOMER_INFO::Customer *> >& container) {
		int ans = -1;
		if (container[hashedId].size() == 0) return -1;
		else {
			for (int i = 0; i < container[hashedId].size(); ++i) {
				if (container[hashedId][i]->GetId() == id) {
					ans = i;
					break;
				}
			}
			if (ans == -1) return -1;
			else return ans;
		}
	}

	int HashingFunc(int num) {
		return num % 50;
	}

	
	void Account::newAccount(std::vector< std::vector<CUSTOMER_INFO::Customer*> >& arr) {

		CUSTOMER_INFO::Customer* client;
		int select = 0;
		cout << "\n[계좌종류선택]\n";
		cout << "1. 보통예금계좌 / 2. 신용신뢰계좌" << endl;
		cout << "선택 : ";
		cin >> select;
		cout << endl;

		switch (select) {
		case 1:
			cout << "[보통예금계좌 개설]" << endl;
			basicInput();
			client = new CUSTOMER_INFO::NACustomer(id, name, money, interest);
			arr[hashvalue].push_back(client);
			cout << "***개설을 축하드립니다!!***" << endl;
			cout << "입금완료 / 잔액 : " << money << ", 이자율 : " << interest << endl << endl;
			break;
		case 2:
			cout << "[신용신뢰계좌 개설]" << endl;
			basicInput();
			cout << "신용등급(1toA, 2toB, 3toC) : ";
			cin >> creditrate;
			client = new CUSTOMER_INFO::HCACustomer(id, name, money, interest, creditrate);
			arr[hashvalue].push_back(client);
			cout << "***개설을 축하드립니다!!***" << endl;
			cout << "입금완료 / 잔액 : " << money << ", 이자율 : " << interest<<", 신용등급 : "<<creditrate << endl << endl;
			break;
		default:
			cout << ERRMSG_TY;
			break;
		}

	}

	void Account::basicInput() {
		cout << "계좌 ID : ";
		id = ERR_MODULE::ErrFilterIdDataType();
		hashvalue = HashingFunc(id);
		cout << "성함 : ";
		getline(cin, name);
		cout << "입금액 : ";
		money = CONTRACT_MODULE::ERR_MODULE::ErrFilterMoneyDataType(1);
		cout << "이자율 : ";
		cin >> interest;
	}
			
	void Deposit::newDeposit(std::vector< std::vector<CUSTOMER_INFO::Customer *> >& arr) {

		cout << "\n[계좌입금]\n";
		cout << "계좌 ID : ";
		id = ERR_MODULE::ErrFilterIdDataType();
		hashvalue = HashingFunc(id);
		if (!ERR_MODULE::ErrFilterIdUnknown(id, hashvalue, arr)) {
			ERR_MODULE::ErrPrintId();
			return;
		}
		cout << "입금액 : ";
		money = ERR_MODULE::ErrFilterMoneyDataType(2);
		CUSTOMER_INFO::Customer * exactLocation = arr[HashingFunc(id)][IdIndexLocatingFunc(id, HashingFunc(id), arr)];
		exactLocation->ReserveInterest();
		exactLocation->ReserveIn(money);
		cout << "입금완료 / 잔액 : " << exactLocation->GetReserve() << endl<<endl;
	}

	void Withdrawal::newWithdrawal(std::vector< std::vector<CUSTOMER_INFO::Customer *> >& arr) {
		cout << "\n[계좌출금]\n";
		cout << "계좌 ID : ";
		id = ERR_MODULE::ErrFilterIdDataType();
		hashvalue = HashingFunc(id);
		if (!ERR_MODULE::ErrFilterIdUnknown(id, hashvalue, arr)) {
			ERR_MODULE::ErrPrintId();
			return;
		}
		cout << "출금액 : ";
		money = ERR_MODULE::ErrFilterMoneyDataType(3);
		CUSTOMER_INFO::Customer* exactLocation = arr[HashingFunc(id)][IdIndexLocatingFunc(id, HashingFunc(id), arr)];
		exactLocation->ReserveOut(money);
		cout << "입금완료 / 잔액 : " << exactLocation->GetReserve() << endl<<endl;
	}

	void PrintAllAccount::NewPrintAllAccount(std::vector< std::vector<CUSTOMER_INFO::Customer *> >& arr) const {
		int cnt = 0;
		int* ptr = &cnt;
		for (int i = 0; i < arr.size(); ++i) {
			if (arr[i].size() == 0) continue;
			for (int j = 0; j < arr[i].size(); ++j) {
				CUSTOMER_INFO::Customer* client = arr[i][j];
				client->ShowAllInfo(ptr);
			}
		}
		if (cnt == 0) cout << "\n개설된 계좌가 없습니다!\n\n";
		else cout << "==============================" << endl << endl;
	}

	void Branch::ShowBranch(std::vector< std::vector <CUSTOMER_INFO::Customer *> >& arr) {
		cout << "-----Menu-----" << endl;
		cout << "1. 계좌 개설" << endl;
		cout << "2. 입금" << endl;
		cout << "3. 출금" << endl;
		cout << "4. 계좌정보 전체 출력" << endl;
		cout << "5. 프로그램 종료" << endl;
		cout << "선택 : ";
		cin >> select;
		SelectBranch(select, arr);
	}

	void Branch::SelectBranch(int n, std::vector< std::vector <CUSTOMER_INFO::Customer *> >& arr) {
		switch (n) {
		case 1:
			makeAccount.newAccount(arr);
			break;
		case 2:
			makeDeposit.newDeposit(arr);
			break;
		case 3:
			makeWithdrawal.newWithdrawal(arr);
			break;
		case 4:
			printIt.NewPrintAllAccount(arr);
			break;
		case 5:
			cout << TERMSG;
			break;
		default:
			cout << ERRMSG_SYS;
			break;
		}
	}

	bool Branch::ExitLoop() {
		if (select == 5) return false;
		else return true;
	}
	

}

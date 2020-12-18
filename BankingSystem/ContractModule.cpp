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

	namespace ERR_MODULE {
		bool ErrFilterIdUnknown(int id, int hashValue, std::vector < std::vector <CUSTOMER_INFO::Customer> > arr) {
			if (CONTRACT_MODULE::IdIndexLocatingFunc(id, hashValue, arr) == 0) return false;
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

		int ErrFilterDepoMoneyDataType() {
			int money;
			while (1) {
				cin >> money;
				if (cin.fail()) { cin.clear(); cin.ignore(256, '\n'); cout << ERRMSG_TY << endl << "입금액 : "; continue; }
				else { cin.ignore(); return money; };
			}
		}

		int ErrFilterWithdrawMoneyDataType() {
			int money;
			while (1) {
				cin >> money;
				if (cin.fail()) { cin.clear(); cin.ignore(256, '\n'); cout << ERRMSG_TY << endl << "출금액 : ";  continue; }
				else { cin.ignore(); return money; };
			}
		}

		void ErrPrintTy() {}
	}

	int IdIndexLocatingFunc(int id, int hashedId, std::vector < std::vector <CUSTOMER_INFO::Customer> >& container) {
		int ans = 0;
		if (container[hashedId].size() == 0) return 0;
		else {
			for (int i = 0; i < container[hashedId].size(); ++i) {
				if (container[hashedId][i].IdReturn() == id) {
					ans = i;
					break;
				}
			}
			if (ans == 0) return 0;
			else return ans;
		}
	}

	int HashingFunc(int num) {
		return num % 50;
	}

	
	void Account::newAccount(std::vector< std::vector<CUSTOMER_INFO::Customer> >& arr) {

		cout << "\n[계좌개설]\n";
		cout << "계좌 ID : ";
		id = ERR_MODULE::ErrFilterIdDataType();
		hashValue = HashingFunc(id);
		cout << "성함 : ";
		getline(cin, name);
		cout << "입금액 : ";
		money = ERR_MODULE::ErrFilterDepoMoneyDataType();
		cout << "***개설을 축하드립니다!!***" << endl;
		cout << "입금완료 / 잔액 : " << money << endl << endl;
		CUSTOMER_INFO::Customer client(id, name, money);

		arr[hashValue].push_back(client);

	}

	
	void Deposit::newDeposit(std::vector< std::vector<CUSTOMER_INFO::Customer> >& arr) {

		cout << "\n[계좌입금]\n";
		cout << "계좌 ID : ";
		id = ERR_MODULE::ErrFilterIdDataType();
		hashValue = HashingFunc(id);
		if (!ERR_MODULE::ErrFilterIdUnknown(id, hashValue, arr)) {
			ERR_MODULE::ErrPrintId();
			return;
		}
		cout << "입금액 : ";
		money = ERR_MODULE::ErrFilterDepoMoneyDataType();
		CUSTOMER_INFO::Customer& exactLocation = arr[HashingFunc(id)][IdIndexLocatingFunc(id, HashingFunc(id), arr)];
		exactLocation.ReserveIn(money);
		cout << "입금완료 / 잔액 : " << exactLocation.ReserveReturn() << endl;
	}

	void Withdrawal::newWithdrawal(std::vector< std::vector<CUSTOMER_INFO::Customer> >& arr) {
		cout << "\n[계좌출금]\n";
		cout << "계좌 ID : ";
		id = ERR_MODULE::ErrFilterIdDataType();
		hashValue = HashingFunc(id);
		if (!ERR_MODULE::ErrFilterIdUnknown(id, hashValue, arr)) {
			ERR_MODULE::ErrPrintId();
			return;
		}
		cout << "출금액 : ";
		money = ERR_MODULE::ErrFilterWithdrawMoneyDataType();
		CUSTOMER_INFO::Customer& exactLocation = arr[HashingFunc(id)][IdIndexLocatingFunc(id, HashingFunc(id), arr)];
		exactLocation.ReserveOut(money);
		cout << "입금완료 / 잔액 : " << exactLocation.ReserveReturn() << endl;

	}

	void PrintAllAccount::NewPrintAllAccount(std::vector< std::vector<CUSTOMER_INFO::Customer> >& arr) {
		int cnt = 0;
		for (int i = 0; i < arr.size(); ++i) {
			if (arr[i].size() == 0) continue;
			for (int j = 0; j < arr[i].size(); ++j) {
				cout << "\n==============================" << endl;
				cout << cnt + 1 << ". " << "계좌ID : " << arr[i][j].IdReturn() << endl;
				cout << "  고객 성함 : " << arr[i][j].NameReturn() << endl;
				cout << "  고객 잔고 : " << arr[i][j].ReserveReturn() << endl;
				++cnt;
			}
		}
		if (cnt == 0) cout << "\n개설된 계좌가 없습니다!\n\n";
		else cout << "==============================" << endl << endl;
	}

	void Branch::ShowBranch(std::vector< std::vector <CUSTOMER_INFO::Customer> >& arr) {
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

	void Branch::SelectBranch(int n, std::vector< std::vector <CUSTOMER_INFO::Customer> >& arr) {
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

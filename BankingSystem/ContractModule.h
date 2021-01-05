#include <iostream>
#include <vector>
#include <string>
#include "CUSTOMER.h"
#pragma once
namespace CONTRACT_MODULE {

	int IdIndexLocatingFunc(int id, int hashedId, std::vector < std::vector <CUSTOMER_INFO::Customer*> >& container);

	int HashingFunc(int num);

	namespace ERR_MODULE {
		bool ErrFilterIdUnknown(int id, int hashValue, std::vector < std::vector <CUSTOMER_INFO::Customer *> > arr);

		int ErrFilterIdDataType();

		int ErrFilterMoneyDataType(int select);

		void ErrPrintId();
	}
	
	class Account {
	private:
		int id;
		int hashvalue;
		int money;
		int interest;
		int creditrate;
		std::string name;
	public:
		void newAccount(std::vector< std::vector<CUSTOMER_INFO::Customer*> >& arr);
		void basicInput();
	};

	class Deposit {
	private:
		int id;
		int hashvalue;
		int money;
	public:
		void newDeposit(std::vector< std::vector<CUSTOMER_INFO::Customer *> >& arr);
	};

	class Withdrawal {
	private:
		int id;
		int hashvalue;
		int money;
	public:
		void newWithdrawal(std::vector< std::vector<CUSTOMER_INFO::Customer *> >& arr);
	};

	class PrintAllAccount {
	public:
		void NewPrintAllAccount(std::vector< std::vector<CUSTOMER_INFO::Customer *> >& arr) const;
	};

	class Branch {
	private:
		int select;
		Account makeAccount;
		Deposit makeDeposit;
		Withdrawal makeWithdrawal;
		PrintAllAccount printIt;

	public:
		void ShowBranch(std::vector< std::vector <CUSTOMER_INFO::Customer *> >& arr);
		void SelectBranch(int n, std::vector< std::vector <CUSTOMER_INFO::Customer *> >& arr);
		bool ExitLoop();
	};

}

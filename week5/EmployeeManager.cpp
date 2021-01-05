#include <iostream>
#include <cstring>
using namespace std;

namespace RISK_LEVEL {
	enum {RISK_A , RISK_B, RISK_C};
}

class Employee {
private:
	char name[100];
public:
	Employee(char* myname) {
		strcpy_s(name, strlen(myname) + 1, myname);
	}
	void ShowYourName() const {
		cout << "name : " << name << endl;
	}
	virtual int GetPay() const = 0;
	virtual void ShowSalaryInfo() const = 0;

};

class PermanentWorker : public Employee {
private:
	int salary;
public:
	PermanentWorker(int mysalary, char *myname) : Employee(myname), salary(mysalary) {}
	int GetPay() const {
		return salary;
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary : " << GetPay() << endl << endl;
	}
};

class TemporaryWorker : public Employee {
private:
	int workTime;
	int PayPerHour;
public:
	TemporaryWorker(char* myname, int mypayperhour) : Employee(myname), PayPerHour(mypayperhour), workTime(0) {}
	void AddWorkTime(int time) {
		workTime = time;
	}
	int GetPay() const {
		return workTime * PayPerHour;
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary : " << GetPay() << endl << endl;
	}

};

class SalesWorker : public PermanentWorker {
private:
	int salesResult;
	double bonusRatio;
public:
	SalesWorker(int mysalary, char* myname, double bonusRatio) : bonusRatio(bonusRatio), salesResult(0), PermanentWorker(mysalary, myname) {}
	void AddSalesResult(int result) {
		salesResult += result;
	}
	int GetPay() const {
		return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
		// PermanentWorker의 GetPay()에 접근하려면 범위한정연산자를 사용해야 한다.
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary : " << GetPay() << endl<<endl;
	}
};

class ForeignSalesWorker : public SalesWorker {
private:
	int risklevel;
public:
	ForeignSalesWorker(char* myname, int mysalary, double bonusRatio, int risklevel) : SalesWorker(mysalary, myname, bonusRatio), risklevel(risklevel) {}
	
	double RiskIncentive(int risklevel) const{
		switch (risklevel) {
		case 0:
			return 0.3;
		case 1:
			return 0.2;
		case 2:
			return 0.1;
		}
	}
	
	int GetRiskPay() const {
		return SalesWorker::GetPay() * RiskIncentive(risklevel);
	}

	// 범위 지정 연산자와 함수를 적절히 조합해 쓰면 상속을 잘 이용할 수 있다.
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary : " << SalesWorker::GetPay() << endl;
		cout << "risk pay : " << GetRiskPay()<<endl;
		cout << "sum : " << SalesWorker::GetPay() + GetRiskPay()<<endl<<endl;
	}
};

class EmployeeHandler {
private:
	Employee* empList[50];
	int empNum;

public:
	EmployeeHandler() : empNum(0) {}

	
	void AddEmployee(Employee* emp) {
		empList[empNum++] = emp;
	}

	void ShowAllSalaryInfo() const {
		int sum = 0 ;
		for(int i=0; i<empNum; ++i){
			empList[i]->ShowSalaryInfo();
		}
	}
	void ShowTotalSalary() const {
		int sum = 0;
		for(int i=0; i<empNum; ++i){
			sum += empList[i]->GetPay();
		}
		cout << "salary sum : " << sum << endl;
	}
	~EmployeeHandler() {
		for (int i = 0; i < empNum; ++i)
			delete empList[i];
	}
};

int main(void) {

	EmployeeHandler handler;

	struct employee {
		char name[10];
		int salary;
		double bonusratio;
		int risklevel;
	};
	employee e1 = { "Hong", 1000, 0.1, RISK_LEVEL::RISK_A }, e2 = { "Yoon", 1000, 0.1, RISK_LEVEL::RISK_B }, e3 = { "Lee", 1000, 0.1, RISK_LEVEL::RISK_C };

	ForeignSalesWorker* fseller1 = new ForeignSalesWorker(e1.name, e1.salary, e1.bonusratio, e1.risklevel);
	fseller1->AddSalesResult(7000);
	handler.AddEmployee(fseller1);

	ForeignSalesWorker* fseller2 = new ForeignSalesWorker(e2.name, e2.salary, e2.bonusratio, e2.risklevel);
	fseller2->AddSalesResult(7000);
	handler.AddEmployee(fseller2);

	ForeignSalesWorker* fseller3 = new ForeignSalesWorker(e3.name, e3.salary, e3.bonusratio, e3.risklevel);
	fseller3->AddSalesResult(7000);
	handler.AddEmployee(fseller3);

	handler.ShowAllSalaryInfo();	

	return 0;
}

/*
  functor는 함수 객체이다. -> 함수를 변수처럼 다룰 수 있는 functional programming의 이점이 생긴다.
  () 연산자의 활용을 통해서 구현한다.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// 순수 가상함수와 추상클래스를 이용한다. : 유도 클래스에서 진짜 의미를 부여하겠다는 의미이다.
class IntCompare {
public:
	virtual bool operator()(int num1, int num2) const = 0;
};

class Ascending : public IntCompare {
public:
	bool operator()(int num1, int num2) const{
		if (num1 > num2)
			return true;
		else
			return false;
	}
};

class Descending : public IntCompare {
public:
	bool operator()(int num1, int num2) const {
		if (num1 < num2)
			return true;
		else
			return false;
	}
};

class DataStorage {
private:
	int* arr;
	int idx;
	const int MAX_LEN;
public:
	DataStorage(int arrlen) :idx(0), MAX_LEN(arrlen) {
		arr = new int[MAX_LEN];
	}
	void AddData(int num) {
		if (idx >= MAX_LEN) {
			cout << "more saving inavailable\n";
			return;
		}
		else {
			arr[idx] = num;
			++idx;
		}
	}
	void ShowAllData(void) {
		if (idx == 0) {
			cout << "nothing to show..\n";
			return;
		}
		for (int i = 0; i < idx; ++i) {
			cout << arr[i] << " ";
		}
		cout << endl;
		return;
	}

	// 함수 객체를 인자로 전달
	void SortData(const IntCompare& functor) {
		for (int i = 0; i < idx - 1; ++i) {
			for (int j = 0; j < idx - 1 - i; ++j) {

				// 전달된 함수 객체의 opertor() 연산을 통하여 비교가 이뤄진다.
				if (functor(arr[j], arr[j + 1])) {
					int tmp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = tmp;
				}
			}
		}
	}

};

int main(void) {

	srand((unsigned int)time(NULL));

	DataStorage DS(20);
	for (int i = 0; i < 10; ++i) {
		DS.AddData(rand() % 9 + 1);
	}
	DS.ShowAllData();
	DS.SortData(Ascending());
	// Ascending() : 임시 객체의 생성이다. + 함수 객체를 생성하여 부여한 것이다.
	DS.ShowAllData();
	DS.SortData(Descending());
	DS.ShowAllData();

	return 0;
}

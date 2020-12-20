// 복사 생성자와 약한복사, 임시객체의 생성 시점 관련 예제 코드.

#include <iostream>
using namespace std;

class SoSimple {
private:
	int num;
public:
	SoSimple(int n) : num(n) {
		cout << "New Object : " << this << endl;
	}
	SoSimple(const SoSimple& copy) : num(copy.num) {
		cout << "New Copy Obj : " << this << endl;
	}
	~SoSimple() {
		cout << "Destroy obj : " << this << endl;
	}
};

SoSimple SimpleFuncObj(SoSimple ob) {
	cout << "Parm ADR : " << &ob << endl;
	return ob;
}

int main(void) {
	SoSimple obj(7);							// 생성자 (New Obj 출력) - 주소1,
	SimpleFuncObj(obj);							// 복사생성자 (New Copy 출력) - 주소2 , (Parm ADR 출력) - 주소2,  (New Copy 출력) - 주소3, 소멸자 (Destroy Obj) - 주소2, 소멸자 (Destroy Obj) - 주소3

	cout << endl;
	SoSimple tempRef = SimpleFuncObj(obj);		// 얕은 복사	// 복사생성자 (New Copy 출력) - 주소2, (Parm ADR 출력) - 주소2, (New Copy 출력) - 주소4, 소멸자 (Destroy Obj) - 주소2
	cout << "Return Obj " << &tempRef << endl;	// (주소 출력) - 주소 4

	return 0;	// 소멸자 (Destroy Obj 출력) - 주소4, 소멸자 (Destroy Obj 출력) - 주소1

	// 주소2 가 같은 점, 주소3과 주소4는 다른 점, 주소4가 바로 소멸되지 않은 점. 눈 여겨 볼 점이다.
}

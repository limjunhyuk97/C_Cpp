#include <iostream>
using namespace std;
class AAA {
private:
	int num;
public:

	AAA(int num = 0) : num(num) {
		cout << "생성자 호출" << endl;
	}

	AAA(const AAA& ref) {
		num = ref.num;
		cout << "복사 생성자 호출" << endl;
	}
	
	AAA& operator=(int num) {
		cout << "num 대입연산자 호출"<<endl;
		this->num = num;
		return *this;
	}
	
	AAA& operator=(const AAA &ref) {
		cout << "&ref 대입연산자 호출"<<endl;
		this->num = ref.num;
		return *this;
	}

	AAA operator+(const AAA& ref) {
		cout << "+연산자 호출"<<endl;
		AAA newAAA(num + ref.num);
		return newAAA;
	}

	void ShowIt() {
		cout << num << endl;
	}
};

AAA foo(AAA obj) {
	obj.ShowIt();
	return obj;
}

int main(void) {
	
	/* 복사생성자 복습 */
	AAA a;
	AAA b = foo(a);
	/*
	 
	  * 복사생성자는 3가지 경우에서 호출된다.
	  1. 객체 생성시에, 다른 객체의 값을 넣어줄 때
	  2. 함수에 인자 전달 시에 참조 형태로 전달하지 않는 경우
	  3. 함수가 인자 반환 시에 참조 형태로 전달하지 않는 경우
	 
	  2, 3 의 경우를 위의 예시를 통해서 보자면..
	  - foo(a)에서 foo의 파라미터인 obj의 복사생성자가 호출되어, obj에 a 값을 넣는다. : obj(a) 처럼 
	  - obj의 값이 복사된, 반환되는 임시객체에 b라는 이름을 부여해서, 새로운 메모리 공간에 존재하던 임시객체를 참조하게 되는 것이다. : "AAA b = foo(a)"는, "AAA b = 반환된 임시객체."
	  - 만약 아무것도 부여하지 않았으면, 그대로 임시객체는 행 종료시에 사라진다.
	*/

	cout << endl;

	/* 생성자와 대입연산자의 차이점 */
	AAA a1(5);
	AAA a2 = 6;
	/*
	
	  * 생성자 : 값이 할당되지 않은 초기에 값을 할당할 때 호출된다.
	  * 대입연산자 : 값이 이미 할당된 객체에 다른 객체의 값을 덮어씌울 때 호출된다.
	  
	  * 위의 예시처럼 묵시적 형변환에 대해서는..
	    - explicit X : 생성자가 호출되는 것이고
		- explicit O : 묵시적 형변환이 일어날 수 없기에 a2 = AAA(6)의 방식으로 생성자호출하여, 임시객체를 직접 생성하고 a2를 그 공간의 이름으로 할당한다.
	*/

	AAA a3 = a1 + a2;
	// 이 연산은 +연산자함수의 반환값으로 생성된 임시객체에 a3라는 이름을 할당한 형식이 되는것이다!

	return 0;

}

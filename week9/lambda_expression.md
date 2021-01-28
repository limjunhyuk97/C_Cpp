# lambda expression

## functional programming의 이점
  - 함수를 변수처럼 다룰 수 있게 되는 이점이 생긴다.
    - 즉, 함수가 argument로 전달될 수 있다.
    - return 값이 함수가 될 수 있다.
    - 함수를 값처럼 할당하고, 수정할 수 있다.
    - (JS에서 많이 사용되는 방법..!)
    
## cpp에서의 functional programming
  - function object 생성하기
    - class내 멤버함수의 operator overloading을 통해서 일반적인 함수처럼 구동가능한 object를 만든다.
    - 이렇게 만들어진 객체는, cpp에서도 함수를 variable처럼 다루는 효과를 낼 수 있게 도와준다.
  - lambda expression 이용하기
  
## lambda expression의 장점
  - function object를 이용하기 위해 class를 선언하는 번거로움을 줄여준다.
  - function pointer과 다르게 인라인화가 가능하다.
  
## [lambda expression](https://docs.microsoft.com/ko-kr/cpp/cpp/lambda-expressions-in-cpp?view=msvc-160)
  - constructs a closure: an unnamed function object capable of capturing variables in scope.
    - lambda expression은 closure를 형성한다.
    - 또한, lambda expression은 고유 객체이다.
    
```cpp
#include <iostream>
using namespace std;

class Plus {
private:
	int localVar;
public:
	explicit Plus(int a) : localVar(a) {}
	int operator() (int x) const {
		return localVar + x;
	}
};

int main() {
  
	// lambda expression
	auto lambdaPlus3 = [localVar = 3](int x, int y){
		return localVar + x;
	};

	Plus plus3(3);
	Plus plus5(5);

	cout << plus3(10) << endl;
	cout << lambdaPlus3(10, 3) << endl;
	
	return 0;
}
```

## capture
  - default capture : Only variables that are mentioned in the lambda are captured when a capture-default is used.
  - **includes a capture-default &** : &identifier form inavailable.
  - **includes a capture-default =** : =identifier form inavailable.
  - **An identifier or this cannot appear more than once** in a capture clause.
  
```cpp
struct S { void f(int i); };

void S::f(int i) {
    [&, i]{};      // OK
    [&, &i]{};     // ERROR: i preceded by & when & is the default
    [=, this]{};   // ERROR: this when = is the default
    [=, *this]{ }; // OK: captures this by value. See below.
    [i, i]{};      // ERROR: i repeated
}
``

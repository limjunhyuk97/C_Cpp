# 복사 생성자

## 1. 복사생성자
 - 객체의 복사를 돕는 생성자.
 - 같은 class 틀을 공유한다면 객체를 복사해서 다른 객체에 그대로 찍어넣을 수 있다.
 - 보통 인자를 const & (const 참조자) 형식으로 많이 받아들인다. (참조자 형식으로 받지 않으면 무한루프를 돌게됨.)
   - 복사생성자 호출 시기의 특성으로 인해서 무한루프를 돌게됨!
```cpp
soSimple sim1 = sim2;
soSimple sim2(sim2);
```

## 2. 생성자 관점에서의 복사 생성자
 - 복사 생성자를 굳이 추가하지 않더라도, 디폴트 복사 생성자가 자동으로 삽입된다.
 - 추가한다면, 생성자의 매개변수를 & 참조자로 선언해주어야한다. -> 그렇지 않으면 무한루프에 빠진다.
 - 생성자들은 이니셜라이저 사용할 수 있다. (복사생성자도 마찬가지!)
 
## 3. explicit과 묵시적 변환
 - 복사생성자가 호출되는 변환은 **name1(name2)** 처럼 직접 변환하는 방식이다.
 - **name1 = name2** 라고 정의했을 때는, **묵시적 변환**이 일어난다. / 이는 곧 대입연산자의 연산이다!
 - **묵시적변환**에서 **복사 생성자의 호출을 배제**하려면 **explicit**을 사용하면 된다.
```cpp
// 예시 1--------------------------------------------------
SoSimple {
  explicit SoSimple(SoSimple &copy)
     : num1(copy.num1) , num2(copy.num2) {} 
     // num1, num2는 SoSimple 객체의 private 멤버변수인데, 복사 시에 그냥 '.'으로 접근할 수 있는 것 같다!
};

SoSimple sim1;
SoSimple sim2 = sim1;
// 묵시적 변환이 일어나야 하지만, explicit으로 제한했기에 변환이 일어나지 않는다.
SoSimple sim2(sim1);
// 직접 sim1을 전달해 주어야만 한다.

// 전달인자가 하나인 경우
class A{
private:
 int n;
public:
 A(int n) : n(n) {}
};

A a = 2;
// 묵시적 변환이 일어나서 a(2)라고 전달한 꼴이 되버린다.
// 제한하려면, explicit A(int n) : n(n) {} 으로 바꿔주면 된다.

// 예시 2--------------------------------------------------
#include <iostream>
using namespace std;

class AAA {
private:
	int n;

public:
	// 생성자
	AAA(int num = 0) : n(num) {
		cout << "생성자 호출 됬으~" << endl;
	}

	// 복사 생성자
	explicit AAA(const AAA& ref) {
		n = ref.n;
		cout << "복사생성자 호출 됬으~" << endl;
	}

	// 대입 연산자
	AAA& operator=(const AAA& ref) {
		n = ref.n;
		cout << "대입연산자 호출 됬으~" << endl;
		return *this;
	}

};

class BBB{
private:
	AAA Aobj;
public:
	BBB(const AAA& ref) : Aobj(ref) {}
};

class CCC {
private:
	AAA Cobj;
public:
	CCC(const AAA& ref) { Cobj = ref; }
};

int main(void) {

	AAA Ao(12);
	cout << endl << endl;
	AAA Ao2(Ao);
	cout << endl << endl;
	AAA Ao3 = Ao;
 // 여기서는 대입 연산이 일어나고 있는 것이 아니라, 복사생성자의 연산이 일어나고 있는 것. (선언과 동시에 할당)
 // 만약 AAA 복사생성자 연산에 explicit 선언을 해버렸다면 이 연산은 일어날 수 없음.
 AAA A4; A4 = A3;
 // 여기서는 대입 연산이 일어나고 있는 것. (선언 후 대입)
 cout << endl << endl;
	return 0;
}
```
## 4.0 얕은 복사와 깊은 복사
 - **얕은 복사**는 복사된 객체가 힙영역의 메모리 공간을 참조할 때, 동일한 메모리 공간을 공유하게 된다.
 - **깊은 복사**는 마찬가지 상황에서, 새로 메모리 공간을 만들고, 새로운 객체가 그 공간을 참조하게 된다.
 
## 4.1 얕은 복사의 문제와 해결
 - **문제**
   - **객체 소멸때**, 사본 객체의 소멸과정에서 **원본 객체의 메모리 또한 소멸**되기에, **원본 객체 메모리 소멸 과정에서 문제**가 생긴다.
 - **해결**
   - **깊은 복사**를 통해 복사 시에 메모리 공간 자체를 새로 만들어 주면 해결 가능.
   - 깊은 복사를 구현하는 방법은 **복사된 녀석에게도 새로운 힙영역 메모리를 부여**해줘서 메모리 삭제시 문제 발생 예방
```cpp
class Person{
private:
  char *name;
  int age;
public:
  Person(Person & per) :age(per.age){
    name = new char[strlen(per.name)+1];  // 객체 복사 시에 아예 새로운 공간을 할당해 버리는 것.
    strcpy(name, per.name);               // 새로 할당된 공간에 값을 넣어버림.
  }
  ~Person(){
    delete []name;                        // 나중에 삭제할 때도 문제 발생하지 않음.
  }
};
```

## 5. 복사생성자와 임시객체

## 5.1 복사생성자 호출 시점
 1. **기존 객체로 새로운 객체를 초기화** 할 때
 2. **call-by-value를 통해서 객체를 인자로** 받아들일 때
 3. **객체를 참조형이 아닌 형식으로 반환**하는 경우
 
## 5.2 메모리 할당과 동시에 초기화 되는 경우 + 복사 생성자
 1. **변수선언과 동시에 값을 할당**할 때 <- **메모리 공간이 할당과 동시에 초기화** 된다. <- 객체 복사생성자를 호출한다.
```cpp
 class obj{
 ...
 };
 
 obj newObj1(...);
 obj newObj2(newObj1);
 obj newObj3 = newObj1;
 // 따로 정의해주지 않는 이상, 얕은 복사들이 일어남.
```
 2. 함수 호출시, **함수 매개변수에 대한 인자가 들어올 때** <- **메모리 공간이 할당과 동시에 초기화** 된다. <- 객체 복사생성자를 호출한다.
```cpp
void foo(obj parObj1){
...
}

obj newObj1;
foo(newObj1); // 전달 시에 복사생성자 호출
```
 3. 함수 종료시, **참조자가 아닌 값의 반환** <- **반환값을 저장할 임시 메모리의 공간이 할당과 동시에 초기화** 된다. <- 객체 복사생성자를 호출한다. 
```cpp
obj foo(obj parObj){
 return parObj;
}

obj newObj1;
foo(newObj1); // 전달, 반환 시에 복사생성자 호출
```

## 5.3 임시객체
 - 객체가 생성되고 반환되는 시점에 **임시객체가 생성**된다. (=**임시객체를 위한 메모리 공간이 생성**된다.)
 - 그 위치에 **참조할 수 있는 임시객체의 참조값이 생성**된다. (=**참조할 수 있는 임시객체 메모리 공간의 참조값이 생성**된다.)
```cpp
class Tmp{
...
  void FuncName(){
  ...}
};

Tmp( , , );   // 임시객체 생성법
Tmp( , , ).FuncName(); == (임시객체의 참조값).FuncName();  // 임시객체의 참조값 이용
```
 - 임시객체는 **행이 넘어가면 사라진다.**
 - 참조자에 임시객체의 참조값을 저장해두면 임시객체의 참조값이 행이 넘어가도 사라지지 않는다.
```cpp
const Tmp &ref = Tmp( , , ); // 임시객체 참조 저장.
```






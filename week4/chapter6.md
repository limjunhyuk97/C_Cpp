# Friend, Static, Const

## Const

### 1. const 객체 선언
  - 객체의 const 멤버함수만 부를 수 있게, const 객체 선언을 할 수 있다.
  - const로 한정하지 않은 멤버함수들은 호출이 불가능하다.
```cpp
// class 선언
class A{
private:
  int num;
public:
  void FooFunc(){ ... }
  void FooConstFunc() const { ... }
};

// const 객체 생성
const A a;
a.FooFunc();      // 호출 불가능
a.FooConstFunc(); // 호출 가능
```

### 2. const 함수와 함수 오버로딩
  - const 함수인지, 아닌지를 바탕으로 함수 오버로딩이 이루어진다.
```cpp
// class 선언
class A{
private:
  int num;
public:
  void FooFunc(){ ... }
  void FooFunc() const { ... }
};

// const 객체 생성
const A a;
A b;
a.FooFunc();  // FooFunc() const{ ... } 호출
b.FooFunc();  // FooFunc(){ ... } 호출
```

## friend

```cpp
#include <iostream>
#include <string>
using namespace std;

class Girl;
// Girl이라는 것이 class임을 미리 선언해 줌

class Boy {
private:
	int height;
	friend class Girl;
  // 1. 이 선언 상에서 Girl이 class 임을 선언해주는 역할
  // 2. friend로서 Boy class의 private 멤버변수를 참조 가능하다고 알박기.
  
public:
	Boy(int len):height(len){}
	void ShowYourFriendInfo(Girl& frn);	
  // 아직 Girl의 멤버변수들이 정의되지 않았기 때문에 phNum을 사용할 수 없다.
  // Boy가 Girl의 private 멤버를 이용가능하도록 알박고, 함수로 끌어와서 사용
  
};

class Girl {
private:
	string phNum;
  
public:
	Girl(string num):phNum(num){}
	void ShowYourFriendInfo(Boy& frn) {
		cout << "His height : " << frn.height << endl;
	}
  // Girl도 Boy의 private 멤버를 이용가능하게 알박고, 함수로 끌어와서 사용
  
	friend class Boy;	
  // public 위치에 friend 선언이 되더라도, 멤버변수에 접근이 가능해진다.
  // friend로서 Girl class의 private 멤버변수를 참조가능하다고 알박기.
};

void Boy::ShowYourFriendInfo(Girl& frn) {
	cout << "her phone number : " << frn.phNum << endl;
}


int main(void) {

	Boy boy(177);
	Girl girl("010-2271-2971");
	boy.ShowYourFriendInfo(girl);
	girl.ShowYourFriendInfo(boy);

	return 0;
}
```

### 1. friend 선언이란?
  - class A가 class B를 friend라고 선언했을 때, B는 A의 private 멤버들에 접근이 가능하다.
  - **public 영역에서든, private 영역에서든, friend 선언이 이루어 진다면**, private 멤버들에 접근 가능.

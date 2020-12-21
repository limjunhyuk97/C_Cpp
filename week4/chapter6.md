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

## Friend

### 1. class의 friend 선언 / (private 멤버 접근)
  - class A가 class B를 friend라고 선언했을 때, B는 A의 private 멤버들에 접근이 가능하다.
  - **public 영역에서든, private 영역에서든, friend 선언이 이루어 진다면**, private 멤버들에 접근 가능.

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

### 2. friend 선언 사용시기
  - friend 선언은 지나치면 정보은닉을 무너뜨릴 수 있기에 위험할 수 있다.
  
### 3. 함수의 friend 선언 / (전역, 멤버 함수 접근)
  - 예시를 봤을 때 전역함수와, 다른 class 함수를 friend로 사용하는 이유로 두가지를 추릴 수 있을 것 같다.
    - friend로 선언하였기에 **class2 함수가**, **class1 private 멤버변수에 직접접근** 가능하다.
    - **class2 함수가 구동**하면서 **class2와 class1의 멤버변수들의 변화를 모두 견인**할 수 있다.
```cpp
#include <iostream>
using namespace std;

class Point;
// Point class 존재 선언.

class PointOP {
private:
	int opcnt;
public:
	PointOP() : opcnt(0) {}

	Point PointAdd(const Point&, const Point&);
	Point PointSub(const Point&, const Point&);
	// 매개인자 명을 포함하지 않는 방식의 선언도 가능하다.

	~PointOP() {
		cout << "Operation times : " << opcnt << endl;
	}
	// 종료되면서 몇번 실행됬는지 출력해주는 역할.
};

class Point {
private:
	int x;
	int y;
public:
	Point(const int &xpos, const int &ypos) :x(xpos), y(ypos){}

	friend Point PointOP::PointAdd(const Point&, const Point&);
	friend Point PointOP::PointSub(const Point&, const Point&);
	// Point 객체를 반환하는 PointOP라는 class 선언 안에 있는 PointAdd함수와, PointSub함수에 대해 friend선언
	
	friend void ShowPointPos(const Point&);
	// void를 반환하는 전역에 있는 ShowPointPos함수에 대해 friend 선언
};

Point PointOP::PointAdd(const Point& pnt1, const Point& pnt2) {
	opcnt++;
	return Point(pnt1.x + pnt2.x, pnt1.y + pnt2.y);
	// Point 클래스의 friend로 선언되었기에, PointOP의 함수 PointAdd가 Point클래스의 private 멤버변수에 직접 접근 가능. 
}

Point PointOP::PointSub(const Point& pnt1, const Point& pnt2) {
	opcnt++;
	return Point(pnt1.x - pnt2.x, pnt1.y - pnt2.y);
	// Point 클래스의 friend로 선언되었기에, PointOP의 함수 PointSub가 Point클래스의 private 멤버변수에 직접 접근 가능.
}

int main(void) {

	Point pos1(1, 2);
	Point pos2(2, 4);
	PointOP op;
	ShowPointPos(op.PointAdd(pos1, pos2));
	ShowPointPos(op.PointSub(pos2, pos1));
	return 0;
}

void ShowPointPos(const Point& pos) {
	cout << "x : " << pos.x << ", ";
	cout << "y : " << pos.y << endl;
}
```

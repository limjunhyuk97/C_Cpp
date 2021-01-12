# 연산자 오버로딩

- [01. 연산자 오버로딩](#01---------)
- [02. 연산자 오버로딩 사용법](#02-------------)
- [03. 단항연산자 오버로딩](#03-----------)
- [04. 연산자 오버로딩과 교환법칙 (전역에서의 선언)](#04--------------------------)
- [05. cout, cin, endl의 정체와 ostream](#05-cout--cin--endl------ostream)
- [06. ostream과 <<, \>>를 이용한 객체 출력](#06-ostream--------------------)

## 01. 연산자 오버로딩
  - operator('연산자') 함수.
    - **('operator')와 (연산자)를 묶어서 함수의 이름으로 정하면, 연산자만으로의 함수호출을 허용한다.**
      - operator+ , operator-, operator+=, operator-= 등등의 함수들이 해당된다.
    - **class가 연산(: '+' '-' '<<' '>>' ...)에 대해서 오버로딩되었다** 라고 보통 이야기한다.
      - 객체도 기본자료형들처럼 연산가능하게 만들자 : 객체의 자료형이 일반자료형을 오버로딩하는 것이기에 저렇게 이야기하는 것이다.
    - **함수가 연산자를 오버로딩했다**고도 이야기한다.
      - 연산자의 내용이 'operator연산자' 함수에 의해서 오버로딩된 것이기 때문이다.
    - **결과적으로! 피연산자를 따라 연산의 방식이 달라지는 것이, 매개변수를 따라 호출되는 함수가 달라지는 것과 같기 때문에 연산자 오버로딩.**
    - 연산자 오버로딩의 과정 (operator+ 로 예를 들자면..)
      1. "class객체 + class객체"의 코드를 컴파일러가 확인
      2. **멤버함수에 의한 연산자 오버로딩인지, 전역함수에 의한 연산자 오버로딩인지 판단** (동시에 선언됬다면 멤버함수 연산자 오버로딩 우선)
      - 멤버함수 연산자 오버로딩에서는 매개인자 한개, 전역함수 연산자 오버로딩에서는 매개인자 두개 필요하다.
      - 왠만하면 멤버함수를 통해서 연산자 오버로딩하는 것이 좋다. (객체지향에는 전역이라는 개념이 없기 때문이다.)
      - 전역함수를 통한 연산자 오버로딩으로 교환법칙 문제를 해결할 수 있다.
      - **멤버함수 선언이나, 전역함수의 friend 선언이 class내에 속해 있을때, 그 class의 객체 관련 연산자 오버로딩이 가능해지는 것이다!**
    - 이점
      - 동일 타입 객체 간의 연산을 보다 직관적으로 수행할 수 있도록 설계가능할 것 같다. (연산을 직관적으로 수행가능!)
      - 심지어 다른 자료형과의 연산또한 연산자오버로딩에서 지원한다. (ex. 객체 * 2 : 객체 내 멤버변수 값 두배로 증가.)
      
```cpp
// 멤버함수에 의한 연산자 오버로딩 예시 - 1
class AAA{
private:
  int x;
public:
  AAA(int x = 0) : x(x) {}
  // const 함수로 선언하는 것이 좋고, 해도 상관없다. 새로운 값의 생성만 있기 때문이다.
  // class 내부에서는 private 멤버변수에 접근가능합니다~ (다음 예에서는 ref.x로의 접근..!)
  AAA opreator+(const AAA &ref) const {
    AAA ans( x + ref.x );
    return ans;
  }
}

int main(void){
  AAA Aobj1(2), Aobj2(3); 
  
  AAA Aobj3 = Aobj1.operator+(Aobj2);
  AAA Aobj3 = Aobj1 + Aobj2;
  // 두가지 의미는 같다!
  
  return 0;
}


// 전역함수에 의한 연산자 오버로딩 예시 - 2
class AAA{
private:
  int x;
public:
  AAA(int x) : x(x) {}
  friend AAA operator+(const AAA &ref1, const AAA &ref2);
  // 전역에 있는 함수정의가 AAA class에서 friend선언을 통해서 private영역에 접근할수 있도록된 것
  // 곧, "이 class의 객체들은 + 연산을 서로 할 수 있게되었다!" 의 의미
}

AAA operator+(const AAA &ref1, const AAA &ref2){
  AAA ans(ref1.x + ref2.x);
  return ans;
}
// const 함수는 멤버함수에서만 쓸 수 있는 것 상기하고 넘어가자!
// 이런 연산자를 오버로딩할겁니다.. 하고 전역에서 정의하는 느낌

int main(void){
  AAA Aobj1(2), Aobj2(3);
  AAA newAobj = Aobj1 + Aobj2;
  AAA newAobj = +operator(Aobj1, Aobj2);
  // 두가지 의미는 같다!
  
  return 0;
}
```
## 02. 연산자 오버로딩 사용법
  - 오버로딩이 불가능한 연산자 (그때 그때 찾아봐라)
  - 멤버함수 기반의 오버로딩만 가능한 연산자
    - =대입연산자, ()함수호출연산자, []배열접근연산자, ->멤버접근위한포인터연산자
  - **연산자 오버로딩시 주의사함**
    1. 본래 연사자의 의도를 벗어나서는 안된다. (+연산자의 순수기능을 빼앗을 수는 없다.)
    2. 연산자의 우선순위와 결합성을 바뀌지 않는다.
    3. 매개변수 디폴트값 설정 불가능하다.
  - **operator연산자 생성시 유념할 것!**
    1. **함수위치 고려(멤버, 전역) + 매개인자 고려(const, const X)** 
    2. **전위연산이냐, 후위연산이냐 고려** 
    3. **반환형 고려, 실제 반환인자 고려** 
    

## 03. 단항연산자 오버로딩
  - **멤버함수로 인한 오버로딩**
    - 매개변수가 필요가 없다. (단항 연산자이므로..)
    - **참조자형식을 반환해야지 다중 단항연산자 오버로딩이 가능하다!**
```cpp
class AAA{
private:
  int x;
public:
  AAA & operator++(){
    x++;
    return *this;
  }
};

int main(void){
  AAA p1(2);
  ++p1;
  ++(++p1);
  // 반환형이 참조자가 아니라면 ++p1의 연산결과를 받아서 한번 더 ++한 연산내용이 p1에 반영될 수 없다. 
}
```
  - **전역함수로 인한 오버로딩**
    - 매개변수가 하나 필요하다.(마찬가지의 이유로..)
    - 마찬가지의 이유로 참조자형식을 반환해야 함.
```cpp
class AAA{
private:
  int x;
public:
  friend AAA& operator--(AAA &ref);
};

AAA& operator--(AAA &ref){
  ref.x--;
  return ref;
  // ref 내의 값을 바꿔주고, ref를 반환해준다.
};

int main(void){
  AAA Aobj(3);
  --Aobj;
  --(--Aboj);
}
```

  - **전위연산자와 후위연산자와의 구분**
    - 매개인자로 받는 영역에 int 키워드가 추가되었는지, 아닌지의 여부를 통해서 구분한다.
    - int 인자 추가 X : 전위연산
    - int 인자 추가 O : 후위연산
```cpp
class AAA{
private:
  int x;
public:
  AAA(int x = 0) : x(x) {}
  
  // ++전위연산, 멤버함수
  AAA& operator++(){
    x += 1;
    return *this;
  }
  
  // 후위연산++, 멤버함수
  const AAA operator++(int){
    const AAA retobj(*this);
    x+=1;
    return retobj;
  }
  
  // --전위연산, 전역함수
  friend AAA& operator--(AAA &ref);
  
  // 후위연산--, 전역함수
  friend const AAA operator--(AAA &ref, int)
  
};  

AAA &operator--(AAA &ref){
  ref.x -= 1;
  return ref;
}

// const 선언은 return할 녀석이 const객체이든 아니든! 반환된 임시객체를 const 객체로 만든다. (객체 내부 멤버 변경 불가능)
// 그리고 '객체1 = const 객체2' (객체1에 const 객체2를 넣는) 연산 수행 시, 객체1은 값만 받아오고, const 객체는 되지 않음.
// 그러므로 객체의 후위연산을 연속으로 두번 호출할 수 없지만, 나눠서 두번 호출할 수는 있다.
// 이유는, (obj--)--를 한번에 가능하게 구현할 수 없기 때문이다.
const AAA operator--(AAA &ref, int){
  const AAA retobj(ref);
  ref.x -= 1;
  return retobj;
}

int main(void){
  
  AAA obj1(3);
  AAA obj2;
  
  obj2 = obj1--;
  // obj2에 들어가는 값은 연산 전의 값. obj1에 들어가는 값은 --연산 후의 값. (prefix unary operation 구현)
  
  return 0;
}

```

## 04. 연산자 오버로딩과 교환법칙 (전역에서의 선언)

  - 정리에 앞서, 연산자 오버로딩은 서로다른 자료형 간의 연산 또한 지원한다는 것도 알고 넘어가자.
  
```cpp
class Point{
private:
  int x, y;
public:
  Point(int x, int y) : x(x), y(y) {}
  
  // 객체와 일반 int형 간의 연산이 가능하도록, 연산자 오버로딩이 지원한다!
  Point operator*(int times){
    Point newPos(x*times, y*times);
    return newPos;
  }
};

Point newpoint(3, 4);

newpoint * 3;
// newpoint.operator*(3); 의 역할을 수행한다.
// 그러므로 객체가 왼쪽에 있어야 한다.
```

  - 교환법칙 성립을 위한 연산자 오버로딩의 구현
    - 교환법칙을 성립시키기 위한 해결책은 전역함수로 연산자함수를 구현하는 것이다!
    - (객체, 다른 자료형), (다른 자료형, 객체) 두가지 경우가 모두 존재해야 연산자에서의 교환법칙이 성립할 수 있다!
    - 어느 한쪽만 존재하면 오류 발생한다. 정의 잘못한다면 런타임 스택오버플로우가 발생할 수도 있다. (전역에서 return 잘못정의하면..!)
    
```cpp
class Point{
private:
  int xpos;
  int ypos;
public:
  Point(int x, int y) :xpos(x), ypos(y) {}
  
  // '객체 * 다른 자료형'의 경우가 먼저 존재하니, 반대 경우만 존재하면 되겠다! : 방법은 전역에서의 구현
  Point operator*(int times){
    Point newpoint(xpos*times, ypos*times);
    return newpoint;
  }
  
  // '다른 자료형 * 객체'의 경우가 존재해야 하니, 전역에서 정의하고 여기서는 friend 선언만 해주자!
  friend Point operator*(int times, Point &ref);
  
};

Point operator*(int times, Point &ref){
  // class내부에서의 정의를 다시 사용해주는 방식을 지금처럼 사용하거나, 새로 정의해줘도 상관없다.
  return ref * times; 
}

```
    
## 05. cout, cin, endl의 정체와 ostream

  - 먼저, 그 구동원리를 보여주는 코드를 보자면..
  
```cpp
#include <iostream>
using mystd{
  using namespace std;
  
  class ostream{
  public:
    ostream & operator<<(char *str){
      printf("%s", str);
      return *this;
    }
    ostream & operator<<(char str){
      printf("%c", str);
      return *this;
    }
    ostream & operator<<(int num){
      printf("%d", num);
      return *this;
    }  
    ostream & operator<<(double e){
      printf("%g", e);
      return *this;
    }
    
    // 함수 포인터 이용
    // endl 함수를 인자로 받아서, endl(*this)를 계산한 return 값인 this 객체의 참조자 반환을, 반환하는 함수..!
    ostream & operator<<(ostream& (*fp)(ostream & ostm)){
      return fp(*this);
    }
  
  };
  
  ostream & endl(ostream &ostm){
    ostm<<"\n";
    fflush(stdout);
    return ostm;
  }
  
  ostream cout;

};

int main(void){

  using mystd::cout;
  using mystd::endl;

  cout<<3.14<<endl<<32<<endl<<c<<endl;
  
  return 0;

}
```   
  - std namespace 안에 istream, ostream class가 존재하고, cin은 istream의 객체, cout은 ostream의 객체이다.
  - \<<은 ostream의 객체인 cout의 operator키워드와 같이 쓰이는 연산자이다.
  - \>>은 istream의 객체인 cin의 operator키워드와 같이 쓰이는 연산자이다.
  - endl은 복잡한 함수였다.. : endl(cout) 또한 실제로 실행됨.

## 06. ostream과 <<, \>>를 이용한 객체 출력
  - 마찬가지로 코드를 먼저 보자면..
  
```cpp
#include <iostream>
using namespace std;

class Point {
private:
	int xpos;
	int ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
	void ShowAllInfo() const {
		cout << "[ xpos : " << xpos << ", ypos : " << ypos << " ]" << endl;
	}
	friend ostream& operator<<(ostream& ostm, Point& ref);
	friend istream& operator>>(istream& istm, Point& ref);
};

// ostream 객체(cout) 참조자 반환, ostream 객체(cout) 참조자와 Point 객체 참조자 매개인자로 받음.
ostream& operator<<(ostream& ostm, Point& ref) {
	ostm << "[ xpos : " << ref.xpos << ", ypos : " << ref.ypos << " ]" << endl;
	return ostm;
}

// istream 객체(cin) 참조자 반환, istream 객체(cin) 참조자와 Point 객체 참조자 매개인자로 받음.
istream& operator>>(istream& istm, Point& ref) {
	istm >> ref.xpos >> ref.ypos;
	return istm;
}
```
  - 얼마 전 봉착 했던 백준 2751 문제에서의 궁금증이 해소됬다! <https://github.com/limjunhyuk97/BOJ/blob/main/SILVER/2751/2751.cpp>
  - 문제는 endl이라는 '함수'가 operator키워드와 꽤 복잡하게 엮여있어서 실행횟수가 늘어나면 함수 오버헤딩이 발생해서 시간을 많이 잡아먹는 것이었다!


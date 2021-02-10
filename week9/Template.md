# Template - 템플릿

## 1.  템플릿이란?
  - 함수나 클래스가 별도의 선언 없이 다른 자료형에서 동작할 수 있게 해주는 역할을 한다.
  - **함수 템플릿 : 템플릿 함수 - 생성된 함수**
  - **클래스 템플릿 : 템플릿 클래스 - 생성된 클래스**

## 2. 함수 템플릿
  - **기능은 같지만, 다른 자료형에 대해서 해당 자료형에서의 연산기능을 수행하는 함수를 구현할 수 있다.**
  - 컴파일 과정에서 한번 만들어진 함수 템플릿은 계속 이용된다.
    - 그렇게 만들어진 함수를 **템플릿 함수**라고 한다.
  - template 정의는 함수마다 해줘야한다.
  - 자료형 정하기
    - 사용자가 정하기
    - 컴파일러가 알아서 판단
    - 2개의 템플릿 자료형.
```cpp
template <typename T>
T Add(T num1, T num2){
  return num1 + num2;
}

Add<int>(3, 5);
Add<double>(2.3, 4.6);
// 사용자가 정의 : 컴파일때 생성된 템플릿 함수는 이후에도 계속사용됨.

Add(3, 5);
// 컴파일러가 정의 : 컴파일러가 주어진 인수를 보고 판단함.

Add(3, 4.5);
// 컴파일 오류 발생. (typename T를 무엇으로 정의할 지 모름)
// 해결하려면.. : 2개의 템플릿 자료형 사용, 컴파일러가 알아먹을 수 있게 해줘야 함. or 1개의 템플릿 자료형 사용, 사용자가 템플릿 자료형 정의

template <typename T1, typename T2>
int Template(T1 num1, T2 num2){
  return num1 + num2;
}

Add(3, 4.2);
```

## 3. 함수 템플릿의 특수화 (Specialization)
  - "어떤 템플릿에서 내가 임의로 정한 이런 자료형을 인자로 받을 때에는, 다음의 함수를 우선 호출해주세요!" 하는 의미를 지닌다.
  - 자료형 정보를 함수명 옆에 명시할 수도, 명시하지 않을 수도 있다.
    - 함수명 옆 명시 : char\* Max<char\*>(char\* a, char \*b);
    - 함수명 옆 명시 안함 : char\* Max(char\*a, char *b);
  
```cpp
template <typename T>
T compare(T var1, T var2){
  return var1 > var2 ? var1 : var2;
}

// const char *형을 받을 때에는 다음의 함수를 통해서 함수연산을 진행해 달라!
// 자료형 정보를 함수명 옆 < > 안에, 함수명<>식으로 명시한 모습
template<>
const char * compare<const char *>(const char* var1, const char* var2){
  return strlen(var1) > strlen(var2) ? strlen(var1) : strlen(var2);
}

// 다음의 경우가 const char* 자료형을 인자로 받는 템플릿함수 호출의 경우이다. : 함수 템플릿의 특수화가 적용된다.
cout << compare("me", "you") << endl;

```
  
## 4. 클래스 템플릿
  - 함수 템플릿을 만들때와 마찬가지로, 클래스 내부의 자료형들을 고정적으로 정의하지 않기 위해서 template <typename T> 정의를 이용한다.
  - **템플릿 클래스**
    - **템플릿 클래스의 새로운 객체 생성 시에** : 어떤 자료형에 대한 객체를 생성하는 것인지 < > 안에 명시 해줘야 한다.
    - **템플릿 클래스 내의 함수 외부 정의 시에** : 특정 "템플릿으로 정의된" 클래스 내의 함수 라는 것을 알리기 위하여,,,
      - template <typename !> 
      - class명<!>::함수명 조건 필요하다.
  
 ```cpp 
 
// 자료형을 결정짓지 않겠다는 의미의 문자 T
// T라는 이름을 이용해서 아래의 class를 템플릿으로 정의한다는 의미의 template <typename T>

template <typename T> 
class Point{
private:
  T xpos, ypos;
public:
  Point(T x, T y) : xpos(x), ypos(y) {}
};

int main(void){
  
  // 템플릿 클래스 생성 시에 자료형 명시해줘야 함.
  Point<int> pt1(2, 3);
  Point<char> pt2('A', 'B');
  
  // 마치, STL의 vector 컨테이너의 초기화 시 선언방법과 유사하다!!
  vector<int> arr(5);
  
  return 0;
}
 ```

## 5.1 클래스 템플릿과 파일분할
  - 파일분할
    - .h 는 선언부 : 각종 선언 + stl을 선언해 준다.
    - .cpp는 구현부(정의부) : 각종 선언에 대한 정의를 구현한다.
  - **클래스 템플릿의 파일분할**
    - 클래스 템플릿으로 **템플릿 클래스를 main에서 만들어 사용할 때에, template에 관한 모든 정보가 필요**하다.
    - .h 헤더파일의 선언만으로 클래스 템플릿의 모든 내용을 알 수 없다.
    - 그러므로, **.h 에 정의까지 구겨넣거나**, **.cpp 정의부 파일을 main에 같이 include해줘야** 한다.

```cpp

// Point class의 헤더파일에서 함수 선언과 정의의 분할

template <typename T>
class Point{
private:
  T xpos, ypos;
public:
  Point(T x = 0, T y = 0);
  void ShowData() const;
};

template <typename T>
Point<T>::Point(T x = 0, T y = 0) : xpos(x), ypos(y) {}

void Point<T>::ShowData() const{
    std::cout << " [ " << xpos << " , " << ypos << " ] " << std::endl;
  }
  
```
    
## 5.2 템플릿 안에 템플릿 넣기
  - 클래스 템플릿을 이용한다면 새로운 자료형들을 찍어낼 수 있다!
  - **템플릿 클래스 안에 자료형으로써 다른 템플릿 클래스를 사용할 수 있다!**
    - 예) 2차원 벡터의 구현
  
```cpp

template <typename T>
class Point{
...
};

template <typename T>
class ArrPoint{
private:
  T *arr;
  int arrlen;
...
};

ArrPoint<Point<int>> oarr(3);
// ArrPoint 템플릿 클래스 안에 다른 클래스 템플릿을 넣을 수 있다.

vector<vector<int>> arr(4, vertor<int>(3));
// vector를 통한 2차원 배열(4 * 3)의 구현!
// arr에 1차적으로 vector<int>형을 위한 공간을 갖는 4개짜리 공간을 마련하고,
// 각각의 공간들에 vector<int>(3)을 통해서 vector<int>형을 위한 공간을 3개씩 마련한다.

```

## 5.3 클래스 템플릿 내의, 특정 템플릿 클래스 객체를 인자로 받는 일반함수와 friend 선언
  - **클래스 템플릿으로 만든 템플릿 클래스 자료형**을 바탕으로 **일반 함수와 그 함수의 friend 선언 함수의 선언 O**
    - **일반함수다!!** 
    - **멤버함수 말하는게 아니다!!**
  - 확인해본 결과, **확정되지 않은 자료형**을 바탕으로는 **일반 함수와 friend 선언 함수 선언 X**

```cpp

template <class T>
class Point {
private:
	T xpos, ypos;
public:
	Point(T x1, T y1) : xpos(x1), ypos(y1) {}
	void ShowPosition() const {
		cout << " [ " << xpos << " , " << ypos << " ] " << "\n";
	}
	friend Point<int> operator+(const Point<int>& pt1, const Point<int>& pt2);
	friend ostream& operator<<(ostream& ostm, const Point<int>& ref);
};

// 외부에 존재하는 일반함수를 friend 선언으로 끌고 들어오는 것이기에, 확정된 템플릿 클래스 자료형을 사용해야 한다!
Point<int> operator+(const Point<int>& pt1, const Point<int>& pt2) {
	return Point<int>(pt1.xpos + pt2.xpos, pt1.ypos + pt2.ypos);
}

ostream& operator<<(ostream& ostm, const Point<int>& ref) {
	cout << " [ " << ref.xpos << " , " << ref.ypos <<  " ] " << "\n";
	return ostm;
}

```

## 5.4 클래스 템플릿의 특수화
  - 함수 템플릿의 특수화와 비슷하다.
  - 특수화가 진행되면 컴파일러가 미리 템플릿 클래스를 생성해 놓는다.
  - **특수화 과정에서, 새로운 멤버변수와 멤버함수의 추가가 가능**하다.
  - **클래스 템플릿의 부분 특수화**도 가능하다.
    - typename T1, typename T2처럼 여러개의 형틀이 존재할 때 부분적으로 특수화 시키는 것이다.
    - 전체 특수화로의 호출이, 부분 특수화로의 호출보다 우선시된다.
    
```cpp

#include <iostream>
using namespace std;

template <typename T1, typename T2>
class MySimple {
public:
	void WhoAreYou() {
		cout << "size of T1 : " << sizeof(T1) << endl;
		cout << "size of T2 : " << sizeof(T2) << endl;
		cout << "<typename T1, typename T2>" << endl;
	}
};

template<>
class MySimple<int, double> {
public:
	void WhoAreYou() {
		cout << "size of int : " << sizeof(int) << endl;
		cout << "size of double : " << sizeof(double) << endl;
		cout << "<int, double>" << endl;
	}
};

template<typename T1>
class MySimple<T1, double> {
public:
	void WhoAreYou() {
		cout << "size of T1 : " << sizeof(T1) << endl;
		cout << "size of double : " << sizeof(double) << endl;
		cout << "<T1, double>" << endl;
	}
};

int main(void) {

  // template <typename T1>의 경우 호출
	MySimple<char, double> m1;
  
  // template<typename T1, typename T2>의 경우 호출
	MySimple<int, long> m2;
  
  // template<>의 경우 호출
  // 전체 특수화가 부분특수화보다 우선시됨을 확인 가능.
	MySimple<int, double> m3;

	m1.WhoAreYou();
	m2.WhoAreYou();
	m3.WhoAreYou();

	return 0;

}

```

## 5.5 클래스 템플릿의 특수화 - 템플릿 매개변수의 상수화
  - **템플릿 매개변수**와 **템플릿 인자**
    - 템플릿 매개변수 : 템플릿의 정해지지 않은 자료형을 표현 (typename T1, T2 에서의 T1, T2)
      - 템플릿 매개변수의 선언에 변수의 선언이 올 수 있다!
      - 자료형 표현의 매개변수이든, 상수 전달을 위한 매개변수이든, 디폴트 값을 선언할 수 있다!
    - 템플릿 인자 : 템플릿에 자료형 정보를 전달함.
      - 템플릿 매개변수의 선언에 온 변수의 선언에 인자로 값을 전달하면, 템플릿 내에서 상수처럼 쓰일 수 있다.

```cpp

// template 매개변수의 선언에 변수의 선언이 들어왔다.
// template 매개변수의 선언에 디폴트 값이 들어갈 수 있음을 보인다.
template <typename T = int, int len = 7>
class SimpleClass{
private:
  
  // 바로 배열길이를 초기화 시킬 수 있다.
  T arr[len];
  
public:

  // (tip) 멤버함수의 const 선언은 외부에서건, 내부에서건 접근을 통한 멤버변수의 값 변경을 허용하지 않는다.
  // 그렇기에 T& 선언과, const 함수 선언은 서로 충돌할 수 있다.
  T& oeprator[](itn idx){ return arr[idx]; }

  SimpleArray<T, len>& opertor=(const SimpleArray<T, len>& ref){
    for(int i=0; i<len; ++i)
      arr[i] = ref.arr[i];
    return *this;
  }
  
};

// 템플릿 클래스 SimpleClass<>는 디폴트 값으로 만들어진 클래스이다.
SimpleClass<> arr;

// i8arr와 i5arr는 서로 다른 자료형으로 만들어진 템플릿 클래스 변수이다.
SimpleClass<int, 8> i8arr;
SimpleClass<int, 5> i5arr;

// arr와 i7arr는 같은 템플릿 클래스에서 생성된 변수이다. 그러므로, 대입연산 가능.
SimpleClass<int, 7> i7arr;
i7arr = arr;
```

  - 템플릿 매개변수로 변수의 선언을 사용할 시에 이점
    - 변수에 들어간 값에 따라서 다른 자료형의 템플릿 클래스가 생성되기 때문에, 불필요한 연산(예. 대입연산)을 막을 수 있다.
    - 상수처럼 템플릿 안에서 쓰이기 때문에, 배열의 길이 초기화 시에 유용하다.

## 6 static 변수와 템플릿
  - 함수내의 static 변수와 템플릿

```cpp
// 함수 템플릿 -> 생성된 템플릿 함수 -> 템플릿 함수 별로 static 변수가 초기화되어 존재하게 된다.

template <typename T>
void Foo(void){
  static T num = 0;
  num += 1;
  cout << num << " ";
}

// 모두 다른 static 변수를 갖게 된다.
Foo<int>();
Foo<double>();
Foo<long>();

```

  - class내의 static 멤버변수와 템플릿
  
```cpp
// 클래스 템플릿 -> 생성된 템플릿 클래스 -> 템플릿 클래스 별로 static 멤버변수가 초기화 되어 존재하게 된다.

template <typename T>
class Foo{
private:
  static T num;
public:
  ...
};

// template으로써 typename T라는 매개인자 명을 이용하겠다. : 컴파일러에게 템플릿 이용을 알림
// T의 익명자료형을 이용하는 Foo라는 클래스 템플릿 안의, T 자료형의 static인자를 0으로 초기화 하겠다. 
template <typename T>
T Foo<T>::num = 0;

// obj1, obj2를 제외한 객체들은 모두 다른 static 멤버 변수를 갖게 된다.
// obj1과 obj2 객체는 같은 템플리스 클래스에서 생성된 객체 이므로 static 멤버변수를 공유한다.
Foo<int> obj1, obj2;
Foo<double> obj2;
Foo<long> obj3;

```
  
  - 템플릿 특수화
    - template <typename T> 는 일부, 또는 전체 자료형이 정의되지 않았음을 컴파일러에게 알리는 것이다.
    - template<> 은 정의 부분에 T라는 익명 자료형이 존재하지 않을 때, 템플릿을 이용하여 찍어낸 것임을 컴파일러에게 알리는 것이다.
    - 템플릿 특수화는 템플릿이 이용되는 어디서든, 특수하게 지정할 필요가 생기면 사용할 수 있다.
      - static 멤버변수의 특수화도 가능하다.
      
```cpp

// int형의 템플릿 클래스에서의 static 멤버변수를 초기화하는 방법이다.
template<>
int Foo<int>::num = 5;

```

 








## 대입 연산자의 오버로딩

### 01. 대입연산자와 복사생성자
  - **객체간 대입연산 : 대입 연산자로 이루어 진다. (즉, 함수의 연산인 것이다!)**
    - 객체 초기화 시에 값을 넣을 때는 복사생성자가 호출되지만, 객체 초기화 이후 값을 대입할 때는 대입연산자, 즉 함수가 사용된다!
  - 대입연산자의 특징
    - **복사생성자의 특징과 유사하다.**
    - 따로 선언하지 않으면, 디폴트 대입연산자가 호출된다.
    - 따로 선언하지 않으면, 얕은 복사가 진행된다.
    - 동적할당된 멤버간의 대입연산 시에 깊은 복사가 필요하면 깊은 복사가 가능하도록 따로 정의해야 한다!
    - **값의 대입은 등호가 여러번 쓰인 경우, 맨 오른쪽에서 왼쪽으로 진행된다.**
```cpp
class AAA{ ... };

AAA obj1(..);
AAA obj2, obj3;

obj2 = obj3 = obj1;
// obj1에서 obj3로 복사되고, 그 다음 obj3에서 obj2로 복사된다!
```

## 02. 대입연산자의 문제점과 해결책
  - 2가지 문제가 발생한다.
    - **원래 있던 메모리 위치를 가리키는 값을 잃어서 메모리 누수 발생, 동일 메모리 주소를 가리키는 얇은 복사가 중복 소멸의 문제를 일으킨다.**
    - 복사생성자는 초기화 단계에서 할당하는 것이기에 원래 존재하던 값이 없어서 메모리 누수는 일어나지 않는데, 대입연산자에선 일어난다.
  - 해결방법
    - 깊은 복사가 가능하게끔 대입연산자의 내용을 수정해준다. : 중복 소멸의 문제 해결
    - 원래 있던 메모리를 해제하고 다시 메모리 공간을 할당한다 : 메모리 누수 문제 해결
```cpp
class Person{
private:
  int age;
  char *name;
public:
  // 생성자
  Person(...)
  
  Person & operator=(const Person &ref){
    // 먼저 원래 할당됬던 공간을 제거 - 메모리 누수 문제 해결
    delete []name;
    
    // 그리고 깊은 복사를 진행. ref가 원본, 해당 객체가 사본
    age = ref.age;
    int len = strlen(ref.name) + 1;
    name = new char[len];
    strcpy_s(name, len, ref.name); // strcpy_s는 vs에서 지원하는 strcpy..
    
    // 사본 해당 객체를 반환하여 다중 대입연산 대비.
    return *this;
    
  }
  // 다중으로 대입연산이 이뤄질 수 있으므로, 참조자를 반환 (ex. per1 = per2 = per3 ...)
  // per1.operator=(per2)의 의미이므로, ref의 값이 복사의 원본이다.
  // const Person& ref를 통하여 (const 선언), ref 값의 방지를 막는다.
}
```

## 03. 대입연산자의 상속에서의 문제점과 해결책
  - **유도 클래스의 디폴트 대입연산자는 자동으로 기초 클래스의 대입연산자를 호출한다.**
  - 유도 클래스의 디폴트 아닌 대입연산자에서 기초 클래스의 대입연산자를 호출하지 않은 경우, 기초 클래스 멤버의 대입이 안일어난다.
    - **유도 클래스의 대입연산자를 사용자가 정의해야하는 경우, 기초 클래스의 대입연산자 또한 같이 호출해주어야 한다!**
```cpp
class AAA {
private:
	int x;
	int y;
public:
	AAA(int x = 0, int y = 0) :x(x), y(y) {}
	virtual void foo() const {
		cout << "x : " << x << ", y: " << y << endl;
	}
	AAA& operator=(const AAA& ref) {
		x = ref.x;
		y = ref.y;
		return *this;
	}
};

class BBB : public AAA {
private:
	int z;
public:
	BBB(int x = 0, int y = 0, int z = 0) :AAA(x, y), z(z) {}
	void foo() const {
		AAA::foo();
		cout << "z : " << z << endl;
	}
  
  // 따로 대입연산자를 정의해줘야 하는 경우
  // 1. 상속상 은닉된 AAA의 멤버변수들에서 복사 일어나도록 AAA에서의 operator=() 함수 호출 후에
  // 2. BBB에서의 멤버변수들의 복사 일어나도록 BBB에서의 복사를 따로 정의
	BBB& operator=(const BBB& ref) {
		AAA::operator=(ref);
		z = ref.z;
    
    // 반환은 *this. 반환형은 BBB참조자. : 연속적인 대입이 일어날 수 있음.
		return *this;
	}
};
```

## 04. 이니셜라이저와 대입 연산자
  - 이니셜라이저는 선언과 동시에 초기화되서 빠르다.
  - 대입연산자는 선언과 초기화가 별도라서, 생성자호출 한번, 대입연산자호출 한번, 총 두번의 호출이 일어나 이니셜라이져보다는 느리다.

## 05. 배열의 인덱스 연산자 오버로딩
  - 배열 인덱스 연산자의 사용
    - 객체명[ 전달인자 ] 으로 받아들일 수 있게한다. : 객체명.operator[]( 전달인자 )와 객체명[ 전달인자 ] 가 같은 것이다.
      - 전달인자는 하나여야만 한다!
      - 전달인자를 통해서 배열과 연관된 여러 연산을 입맛대로 만들 수 있다.
    - **배열 클래스**를 사용하면, **선언된 배열의 범위를 넘는 주소에 할당된 값이 호출되는 문제의 발생을 미연에 방지**할 수 있다.
    - 배열 클래스에서는, **복사생성자와 대입연산자의 호출을 private 선언으로 원천 차단하는 것이 좋다.**
      - 얕은 복사에서의 소멸문제가 발생할 수도 있고, 애초에 배열(저장소)의 유일성 보장을 위해서, 복사할 이유가 없다.
```cpp
class IntArray{
private:
  int *arr;
  int arrlen;
public:
  IntArray(int arrlen) : arrlen(arrlen){
    arr = new int[arrlen];
  }
  
  // int 참조자를 return하는 이유는 배열의 값을 변경할 수 있게 하기위해서다.
  int & operator[](int idx){
    if(idx < 0 || idx >= arrlen){
      // exit은 프로그램 종료 코드다.
      exit(1);
    }
    return arr[idx];
  }
  
  ~IntArray(){
    delete []arr;
  }
};

// arr배열의 생성은 arr(정수값) : 생성자를 통한 생성, arr배열의 접근은 arr[인덱스값] : 인덱스 연산자를 통한 생성.
```

  - **const 객체 참조와 배열 인덱스 연산자 오버로딩**
    - const 객체 참조를 할 경우, 배열 인덱스 연산자 사용시 호출 불가능한 문제가 발생할 수 있다.
    - **함수 const 선언의 유무를 이용한 함수 오버로딩이 해결책이다.**
    
```cpp
// 위와 같은 class 조건에서 const 객체 참조자를 인자로 받는 함수가 등장하는 경우
// const의 선언 유무와 관련한 함수 오버로딩 개념을 사용한다.

// class IntArray 내부
int & operator[](int idx) {
  if(idx < 0 || idx >= arrlen)
    exit(1);
  else
    return arr[idx];
}

int & operator[](int idx) const{
  if(idx < 0 || idx >= arrlen)
    exit(1);
  else
    return arr[idx];

}

// class 외부
void ShowAllInfo(const IntArray &ref){
  for(int i=0; i<ref.arrlen; ++i){
    cout << ref[i] << " ";
    // ref[i]는 const ref.operator()[i]의 호출과도 같다. : 함수 오버로딩 요구!
  }
}
```

  - **배열 객체에서의 객체 저장 : 객체? 객체포인터?**
    - 결론은 객체저장보다 객체포인터를 통한 저장이 더 안전하다.
    - class타입 포인터에 대해서 typedef를 통해 새로운 별칭(자료형)을 지정해 주는 것이 좋다.
    
|객체 저장|객체 포인터 저장|
|:---:|:---:|
|배열 객체 속 배열에 객체 저장|배열 객체 속 배열에 객체 포인터 저장|
|임시객체 생성|새로운 객체 생성|
|대입 연산자로 저장|new를 통한 할당|
|깊은 복사, 얕은 복사의 문제|깊은 복사, 얕은 복사 문제 없음|

```cpp
// 배열 객체 <- 객체 저장
Point arr(3);
arr[0] = Point(2, 3);

// 배열 포인터 객체 <- 객체 포인터 저장
typedef Point* POINT_PTR;
PointPtr arr(3);
arr[0] = new Point(2, 3);

```
  
  
  
  
  
  
  
  

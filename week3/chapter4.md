## 1. 정보은닉
- 정보은닉은 class에서 private한 멤버변수들에 접근하기 위해 거쳐야 하는 멤버함수를 선언하여, **부정확한 값의 전달을 막고 안전한 접근을 유도**하는 것이다.


## 2. const 함수 / const 참조자 매개변수
- const 함수
```cpp
int Point::GetX() const{
  return x;
}
void Rectangle::ShowInfo() const{
  cout<< ....
}
```
  - **const 함수**는, 함수 내에서 **멤버변수의 값의 변경(저장)을 허용하지 않는 함수**다.
  - **const 함수 내**에서, **const 함수가 아닌 함수(값의 변경을 잠재적으로 허용하는 함수)는 호출될 수 없다.**
```cpp
int GetNum(){
  return num;
}

void ShowNum() const{
  cout<<GetNum()<<endl; // 오류 발생 - GetNum()이 const 함수가 아니다.
}
```
  - **const 참조자를 매개변수로 사용하는 함수**는, **const 함수만 인자로** 받을 수 있다.
```cpp
int GetNum(){
  return num;
}

void InitNum(const Easyclass &easy){
  num = easy.GetNum();  // 오류 발생 - GetNum()이 const 함수가 아니다.
}
```


## 3. 생성자

### 3.0 객체의 생성과정
 - 1단계: 메모리 공간 할당
 - 2단계: 이니셜라이저(member initializer)를 이용한 멤버변수 초기화
 - 3단계: 생성자의 몸체부분 실행
 - 객체가 되기 위해서는 반드시 하나의 생성자가 호출되어야함.
 - 객체 동적할당하려 하면 new를 이용해야 함.
    - malloc은 생성자가 호출되지 않는다.
    - ClassName *ptr = new ClassName;

### 3.1 생성자의 특징
 - **단 한 번**만! **객체 생성과 동시에 호출**되서, 값 할당.
 - **반환형이 없다.**
 - 함수기에 **함수 오버로딩이 가능**하다.
 - 함수기에 **default value 설정이 가능**하다.
 - 생성자 함수를 **정의하지 않더라도, 'default constructor'라는게 자동으로 삽입되어 호출**된다.

### 3.2 가능한 오류들
 - 생성자 함수 정의 시에 **default value에 대한 선언이 모호**하면 오류 발생 가능.
 - 생성자 함수 정의 시에 **매개변수 선언을 하지 않으면.. **
   - **객체명() 식으로 초기화 해서는 안된다.** 함수의 원형선언과 구분할 수 없는 경우가 생기기에, 저런 문장은 함수의 원형선언에 한해서만 사용하기로 약속하였다.
```cpp
Class SimpleClass ..
SimpleClass sc1(); X
SimpleClass sc1; O
SimpleClass *ptr = new SimpleClass(); O
SimpleClass *ptr = new SimpleClass; O
```

### 3.3 생성자의 사용
 - InitMembers를 생성자 안에 넣어서 활용할 수도 있다.
 - 멤버변수로 활용된 객체가 존재할 때
   - **member initializer**의 사용 
     - 객체 멤버 초기화 가능:memObj(parameter)
     - 객체가 아닌 멤버도 초기화 가능:variable(parameter)
     - 선호됨
       - **성능상 이점 : 선언과 동시에 초기화**
          - const와 &참조자는 선언과 동시에 초기화 되어야 한다.
          - **const 멤버변수 초기화 가능**
          - **&참조자 멤버변수 초기화 가능**
       - 초기화 대상을 명확히 인식 가능.
   - body부분 통해서 값 할당 - 객체 값 할당함수 직접 활용

### 3.4 public 생성자 함수 / private 생성자
 - **public 생성자**
  - class 외부에서 객체 생성함 - 외부에서 public 생성자로 접근 - public 생성자에서 private 멤버변수로 접근
 - **private 생성자**
  - class 내부 멤버 함수에서 객체 생성함 - 내부에서 private 생성자로 접근 - private 생성자에서 private 멤버변수로 접근
  - 객체의 생성방법을 제한할 때 매우 유용하게 활용됨.
  - (힙에 할당된 메모리 공간은 변수로 간주하여, 참조자를 통한 참조가 가능하다!)


## 4. 소멸자

### 4.0 소멸자의 의미
 - 객체를 생성하면서, **생성자가 할당한 리소스의 소멸**에 이용

### 4.1 소멸자의 활용
 - **~ClassName(){} 형식**으로 쓰인다.
  - ClassName() {} ~ClassName() {} 형식으로 생성자와 소멸자가 짝을 이룬다.
 - **반환값이 없다.**
 - **매개변수도 없다. / 오버로딩도 없고 / default value도 없다.**
 - **선언하지 않는다면 자동으로 default 소멸자가 생성**된다.








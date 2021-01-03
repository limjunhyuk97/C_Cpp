# 상속(Inheritance)의 등장

## 1. 상속은 단순한 재활용을 위한 도구 이상의 의미가 있다.

## 2. 데이터 중심 객체, 기능 중심 객체
   - 데이터 중심적인 class
     - 데이터 중심적인 class를 가리켜, **entity class** 라고 한다.
     - 파일 및 데이터베이스에 저장되는 데이터를 소유하고 있다.
     - 프로그램상 관리되는 **데이터 종류 파악에 도움을 준다.**
   - 기능 중심적인 class가
     - 기능 중심적인 class를 가리켜, **컨트롤 class**, 혹은 **핸들러 class**라고 한다.
     - control class를 통해서 **프로그램의 기능을 알 수 있게 된다.**
```cpp
class EmployeeData{
private:
    int salary;
    char * employeeId;
public:
    EmployeeData(char *Id, int salary) ...
    GetPay() const ...
    ShowSalaryInfo() const ...
}
// 데이터 중심적인 class !

class EmployeeHandler{
private:
    EmployeeData *empList[50];
    int empNum;
public:
    EmployeeHandler(Employee Data *emp) ...
    ShowAllSalaryInfo() const ...
    ShowTotalSalaryInfo() const ...
};
// 기능 중심적인 class , control class, handler class !
 
// heap corruption detected 오류 ?
// EmployeeData의 생성자 함수에서 employeeId를 new로 동적할당 해준 후에, 소멸자 함수에서 따로 delete 해주는 과정을 구현해주었더니 오류 등장.. 아직 이유를 모르겠음.
```

## 3. 좋은 프로그램의 조건
   - **요구사항 변경에 대응 가능한 프로그램의 유연성**
   - **기능의 추가에 따른 프로그램의 확장성**
    
## 4. 기능 추가에 따른 프로그램 확장시 발생가능한 문제
   - 단순히 class 종류를 늘리는 작업은 컨트롤 class의 대대적이고 비효율적인 보수작업을 유도한다.
   - **상속 개념을 이용하면 이러한 비효율적인 작업과정을 대폭 줄일 수 있다.**
    
    
    
    
# 상속(Inheritance)

## 1. 상속이란?
   - A 가 B 를 상속한다는 것은, A가 본인 스스로의 성질은 물론이고, B가 갖고 있는 성질까지 갖게된다는 것이다.
   - class A 가 class B 를 상속한다는 것은, class A 가 본인의 멤버 + class B 의 멤버까지 갖게된다는 것이다.
    
## 2. 상속의 결과
  |class A|class B|
  |:---:|:---:|
  |상속된 클래스|상속한 클래스|
  |기초(base) 클래스|유도(derived) 클래스|
  |슈퍼(super) 클래스|서브(sub) 클래스|
  |부모(parent) 클래스|자식(child) 클래스|
   - 멤버 함수
       - **부모 class의 멤버 함수와 변수들을 바로 호출할 수 있다.**
   - 생성자
       - 부모 class의 멤버 변수들 또한 생성자에 의해 초기화 되어야만 한다. (어쨌든 모두 상속한 클래스의 멤버변수들이다!)
       - 생성자는 함수다. 부모 클래스 A에 이미 존재하는 생성자를 자식 클래스 B에서 그대로 사용해주어야 한다.
       - **그러므로, 부모 클래스 A의 생성자를 바탕으로 부모 클래스 A의 멤버변수를 초기화해줘야 한다.** 
   - 멤버 변수
       - 자식 클래스 B의 멤버함수를 통해서 부모 클래스 A의 private에 접근할 수 없다. **(private 접근제한의 기준은 class다!)**
       - **자식 클래스 B 안의 부모 클래스 A 멤버함수를 통해서 A의 private에 접근해야만 한다.**
       - **정보은닉이 하나의 객체 내에 여러개의 class가 존재하는 상황인 상속에서도 진행되는 것이다.**
```cpp
class A{
private:
    int n;
    int m;
public:
    A(int n, int m) :n(n) , m(m) {}
    void ShowInfo_A() const{
        std::cout<<n<<", "<<m<<endl;
        return;
    }
};

class B : public A{
private:
    int k;
public:
    // 상속된 A의 생성자를 이용해서 A의 멤버변수를 초기화 해주고, B의 멤버변수는 따로 초기화 해준다.
    // A 멤버변수 초기화를 위한 값 또한 전달받아야 하며, 이니셜라이저를 통해서 A 생성자를 호출할 수 있다.
    B(int k, int n, int m) :A(n, m), k(k) {}
    
    // 상속된 A의 멤버함수는 이제 B의 멤버함수이기도 하기에 자유롭게 끌어와서 사용할 수 있다.
    void ShowInfo_B() const{
        ShowInfo_A();
        std::cout<<k<<endl<<endl;
        return;
    }
};
```

## 3. 유도클래스의 객체 생성과 소멸
   - **유도 클래스 객체 형성 과정**에서 **기초 클래스의 생성자와, 유도 클래스의 생성자가 각각 호출된다. (생성자 호출이 두번 일어난다.)**
       - 기초 클래스의 생성자는 100% 호출된다.
       - 기초 클래스 생성자를 별도로 호출하지 않으면, 기초 클래스의 void생성자가 호출된다.
       - 기초 클래스의 생성자가 호출된 후에, 유도 클래스의 생성자가 호출된다.
```cpp
class B : public A{
private:
    int k;
public:
    A(int n, int m, int k) : B(n ,m), k(k) {}
    
    // 객체 형성과정 : 메모리할당 -> 생성자 호출, 멤버변수 초기화 -> 생성자 몸체부분 실행
    // 생성자 호출, 멤버변수 초기화 : (기초 class 생성자 호출, 멤버변수 초기화 -> 유도 class 생성자 호출, 멤버변수 초기화)

```   
   - **유도 클래스 객체 소멸 과정**에서 **유도 클래스의 소멸자와, 기초 클래스의 소멸자가 각각 호출된다. (소멸자 호출이 두번 일어난다.)**
       - 유도 클래스의 소멸자가 호출된 후에, 기초 클래스의 소멸자가 호출된다. (객체 소멸시의 순서가, 생성의 순서와 반대이다.)
       - 스택에 생성된 객체의 소멸순서는 생성순서와 반대되는 것이다.
       - 유도클래스 멤버변수에서의 해제는 유도클래스 소멸자에서, 기초클래스 멤버변수에서의 해제는 기초클래스에서 진행한다. 
```cpp
class A{
    ...
};
class B : public A{
    ...
};

// 소멸 시에 B의 소멸자가 먼저 호출되고,다음으로 A의 소멸자가 호출된다. 
```
    
    
    
    
# 상속(Inheritance)의 형태

## 0. public, protected, private
  - **public, protected, private은 접근제어 지시자로 사용되기도 하지만, 상속형태의 명시자로도 사용된다.**

## 1. 3가지 접근제어지시자, 특징
 |-|private|protected|public|
 |:---:|:---:|:---:|:---:|
 |접근 허용 범위|좁음|중간|넓음|
 |외부에서의 접근|불가능|불가능|가능|
 |상속 시에|은닉|상속|상속|
 |유도클래스에서의 접근|불가능(은닉)|가능|가능|
 |자체클래스에서의 접근|가능|가능|가능|
 
  - **객체에서 protected는 private과 같은 지위를 갖는다.**
  - **protected와 private의 다른 점은 상속상황에서 유도클래스내에서의 은닉여부이다.**
  
## 2. 3가지 상속, 특징
  - **! 상속 == ! 보다 제한범위가 큰 멤버들을 !로 상속받겠다.**
  - **protected 상속**
    - protected보다 넓은 범위의 접근을 허용하는 멤버(public 멤버)를 protected로 상속받는다.
    - 기존 protected 멤버는 protected 속성으로 상속되고, 정보은닉이 일어나지 않기에 유도 class내에서 바로 접근 가능하다.
    - 기존 private멤버는 private 속성으로 상속되고, 정보은닉에 의거하여 유도 class내에서 바로 접근은 불가하다.
    - 유도 class에서 멤버들의 취급
    
||기초class|유도class|
|:---:|:---:|:---:|
|**private**|은닉|private|
|**protected**|protected|protected|
|**public**|protected|public|
  
  - **private 상속**
    - private보다 넓은 범위의 접근을 허용하는 멤버(protected, public 멤버)를 private으로 상속받는다.
    - 기존 private멤버는 private 속성으로 상속되고, 정보은닉에 의거하여 유도 class내에서 바로 접근은 불가하다.
    - 유도 class에서 멤버들의 취급
    
||기초 class|유도 class|
|:---:|:---:|:---:|
|**private**|은닉|private|
|**protected**|private|protected|
|**public**|private|public|

  - **public 상속**
    - public보다 넓은 범위의 접근을 허용하는 멤버를 public 상속받는 것인데, 그냥 기초 class의 내용을 그대로 상속받는다.
    - 기존 private멤버는 private 속성으로 상속되고, 정보은닉에 의거하여 유도 class내에서 바로 접근은 불가하다.
    - 유도 class에서 멤버들의 취급
    
||기초 class|유도 class|
|:---:|:---:|:---:|
|**private**|은닉|private|
|**protected**|protected|protected|
|**public**|public|public|

  - **근데 왠만하면 public상속만 사용한다고 하더라..!**
    
# 상속(Inheritance)의 조건과 필요

## 1. 상속은 특별한 상황적 조건과, 필요가 수반될 때 사용하는 것이 가장 좋다.
  - 조건
    - IS-A관계의 성립. (가끔 HAS-A 관계의 성립 시에!)
  - 필요 (왜?) 
    - 상속을 통해서 일련의 클래스에 공통의 규약을 정의할 수 있다!
  
## 2. 상속의 조건
  - IS-A 관계의 성립
    - IS-A 관계란, "~은 곧 ~이다."의 관계가 성립하는 경우를 말한다.
    - UML 상속표현으로 나타낼 수 있다. (Unified Modeling Language, UML)

  - HAS-A 관계의 성립
    - HAS-A 관계란, "~이 ~을 갖고있다."의 관계가 성립하는 경우를 말한다.  
    - 그러나, 이 경우는 **컨트롤 객체를 만드는 것처럼, 상속이 아닌 다른 방식으로 소유관계를 구현하는 것이 나은 경우가 많다.**
  
  
    
    
    
    

## 1.객체 포인터 변수와 상속관계
  - **AAA 형 포인터 변수는 AAA+a 인 객체의 주소값을 저장할 수 있다.(즉, AAA를 상속하는 모든 객체의 주소값을 가리킬 수 있다는 것이다.)**
  - AAA형 포인터와 접근성 -> **가상함수(virtual function)와 관련된 내용이다..!**
    - AAA형 포인터로는, AAA+a 클래스 내부의, AAA 클래스 속의 public영역에만 접근가능하다.
  - AAA형 포인터와 생성자
    - AAA형 포인터로 AAA+a 객체를 가리킨다면, AAA+a 객체의 생성자 호출이 가능하다.
    
```cpp
class Person{
private:
  char *name;
public:
  ...
  void MyName(){
    std::cout<<"my name is "<<name<<endl;
  }
}; 

class Student : public Person{
private:
  int age;
public:
  ...
  void Age(){
    std::cout<<"my age is "<<age<<endl;
  }
}; 

int main(void){
  
  Person *ptr;
  
  ptr = new Student(..);
  // Student 객체의 생성자 호출함.
  
  ptr->MyName();
  // ptr->Age() 접근은 불가하다!

  return 0;
}
```

  - **(가능한 이유) IS-A 관계에 따라서 기초class를 상속하면(특성을 갖으면), 유도class들 또한 기초class의 일종인 것이기 때문이다.** 
  - **(사용의 이점) 프로그램 확장시에 상속의 관계에 있는 객체를 추가하는데에 불필요한 작업이 사라진다.**
  
```cpp
class Employee ...

class PermanentWorker : public Employee ...

class EmployeeHandler{
...
  void addEmployee(Employee *emp){
    empList[empNum++] = emp;
    // Employee class를 상속하는 어떤 객체든지 간에 handler class에서 Employee 객체 포인터을 매개변수로 받아들일 수 있다.
    // 이는 각 객체별로 다른 종류의 포인터를 새로 매개변수 선언해주는 번거로움을 줄여준다.
  }
};

int main(void){

  EmployeeHandler handler;
  handler.addEmployee(new PermanentWorker(...));
  // Employee class를 상속하는 PermanentWorker class를 받고 있다.
  
  return 0;
}
```

## 2. 함수 오버라이딩(overriding), 함수 오버로딩(overloading)
  - **기초 클래스와 유도 클래스에 동일한 이름과 형태로 정의된 함수가 있다면, 함수 호출시 유도클래스의 함수가 먼저 호출된다. (함수 오버라이딩)**
  - 만약, 이름은 같고 매개변수의 자료형 및 개수가 다른 함수가 선언되면, 함수 오버로딩이 일어난다.
  - **범위지정연산자를 사용해서 지정해준다면, 특정 층위 class내의 함수이용을 강제할 수 있다.**
  - 범위지정연산자를 사용하지 않는다면, "함수오버라이딩/ 함수오버로딩 -> 같은 층위 class 내의 함수이용" 순서로 코드가 해석된다.
  
```cpp
class PermanenetWorker{

  int GetPay() const ...
  
  void ShowSalaryInfo() const {
    cout << GetPay();
  }
};

class SalesWorker : public PermanentWorker{

  int GetPay() const {
    return PermanentWorker::GetPay() + (int)(salesResult*bonusRatio);
  }
  // 범위연산자 지정 O : PermanentWorker의 GetPay()함수에 접근
  
  void ShowSalaryInfo() const{
    cout<< GetPay();
  }
  // 범위연산자 지정 X : 함수 오버라이딩 -> 같은 층위의 GetPay() 함수로 코드 진행.
  
}

int main(){
  
  SalesWorker salesman(...);
  
  salesman.GetPay();
  // 범위연산자 지정 X : salesman class의 GetPay 함수가 호출된다.
  
  salesman.PermanentWorker::GetPay();
  // 범위연산자 지정 O : PermanentWorker class의 GetPay 함수가 호출된다.
}
```

## 3. 가상함수(Virtual Function) / 가상소멸자(Virtual Destructor)
  - 객체 포인터 할당
    - C++ 컴파일러는 연산수행시에 포인터가 실제로 참고하고 있는 객체를 기준으로 판단하지 않고, 포인터의 자료형으로 연산가능성을 판단한다.
    - 유도 class의 객체 일체에 관해서는 참조는 가능하지만
    - 유도 class의 함수를 호출하거나, 유도 class 포인터에 기초 class포인터를 할당하는 것은 불가능하다.
    - 또한 함수 오버라이딩이 일어나서, 동일명, 동일형태의 함수를 호출할 경우 포인터 자료형 기준으로 오버라이딩 가능한 가장 상위 함수를 호출한다.
     
```cpp
class AAA{
  void fooA() { cout << "AAA foo function called" << endl;}
};
class BBB : public AAA{
  void fooB() { cout << "BBB foo function called" << endl;}
};
// AAA가 상위 class, BBB가 하위 class라고 할때!

AAA *ptrA;
ptrA = new BBB();
// 가능하다. BBB가 AAA를 상속하는 class이기 때문에 AAA의 성질을 갖고 있어서 할당가능하다고 판단한 것이다.

BBB *ptrB = new BBB();
AAA *ptrA = ptrB;
// 가능하다. 위와 같은 원리이다.

AAA *ptrA = new BBB();
ptrA->fooB();
// 불가능하다. AAA class의 포인터가 BBB class 객체를 참조하고 있지 않을 수도 있기 떄문이다.

AAA *ptrA = new AAA();
BBB *ptrB = ptrA;
// 불가능하다. 마찬가지로 AAA class의 포인터가 BBB class 객체를 참조하고 있지 않을 수도 있기 떄문이다.

AAA *ptrA = new AAA();
BBB *ptrB = new BBB();

ptrA->foo();
// A class의 foo함수가 오버라이딩 됨.

ptrB->foo();
// B class의 foo함수가 오버라이딩 됨.
```

  - 가상 함수 (Virtual Function)
    - 포인터 자료형 기준으로 함수가 오버라이딩되는 특성이 문제를 불러일으킬 수 있기 때문에, 가상함수라는 개념을 제공한다.
    - **포인터 자료형 기준으로 호출 대상 함수를 정하는 것이 아니라, 실제 가리키는 객체를 기준으로 호출 대상 함수를 정하는 방법을 제공한다.**
    - 정리
      - **컴파일러 연산시 발생하는 문제점 : '포인터 자료형 기준 판단'으로 해결**
      - **상속상태에서 함수 호출시 발생하는 문제점 : '가상함수 설정'과 '범위지정연산자'를 통해서 해결**
      
```cpp
class AAA{
  virtual void fooA() { cout << "AAA foo function called" << endl;}
};
class BBB : public AAA{
  virtual void fooB() { cout << "BBB foo function called" << endl;}
  // virtual 선언을 따로 해주지 않아도 된다.
};
// AAA가 상위 class, BBB가 하위 class라고 할때! (위와 마찬가지의 경우)

BBB *ptrB = new BBB();
AAA *ptrA = ptrB;
// ptrA가 자료형 상으로는 AAA 객체를 가리키지만, 실제 상으로는 BBB 객체를 가리킨다.

ptrA->foo();
// 그러므로 B class의 foo함수가 가상함수 개념에 따라서 실행됨

ptrB->foo();
// 그러므로 B class의 foo함수가 가상함수 개념에 따라서 실행됨
```

  - 순수 가상 함수(Pure Virtual Function)와 추상 클래스(Abstract Function)
    - 순수 가상 함수
      - 유도 class에서의 함수호출을 위해 정의된 연결고리 같은 느낌의 실제 동작이 목적이 아닌 가상 함수를 의미한다.
      - 함수의 몸체가 정의되지 않은 함수
    - 추상 클래스
      - 유도 클래스들의 표현적 바탕이 될 수 있는, 순수 가상 함수가 하나라도 존재하는 완전하지 못한 class
      - 추상 클래스를 통해서 객체를 생성할 수 없다.
    - 사용의 이점
      - 객체의 생성을 미연에 방지할 수 있다
      - 순수 가상 함수임을 (몸체가 정의되지 않았음을) 명시하는 역할을 해줄 수 있다.
    - 사용법
    
```cpp
class Employee{
private:
  char name[100];
public:
  Employee(char *name) { ... }
  void ShowYourName() const { ... }
  virtual int GetPay() const = 0;
  virtual void ShowSalaryInfo() const = 0;
  // const = 0은 대입의 의미가 아니라, 함수의 몸체가 비어있다는 의미이다.
};
// Employee class 로는 객체를 생성할 수 없다.
```

  - 가상 소멸자(Virtual Constructor)
    - vitrual 선언 X 시에 : 포인터의 자료형을 기준으로 그것보다 상위의 소멸자들만 호출된다.
    - 가상 소멸자 선언을 해야, 계층 구조상 가장 아래에 있는 소멸자부터 가장 상위의 소멸자까지 차례대로 실행이 된다.

```cpp
class AAA{
public:
  virtual ~AAA() ...
};

class BBB : public AAA{
public:
  virtual ~BBB() ...
};

class CCC : public BBB{
public:
  virtual ~CCC() ...
};

AAA *ptr = new CCC(...);
delete ptr;
// virtual 선언을 해주었으므로 CCC 부터 BBB AAA 순으로 소멸자가 호출된다!
//

``` 

## 4. 객체 참조 변수와 상속관계
  - **객체 참조변수와 상속관계에서도, 객체 포인터 변수에서의 특징들이 고스란히 유지된다.**
    - (객체 참조변수가 참조하는 class + a) class 객체 참조 가능.
    - 참조 자료형 기준으로 객체 참조자 연산이 일어난다.
    - 참조 자료형 기준으로 일어나는 연산을 실제 참조 객체 기준 연산으로 바꾸려면 virtual 선언을 해주면 된다.

## 5. 상속(Inheritance)의 조건, 이유와 핵심정리!
  - **상속의 조건 : IS-A 관계의 성립 (의미를 포함하는 관계의 성립), HAS-A 관계의 성립 (의미를 지니고 있는 관계 : 종종 상속으로 표현)**
  - **상속의 이유 : 상속을 통해서 일련의 class들 사이의 공통적인 규약을 정의할 수 있다.**
    - 기초 class에서 파생되는 모든 유도 클래스의 객체를 기초 class의 객체로 바라볼 수 있게된다.
    - class 별로 다른 행동들은 가상함수 개념과, 함수오버라이딩 개념으로 해결할 수 있다.

## 6. 다형성(Polymorphism)
  - 같은 모습, 다른 형태
  - 문장은 같은데 결과는 다른 상황.

```cpp
class First{
public:
  virtual void SimpleFunc() {
      cout << "Fist class" << endl;
  }
};

class Second : public First{
public:
  virtual void SimpleFucn() {
    cout << "Second class" << endl;
  }
};

int main(void){
  
  First *ptr = new First();
  ptr->SimpleFunc();
  // 출력 결과 : "First class"
  delete ptr;
  
  ptr = new Second();
  ptr->SimpleFunc();
  // 출력 결과 : "Second class"
  delete ptr;
  
  // 같은 ptr->SimpleFunc() 인데, 결과가 다르다. 이유는 가상함수로 인해서 같은 포인터 변수가 가리키는 객체의 자료형이 달라지기 때문이다!
  
  return 0;
}
```
  
  
  
  
  
  
  
  
  
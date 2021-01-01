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

## 3. 가상함수(Virtual Function)
  - 객체 포인터 할당
    - C++ 컴파일러는 연산수행시에 포인터가 실제로 참고하고 있는 객체를 기준으로 판단하지 않고, 포인터의 자료형으로 연산가능성을 판단한다.
    - 유도 class의 객체 일체에 관해서는 참조는 가능하지만
    - 유도 class의 함수를 호출하거나, 유도 class 포인터에 기초 class포인터를 할당하는 것은 불가능하다.
     
```cpp
class AAA{
  void fooA() {}
};
class BBB : public AAA{
  void fooB() {}
};
// AAA가 상위 class, BBB가 하위 class라고 할때!

AAA *ptrA;
BBB *ptrB;

ptrA = new BBB(...);
// 가능하다. BBB가 AAA를 상속하는 class이기 때문에 AAA의 성질을 갖고 있어서 할당가능하다고 판단한 것이다.

ptrB = new BBB(...);
ptrA = ptrB;
// 가능하다. 위와 같은 원리이다.

ptrA->fooB();
// 불가능하다. AAA class의 포인터가 BBB class 객체를 참조하고 있지 않을 수도 있기 떄문이다.

ptrB = ptrA;
// 불가능하다. 마찬가지로 AAA class의 포인터가 BBB class 객체를 참조하고 있지 않을 수도 있기 떄문이다.
```


  
  
  
  
  
  
  
  
  
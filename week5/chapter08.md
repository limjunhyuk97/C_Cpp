## 1.객체 포인터 변수와 상속관계
  - **AAA 형 포인터 변수는 AAA+a 인 객체의 주소값을 저장할 수 있다.(즉, AAA를 상속하는 모든 객체의 주소값을 가리킬 수 있다는 것이다.)**
  - AAA형 포인터와 접근성
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
class Employee{
private:
  char name[50];
public:
  Employee(char *myName) ...
};

class permanentWorker : public Employee{
private:
  int salary;
public:
  void permanentWorker(int mySalary) ...
};

...

class EmployeeHandler{
private:
  Employee *empList[50];
  int empNum;
public:
  EmployeeHandler() ...
  void addEmployee(Employee *emp){
    empList[empNum++] = emp;
    // Employee class를 상속하는 어떤 객체든지 간에 handler class에서 Employee 객체 포인터을 매개변수로 받아들일 수 있다.
    // 이는 각 객체별로 다른 종류의 포인터를 새로 매개변수 선언해주는 번거로움을 줄여준다.
  }
};

```
  
  
  
  
  
  
  
  
  
  
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

## const , 포인터, 참조자, 함수

### 1.0 const와 포인터 (visual studio 환경에서 실험해봤을때..)
  - **const data_type** \*ptr , data_type **const \*ptr**
    - 가리키고 있는 값을 변경할 수 있다.
```cpp
  int a = 5, b= 4;
  const int *ptr = &a;
  cout << *ptr; // 5 출력
  ptr = &b;
  cout << *ptr; // 4 출력
```
    - 역참조를 통한 값의 변경은 불가능하다.
```cpp
  int a = 5, b= 4;
  int const *ptr = &a;
  *ptr = 6; // 불가능
```

### 1.1 const와 포인터 (내가 알아낸 정보)
  - **const data_type** \*ptr
    - 상수를 가리키는 포인터, 상수 변수에 대한 포인터
    - 가리키고 있는 값은 변경할 수 있다
    - 역참조를 통한 값의 변경은 불가능 하다
```cpp
  int a = 4, b= 5;
  const int *ptr = &a;
  *ptr = 4 // 불가능
  ptr = &b // 가능
```
  - data_type **const \*ptr**
    - 상수 포인터, 포인터 값이 불변하는 상수
    - 가리키고 있는 값을 변경할 수 없다
    - 역참조를 통한 값의 변경이 가능하다
```cpp
  int a= 5, b = 9;
  int const *ptr = &a;
  *ptr = 5 // 가능
  ptr = &b // 불가능
```
  - **const data_type const \*ptr**
    - 상수변수를 가리키는 상수 포인터
    - 가리키고 있는 값의 변경 불가능 (const *ptr 때문)
    - 역참조를 통한 값의 변경 불가능 (const data_type 때문)
```cpp
  int a= 5, b = 9;
  int const *ptr = &a;
  *ptr = 5 // 불가능
  ptr = &b // 불가능
```

### 2. const 와 참조자 (visual studio 환경에서 실험해봤을때..)
  - **const data_type** &ref
    - ref의 값을 변경할 수 없다.
    - ref가 가리키는 값 조차도 변경할 수 없다.
    - 즉, **ref가 가리키는 메모리의 변경과, 메모리 속 값의 변경을 일체 허용하지 않는다.**
```cpp
  int a = 4, b= 6;
  const int &ref = a;
  
  ref += 2  // 불가능
  ref = b   // 불가능
```

### 3. const 와 멤버함수
  - 멤버함수 끝 const 선언
  - **이 함수 내에서 멤버 변수 내에 저장된 값을 변경하지 않겠다**는 의미!
  
  

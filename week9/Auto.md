# auto

## auto란?
  - 데이터 타입 추론
  - 선언한 변수나, 람다식의 타입을 컴파일러에게 추론하도록 맡기는 역할을 한다.
  - **초기화 값에 따라 컴파일러가 알아서 데이터 타입을 정해주는 키워드이다.**

## auto와 iterator
  - auto를 iterator가 대신할 수 있다.
  - **auto가 주소를 받아오는 것이 가능한 것!**
  
```cpp

// stl vector container를 이용해서 동적으로 1 ~ 10 까지 저장함.
vector <int> arr;
for(int i=0; i<10; ++i){
  arr.push_back(i+1);
}

// iterator를 사용하는 방법
vector <int>::iterator iter;
for(iter = arr.begin(); iter != arr.end(); ++iter){
 ....
}

// iterator auto로 대신하는 방법 - 1
// 실제값 변경가능. 특정 인덱스로 접근 가능
for(auto it = arr.begin(); it != arr.end(); ++it){
 ....
}

// iterator auto로 대신하는 방법 - 2
// 실제값 변경가능. 특정 인덱스로 접근 불가능
for(auto& it : arr){
 ....
}

// auto 네글자로 vector <int>::iterator 를 대신할 수 있는 신세계..

```

## auto와 const, const &
  - auto와 const
    - const 상수 취급으로 만든다.
    - 효과 : 값의 변경 불가능
  - auto와 const &
    - const 상수 참조자 취급으로 만든다. 
    - 효과 : 값의 변경 불가능 + 복사 비용의 절약
    
```cpp

for(const auto& it : arr){
  cout << it << endl;
}

```

## auto 응용
  - STL <algorithm> 지원, sort함수와 auto.

```cpp

#include <iostream>
#include <algorithm>
using namespace std;


```
    
    
    
    
    
    
    
    
  
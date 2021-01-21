## 0. stl이란?
 - standard template library
 - 표준 cpp 라이브러리
 - stl의 구성
   - container
     - sequence container : array, vector, list, deque
     - assoicative container : set, multiset, map, multimap
   - iterator
   - algorithm
   - function object
   - container adaptor
   - allocator

## 1. 해쉬충돌을 방지하는 방법?
 - open addressing
   - 충돌이 일어나면 다른 저장소에 저장하도록 한다. 해쉬값과 실제 저장 위치가 다를 수 도 있다.
   - 선형탐사 : 다음 칸 비어있으면 다음칸에
   - 제곱탐사 : 제곱만큼 떨어진 빈칸에 넣기
   - 이중해쉬 : 2개의 해쉬함수를 사용한다.
 - close addressing
   - 해쉬값과 실제 저장소 위치가 다를 수 가 없다.
   - 버켓 : 2차원 배열로 해당위치에 넣는다
   - 체이닝 : 충돌 값을 연결리스트로 연결

## 2. bool형 자료형
 - true false는 1과 0의 값으로 매치된다
 - 참, 거짓을 판별 시 사용

## 3. 참조자(reference)
 - 변수란) 할당된 메모리 공간에 붙여진 이름
 - (참조자란) 이미 선언된 변수를 대상으로, 동일 메모리 공간에 하나의 이름을 더 붙이는 것. 변수와 구분된다. 즉, 별칭이다.
 - 선언 후에 변수와 다를 바 없다.
   - &로 주소값 반환도 가능하다
   - local reference는 함수를 빠져나가면 소멸됨
 - 참조자는 여러개 만들 수 있으며, 참조자의 참조자를 만들 수도 있다.
 - 제약조건
   - 상수 참조 X, 오직 변수 참조O
   - 미리 참조 선언X
   - 참조 대상 바꾸기X
   - 무조건 선언과 동시에 참조O
   - 배열요소도 참조 가능O - 변수이기에
   - 포인터도 참조 가능O - 포인터 변수이기에

## 4 참조자와 함수
 - 두가지 함수 종류
   - call-by-value : 값을 인자로 전달 받음
   - call-by-reference : 주소값을 인자로 전달 받아서 함수 외부의 값에 접근하는 형태의 함수호출
   - 주소값이 참조의 도구로 쓰였느냐, 그렇지 못했느냐가 구분의 기준이 된다.
 - 외부 값에 접근하는 두가지 방식
   - 주소값을 이용한 call-by-reference
   - 참조자를 이용한 call-by-reference
  - 어쨌건 이 두가지 모두, 저장 공간(주소값)에 대해서 다루게 된다.

## 5.1 참조자 매개변수

### 5.1.1 참조자를 이용한 call-by-reference
 - 매개변수로 참조자를 선언하게 되면..
 - 함수가 인자들을 받는 순간, 참조자 매개변수들이 '기존'의 변수들의 별칭으로 초기화 된다.
 - 이는 참조자가 가리키는 메모리 공간이 기존 변수들과 일치하게 되는 것이고,
 - 이를 통해서 참조자는 외부 공간에 접근할 수 있게 되는 별칭이 되는 것이다.

### 5.1.2 참조자를 이용한 call-by-reference의 단점
 - 코드 수정 과정에서, 전달하는 과정이 call-by-value와 차이가 없게 보일 수 있으므로, 의도치 않게 값이 바뀌는 오류가 생길 수도 있다.
 - C++에서는 함수의 원형까지 확인해야 하는 경우가 자주 발생한다.
 - const int &ref 같이 const를 이용해주면 값의 저장을 제한하여 문제를 해결해줄 수 있다.
   - dogma 정하기 : 참조자를 통한 값의 변경을 유도하지 않는 경우는 const를 붙여서 함수의 원형만 보아도 변경이 일어나지 않음을 알 수 있도록 한다.

## 5.2 참조자 반환형

### 5.2.1. 반환형과 자료형, 참조자
 - 반환형이 참조형이면 반환값을 무엇으로 받느냐에 따라서 결과가 달라진다!
 - return 형은 연산 다끝나고, 밖으로 튀어나온(참조자로 인해서 원래 값과 같은 공간을 가리키던, 임시로 존재하던) 요소에게 부여된다!!(422p)

- (자료형)& &ref반환 -> &num받기 O
 - 참조자 return, 반환형이 참조자형
   - **참조자가 참조자를 받으므로**, **ref와 num이 같은 자료공간 가리키게** 된다.
   - 값 같다. 공간 같다. (num1, num2)

```cpp
int& RefRetFuncOne(int &ref){
  ++ref;
  return ref;
}

int main(void){
 
 int num1 = 1;
 int &num2 = RefRetFuncOne(num1);
 // num1 과 num2 는 완벽히 같은 공간을 가리키게 된다.
 // ref는 지역변수이므로, 후에 사라진다.
 
 return 0;
}
```
   
 - (자료형)& &ref반환 -> num받기 O
 - 참조자 return, 반환형이 참조자형
   - **참조자X가 참조자를 받으므로**, **ref와 num가 다른 자료공간 가리키게** 된다.
   - **ref가 가리키는 자료공간 속 값을 num이 가져가게** 된다.
   - 값 같다. 공간 다르다. (num1, num2)
   
```cpp
int& RefRetFuncTwo(int &ref)
  ++ref
  return ref;
}

int main(void){
  
  int num1 = 1;
  int num2 = RefRetFuncTwo(num1);
  // num1 과 num2는 다른 공간이다. 단지, num2가 RefRetFuncTwo(num1)의 값을 받았을 뿐이다.
  
  return 0;
}
```
   
 - (자료형) &ref -> num받기 O
 - 참조자 return, 반환형이 기본자료형
   - **참조자 값을 토대로 참조자X를 리턴하고, 그것을 참조자X가 받으므로 **, **ref와 num가 다른 자료공간 가리키게** 된다.
   - 값 같다. 공간 다르다 (num1, num2)
 
 ```cpp
 int RefRetFuncThree(int &ref)
   ++ref;
   return ref;
 }
 
 int main(void){
   int num1 = 1;
   int num2 = RefRetFuncThree(num1);
   // num1과 num2는 다른공간이다. num2는 함수의 return 값만 받아온다.
 }
 ```
   
 - (자료형) &ref -> &num받기 X
 - 참조자 return, 반환형이 기본자료형
   - **상수 값 같은 반환형**이 **참조자 안에 안들어감.**
   - const 참조자 선언해준다면, 값 같다. 공간 다르다. (num1, num2)
   
```cpp
int RefRetFuncFour(int &ref){
  ++ref;
  return ref;
}

int main(void){
  int num1 = 1;
  int &num2 = RefRetFuncFour(num1);
  // &num2 참조자에 상수 넣는 것과 다를게 없으므로 안됨.
  // '비const 참조에 대한 초기값은 lvalue여야 한다!' 오류발생 -> const참조자로 선언해주는게 유일한 해결책
  
  const int &num2 = RefRetFuncFour(num1);
  // 오류발생하지 않음.
```

 - (자료형)& (기본형)반환 -> X
   - 기본자료형 return, 반환형이 참조자형
   - 지역변수의 값이 보존되어, 일시적으로 임시의 공간에 return된 값을 num2가 참조하게 되지만, 그 값은 곧 소멸되는 찌꺼기 값이다.
   - return된 임시객체를 참조자 참조하여 보존하는 것과는 다른 상황이다! 이건 객체가 아니라 상수값이다.
   - NO!
   
```cpp
  int& RefRetFuncFive(int ref){
    ++ref;
    return ref;
  }
int main(void){
  int num1 = 1;
  int &num2 = RefRetFuncFive(num1);
  // ref는 지역변수이므로, 반환 후에 사라지는 공간을 참조할 수 없다.

}
  
```

## 6. const 참조자
 - 상수화된 변수, 임시변수의 값을 참조
 - 참조자를 매개변수로 사용하는 함수에 상수를 받을 수 있게끔 하기 위해 사용됨.
 - void function( const int &ref )
   - 값을 변경할 수 없고, 읽을 수만 있다. 
```  
    const int num = 10;
    const int &num2 = num;
    const int &num2 = 30;
```

## 7. malloc과 free를 대신하는 new와 delete
 - **new 와 delete**는 **runtime중 heap에 할당하는 동적 할당방식과 관련**이 있다.
 - class, 객체 생성시 문제가 발생할 수도 있으니 new와 delete를 이용하자.
 - new의 역할
   - 메모리 공간의 할당 : 자료형 한개 크기의 공간인지, [ ] 붙어서 배열처럼 자료형 여러개 크기의 공간인지 할당.
   - 생성자의 호출 : 객체생성 시에 생성자 호출. 
   - 할당하고자하는 자료형에 맞게 반환된 주소 값의 형 변환 : malloc 앞에 붙어있던 형변환인자의 역할 느낌.
   - C에서는 기본 타입과, 기본타입의 모임인 구조체가 존재했고, C++에서는 거기에 생성자와 소멸자가 추가된 class가 생겨났다.
   - 그래서 C++에서는 메모리에 객체를 생성할 때 생성자를 호출해줄 무언가가 필요했기에 new가 탄생한 것이다.
   
 - new, delete 이용법
 ```
   new 선언
 
   (자료형) *ptr = new (자료형)            // 일반 변수
   (자료형) *ptr = new (자료형)[배열크기]  // 배열일 경우
   
   delete 선언
   
   delete ptr;                             // 일반 변수 소멸
   delete []ptr;                           // 배열 소멸
```

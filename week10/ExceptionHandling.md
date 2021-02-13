# Exception Handling (예외처리)

## 1. 예외적인 상황이란   

  - 예외적인 상황이란 컴파일시 발생하는 문법적인 오류를 말하는 것이 아니라, **논리적인 오류 발생의 상황**을 말하는 것이다.
    - 예) divisor(제수)가 0인 경우, 13자리 문자열이 아닌 14자리 문자열이 입력된 경우 등..

## 2. 예외적인 상황의 해결법 - if 문을 통한 처리방법   

  - if문을 사용해서 예외적인 처리를 한다.
  - 단점
    - 프로그램의 논리적 실행흐름과, 예외처리를 위한 부분의 구분이 모호해 진다. (if문과 주석처리를 양쪽에서 같이 사용하기에)
    - 오류의 발생부분과, 프로그램의 오류발생 인지 부분의 위치가 서로 다르다.

```cpp
#include <iostream>
using namespace std;

int main(void){

  int num1, num2;
  cin >> num1 >> num2;   // 오류의 발생 부분
  
  if(num2 == 0)    // 프로그램의 오류발생 인지 부분
    cout << "divisor can't be 0" << endl;
  
  else{
    cout << "num1 / num2 = " << num1/num2 << endl;
    cout << "num1 % num2 = " << num1/num2 << endl;
  }
  
  return 0;
}
```

## 3. 예외적인 상황의 해결법 - 예외처리 메커니즘의 이용 (try, catch, throw 방식의 이용)   

  - try, catch, throw 개념적 이해
    - throw : 예외 상황이 발생하면 그 특정 예외의 상황을 던진다. (예외상황의 데이터가 전달된다.)
    - try : 예외상황을 감지하여 throw된 예외를 catch에 전달한다.
    - catch : throw된 예외를 받아들여서 처리한다. (예외처리를 위한 코드가 담겨있다.)
    - try{} 블록과, catch(예외){} 블록은 서로 붙어있어야 한다.
      - try에서 throw하는 데이터의 자료형이 catch(매개인자)에서 매개인자의 자료형과 일치해야, 데이터가 전달된다.   
      
  - 예외 발생에 따른 프로그램 흐름의 분기
    - **예외가 발생**하면, **try 블록 내의 예외 인지영역 외의 부분은 건너뛰고, catch 블록에서 예외의 처리과정을 거치게 된다.**
    - **예외가 발생하지 않으면, try부분은 그대로 실행되고, catch 블럭을 건너뛰게 된다.**   
    
  - try{} 블록으로 묶는 기준
    - 예외가 발생하는 부분 + 예외가 발생하면 실행되어서는 안되는 부분들(관련된 실행문들)을 엮어서 일(work) 단위로 구성해야 한다.
    - try내의 throw가 발생하면, try 블록 내의 나머지 부분들은 무시된다는 것을 생각하자.   
  
  - 예외 처리 메커니즘에서 더 생각해볼만한 것!
    - 같은 영역(scope)에서 예외의 처리가 일어나지 않는다면?
    - throw된 예외와 catch하는 예외의 자료형이 일치하지 않는다면?
    - throw된 예외가 여러개라면?
    - throw의 가능한 경우들(발생가능한 오류의 경우들)을 미리 설정할 수 있을까? 

```cpp
#include <iostream>
using namespace std;

int main(void){

  int num1, num2;
  cin >> num1 >> num2;   // 오류의 발생 부분
  
  try{
  
    if(num2 == 0)
      throw num2;
    
    // num2 == 0 인 상태를 만족하면 num2가 throw되면서 try 나머지 실행문들은 무시되기에 else로 묶어줄 필요가 없다.
    cout << "Quotient : " << num1 / num2 << endl;
    cout << "Remainder : " << num1 % num2 << endl;
    
  }
  
  catch(int expn){
    cout << expn << "can't be a divisor"<< endl;
    cout << "Restart the program!"<< endl;
  }
  
  return 0;
}
```

## 3.1 예외처리의 전달 (Stack Unwinding)   

  - 함수 호출과 예외 throw와의 관계
    - 함수에서 예외가 throw됬는데, 예외가 처리되지 않았다면 예외가 발생한 함수를 호출한 영역에서 예외 데이터와 예외 처리의 책임을 받는다.
    - 보통 함수를 호출한 영역의 상황에 따라 예외 처리의 방식이 달라지기 때문에, 예외 발생지점과, 예외 처리지점(scope)이 다르다.
    - 함수 내에서 예외가 발생한다면, return문의 실행 상황처럼, 함수 내 예외 뒤의 실행부분들은 무시된다.

```cpp
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int StoI(char *str){

  int len = strlen(str);
  int num = 0;
  
  for(int i=0; i<len; ++i){
  
    // 문자열 중에 0 ~ 9 사이의 문자가 아닌 것이 있다면 예외처리 해버리겠다.
    // 만약에 예외처리가 일어나면 throw 이후의 부분은 실행되지 않고 함수에서 탈출하고, StoI함수를 호출한 부분에서 예외를 처리할 것이다.
    if(str[i] < '0' || str[i] > '9')
      throw str[i];
    
    num += ( (int)pow((double)10, (double)(len - (i+1))) * (str[i] - '0') );
  }
  
  return num;
}

int main(void){
  
  char str1[100];
  char str2[100];
  
  while(1){
    
    // 문제 발생시 계속 입력받을 수 있게 만듦
    cout << "input two numbers : ";
    cin >> str1 >> str2;
    
    // 오류 발생 인지 부분
    try{
      // StoI 문제 발생시 catch로 넘어감 
      cout << str1 << " + " << str2 << " = " << StoI(str1) << StoI(str2) << endl;
      // 문제없다면 break
      break;
    }
    
    // 오류 처리 부분
    catch(char ch){
      cout << ch << "는 숫자가 아닙니다." << endl;
      cout << "다시 입력하세요." <<endl;
    }
  
  }
  
  cout << "Terminating Program" << endl;

  return 0;
}

```

  - 스택 풀기(Stack Unwinding)이라고 하는 이유가 무엇일까?
    - 함수의 호출순서의 역순으로 예외가 전달되기 때문이다.
    
```cpp

#include <iostream>
using namespace std;

void Foo3(void) {
	cout << "Foo3() called" << endl;
	throw - 1;
}

void Foo2(void) {
	cout << "Foo2() called" << endl;
	Foo3();
}

void Foo1(void) {
	cout << "Foo1() called" << endl;
	Foo2();
}

int main(void) {
  
  // 호출 순서 : Foo1 -> Foo2 -> Foo3
  // 예외 전달 수서 : Foo3 -> Foo2 -> Foo1
	try {
		Foo1();
	}
	catch (int num) {
		cout << "exceptional code : " << num << endl;
	}

	return 0;
}

```

## 3.2 throw와 catch 자료형이 일치하지 않는 경우   
  
  - 함수 내에서 일치하는 자료형이 존재하지 않는 경우는, 해당 함수를 호출한 영역으로 오류 throw의 처리 책임이 넘어간다.
  - 만약, 넘어갔음에도 처리가 되지 않았다면, 오류가 발생하고 프로그램이 멈춘다 ( abort() has been called! )

## 3.3 throw가 여러개인 경우   
  
  - throw가 여러개인 경우, 이에 부합하도록 서로다른 자료형에 대한 catch(){ } 블록 또한 여러개 생성할 수 있다.  
  
```cpp
#include <iostream>
using namespace std;


```

## 3.4 throw 예외의 명시   

  - 발생가능한 예외의 경우들을 함수 이름에 명시할 수 있다. (이 발생가능한 오류의 종류들 또한 함수의 특징으로 간주된다.)
  - 발생가능한 예외의 경우로 명시하지 않은 다른 예외가 발생한 경우, terminate 함수의 호출이 일어나고 프로그램이 종료된다.
  - 예시
    - void Foo() throw(int, char) { ... }  : int 형과, char 형의 오류가 throw될 수 있다. 이외의 오류들은 발생해서는 안된다.
    - void Foo() throw() { ... }           : 아무런 오류도 발생하지 않을 것이다. 어떠한 오류도 발생해서는 안된다.
  
  
  
  
  
  
  



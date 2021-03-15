# 함수 포인터

## 함수 포인터란?
  - **함수를 저장하는 포인터로, 함수 포인터를 주고 받거나, 함수 포인터로 함수를 호출할 수 있다.**
  - 모든 함수명은 실제로 포인터 값을 갖는다!
  - 함수를 고정된 형태가 아닌, 데이터의 형태로 이용할 수 있게 된다!
  - 껍데기 틀만 정해두고, 경우에 따라서 내가 원하는 내용물을 채워넣게 해준다!

## 함수 포인터의 생성과 호출

### 1. 함수 포인터의 생성
  - **반환형 (\*함수포인터명)( 매개변수 자료형1, 매개변수 자료형2, ,,,)**
  - 이렇게 만들어진 함수 포인터는 다음 (3가지 조건)을 만족하는 함수들을 포인터처럼 가리킬 수 있다.
    - 반환 자료형이 일치하는,
    - 매개변수의 자료형이 일치하는,
    - 매개변수의 수가 일치하는,
    
```c
void (*fp1)();
// 1. void 형을 반환하는
// 2. 매개인자를 받지 않는
// fp라는 이름을 갖는 함수 포인터가 생성된다.

int (*fp2)(int, int)
// 1. int 형을 반환하고
// 2. 매개인자로 두개의 int 형을 받는
// fp2라는 이름의 함수 포인터가 생성된다.
```

### 2. 함수 포인터의 사용 (할당, 이용)
  - **함수 포인터에 함수 할당**
    - **함수포인터명 = 타 함수명** : 함수 포인터가 다른 함수를 가리킬 수 있게, = 연산자로 할당한다.
  - **함수 포인터의 이용**
   - **함수포인터( 전달 값1, 전달 값2 , ,,, )** : 함수 포인터에 담긴 다른 함수를 이용할 수 있음.

```c
#include <stdio.h>

void print(void) {
	printf("printit\n");
}

int main(void) {

	void (*fp)();
  
  // fp 에 print 함수를 할당
	fp = print;
  
  // fp, print 모두 같은 포인터 값을 갖는다.
	printf("%p\n", print);
	printf("%p\n", fp);
  
  // fp()의 방식으로 실행하는 것 확인 가능.
	fp();
	print();

	return 0;
}
```

## 함수 포인터 활용
  - [**배열에 함수 넣을 때**](#1.-함수-포인터-배열)
  - [**구조체에 함수 넣을 때**](#2.-구조체-인자,-함수-포인터)
  - [**함수 인자로 함수 전달할 때**](#3.-함수-인자,-함수-포인터)
  - [**함수 반환값으로 함수 전달할 때**](#4.-함수-반환값,-함수-포인터)
  - [**typedef로 함수포인터 별칭 사용하기**](#5.-typedef,-함수-포인터-별칭)

### 1. 함수 포인터 배열
  - **반환형 (\*함수포인터명[함수포인터 배열 크기])( 매개변수 자료형1, 매개변수 자료형2, ,,,)**
  - 함수 포인터 배열의 각 요소들이 함수들을 가리키고 있게 할 수 있다.
  
```c
#include <stdio.h>

int multiply(int n, int m) { return n * m; }
int add(int n, int m) { return n + m; }
int subtraction(int n, int m) { return n - m; }
int division(int n, int m) { return n / m; };

int main(void) {
	
  // 함수 포인터 배열의 선언
	int (*fp[4])(int, int);
	
  // 함수 포인터 배열요소들이 함수 가리키도록 설정
  fp[0] = multiply; fp[1] = add; fp[2] = subtraction; fp[3] = division;

	int num, num2, num1;
	scanf_s("%d %d %d", &num, &num1, &num2);
	printf("%d \n", fp[num](num1, num2));

	return 0;
}
```

### 2. 구조체 인자, 함수 포인터
  - 함수 포인터 또한, 포인터 자료형이므로, 구조체에 넣을 수 있다.

```c
// 구조체 인자로 함수 포인터 받기 (결국 구조체에 포인터 인자를 받게 하는 것)
struct 구조체명{
  반환형 (\*함수포인터명)( 매개변수 자료형1, 매개변수 자료형2, ,,,)
}

#include <stdio.h>

int multiply(int n, int m) { return n * m; }

typedef struct Struct {
	int (*fp)(int, int);
}S;

int main(void) {
	
	S s;
	s.fp = multiply;

	printf("%d", s.fp(10, 20));
	
	return 0;
}
```

### 3. 함수 인자, 함수 포인터
  - 함수 포인터의 선언을, 함수 매개변수 선언부분에서 해준다.

```c
#include <stdio.h>

int multiply(int n, int m) { return n * m; }
int add(int n, int m) { return n + m; }
int subtraction(int n, int m) { return n - m; }
int division(int n, int m) { return n / m; };

// 함수 매개변수 선언 부에서 함수 포인터를 넣어준다.
int exeFunc(int (*fp)(int, int), int n, int m) {
	return fp(n, m);
}

int main(void) {
	
	printf("%d \n", exeFunc(multiply, 10, 20));
	
	return 0;
}
```

### 4. 함수 반환, 함수 포인터
  - 함수를 데이터처럼 반환하고자 사용한다. 함수를 반환하는 것이기에,,
    - 기존 함수가 받아야할 매개변수가 있어야 하고,
    - 기존 함수가 반환하는 함수가 받아야할 매개변수가 있어야 하고,
    - 기존 함수가 반환하는 함수가 반환하는 자료형이 곧 반환형일 것이다.
  - **반환함수의반환형 (\*기존함수명(in매개변수 자료형1 변수 , ,,,))( out매개변수 자료형1, ,,,)**
    - **반환형** : 반환하는 함수가 반환하는 자료형.
    - **in매개변수** : 기존함수가 이용할 수 있는 자료형
    - **out매개변수** : 기존함수가 반환하는 함수가 이용할 수 있는 자료형
  - **왜 int (\*fp)(int, int) getAdd() 처럼 작성하지 않는 것인가??!**
    - 반환형에 이름이 붙어버리기 때문이다.. 

```c
#include <stdio.h>

double add(double n, double m) { return n + m; }

// 반환형이 함수인 함수의 선언
double (*fp(int x, int y))(double, double) {
	printf("%d %d \n", x, y);
	return add;
}

int main(void) {
  
  // 반환형이 함수인 함수의 이용
	printf("%f \n", fp(2, 3)(3.6, 5.6));

	return 0;
}
```

### 5. typedef, 함수 포인터 별칭
  - 함수 포인터의 생성과 맞물리는 내용이다.
  - typedef를 이용하여, 함수 포인터를 여러개 찍어낼 수 있다.
    - **1) 함수포인터 배열을 쉽게 만들 수 있다**
    - **2) 구조체 인자로 쉽게 사용할 수 있다**
    - **3) 함수 인자로 받을 때도 쉽게 사용할 수 있다.**
    - **4) 특정 함수를 반환하는 함수를 정의할때 쉽게 사용할 수 있다.(매개인자 전달은 어려움)**
  - **typedef 반환형 (\*함수포인터명)( 매개변수 자료형1, 매개변수 자료형2, ,,,)**
    - 함수포인터명은 자료형이 된다.
    - 그 함수포인터명을 바탕으로 만들어진 것들이 변수가 된다.

```c
#include <stdio.h>

// FP는 자료형이 되고, FP를 바탕으로 찍어낸 것들이 변수가 된다.
typedef double (*FP)(double, double);

double add(double n, double m) { return n + m; }
double division(double n, double m) { return  n / m; }
double multiply(double n, double m) { return n * m; }

// 4) 함수 반환 표현의 과정이 수월해진다.
FP GetAdd1(int n, int m) {
	printf("%d + %d = %d\n", n, m, n + m);
	return add; 
}
FP GetAdd2() {
	return add;
}

// 3) 함수 인자로 함수를 받는 과정이 수월해진다.
double Multiply(FP funcP, double n, double m) {
	printf("double multiply(FP, double n, double m) called !\n");
	return funcP(n, m);
}

// 2) 구조체에서의 함수 포인터의 사용이 수월해진다.
typedef struct Foo{
  
  // FP 자료형 바탕으로 funcP 만들어짐
	FP funcP;
  
}Foo;

int main(void) {

	// 1) 함수 포인터 배열의 선언이 수월해 진다.
	FP funcP[3] = { add, multiply, division };

	printf("FP getAdd1(int n, int m) called : %.2f +%.2f = %.2f\n", 4.5, 6.7, GetAdd1(2, 3)(4.5, 6.7));
	printf("FP getAdd2() called : %.2f + %.2f = %.2f\n", 4.5, 6.7, GetAdd2()(4.5, 6.7));

	printf("%f\n", Multiply(funcP[1], 3.56, 5.78));

	Foo foo1;
	foo1.funcP = funcP[2];
	printf("%f\n", foo1.funcP(2.45, 1.784));

	return 0;
}
```



# 열거형 enum

## 열거형이란?
 - 열거형은 사용자 정의 자료형이다!
 
## 용어 
- 열거형이름
- 열거자
- enum
- 열거형변수
- 열거자 지정 정수

## 정의 
- **enum 열거형이름**(지정하지 않을 수도 있음){ , **열거자** , }
```cpp
enum Color{ GREEN, WHITE, BLACK, YELLOW };
```

## 변수 할당
- **열거형이름** **열거형변수** = **열거자** , **열거형이름** **열거형변수**(**열거자**) : 메모리 공간이 할당됨.
```cpp
Color whatColor = GREEN;
Color whatColor(GREEN);
```
## 출력
- 열거형 변수를 출력하면, 열거자에 지정된 특정 정수 값을 출력한다. 
```cpp
cout << whatColor // 0 출력
```
## 입력
- **열거형이름 열거형변수** = static_cast<**열거형이름**>(**열거자 지정 정수**)
```cpp
int num
cin>> num;
Color nextColor = static_cast<Color>(num);
```
## 함수 전달
- function( **enum 열거형 이름 매개인자 이름**)
```cpp
int foo(enum Color value){
     return value;
}
```
## 사용시기
- 관련된 상태집합 표현, 코드 가독성 증대 요구시 등등..

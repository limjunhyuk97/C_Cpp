## 1. 정보은닉
- 정보은닉은 class에서 private한 멤버변수들에 접근하기 위해 거쳐야 하는 멤버함수를 선언하여, **부정확한 값의 전달을 막고 안전한 접근을 유도**하는 것이다.

## 2 const 함수 / const 참조자 매개변수
- const 함수
```cpp
int Point::GetX() const{
  return x;
}
void Rectangle::ShowInfo() const{
  cout<< ....
}
```
  - **const 함수**는, 함수 내에서 **멤버변수의 값의 변경(저장)을 허용하지 않는 함수**다.
  - **const 함수 내**에서, **const 함수가 아닌 함수(값의 변경을 잠재적으로 허용하는 함수)는 호출될 수 없다.**
```cpp
int GetNum(){
  return num;
}

void ShowNum() const{
  cout<<GetNum()<<endl; // 오류 발생 - GetNum()이 const 함수가 아니다.
}
```
  - **const 참조자를 매개변수로 사용하는 함수**는, **const 함수만 인자로** 받을 수 있다.
```cpp
int GetNum(){
  return num;
}

void InitNum(const Easyclass &easy){
  num = easy.GetNum();  // 오류 발생 - GetNum()이 const 함수가 아니다.
}
```

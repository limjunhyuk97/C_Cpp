# 복사 생성자

## 1. 복사생성자
 - 객체의 복사를 돕는 생성자.
 - 같은 class 틀을 공유한다면 객체를 복사해서 다른 객체에 그대로 찍어넣을 수 있다.
```cpp
soSimple sim1 = sim2;
soSimple sim2(sim2);
```

## 2. 생성자 관점에서의 복사 생성자
 - 복사 생성자를 굳이 추가하지 않더라도, 디폴트 복사 생성자가 자동으로 삽입된다.
 
## 3. 복사 생성자의 배제
 - 복사 생성자를 배제하려면 explicit을 사용하면 된다.
```cpp
SoSimple {
  explicit SoSimple(SoSimple &copy)
     : num1(copy.num1) , num2(copy.num2) {} 
};
```

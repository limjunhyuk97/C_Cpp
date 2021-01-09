# 연산자 오버로딩

## 01. 연산자 오버로딩
  - operator('연산자') 함수.
    - **('operator')와 (연산자)를 묶어서 함수의 이름으로 정하면, 연산자만으로의 함수호출을 허용한다.**
      - operator+ , operator-, operator+=, operator-= 등등의 함수들이 해당된다.
    - **class가 연산(: '+' '-' '<<' '>>' ...)에 대해서 오버로딩되었다** 라고 보통 이야기한다.
      - 객체도 기본자료형들처럼 연산가능하게 만들자 : 객체의 자료형이 일반자료형을 오버로딩하는 것이기에 저렇게 이야기하는 것이다.
    - **함수가 연산자를 오버로딩했다**고도 이야기한다.
      - 연산자의 내용이 'operator연산자' 함수에 의해서 오버로딩된 것이기 때문이다.
    - **결과적으로! 피연산자를 따라 연산의 방식이 달라지는 것이, 매개변수를 따라 호출되는 함수가 달라지는 것과 같기 때문에 연산자 오버로딩.**
    - 연산자 오버로딩의 과정 (operator+ 로 예를 들자면..)
      1. "class객체 + class객체"의 코드를 컴파일러가 확인
      2. **멤버함수에 의한 연산자 오버로딩인지, 전역함수에 의한 연산자 오버로딩인지 판단** (동시에 선언됬다면 멤버함수 연산자 오버로딩 우선)
      - 멤버함수 연산자 오버로딩에서는 매개인자 한개, 전역함수 연산자 오버로딩에서는 매개인자 두개 필요하다.
      - 왠만하면 멤버함수를 통해서 연산자 오버로딩하는 것이 좋다. (객체지향에는 전역이라는 개념이 없기 때문이다.)
      - **멤버함수 선언이나, 전역함수의 friend 선언이 class내에 속해 있을때, 그 class의 객체 관련 연산자 오버로딩이 가능해지는 것이다!**
    - 이점
      - x, y 등의 멤버변수가 존재하는 좌표와 관련된 연산을 보다 직관적으로 수행할 수 있도록 설계가능할 것 같다. (연산을 직관적으로 수행가능!)
```cpp
// 멤버함수에 의한 연산자 오버로딩 예시 - 1
class AAA{
private:
  int x;
public:
  AAA(int x = 0) : x(x) {}
  // const 함수로 선언하는 것이 좋고, 해도 상관없다. 새로운 값의 생성만 있기 때문이다.
  // class 내부에서는 private 멤버변수에 접근가능합니다~ (다음 예에서는 ref.x로의 접근..!)
  AAA opreator+(const AAA &ref) const {
    AAA ans( x + ref.x );
    return ans;
  }
}

int main(void){
  AAA Aobj1(2), Aobj2(3); 
  
  AAA Aobj3 = Aobj1.operator+(Aobj2);
  AAA Aobj3 = Aobj1 + Aobj2;
  // 두가지 의미는 같다!
  
  return 0;
}


// 전역함수에 의한 연산자 오버로딩 예시 - 2
class AAA{
private:
  int x;
public:
  AAA(int x) : x(x) {}
  friend AAA operator+(const AAA &ref1, const AAA &ref2);
  // 전역에 있는 함수정의가 AAA class에서 friend선언을 통해서 private영역에 접근할수 있도록된 것
  // 곧, "이 class의 객체들은 + 연산을 서로 할 수 있게되었다!" 의 의미
}

AAA operator+(const AAA &ref1, const AAA &ref2){
  AAA ans(ref1.x + ref2.x);
  return ans;
}
// const 함수는 멤버함수에서만 쓸 수 있는 것 상기하고 넘어가자!
// 이런 연산자를 오버로딩할겁니다.. 하고 전역에서 정의하는 느낌

int main(void){
  AAA Aobj1(2), Aobj2(3);
  AAA newAobj = Aobj1 + Aobj2;
  AAA newAobj = +operator(Aobj1, Aobj2);
  // 두가지 의미는 같다!
  
  return 0;
}
```
## 02. 연산자 오버로딩 사용법
  - 오버로딩이 불가능한 연산자 (그때 그때 찾아봐라)
  - 멤버함수 기반의 오버로딩만 가능한 연산자
    - =대입연산자, ()함수호출연산자, []배열접근연산자, ->멤버접근위한포인터연산자
  - **연산자 오버로딩시 주의사함**
    1. 본래 연사자의 의도를 벗어나서는 안된다. (+연산자의 순수기능을 빼앗을 수는 없다.)
    2. 연산자의 우선순위와 결합성을 바뀌지 않는다.
    3. 매개변수 디폴트값 설정 불가능하다.
  - **operator연산자 생성시 유념할 것!**
    - 1. **함수위치 고려(멤버, 전역) + 매개인자 고려(const, const X)** 
    - 2. **전위연산이냐, 후위연산이냐 고려** 
    - 3. **반환형 고려, 실제 반환인자 고려** 
    

## 03. 단항연산자 오버로딩
  - **멤버함수로 인한 오버로딩**
    - 매개변수가 필요가 없다. (단항 연산자이므로..)
    - **참조자형식을 반환해야지 다중 단항연산자 오버로딩이 가능하다!**
```cpp
class AAA{
private:
  int x;
public:
  AAA & operator++(){
    x++;
    return *this;
  }
};

int main(void){
  AAA p1(2);
  ++p1;
  ++(++p1);
  // 반환형이 참조자가 아니라면 ++p1의 연산결과를 받아서 한번 더 ++한 연산내용이 p1에 반영될 수 없다. 
}
```
  - **전역함수로 인한 오버로딩**
    - 매개변수가 하나 필요하다.(마찬가지의 이유로..)
    - 마찬가지의 이유로 참조자형식을 반환해야 함.
```cpp
class AAA{
private:
  int x;
public:
  friend AAA& operator--(AAA &ref);
};

AAA& operator--(AAA &ref){
  ref.x--;
  return ref;
  // ref 내의 값을 바꿔주고, ref를 반환해준다.
};

int main(void){
  AAA Aobj(3);
  --Aobj;
  --(--Aboj);
}
```

  - **전위연산자와 후위연산자와의 구분**
    - 매개인자로 받는 영역에 int 키워드가 추가되었는지, 아닌지의 여부를 통해서 구분한다.
    - int 인자 추가 X : 전위연산
    - int 인자 추가 O : 후위연산
```cpp
class AAA{
private:
  int x;
public:
  AAA(int x = 0) : x(x) {}
  
  // ++전위연산, 멤버함수
  AAA& operator++(){
    x += 1;
    return *this;
  }
  
  // 후위연산++, 멤버함수
  const AAA operator++(int){
    const AAA retobj(*this);
    x+=1;
    return retobj;
  }
  
  // --전위연산, 전역함수
  friend AAA& operator--(AAA &ref);
  
  // 후위연산--, 전역함수
  friend const AAA operator--(AAA &ref, int)
  
};  

AAA &operator--(AAA &ref){
  ref.x -= 1;
  return ref;
}

// const는 반환된 임시객체를 const 객체로 만든다. (객체 내부 멤버 변경 불가능)
// 그러므로 객체의 후위연산을 연속으로 두번 호출할 수 없다! : const 함수가 아니기 때문에..
const AAA operator--(AAA &ref, int){
  const AAA retobj(ref);
  ref.x -= 1;
  return retobj;
}

int main(void){
  
  AAA obj1(3);
  AAA obj2;
  
  obj2 = obj1--;
  // obj2에 들어가는 값은 연산 전의 값. obj1에 들어가는 값은 --연산 후의 값. (prefix unary operation 구현)
  
  return 0;
}

```
    
    
    


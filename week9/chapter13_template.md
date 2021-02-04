# Template - 템플릿

## 1.  템플릿이란?
  - 함수나 클래스가 별도의 선언 없이 다른 자료형에서 동작할 수 있게 해주는 역할을 한다.
  - **함수 템플릿 : 템플릿 함수 - 생성된 함수**
  - **클래스 템플릿 : 템플릿 클래스 - 생성된 클래스**

## 2. 함수 템플릿
  - **기능은 같지만, 다른 자료형에 대해서 해당 자료형에서의 연산기능을 수행하는 함수를 구현할 수 있다.*
  - 컴파일 과정에서 한번 만들어진 함수 템플릿은 계속 이용된다.
    - 그렇게 만들어진 함수를 **템플릿 함수**라고 한다.
  - template 정의는 함수마다 해줘야한다.
  - 자료형 정하기
    - 사용자가 정하기
    - 컴파일러가 알아서 판단
    - 2개의 템플릿 자료형.
```cpp
template <typename T>
T Add(T num1, T num2){
  return num1 + num2;
}

Add<int>(3, 5);
Add<double>(2.3, 4.6);
// 사용자가 정의 : 컴파일때 생성된 템플릿 함수는 이후에도 계속사용됨.

Add(3, 5);
// 컴파일러가 정의 : 컴파일러가 주어진 인수를 보고 판단함.

Add(3, 4.5);
// 컴파일 오류 발생. (typename T를 무엇으로 정의할 지 모름)
// 해결하려면.. : 2개의 템플릿 자료형 사용, 컴파일러가 알아먹을 수 있게 해줘야 함. or 1개의 템플릿 자료형 사용, 사용자가 템플릿 자료형 정의

template <typename T1, typename T2>
int Template(T1 num1, T2 num2){
  return num1 + num2;
}

Add(3, 4.2);
```

## 3. 함수 템플릿의 특수화 (Specialization)
  - "어떤 템플릿에서 내가 임의로 정한 이런 자료형을 인자로 받을 때에는, 다음의 함수를 우선 호출해주세요!" 하는 의미를 지닌다.
  
```cpp
template <typename T>
T compare(T var1, T var2){
  return var1 > var2 ? var1 : var2;
}

// const char *형을 받을 때에는 다음의 함수를 통해서 함수연산을 진행해 달라!
template<>
const char * compare(const char* var1, const char* var2){
  return strlen(var1) > strlen(var2) ? strlen(var1) : strlen(var2);
}

// 다음의 경우가 const char* 자료형을 인자로 받는 템플릿함수 호출의 경우이다. : 함수 템플릿의 특수화가 적용된다.
cout << compare("me", "you") << endl;

```
  
## 4. 클래스 템플릿
  - 함수 템플릿을 만들때와 마찬가지로, 클래스 내부의 자료형들을 고정적으로 정의하지 않기 위해서 template <typename T> 정의를 이용한다.
  - **템플릿 클래스**
    - **템플릿 함수와는 다르게 생성 시에 <자료형>의 자료형 정보를 반드시 명시해줘야 함.**
  
 ```cpp 
 
// 자료형을 결정짓지 않겠다는 의미의 문자 T
// T라는 이름을 이용해서 아래의 class를 템플릿으로 정의한다는 의미의 template <typename T>

template <typename T> 
class Point{
private:
  T xpos, ypos;
public:
  Point(T x, T y) : xpos(x), ypos(y) {}
};

int main(void){
  
  // 템플릿 클래스 생성 시에 자료형 명시해줘야 함.
  Point<int> pt1(2, 3);
  Point<char> pt2('A', 'B');
  
  // 마치, STL의 vector 컨테이너의 초기화 시 선언방법과 유사하다!!
  vector<int> arr(5);
  
  return 0;
}
 ```

## 5. 클래스 템플릿과 파일분할
  - 파일분할
    - .h 는 선언부 : 각종 선언 + stl을 선언해 준다.
    - .cpp는 구현부(정의부) : 각종 선언에 대한 정의를 구현한다.
  - **클래스 템플릿의 파일분할**
    - 클래스 템플릿으로 **템플릿 클래스를 main에서 만들어 사용할 때에, template에 관한 모든 정보가 필요**하다.
    - .h 헤더파일의 선언만으로 클래스 템플릿의 모든 내용을 알 수 없다.
    - 그러므로, **.h 에 정의까지 구겨넣거나**, **.cpp 정의부 파일을 main에 같이 include해줘야** 한다.
 
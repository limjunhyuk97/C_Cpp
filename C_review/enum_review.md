# Enum

  - 열거 상수
  - 표준 정수형 기반의, 사용자 정의 type
    - 정수형을 기반으로 특정 상수명을 정수의 값과 엮어버린다.

## 1. 열거형 타입의 정의(+2)

  - 열거형 타입의 정의는 다양한 위치에서 가능하다. (struct 안에서도, main에서도, 전역에서도, ,,,)

### 1. **enum typeName {identifier list};**
  - **typedef 사용하지 않는 방식**
 
```c
// 전역에서 enum 선언
enum typeName {identifier list};

enum month {Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec}
// Jan = 1, Feb = 2, Mar = 3, Apr = 4, ,,,
// 상수명과 정수의 값을 엮어 버리는 것.

enum color {
  Red, Rose = 0, CRIMSON = 0,
  Blue, Aqua = 1, Navy = 1,
  Green, Jade = 2,
  White
}

// struct 내에서 enum 정의
typedef struct Person{
  enum sex{ female, male } gender;
  char name[20];
  int age;
}Person;

// 함수 내에서의 enum 정의
int main(void){
   enum flag {up, down};
}
```

### 2. typedef enum typeName{identified list} aliasName;**
  - **typedef 사용하는 방식**

```c
typedef enum color{RED, GREEN, BLUE} Color;
```

## 2. 열거형 타입 변수의 선언(+2)

### 1. **typedef 사용하지 않는 방식**
  - **enum typeName {identifier list} variableName;**  
  - "struct 구조체이름 구조체변수;" 같은 느낌

```c
typedef struct Person{
  enum sex{ female, male } gender;
  char name[20];
  int age;
}Person;

Person p1 = {female, "Lucy", 22};
p1.gender = male;
```

### 2. **typedef 사용하는 방식**
  - **typedef enum typeName {identifier list} aliasName;**
  - **aliasName variableName;**
  - "typedef struct 구조체이름{ ... }구조체별칭;" 같은 느낌

```c
typedef enum floor {_1th, _2nd, _3rd} Floor;
Floor f1 = _1th;
```

## 3. 열거형 타입과 int형 타입

  - **enum 사용자정의_열거type_명 사용자정의_열거type_변수 = 사용자정의_열거type_상수**

```c
enum color CT1 = Red;
```

  - **int형 = 사용자정의_열거type_상수 or 사용자정의_열거type_변수**
    - int 형에 enum 열거형 타입 변수 및 상수를 넣을 수 있다.

```c
int CT2 = CT1;
// CT2 에 CT1이 갖는 정수 값을 건네준다.

int CT3 = Green
// 마찬가지.
```

  - **사용자정의_열거type_변수 = (enum 사용자정의_열거type_명) int형**
    - enum 열거형 타입 변수에 int형 타입을 형변환 후에 넣을 수 있다.
 
```c
enum color CT4 = (enum color)1;
// CT4가 정수1의 값을 color형_열거type_변수가 된다.
// CT4 == Blue, CT4 == Aqua, CT4 == Navy

```

  - **출력시에 %d의 정수형 형식 지정자를 사용하여 출력, 해당 사용자정의_열거type_상수 와 엮여있는 정수 값이 출력.**
    - 열거형 상수를 출력하면, 열거형 상수의 정수 값이 출력된다.

```c
printf("%d", White);
// 3 출력
```

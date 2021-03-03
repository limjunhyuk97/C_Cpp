# Struct

## 1. struct
  - 연관된 멤버로 구성되는 통합 자료형으로 대표적인 유도 자료형(구조체, 공용체, 열거형)이다.
  - 연관된 데이터의 묶음. (여러 데이터를 묶음으로 나타낸 것.)

## 2. struct 정의 (+2)
  
  - **방식 1 : typedef struct ... name**
    - typedef 사용방식 
    - 별칭 부여 방식
    - 나중에 구조체 사용 시에 struct 명시가 따로 필요없음.
    - 구조체 정의 안에서 해당 구조체를 다시 사용할 때에는 struct 명시가 필요함.

```c

  typedef struct Name{
    int ...;
    char ...;
    struct Name ...;
  } name;
  
  name name1;
  
```

  - **방식 2 : struct name**
    - 태그 사용방식
    - 나중에 구조체 사용 시에 struct 명시가 따로 필요함.
    - 구조체 정의 안에서 해당 구조체를 다시 사용할 때에는 struct 명시가 필요함.

```c

  struct TAGNAME{
    int ...;
    char ...;
    struct Name ...;
  };
  
  struct name name1;
  
```
  - typedef는 자료형에 새로운 별칭을 부여할 때 이용하는 방식이다!
		
		
## 3. struct 선언 (+2)
		
  - **방식 1 : struct name type1**
    - 태그 사용 방식으로 struct를 정의했을 시에 사용
    - struct 정의 내부에서 자기 struct를 다시 사용하는 경우 ( ex. 연결리스트 구현시에) 
 
```c

struct name type1;
type1.name = "...";
type1.age = ...;

```

  - **방식 2 : name type1**
    - typedef 사용 방식으로 struct 정의했을 시에 사용
```c

name type1;
type1.name = "...";
type1.age = ...;

```

## 4. struct 초기화 및 값 할당
  
  - struct 선언과 동시에 값을 넣어줄 수는 없다.
  - **선언과 동시에 초기화 시**
    - 인자들이 왼쪽에서 오른쪽으로 순서대로 들어가게 된다.
    - 충분한 value가 전달되지 못했다면 전달받지 못한 인자들은 0으로 초기화 된다.
  - **선언 이후에 값을 할당 시**
    - struct 요소 접근 방식을 이용해서 요소 마다 값을 할당함.
    - 선언 이후에는 중괄호를 통해서 값 할당하는 것 불가능 하다.
	
```c

  typedef struct{
    int x; // int x = 3; 처럼 x에 3이라는 값을 넣을 수는 없다.
    int y;
    float t;
    char u;
  } sample;


// 구조체 초기화
sample sam1 = { 2, 3, 2.5, 'Q'};
// x = 2, y = 3, t = 2.5, u = 'Q'
		
sample sam2 = {2, 3 };
// x = 2, y = 3, t = 0.0, u = '\0'(NULL)

sample sam3;
sam3 = {2, 3 };
// 불가능하다. 선언과 동시에 초기화 시에만 중괄호를 통한 값 할당이 가능하다.


// 구조체 값 할당
sample sam3;
sam3.x = 2;
sam3.y = 5;

```

## 5. struct 요소 접근 (+3)
  
  - **struct 이름을 통한 접근**
    - structName.element (Direct Selection)
  - **struct 포인터 통한 접근**
    - ptr -> element     (Indirect Selection)
    - (\*ptr).element    (Indirection)
	
```c
			
  struct person p1;
  person *ptr = &p1;
  
  // (*ptr).과, *ptr.을 구분해야 한다.
  
  // ptr 포인터가 가리키는 struct 속의 element.
  (*ptr).element  ==  ptr ->element  ===  p1.element
  
  // ptr이라는 "struct 변수" 속의 element.
  *ptr.element == *(ptr.element)
  
```

## 6. struct 연산

  - **= 연산**
    - struct 변수 요소들의 값을, 다른 struct 변수 요소들의 값에 할당할 수 있다.
  - **요소 접근**
    - 이름 통한 접근, 포인터 통한 접근

```c
  struct person{
    char name[20];
    int age;
  };
  
  struct person p1 = { "Lim", 20 }, p2 = { "Tom" , 22};
  p1 = p2;
  //
  
```

## 7. struct 내부 struct (Complex Structure)

## 8. struct 배열 사용 방식

	- struct grading student[10];
	
	- 위의 예를 들자면 grading이라는 틀을 가진 struct를 student라는 이름을 붙여서 10개를 찍어내는 것이다
	
	- student[0], student[1], ,,, 식으로 grading struct를 통해서 여러개를 찍어내는 것이다. 

7. struct 요소 안에 문자열 넣기

	- strcpy를 적극적으로 이용해보자. 
	
	- scanf를 통해서도 문자열 넣을 수 있다. 

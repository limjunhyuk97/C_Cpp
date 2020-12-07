/////////////////////////////////////////// struct /////////////////////////////////////////// 

1. struct

	- 서로 다른 type의 원소들을 같은 공간에 묶어서 관리할 수 있게 해주는 녀석
	
	
2. struct 정의 방식 (+2)

	- 방식 1 : typedef struct ... name	// typedef 사용방식
	
		typedef struct{
			int ...
			char ...
		} name;

	- 방식 2 : struct name				// 태그 사용방식 

		struct name{
			int ...
			char ...	
		};
		
		
3. struct 선언 방식 (+2)
		
	- 방식 1 : struct name type1		// struct 정의 이후에 선언 
	
	```
		struct name type1;
		type1.name = "...";
		type1.age = ...;
	```

	- 방식 2 : name type1				// struct 정의 이후에 선언 
	
	```
		name type1;
		type1.name = "...";
		type1.age = ...;
	```


4.	struct 인자 초기화 

	- 인자들이 왼쪽에서 오른쪽으로 순서대로 들어가게 된다.
	
	- 충분한 value가 전달되지 못했다면 전달받지 못한 인자들은 0으로 초기화 된다.
	
	```
		typedef struct{
			int x;
			int y;
			float t;
			char u;
		} sample;
		
		sample sam1 = { 2, 3, 2.5, 'Q'};		// x = 2, y = 3, t = 2.5, u = 'Q'
		
		sample sam2 = {2, 3 };					// x = 2, y = 3, t = 0.0, u = '\0'(NULL)	
	```

5. struct 요소 접근 방식 (+3)

	- structName.element			// Direct Selection
	 
	- 포인터를 이용하는 방식
	
	```
		- ptr -> element 			// Indirection
			
		- (*ptr).element			// Indirect Selection
			
			struct person p1;
			person *ptr = &p1;
			
			(*ptr).element  ===  ptr ->element  ===  p1.element
	```		
			
6. struct 배열 사용 방식

	- struct grading student[10];
	
	- 위의 예를 들자면 grading이라는 틀을 가진 struct를 student라는 이름을 붙여서 10개를 찍어내는 것이다
	
	- student[0], student[1], ,,, 식으로 grading struct를 통해서 여러개를 찍어내는 것이다. 

7. struct 요소 안에 문자열 넣기

	- strcpy를 적극적으로 이용해보자. 
	
	- scanf를 통해서도 문자열 넣을 수 있다. 

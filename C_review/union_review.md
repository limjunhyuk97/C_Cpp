# 공용체 (Union)

## union 이란?
  - 메모리상에서, 서로 다른 데이터 형식을 공유할 수 있도록 한 개념이다.
  - struct 대신, union 예약어를 사용한다.

```c

union shareData{
  char chAry[2];
  short num;
};
// num의 2byte 메모리 공간이, chAry[0] + chAry[1]의 2byte 메모리 공간과 공유된다.

```

## union의 사용
  - 기본적인 사용방법은 struct와 같으나, 데이터 저장시 메모리 사용에서 차이가 발생하는 것이다.

## union을 왜 사용하는가?
  - 메모리 공간을 아끼려고 사용한다. (효율적으로 활용하기 위해서!)
    - 어떤경우 필요하고, 어떤 경우 필요하지 않는 메모리 공간 같은 경우, 메모리 공간을 공유하도록 하는 것이다.

```c

#include <stdio.h>
#include <string.h>

typedef struct {
	char first[20];
	char init;
	char last[30];
} PERSON;

typedef struct {
	char type;
	union {
		char company[40];
		PERSON person;
	}un;
}NAME;

int main(void) {

	NAME business = { 'C', "ABC Company" };
	NAME friend;
	NAME names[2];

	friend.type = 'P';
	strcpy_s(friend.un.person.first, 20, "Martha");
	strcpy_s(friend.un.person.last, 30, "Washington");
	friend.un.person.init = 'C';

	names[0] = business;
	names[1] = friend;

	for (int i = 0; i < 2; ++i) {
		switch (names[i].type)
		{
		case 'C':
			printf("Company : %s\n",names[i].un.company);
			break;
		case 'P':
			printf("Friend : %s %c %s\n"
			, names[i].un.person.first
			, names[i].un.person.init
			, names[i].un.person.last);
			break;
		default:
			break;
		}
	}

	return 0;
}

```

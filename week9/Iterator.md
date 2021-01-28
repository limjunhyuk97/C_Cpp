# iterator

## iterator란?
  - **STL안의 데이터의 주소**를 가리키는 **일종의 포인터.**
  - 각 클래스 안에 중첩 클래스의 형태로 선언된 또다른 클래스이다.
  - ++, -- 연산이 가능하다.
  
```cpp
vector<int>::iterator iter;
// 선언방식을 본다면 vector <int> 내의 iterator 네임스페이스를 호출하는 범위한정자를 사용하는 것을 볼 수 있다.
```

# iterator - vector
  
## begin()
  - iterator에 데이터가 있는 리스트의 시작주소를 부여하는 역할을 한다.
  
## end()
  - iterator에 데이터가 있는 리스트의 끝주소를 부여하는 역할을 한다.
  - **값 자체는 마지막 값보다 한 칸 뒤 위치의 주소값을 리턴한다.**
  
## insert()
  - insert(특정위치, 넣을 값)
  - iterator를 사용하여 특정위치에 접근한다.
  - 특정위치의 값을 넣을 값으로 대체하고, 특정위치에 있던 값 + 뒤 주소에 있던 값들을 하나씩 뒤로 민다.

## erase()
  - erase(특정위치)
  - iterator를 사용하여 특정위치에 접근한다.
  - 특정위치의 값을 제거하고, 특정위치 뒤 주소에 있던 값들을 한칸씩 앞으로 당긴다.
  
```cpp

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

bool compareDesc(int a, int b) {
	return a > b;
}

bool compareAsc(int a, int b) {
	return a < b;
}

int main(void) {

	vector <int>arr;
	srand((unsigned int)time(NULL));
	
	// arr에 10개짜리 공간 형성
	for (int i = 0; i < 10; ++i) {
		arr.push_back(rand() % 10 + 1);
	}

	// auto로 각 항목들에 접근하기
	cout << "arr에 들어있는 원소 갯수 : " << arr.size() << endl;
	for (const auto& it : arr) {
		cout << it << " ";
	}
	cout << endl << endl;

	// 원하는 인덱스 위치의 항목 제거
	int idx;
	vector<int>::iterator iter;
	cout << "몇번째 인덱스 제거? : ";
	cin >> idx;
	arr.erase(arr.begin() + idx);
	cout << "arr에 들어있는 원소 갯수 : " << arr.size() << endl;
	for (iter = arr.begin(); iter != arr.end(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl << endl;

	// iterator로 항목들 접근하여 값 변경
	for (iter = arr.begin(); iter != arr.end(); ++iter) {
		*iter *= 2;
	}
	for (iter = arr.begin(); iter != arr.end(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl << endl;

	// 3개 항목 추가
	for (int i = 0; i < 3; ++i) {
		arr.insert(arr.begin() + rand() % 10, rand() % 10 + 1);
	}
	for (iter = arr.begin(); iter != arr.end(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl << endl;

	// auto와 sort 정리
	// compareAsc(int a, int b) {return a < b;} 함수 대입 시 오름차순
	auto crit = compareAsc;
	sort(arr.begin(), arr.end(), crit);
	for (iter = arr.begin(); iter != arr.end(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl << endl;

	// compareDesc(int a, int b) {return a > b;} 함수 대입 시 내림차순
	crit = compareDesc;
	sort(arr.begin(), arr.end(), crit);
	for (iter = arr.begin(); iter != arr.end(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl << endl;

	// vector container를 sort할 때에는 .begin() .end() 를 사용해야 한다.
	// 그냥 배열을 sort할 때에는 arr, arr+배열길이 를 사용해야 한다.

	return 0;
}

```

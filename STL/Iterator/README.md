# Iterator

## 01. Iterator의 쓰임
  - 사용하는 **라이브러리의 방식대로 자료구조에 접근**할 수 있다. (라이브러리가 효과적으로 동작하는 것을 담보한다.)
  - **컨테이너에 존재하는 원소들을 참조할 때 사용**하는, 포인터와 비슷한 객체이다.
  - 알고리즘마다 다른 방식으로 컨테이너를 훑어가기에, 반복자에 여러 종류가 존재한다.

## 02. Iterator의 성질
 - 요소의 값 확인
 - 컨테이너가 효과적으로 처리할 수 있는 방식으로 연산 한정
 - 요소 간에 이동할 수 있는 연산 제공

## 03. Iterator의 구간
  - 한쌍의 반복자로 값의 구간을 설정할 수 있으며, 두 반복자는 한 컨테이너에서 생성된 것이어야 한다. (begin(), end())
  - 설정된 범위내의 값들이 물리적으로 연속적일 필요는 없다. 

## 04. begin() , end() 함수
  - begin() 함수 : 컨테이너의 첫번째 원소를 가리킨다
  - **end() 함수 : 컨테이너의 맨마지막 원소의 다음원소를 가리킨다. (past-the-end 반복자)**

## 05. Iterator의 종류
  - 입력 반복자(input iterator) : 읽기만 가능, 순방향 이동(++), 현 위치의 원소 한 번만 읽을 수 있음
  - 출력 반복자(output iterator) : 쓰기만 가능, 순방향 이동(++), 현 위치의 원소 한번만 쓸 수 있음
  - 순방향 반복자(forward iterator) : 읽기, 쓰기 가능, 순방향 이동(++), 재할당 가능
  - 양방향 반복자(bidirectional iterator) : 읽기, 쓰기 가능, 순,역방향 이동(++ --), 재할당 가능
    - list, set, map, multiset, multimap ..
  - 임의접근 반복자(random access iterator) : 읽기, 쓰기 가능, 추가적인 이동(+, -, +=, -=, [])가능, 재할당 가능
    - vector, deque

![image](https://user-images.githubusercontent.com/59442344/125278188-6025a980-e34d-11eb-9974-b0f5a7f4a56a.png)

## 06. 반복자 요소의 삭제
  - vector
    - erase로 **요소를 삭제**하거나 push_back을 사용하여 **요소를 추가**하는 경우, **해당 vector가 갖고 있는 반복자가 사라지는 경우가 발생**한다
    - **erase** : 잘못된 방법으로 iterator와 같이 사용하면, erase된 위치부터 그 이후에 존재하는 위치들에 존재하던 iterator들이 변경될 수 있다.
    - **push_back** : 특정 iterator 변수 iter가 vector의 end() 함수로 받은 past-the-end 위치를 가리키고 있을 때, push_back으로 새로운 원소가 추가되면, iter는 무효화된다.
  -  list
    - **erase에 의해 삭제된 요 소를 가리키던 반복자만 무효화 된다.**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(void) {

	vector<int> arr;
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(5);
	arr.push_back(6);
	arr.push_back(1);
	arr.push_back(8);
	arr.push_back(9);

	for (auto iter = arr.begin(); iter != arr.end(); ++iter) {
		if (*iter == 5) {
		
      			// iter가 사라지게 되어, 이후부터 오류가 발생한다.
			arr.erase(iter);
			
		}
		else
			cout << *iter << " ";
		cout << "\n";
	}

	vector<int>::iterator iter = arr.end();

	arr.push_back(12);
	
  	// iter는 push_back()으로 값이 무효화되기에 오류가 발생한다.
	cout << *(iter-1) << "\n";

	return 0;
}
```




# Priority Queue
  - 우선순위에 따른 값의 반환

## 사용방법

### 1. priority_queue< 자료형, 컨테이너 종류, 우선순위 계산의 방법 >
  - priority_queue< int, vector<int>, less<int> > : 내림차순 저장 (우선순위 - 큰 int형 정수)
  - priority_queue< int, vector<int>, greater<int> > : 오름차순 저장 (우선순위 - 작은 int형 정수)
  - priority_queue< pair<int, int>, vector< pair<int, int> > > : 따로 설정 안해줄 경위, 내림차순 저장 (우선순위 - 큰 first > 큰 second)
  - priority_queue< pair<int, int>, vector< pair<int, int> >, compare> : compare가 지정해 주는 방식에 따라, 우선순위 지정
    - compare를 struct로 선언, 연산자 오버로딩을 이용해서 저장의 우선순위를 결정.
    - 여기 compare과 sort()에서의 swap조건이 다르다 : compare - 참이면 swap, sort - 거짓이면 swap
  - **구조체를 통한 비교를 자유자재로 다뤄야지 자유롭게 우선순위를 설정해줄 수 있다.**

```cpp
// 구조체 compare를 사용하는 priority_queue

#include <iostream>
#include <utility>
#include <queue>
#include <ctime>
#include <cstdlib>
using namespace std;

// compare라는 struct를 연산자 오버로딩을 통해서 마치 함수처럼 사용할 수 있게 된다!
struct compare {
	bool operator()(pair<int, int> p1, pair<int, int> p2) {

		// 숫자가 작을수록 우선순위가 높아지게 해봅시다.
		if (p1.first != p2.first)
			// priority queue에서는 true면 swap한다 : 원하는 결과와 반대로 선언 , 전 > 후 : 오름차순 저장
			// sort() 함수에서는 false면 swap하는 것과 반대이다 : 원하는 결과대로 선언 , 전 < 후 : 오름차순 정렬
			return p1.first > p2.first;
		else
			return p2.second > p2.second;
	}
};

int main(void) {

	priority_queue< pair<int, int>, vector<pair<int, int> >, compare> pq;
	srand((unsigned int)time(NULL));

	// 기본적으로 내림차순으로 저장된다.
	for (int i = 0; i < 10; ++i) {
		pq.push(make_pair(rand() %5, rand()%6));
	}

	for (int i = 0; i < 10; ++i) {
		cout << pq.top().first << " " << pq.top().second << endl;
		pq.pop();
	}

	return 0;
}

```

### 2. void push(element) : 원소 추가

### 3. void pop() :  우선순위에 따른 원소 제거

### 4. element_data_type top() : 가장 우선순위 높은 원소 반환

### 5. bool empty() : 비었으면 true, 차있으면 false

### 6. int size() : 들어있는 원소의 갯수 반환

```cpp
// functional의 greater<type..> 을 이용하는 Min Heap
#include <iostream>
#include <functional>
#include <queue>
using namespace std;

int main(){

	// priority_queue
	priority_queue< int, vector<int>, greater<int> > pq;

	// push(element)
	pq.push(5);
	pq.push(2);
	pq.push(8);
	pq.push(9);
	pq.push(1);
	pq.push(14);

	// pop()
	pq.pop();
	pq.pop();

	// top();
	cout << "pq top: " << pq.top() << '\n';

	// empty(), size()
	if(!pq.empty()) cout << "pq size: " << pq.size() << '\n';

	// pop all
	while(!pq.empty()){
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << '\n';

	return 0;
}


// functional의 less<type..> 을 이용하는 Max Heap
#include <iostream>
#include <functional>
#include <queue>
using namespace std;

int main(){

	// priority_queue
	priority_queue< int, vector<int>, less<int> > pq;
	// or priority_queue<int> pq;

	// push(element)
	pq.push(5);
	pq.push(2);
	pq.push(8);
	pq.push(9);
	pq.push(1);
	pq.push(14);

	// pop()
	pq.pop();
	pq.pop();

	// top();
	cout << "pq top: " << pq.top() << '\n';

	// empty(), size()
	if(!pq.empty()) cout << "pq size: " << pq.size() << '\n';

	// pop all
	while(!pq.empty()){
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << '\n';

	return 0;

}
```



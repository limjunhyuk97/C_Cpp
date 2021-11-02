# Priority Queue
  - 우선순위에 따른 값의 반환

## 사용방법

### 1. priority_queue< 자료형, 컨테이너 종류, 우선순위 계산의 방법 >
  - priority_queue는 기본적으로 max_heap

```cpp
////////// functional object //////////
struct FuncObj1 {
	bool operator()(const ipair& p1, const ipair& p2) const {
		if (p1.first == p2.first) return p1.second > p2.second;
		else return p1.first > p2.first;
	}
}funcObj1;

struct FuncObj2 {
	bool operator()(const ipair& p1, const ipair& p2) const {
		if (p1.first == p2.first) return p1.second < p2.second;
		else return p1.first < p2.first;
	}
}funcObj2;
	
struct compare{
    bool operator()(const int & n1, const int & n2){
        return n1 > n2;
    }
};
	
priority_queue<int, vector<int>, compare> pq1;
priority_queue<int, vector<int>, greater<int> > pq2;
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



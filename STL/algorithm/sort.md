# [SORT](https://en.cppreference.com/w/cpp/algorithm/sort)


## 1. 정렬 형태

### 1.1 [first, last) 사이의 원소들을 정렬방식(기본은 오름차순)에 따라 정렬   
  
### 1.2 first, last는 각각 주소값을 반환해야함  

### 1.3 배열 sorting
  - **sort(arr, arr+n)**

### 1.4 vector sorting
  - **sort(v.begin(), v.end())**
  - **sort(v.begin(), v.end(), compare) : 사용자 정의 compare로 sorting : operator overloading, lambda expression, ...**
  - **sort(v.begin(), v.end(), greater\<type>()) : 내림차순 sorting**
  - **sort(v.begin(), v.end(), less\<type>()) : 오름차순 sorting**

  
## 2. 정렬방식

### 2.1 기본적인 원리
  - **앞 < 뒤 true, 앞 > 뒤 false(교환 일어나는 경우) : 오름차순**
  - **앞 > 뒤 true, 앞 < 뒤 false(교환 일어나는 경우) : 내림차순**

### 2.2.0 compare 이용시 주의사항
- **invalid comparator 발생 문제**    
    - **strict weak ordering relation**을 만족시켜야 해결할 수 있다.
      - 비교불가능성이 동등성을 의미하는 경우
      - 즉, 동등하지 않은 경우를 비교가능하게 구현해야 한다..

### 2.2.1 compare 이용 - 연산자 오버로딩
  - 기본적으로 <, > 연산자를 이용하여 element들을 비교한다.
  - **객체간 비교**위한 **연산자 오버로딩**

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

class Point{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
	void PointInit(int x, int y) {
		xpos = x; ypos = y;
	}
  
  // strict weak ordering relation을 만족시키기 위한 정의
  // 같지 않은 경우에 대해서 원하는 bool형 값을 반환하도록 정의하였다..
	bool operator<(const Point &ref) {
		if (this->xpos != ref.xpos) return this->xpos < ref.xpos;
		else
			if (this->ypos != ref.ypos) return this->ypos < ref.ypos;
	}
  
	friend ostream& operator<<(ostream& ostm, const Point& ref);
};

ostream& operator<<(ostream& ostm, const Point& ref) {
	cout << ref.xpos << " " << ref.ypos << "\n";
	return ostm;
}

int main(void) {

	int N;
	cin >> N;
	
	Point* parr = new Point[N];

	for (int i = 0; i < N; ++i) {
		int x, y;
		cin >> x >> y;
		parr[i].PointInit(x, y);
	}
	sort(parr, parr + N);
	for (int i = 0; i < N; ++i) {
		cout << parr[i];
	}

	delete[]parr;

	return 0;
}
```

### 2.3 grater<자료형> , less<자료형> 이용
  - greater<자료형> : 내림차순 정렬
  - less<자료형> : 오름차순 정렬

```cpp
#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> P1;
typedef pair<int, string> P2;

int main(void) {

	P1 pair1;
	P2 pair21, pair22, pair23;
	vector<P2> vec;
	vector<P2>::iterator iter;

	pair21 = make_pair(2, "whaat");
	pair22 = make_pair(2, "hello!");
	pair23 = make_pair(3, "yello!");
	vec.push_back(pair21);
	vec.push_back(pair22);
	vec.push_back(pair23);

	sort(vec.begin(), vec.end(), greater<pair<int, string>>());
	for (iter = vec.begin(); iter < vec.end(); ++iter) {
		cout << iter->first << " " << iter->second << '\n';
	}
	cout << '\n';

	sort(vec.begin(), vec.end(), less<pair<int, string>>());
	for (iter = vec.begin(); iter < vec.end(); ++iter) {
		cout << iter->first << " " << iter->second << '\n';
	}

	return 0;
}
```

### 2.4 이외의 사항
  - 사용자 정의를 통해서 functor나 lambda expression을 집어넣을 수 있다.
  


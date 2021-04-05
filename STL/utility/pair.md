# Pair class


## pair class란?

### 1. 두 객체를 하나의 객체로 취급할 수 있게 묶어주는 클래스이다.
### 2. STL에서 '데이터 쌍'을 표현할 때 사용한다!
### 3. \<utility> 헤더에 존재한다.


## pair class의 이용

### 1.0 pair\<type1, type2> P
  - type1, type2의 타입을 쌍으로 갖는 pair P에 대한 선언

```cpp
pair<int, int> P1;
```

### 1.1 typedef pair\<type1, type2> P
  - type1, type2의 타입을 쌍으로 갖는 pair쌍 타입에 P라는 별칭 부여

```cpp
typedef pair<int, int> P1;
P1 pair11;
```

### 2. p.first
  - pair 타입 p의 첫번째 인자 반환

### 3. p.second
  - pair 타입 p의 두번째 인자 반환

### 4. make_pair(type1 값or변수, type2 값or변수)
  - pair 만들어준다.

```cpp
P1 pair1 = make_pair(1, 2);

vector< pair<int, int> > v;
v.push_back(make_pair(3, 4));
```

### 5. operator == != < > <= >= 에 대해서 오버로딩 되어있어 이용가능하다.

### 6. sort 알고리즘에 의해서 정렬 가능하다!
  - 첫번째 인자 기준 정렬 -> 두번째 인자 기준 정렬

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

	int a = 2;

	pair21 = make_pair(a, "whaat");
	pair22 = make_pair(a, "hello!");
	pair23 = make_pair(3, "yello!");
	vec.push_back(pair21);
	vec.push_back(pair22);
	vec.push_back(pair23);
  
  // 기본적인 pair에 대한 정렬
	sort(vec.begin(), vec.end());
	for (iter = vec.begin(); iter < vec.end(); ++iter) {
		cout << iter->first << " " << iter->second << '\n';
	}
	cout << '\n';
  
  // greater을 통한 pair 정렬
	sort(vec.begin(), vec.end(), greater<pair<int, string>>());
	for (iter = vec.begin(); iter < vec.end(); ++iter) {
		cout << iter->first << " " << iter->second << '\n';
	}
	cout << '\n';
  
  // less를 통한 pair 정렬 - 기본적인 pair에 대한 정렬과 같다.
	sort(vec.begin(), vec.end(), less<pair<int, string>>());
	for (iter = vec.begin(); iter < vec.end(); ++iter) {
		cout << iter->first << " " << iter->second << '\n';
	}

	return 0;
}
```










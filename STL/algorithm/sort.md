# [SORT](https://en.cppreference.com/w/cpp/algorithm/sort)

  - sort(first, last, 정렬방식)   
  
  - [first, last) 사이의 원소들을 정렬방식(기본은 오름차순)에 따라 정렬   
  
  - first, last는 각각 주소값을 반환해야함. // .begin(), .end()와 같이 많이 쓰임 //   
  
  - 정렬방식
    - **앞 인자 < 뒤 인자 : 오름차순** , **앞 인자 > 뒤 인자 : 내림차순**
    - 기본적으로 < 연산자를 이용하여 element들을 비교한다. // 그래서 객체간 비교를 위해서는 operator< 연산자 오버로딩이 요구된다. //
    - 사용자 정의를 통해서 functor나 lambda expression을 집어넣을 수 있다.
    - **invalid comparator 발생 문제**    
      - **strict weak ordering relation**을 만족시켜야 해결할 수 있다.
        - 비교불가능성이 동등성을 의미하는 경우
	- 즉, 동등하지 않은 경우를 비교가능하게 구현해야 한다..

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

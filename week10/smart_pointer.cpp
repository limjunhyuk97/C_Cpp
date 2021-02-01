#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) { cout << "Constructor called\n"; }
	~Point() { cout << "Destructor called\n"; }
	void SetPos(int x, int y) { xpos = x; ypos = y; }
	friend ostream& operator<<(ostream& ostm, const Point& ref);	
};

ostream& operator<<(ostream& ostm, const Point& ref) {
	cout << " [ " << ref.xpos << " , " << ref.ypos << " ] " << endl;
	return ostm;
}

class PointSmartPointer {
private:
	Point* ptr;
public:
	PointSmartPointer(Point* myptr) : ptr(myptr) {}
	Point* operator->()const { return ptr; }
	Point& operator*()const { return *ptr; }
	~PointSmartPointer() {
		delete ptr;
	}
};
// smartpointer(스마트 포인터)는 포인터 역할을 하는 객체로, 구현하는 것이다.
// STL에서 지원하며, 가장 큰 이점은 스마트 포인터의 자동 소멸연산이다.

int main() {

	PointSmartPointer sptr1(new Point(3, 4));
	cout << *sptr1;

	return 0;
}

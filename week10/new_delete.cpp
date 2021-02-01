#include <iostream>
using namespace std;
class Point {
private:
	int xpos, ypos;
public:
	Point(int x, int y) : xpos(x), ypos(y) {}
	friend ostream& operator<<(ostream& ostm, const Point& ref);
	
	// 오버로딩되는 new 연산자 함수가 반환하는 값은, 컴파일러에 의해 적절히 형변환이 된 주소의 크기 값이다. 
	// operator new 연산자함수를 활용할 때에는, 컴파일러가 여전히 생성자 호출과 반환된 주소값의 형변환을 관리하니, 메모리 공간의 할당만 책임지게 되는 것이다.
	void* operator new (size_t size){
		cout << "operator new : "<<size<<endl;
		void* adr = new char[size];
		return adr;
	}

	// delete 연산자에 의해서 지워지는 것은 주소의 크기 표현을 위해 사용된 char 배열이다.
	void operator delete(void* adr) {
		cout << "operator deleted!" << endl;
		delete[]adr;
	}

	Point* operator->() {
		return this;
	}

	Point& operator*() {
		return *this;
	}

};

ostream& operator<<(ostream& ostm, const Point& ref) {
	cout << "[ " << ref.xpos << ", " << ref.ypos << " ]" << endl;
	return ostm;
}

int main(void) {

	Point* pt = new Point(3, 4);
	cout << *pt;
	delete pt;

	return 0;
}

// 이외에도 더 많은 기능들이 있지만, 기본적인 부분만 다루고 넘어간다. STL을 통하여 다루게 될 때 그때가서 알아보자.

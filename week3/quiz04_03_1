#include <iostream>
using namespace std;

class Point {
private:
	int xPos, yPos;
public:
	Point(int x, int y)
		:xPos(x), yPos(y) {}
	void ShowPointInfo() const {
		cout << "[" << xPos << ", " << yPos << "]" << endl;
	}
};

class Circle {
private:
	Point center;
	int radius;

public:
	Circle(int x, int y, int r)
		: center(x, y), radius(r) {}

	void PrintStatus() const {
		cout << "radius : " << radius << endl;
		center.ShowPointInfo();
	}
};

class Ring {
private:
	Circle innerRing;
	Circle outerRing;
public:
	Ring(int x1, int y1, int r1, int x2, int y2, int r2)
		: innerRing(x1, y1, r1), outerRing(x2, y2, r2) {}
	
	void ShowRingInfo() const {
		cout << "inner Circle Info...\n";
		innerRing.PrintStatus();
		cout << "outer Circle Info...\n";
		outerRing.PrintStatus();
	}

};

int main(void) {
	Ring ring(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();

	return 0;
}

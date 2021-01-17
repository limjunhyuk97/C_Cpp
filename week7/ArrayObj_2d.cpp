#include <iostream>
using namespace std;

class BoundCheckIntArray {
private:
	int arrlen;
	int* arr;
	BoundCheckIntArray(const BoundCheckIntArray& ref) {}
	BoundCheckIntArray& operator=(const BoundCheckIntArray& ref) {}
public:
	BoundCheckIntArray(int arrlen = 0) : arrlen(arrlen) {
		arr = new int[this->arrlen];
	}
	int operator[](int idx) const {
		if (idx < 0 || idx >= arrlen) {
			cout << "out of range\n";
		}
		return arr[idx];
	}
	int& operator[](int idx) {
		if (idx < 0 || idx >= arrlen) {
			cout << "out of range\n";
		}
		return arr[idx];
	}
	int GetArrLen(void) const {
		return arrlen;
	}
	~BoundCheckIntArray() {
		delete[] arr;
	}

};

typedef BoundCheckIntArray* BoundCheckIntArrayPtr;

class BoundCheck2DIntArray {
private:
	int rowlen;
	int collen;
	BoundCheckIntArray** arr2d;

	BoundCheck2DIntArray(const BoundCheck2DIntArray& ref) {}
	BoundCheck2DIntArray& operator=(const BoundCheck2DIntArray& ref) {}
public:
	BoundCheck2DIntArray(int row = 0, int col = 0) : rowlen(row), collen(col) {
		arr2d = new BoundCheckIntArrayPtr[rowlen];
		for (int i = 0; i < rowlen; ++i) {
			arr2d[i] = new BoundCheckIntArray(collen);
		}
	}

	BoundCheckIntArray& operator[](int idx) {
		if (idx < 0 || idx >= rowlen) {
			cout << "Out Of Range\n";
			exit(1);
		}
		return *(arr2d[idx]);
	}
	
	~BoundCheck2DIntArray() {
		for (int i = 0; i < rowlen; ++i) {
			delete arr2d[i];
		}
		delete[] arr2d;
	}
};

int main(void) {

	BoundCheck2DIntArray arr2d(3, 4);
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j) {
			arr2d[i][j] = i + j;
		}
	}

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j) {
			cout<<arr2d[i][j]<<endl;
		}
	}

	return 0;
}

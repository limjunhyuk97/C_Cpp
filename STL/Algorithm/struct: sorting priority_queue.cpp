// struct //

// sort (struct 내장 함수, functional object, function)
// 1. struct 안에 함수 내장
//		- operator< 에 대한 연산자 오버로딩에 의해서 정렬 순서를 정의 : < 오름차순, > 내림차순
//		- operator> 에 대해서는 해당사항 없음
// 2. sturct 밖에 함수 정의
//		2.1 functional object 객체 전달, operator() : < 오름차순, > 내림차순
//		2.2 function 정의, struct인자 두개 받기 : < 오름차순, > 내림차순

// priority_queue (struct 내장 함수, functional object)
// 1. struct 안에 함수 내장
//		- 반드시 const 함수로 선언하기!
//		- operator< 에 대한 연산자 오버로딩에 의해서 정렬 순서를 정의 : < 내림차순, > 오름차순
//		- operator> 에 대해서는 해당사항 없음
// 2. sturct 밖에 함수 정의
//		2.1 functional object 자료형 전달, operator() : < 내림차순, > 오름차순

// 정렬기준의 우선순위 (sort, priority_queue 모두 해당)
// 내장함수에서의 정의보다, 나중에 전달된 functional object의 정의 혹은 function의 정의가 우선한다

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct node {
	
	int x, y;

	// 1. struct 내부 함수 내장

	/*
	* sort에서 오름차순, priority_queue에서는 내림차순
	* const 함수가 아니라면 priority_queue에서 오류 발생 - 오버로딩이 되있지 않다고 판단
	bool operator<(const node& other) const{
		if (x == other.x) return y < other.y;
		else return x < other.x;
	}
	*/

	
	//* sort에서 내림차순, priority_queue에서는 오름차순
	//* const 함수가 아니라면 priority_queue에서 오류 발생 - 오버로딩이 되있지 않다고 판단
	bool operator<(const node& other) const{
		if (x == other.x) return y > other.y;
		else return x > other.x;
	}
	
	
	/*
	* operator> 는 내장함수로써 의미가 없음
	bool operator>(const node& other) {
		if (x == other.x) return y < other.y;
		else return x < other.x;
	}
	*/

};

// 2.1 functional object
// sort에서는 내림차순, priority_queue에서는 오름차순
struct FuncObj1 {
	bool operator()(const node& p1, const node& p2) const{
		if (p1.x == p2.x) return p1.y > p2.y;
		else return p1.x > p2.x;
	}
}funcObj1;

// sort에서는 오름차순, priority_queue에서는 내림차순
struct FuncObj2 {
	bool operator()(const node& p1, const node& p2) const{
		if (p1.x == p2.x) return p1.y < p2.y;
		else return p1.x < p2.x;
	}
}funcObj2;


// 2.2 function
// sort에서 오름차순
bool func1(const node &p1, const node&p2) {
	if (p1.x == p2.x) return p1.y < p2.y;
	else return p1.x < p2.x;
}

// sort에서 내림차순
bool func2(const node& p1, const node& p2) {
	if (p1.x == p2.x) return p1.y > p2.y;
	else return p1.x > p2.x;
}


int main(void) {
	
	// sort에 대한 정리

	node p[4];
	p[0] = { 5, 2 };
	p[1] = { 2, 4 };
	p[2] = { 2, 3 };
	p[3] = { 3, 5 };

	sort(&p[0], &p[4]);

	for (int i = 0; i < 4; ++i)
		cout << p[i].x << " " << p[i].y << endl;
	cout << endl;

	sort(&p[0], &p[4], funcObj1);

	for (int i = 0; i < 4; ++i)
		cout << p[i].x << " " << p[i].y << endl;
	cout << endl;

	sort(&p[0], &p[4], func1);

	for (int i = 0; i < 4; ++i)
		cout << p[i].x << " " << p[i].y << endl;
	cout << endl;

	// priority_queue에 대한 정리
	priority_queue<node,vector<node>, FuncObj2> pq;
	pq.push({ 3, 10 });
	pq.push({ 6, 9 });
	pq.push({ 6, 7 });
	pq.push({ 5, 5 });
	pq.push({ 5, 7 });
	pq.push({ 1, 11 });

	for (; !pq.empty();) {
		node tmp = pq.top(); pq.pop();
		cout << tmp.x << " " << tmp.y << endl;
	}
	cout << endl;


	return 0;
}

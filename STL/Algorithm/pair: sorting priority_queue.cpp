// pair //

// sort
// 1. pair에는 내장함수를 넣을 수 없다.
// 2. 기본 정렬 순서 - 오름차순
// 3. 함수 정의
//		2.1 function object 객체 전달, operator() : < 오름차순, > 내림차순
//		2.2 function 정의, pair인자 두개 받기 : < 오름차순, > 내림차순

// priority_queue
// 1. pair에는 내장함수를 넣을 수 없다.
// 2. 기본 정렬 순서 - 내림차순(max_heap)
// 3. 함수 정의
//		2.1 function object 객체 전달, operator() : < 내림차순, > 오름차순


#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>

using namespace std;

typedef pair<int, int> ipair;

// 3.1 functional object
// sort에서는 내림차순, priority_queue에서는 오름차순
struct FuncObj1 {
	bool operator()(const ipair& p1, const ipair& p2) const {
		if (p1.first == p2.first) return p1.second > p2.second;
		else return p1.first > p2.first;
	}
}funcObj1;

// sort에서는 오름차순, priority_queue에서는 내림차순
struct FuncObj2 {
	bool operator()(const ipair& p1, const ipair& p2) const {
		if (p1.first == p2.first) return p1.second < p2.second;
		else return p1.first < p2.first;
	}
}funcObj2;

// 3.2 function
// sort에서 오름차순
bool func1(const ipair& p1, const ipair& p2) {
	if (p1.first == p2.first) return p1.second < p2.second;
	else return p1.first < p2.first;
}

// sort에서 내림차순
bool func2(const ipair& p1, const ipair& p2) {
	if (p1.first == p2.first) return p1.second > p2.second;
	else return p1.first > p2.first;
}

vector<ipair> vpair;
priority_queue<ipair, vector<ipair>, FuncObj1> ppair;

int main(void) {

	srand((unsigned int)time(NULL));

	for (int i = 0; i < 10; ++i) {
		ipair tmp = make_pair(rand() % 10, rand() % 10);
		vpair.push_back(tmp);
		ppair.push(tmp);
	}

	sort(vpair.begin(), vpair.end(), func2);

	for (int i = 0; i < 10; ++i)
		cout << vpair[i].first << " " << vpair[i].second << "\n";
	cout << endl;

	for (; !ppair.empty(); ) {
		ipair tmp = ppair.top(); ppair.pop();
		cout << tmp.first << " " << tmp.second << endl;
	}
	cout << endl;


	return 0;
}

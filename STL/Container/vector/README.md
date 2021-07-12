# vector

## erase
  - iterator를 통해서 지울 위치를 지정해주어야 한다
  - erase를 사용하면 size가 줄어들면서, 원소들이 빈공간을 메우도록 당겨진다.

```cpp
// 출력
// 0 2  1 3  2 4  3 5  4 6  5 1  6 8  7 9
// 0 2  1 3  2 5  3 6  4 1  5 8  6 9

#include <iostream>
#include <vector>
using namespace std;

int main(void) {

	vector<int> arr;
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(5);
	arr.push_back(6);
	arr.push_back(1);
	arr.push_back(8);
	arr.push_back(9);

	for (int i = 0; i < arr.size(); ++i)
		cout << i << " " << arr[i] << '\n';

	cout << endl;

	vector<int>::iterator iter = arr.begin();
	arr.erase(iter + 2);

	for (int i = 0; i < arr.size(); ++i)
		cout << i << " " << arr[i] << '\n';
	
	return 0;
}
```

## [rbegin, rend](http://www.soen.kr/lecture/ccpp/cpp4/39-3-3.htm)
  - 역방향 순회를 하고 싶을 떄, 단순히 v.end() 부터 시작해서는 안되는 이유이다.

![image](https://user-images.githubusercontent.com/59442344/123751871-28514780-d8f3-11eb-9827-0bc9b445a685.png)

```cpp
// 역방향 순회의 예시
vector<int>::reverse_iterator rit;
     for (rit=vi.rbegin();rit!=vi.rend();rit++) {
          printf("%d\n",*rit);
     }
```

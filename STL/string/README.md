# string

## string parsing

### 1. string.find를 사용하여 parsing 하는 방식

```cpp
// string.find 함수를 사용한 tokenizing
// 찾고자 하는 문자(열)을 찾으면 문자열이 위치한 주소 값을 반환
// 찾고자 하는 문자(열)을 찾지 못하면 string::npos를 반환

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string str;
size_t previous, current;
vector<string> parsed;

int main(void) {

	getline(cin, str);
  // std::istream::getline : istream& cin.getline(char *s, streamsize n, char delim);
  // std::getline : istream& getline(istream& is, string &str, char delim);
  
  // string parsing의 방식
	previous = 0; current = str.find(',', previous);
	while (current != string::npos) {
		parsed.push_back(str.substr(previous, current - previous));
		previous = current + 1;
		current = str.find(',', previous);
	}
	parsed.push_back(str.substr(previous, current - previous));

	for (auto iter = parsed.begin(); iter != parsed.end(); ++iter)
		cout << *iter << '\n';

	return 0;
}
```

### 2. istringstream를 사용하여 parsing 하는 방식

```cpp
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main(void) {

	string str, tmp;
	vector<string> parsed;

	getline(cin, str);

	istringstream ss(str);
	while (getline(ss, tmp, ',')) {
		parsed.push_back(tmp);
	}

	for (int i = 0; i < parsed.size(); ++i)
		cout << parsed[i] << '\n';

	return 0;
}
```

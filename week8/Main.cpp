#include <iostream>
#include <string>
#include "String.h"
using namespace std;

int main(void) {

	char c1[8] = "I like ";
	char c2[13] = "string class";

	String str1 = c1;
	String str2 = c2;
	String str3 = str1 + str2;

	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;

	str1 += str2;
	if (str3 == str1)
		cout << "동일 문자열" << endl;
	else
		cout << "다른 문자열" << endl;

	String str4;
	cout << "문자열 입력 : ";
	cin >> str4;
	cout << "문자열 출력 : " << str4 << endl;

	return 0;
}

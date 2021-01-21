#include "String.h"
#include <iostream>
#include <cstring>
using namespace std;

String::String() : arrlen(0) {
	arr = NULL;
}

String::String(char* str) {
	arrlen = strlen(str) + 1;
	arr = new char[arrlen];
	strcpy_s(arr, arrlen, str);
}

String::String(const String& ref) {
	arrlen = ref.arrlen;
	arr = new char[arrlen];
	strcpy_s(arr, arrlen, ref.arr);
}

String& String::operator=(const String& ref) {
	if (arr != NULL)
		delete[]arr;
	arrlen = ref.arrlen;
	arr = new char[arrlen];
	strcpy_s(arr, arrlen, ref.arr);
	
	return *this;
}

String String::operator+(const String& ref) {
	String str;
	str.arrlen = arrlen + ref.arrlen - 1;
	str.arr = new char[str.arrlen];
	strcpy_s(str.arr,str.arrlen, arr);
	strcat_s(str.arr,str.arrlen, ref.arr);
	return str;
}

String& String::operator+=(const String& ref) {
	
	int tmplen = arrlen;
	char* tmparr = new char[tmplen];
	strcpy_s(tmparr, arrlen, arr);
	if (arr != NULL) {
			delete[]arr;
	}
	arrlen += ref.arrlen - 1;
	arr = new char[arrlen];
	strcpy_s(arr, arrlen, tmparr);
	strcat_s(arr, arrlen, ref.arr);
	delete[]tmparr;

	return *this;

}

bool String::operator==(const String& ref) {
	if (!strcmp(arr, ref.arr))
		return true;
	else
		return false;
}

String::~String() {
	if(arr !=NULL)
		delete[]arr;
}

std::ostream& operator<<(std::ostream& ostm, const String& ref) {
	ostm << ref.arr;
	return ostm;
}

std::istream& operator>>(std::istream& istm, String& ref) {
	char tmp[100];
	istm >> tmp;
	ref = String(tmp);
	return istm;
}

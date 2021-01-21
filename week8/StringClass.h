#pragma once
#include <iostream>

class String {
private:
	char* arr;
	int arrlen;
public:
	String();
	String(char *str);
	String(const String& ref);
	String& operator=(const String& ref);
	String operator+(const String& ref);
	String& operator+=(const String& ref);
	bool operator==(const String& ref);
	friend std::ostream& operator<<(std::ostream& ostm, const String& ref);
	friend std::istream& operator>>(std::istream& istm, String& ref);
	~String();
};

std::ostream& operator<<(std::ostream& ostm, const String& ref);
std::istream& operator>>(std::istream& istm, String& ref);

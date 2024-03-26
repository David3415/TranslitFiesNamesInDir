#pragma once
#include <string>

class Utf8ToUtf16_Class {
public:
	Utf8ToUtf16_Class(char* utf8Char) : _utf8Char(utf8Char) {};
	static wchar_t* Utf8ToUtf16_Void(char* _utf8Char);
private:
	char* _utf8Char;
};

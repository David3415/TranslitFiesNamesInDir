#pragma once
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <string>
#include <experimental/filesystem>

class IfFileNameAlreadyExistsClass {
public:
	IfFileNameAlreadyExistsClass(wchar_t* fullPathChar, wchar_t* fullPathCharSubstr) :
		_fullPathChar(fullPathChar), _fullPathCharSubstr(fullPathCharSubstr) {};

	static bool IfFileNameAlreadyExistsVoid(wchar_t* _fullPathChar, wchar_t* _fullPathCharSubstr);
private:
	wchar_t* _fullPathChar;
	wchar_t* _fullPathCharSubstr;
};

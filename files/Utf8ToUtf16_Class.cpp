#include "Utf8ToUtf16_Class.h"
#include <windows.h>

wchar_t* Utf8ToUtf16_Class::Utf8ToUtf16_Void(char* _utf8Char) {
	size_t utf8CharSize = strlen(_utf8Char) + 1;
	size_t convertedChars = 0;//вообще не ясно чё за
	const size_t utf16CharSize = utf8CharSize * 2 + 10;
	wchar_t* Utf16Char = new wchar_t[200];
	mbstowcs_s(&convertedChars, Utf16Char, 200, _utf8Char, _TRUNCATE);
	//delete[]utf16Char;
	return Utf16Char;
};
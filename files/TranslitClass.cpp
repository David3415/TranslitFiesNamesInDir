#include "TranslitClass.h"
#include "SlovarClass.h"
#include <iostream>
#include "Utf8ToUtf16_Class.h"
#include "Utf16ToUtf8_Class.h"

std::string TranslitClass::TranslitVoid(const std::string& _strFromClipboard) {

	struct SlovarVec
	{
		wchar_t first;
		char sec;
		char third;
	};
	std::vector<SlovarVec>slovarVec = {
	{L'�',L'=',L'A' },
	{L'�',L'=',L'B' },
	{L'�',L'=',L'V' },
	{ L'�',L'=',L'G' },
	{ L'�',L'=',L'D' },
	{ L'�',L'=',L'E' },
	{ L'�',L'=',L'E' },
	{ L'�',L'=',L'G' },
	{ L'�',L'=',L'Z' },
	{ L'�',L'=',L'I' },
	{ L'�',L'=',L'I' },
	{ L'�',L'=',L'K' },
	{ L'�',L'=',L'L' },
	{ L'�',L'=',L'M' },
	{ L'�',L'=',L'N' },
	{ L'�',L'=',L'O' },
	{ L'�',L'=',L'P' },
	{ L'�',L'=',L'R' },
	{ L'�',L'=',L'S' },
	{ L'�',L'=',L'T' },
	{ L'�',L'=',L'Y' },
	{ L'�',L'=',L'F' },
	{ L'�',L'=',L'H' },
	{ L'�',L'=',L'C' },
	{ L'�',L'=',L'C' },
	{ L'�',L'=',L'S' },
	{ L'�',L'=',L'S' },
	{ L'�',L'=',L'&' },
	{ L'�',L'=',L'I' },
	{ L'�',L'=',L'&' },
	{ L'�',L'=',L'E' },
	{ L'�',L'=',L'Y' },
	{ L'�',L'=',L'A' },

	{ L'�',L'=',L'a' },
	{ L'�',L'=',L'b' },
	{ L'�',L'=',L'v' },
	{ L'�',L'=',L'g' },
	{ L'�',L'=',L'd' },
	{ L'�',L'=',L'e' },
	{ L'�',L'=',L'e' },
	{ L'�',L'=',L'g' },
	{ L'�',L'=',L'z' },
	{ L'�',L'=',L'i' },
	{ L'�',L'=',L'i' },
	{ L'�',L'=',L'k' },
	{ L'�',L'=',L'l' },
	{ L'�',L'=',L'm' },
	{ L'�',L'=',L'n' },
	{ L'�',L'=',L'o' },
	{ L'�',L'=',L'p' },
	{ L'�',L'=',L'r' },
	{ L'�',L'=',L's' },
	{ L'�',L'=',L't' },
	{ L'�',L'=',L'y' },
	{ L'�',L'=',L'f' },
	{ L'�',L'=',L'h' },
	{ L'�',L'=',L'c' },
	{ L'�',L'=',L'c' },
	{ L'�',L'=',L's' },
	{ L'�',L'=',L's' },
	{ L'�',L'=',L'&' },
	{ L'�',L'=',L'i' },
	{ L'�',L'=',L'&' },
	{ L'�',L'=',L'e' },
	{ L'�',L'=',L'u' },
	{ L'�',L'=',L'a' },
	};

	std::string strFromClipboard;
	strFromClipboard.assign(_strFromClipboard);
	std::wstring wide_strFromClipboard = Utf8ToUtf16_Class::Utf8ToUtf16_Void(&strFromClipboard[0]);

	size_t last_slash_idx = wide_strFromClipboard.rfind('\\');
	size_t wide_strFromClipboardLen = wide_strFromClipboard.length();

	std::wstring wresult;

	if (std::string::npos != last_slash_idx)
	{
		wresult = wide_strFromClipboard.substr(last_slash_idx + 1, wide_strFromClipboardLen);
		wresult = wide_strFromClipboard.substr(last_slash_idx + 1, wide_strFromClipboardLen);
	}

	for (size_t i = 0; i < wresult.size(); ++i) {
		wchar_t currentChar = wresult[i];
		for (int j = 0; j < 66; j++) {

			if (currentChar == slovarVec[j].first) {
				wresult[i] = slovarVec[j].third;
				std::wcout << wresult[i];
				break;
			}
		}
	}

	std::string result = strFromClipboard.substr(0,last_slash_idx+1);
	return result.append(Utf16ToUtf8_Class::Utf16ToUtf8_Void(&wresult[0]));
};

